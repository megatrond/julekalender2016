"use strict"

let digits = "0123456789".split('');

function shuffle(a) {
    for (let i = a.length; i; i--) {
        let j = Math.floor(Math.random() * i);
        [a[i - 1], a[j]] = [a[j], a[i - 1]];
    }
}

let max = 0;
while(true) {
	const l1 = 1+ Math.floor(Math.random() * (digits.length-1));
	const p1 = digits.join('').substr(0, l1);
	const p2 = digits.join('').substr(l1);
	const p = parseInt(p1) * parseInt(p2);
	if(p > max) {
		console.log(p1, p2, p);
		max = p;
	}
	shuffle(digits);
}