const BigNumber = require('bignumber.js');

let numbers = [1,2,4];


for (let i = 3;i<250;i++) {
	numbers[i] = new BigNumber(numbers[i-3]).plus(new BigNumber(numbers[i-2])).plus(new BigNumber(numbers[i-1]));
}

console.log(numbers[249].toFixed(0));