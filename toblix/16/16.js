"use strict";

for(let i = 100000; i < 1000000; i++) {
	if((""+i).split('').map(c=>parseInt(c)).reduce((a,b)=>a+b, 0) !== 43) continue;

	let hits = i < 500000;
	hits += ~~ Number.isInteger(Math.sqrt(i));
	if(hits === 0) continue;
	hits += ~~ Number.isInteger(Math.cbrt(i));
	if(hits !== 2) continue;
	console.log(i);
}