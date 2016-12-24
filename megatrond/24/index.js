
let n = 90101894;
const offset = 65;
let result = '';


while (n > 0) {
	n--;
	result = String.fromCharCode((n%26)+offset) + result;
	n = Math.floor(n/26);
}

console.log(result);