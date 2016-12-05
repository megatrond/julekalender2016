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

source.on('end', function() {
});

function parse(str) {
	if(str === '0') return 0;
	if(str === 'I') return 1;
	if(str === 'II') return 2;
	if(str === 'III') return 3;
	if(str === 'III') return 4;
	if(str === 'IV') return 4;
	if(str === 'V') return 5;
	if(str === 'VI') return 6;
	if(str === 'VII') return 7;
	if(str === 'VIII') return 8;
	if(str === 'IX') return 9;
	if(str === 'X') return 10;
	if(str === 'XI') return 11;
	if(str === 'XII') return 12;
	if(str === 'XIII') return 13;
}

function check(line) {
	var parts = line.substr(1,line.length-2).split(',').map(line=>line.trim());
	var ret = "";
	for(var i = 0; i < parts.length/2; i++) {
		ret += String.fromCharCode(96 + parse(parts[i])+parse(parts[parts.length-i-1]));
	}
	console.log(ret);
}