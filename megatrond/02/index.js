
const isEven = (number) => number % 2 === 0;

let sum = 0;

const fib = (one, two) => one + two;

let notFinished = true;

let first = 0;
let second = 1;


while (notFinished) {
	let number = fib(first, second);

	first = second;
	second = number;

	if (isEven(number)) {
		if (number > 4000000000) {
			notFinished = false;
		} else {
			sum += number;
		}
	}
}

console.log(sum);