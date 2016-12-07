const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream('data.txt')
});
rl.on('line', function(line) {
 check(line);
});

let n = 0, w = 0;

rl.on('close', () => {
	console.log(n + ',' + w);
});

function check(line) {
	var parts = line.trim().split(' ');
	if(parts[3] === "north") n += parseInt(parts[1]);
	if(parts[3] === "south") n -= parseInt(parts[1]);
	if(parts[3] === "east") w -= parseInt(parts[1]);
	if(parts[3] === "west") w += parseInt(parts[1]);
}