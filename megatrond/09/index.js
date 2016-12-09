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
	let richPeople = 0;
	for (let key in balance) {
		if (balance.hasOwnProperty(key)) {
			if (balance[key] > 10) {
				richPeople++;
			}
		}
	}
	console.log(richPeople);
});