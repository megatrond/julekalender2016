"use strict";

function lol(str) {
	const ret = [];
	for(var i = 0; i < str.length; i++) {
		const c = str.charAt(i);
		let count = 1;
		while(++i < str.length && str.charAt(i) === c) count++; i--;
		ret.push(""+count, c);
	}
	return ret.join('');
}
let str = "1111321112321111";
for(var i = 0; i < 50; i++) str = lol(str);
console.log(str.length);