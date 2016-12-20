const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/09.txt')
});

let balance = {};

rl.on('line', line => {
	const frags = line.split(',');
	const fromAccount = frags[0];
	const toAccount = frags[1];
	const amount = parseInt(frags[2]);

	if (!balance[fromAccount]) {
		balance[fromAccount] = 0;
	}
	if (!balance[toAccount]) {
		balance[toAccount] = 0;
	}

	balance[fromAccount] -= amount;
	balance[toAccount] += amount;

});


rl.on('close', () => {
	const richPeople = Object.keys(balance).reduce((richPeople, account) => {
		if (balance[account] > 10) {
			return richPeople + 1
		}
		return richPeople;
	}, 0);
	console.log(richPeople);
});