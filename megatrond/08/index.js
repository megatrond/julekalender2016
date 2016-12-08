const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/08.txt')
});

const ladders =  [[3,17], [8,10], [15,44], [22,5], [39,56], [49,75], [62,45], [64,19], [65,73], [80,12], [87,79]];

let laddersUsed = 0;

const nPlayers = 1337;

let currentPlayer = 1;
let positions = [];

const isOnLadder = position => {
	let ladderIndex = ladders.findIndex(el => position === el[0]);

	if (ladderIndex > -1) {
		laddersUsed++;
		return ladders[ladderIndex][1];
	}

	return position;
}

rl.on('line', line => {
	let move = parseInt(line);

	let newPosition = positions[currentPlayer] ? (positions[currentPlayer] + move) : (1 + move);

	if (newPosition > 90) {
		newPosition = positions[currentPlayer];
	}

	positions[currentPlayer] = newPosition;

	positions[currentPlayer] = isOnLadder(positions[currentPlayer]);

	if (positions[currentPlayer] === 90) {
		console.log(currentPlayer * laddersUsed);
	}

	if (currentPlayer === 1337) {
		currentPlayer = 1;
	} else {
		currentPlayer++;
	}
});