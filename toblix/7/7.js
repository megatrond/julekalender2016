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

liner.on('readable', function () {
     var line;
     while (line = liner.read()) {
		 check(line);
     }
});

let n = 0, w = 0;

source.on('end', function() {
	console.log(n + ',' + w);
});

function check(line) {
	var parts = line.trim().split(' ');
	if(parts[3] === "north") n += parseInt(parts[1]);
	if(parts[3] === "south") n -= parseInt(parts[1]);
	if(parts[3] === "east") w -= parseInt(parts[1]);
	if(parts[3] === "west") w += parseInt(parts[1]);
}