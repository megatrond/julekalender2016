

let notFound = true;
let number = 16;

while (notFound) {
	let numberArray = number.toString().split('');
	const last = numberArray.pop();

	const rearranged = parseInt([last].concat(numberArray).join(''));

	if ((number*4) === rearranged) {
		notFound = false;
		console.log(number);
	}

	number = number + 10;
}