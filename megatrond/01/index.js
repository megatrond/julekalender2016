
for (let number = 16; number < Number.MAX_SAFE_INTEGER; number += 10) {
	const log = Math.floor(Math.log10(number));

	const tester = Math.floor(number/10) + (Math.pow(10, log) * 6);

	if (tester === (number * 4)) {
		console.log(number);
		break;
	}
}
