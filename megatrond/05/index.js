let data = require('./data');

const romanMap = {
	'0': 0,
	'I': 1,
	'II': 2,
	'III': 3,
	'IV': 4,
	'V': 5,
	'VI': 6,
	'VII': 7,
	'VIII': 8,
	'IX': 9,
	'X': 10,
	'XI': 11,
	'XII': 12,
	'XIII': 13
};

let encrypted = [];

while (data.length > 0) {
	encrypted.push(romanMap[data.pop()] + romanMap[data.shift()]);
}
let decrypted = encrypted.reduce((acc, curr) => {
	// console.log(curr);
	acc += String.fromCharCode(curr+96);
	return acc;
}, '');

console.log(decrypted);