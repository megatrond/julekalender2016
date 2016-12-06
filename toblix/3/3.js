var stream = require('stream');
var fs = require('fs');

var liner = new stream.Transform( { objectMode: true } );
liner._transform = function (chunk, encoding, done) {
     var data = chunk.toString();
     if (this._lastLineData) data = this._lastLineData + data;
 
     var lines = data.split('\n');
     this._lastLineData = lines.splice(lines.length-1,1)[0];
 
     lines.forEach(this.push.bind(this));
     done();
};
liner._flush = function (done) {
     if (this._lastLineData) this.push(this._lastLineData);
     this._lastLineData = null;
     done();
};
 
var source = fs.createReadStream('./data.txt');
source.pipe(liner);

const people = {};
function getPerson(name) {
	if(!people[name]) people[name] = {
		name,
		friends:[],
		hates:[]
	};
	return people[name];
}

function chameleonCount(person) {
	var count = 0;
	 person.friends.forEach((friend)=>{
		 if(person.hates.indexOf(friend) !== -1 && friend.hates.indexOf(person) === -1) count++;
	 });
	 return count;
}

liner.on('readable', function () {
	var line;
    while (line = liner.read()) {
		var parts = line.trim().split(/[\s,]+/);
		if(parts[0] === 'friends') {
			if(getPerson(parts[1]).friends.indexOf(getPerson(parts[2])) !== -1) break;
			getPerson(parts[1]).friends.push(getPerson(parts[2]));
			getPerson(parts[2]).friends.push(getPerson(parts[1]));
		} else if (parts[1] === 'hates') {
			getPerson(parts[0]).hates.push(getPerson(parts[2]));
		} else throw line;
    }
});

source.on('end', function() {
	for (var name in people) people[name].chameleonCount = chameleonCount(people[name]);
	 var max = null;
	 for (var name in people) {
		 if(max == null || people[name].chameleonCount > people[max].chameleonCount) max = name;
	 };
	 console.log(people[max].name);
});