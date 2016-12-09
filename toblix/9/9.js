const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/09.txt')
});

const accounts = {};

function getAccount(id) {
	if(id === 'None') return {amount: 0};
	if(!accounts[id]) accounts[id] = {amount:0};
	return accounts[id];
}

rl.on('line', function(line) {
	const parts = line.trim().split(',').map(s=>s.trim());
	const from = parts[0];
	const to = parts[1];
	const amount = parseInt(parts[2]);
	getAccount(from).amount -= amount;
	getAccount(to).amount += amount;
});

rl.on('close', () => {
	console.log(Object.keys(accounts).map(key=>accounts[key]).filter(acc=>acc.amount > 10).length);
});