const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/08.txt')
});

const ladders = [[3,17], [8,10], [15,44], [22,5], [39,56], [49,75], [62,45], [64,19], [65,73], [80,12], [87,79]];

const squares = new Array(90).fill(0);
ladders.forEach(l=>squares[l[0]-1] = l[1]-l[0]);

const players = new Array(1337).fill(0);

let player = 0;
let laddersClimbed = 0;
rl.on('line', function(line) {
	let pos = players[player];
	const roll = parseInt(line.trim());
	if(pos + roll <= 89) {
		pos += roll;
		while(squares[pos] !== 0) {
			pos += squares[pos];
			laddersClimbed++;
		}
		if(pos === 89) {
			console.log((player+1) * laddersClimbed);
		}
	}
	players[player] = pos;
	player = (player+1) % 1337;
});

rl.on('close', () => {
});