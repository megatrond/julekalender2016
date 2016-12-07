
const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/07.txt')
});

let meters = [0,0];

const parseLine = (line) => {
	const a = line.split(' ');
	const length = parseInt(a[1]);
	const direction = a[3];
	switch (direction) {
		case 'north':
			meters[0] += length;
			break;
		case 'east':
			meters[1] -= length;
			break;
		case 'south':
			meters[0] -= length;
			break;
		case 'west':
			meters[1] += length;
			break;
	}
}

rl.on('line', line => {
	parseLine(line);
});	

rl.on('close', () => {
	console.log(meters[0] + ',' + meters[1]);
})
