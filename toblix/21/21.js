"use strict";

const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/21.txt')
});

const numbers = [];
rl.on('line', function(line) {
	numbers.push(...line.trim().split(' ').map(s=>parseInt(s)));
});

rl.on('close', () => {
	
	const rows = [];
	for(let i = 0, n = 0; n < numbers.length; i++) {
		rows.push(numbers.slice(n,n+i+1));
		n = i+1+(i*i+i)/2;
	}
	const a = calc(rows, 0, 0, 1, 0, 1, 1, (rows, row, idx)=>row === rows.length-1);
	const b = calc(rows, rows.length-1, rows[rows.length-1].length-1, 0, -1, -1, -1, (rows, row, idx)=>idx === 0);
	const c = calc(rows, rows.length-1, 0, -1, 0, 0, 1, (rows, row, idx)=>idx === rows[row].length-1);
	if(a > b && a > c) console.log('A'+a);
	else if(b > c && b > a) console.log('B'+b);
	else console.log('C'+a);
});

function calc(rows, startRow, startIdx, ldr, ldi, rdr, rdi, isLast) {
	const c = [];
	function maxSum(rows, row, idx) {
		if(c[row+'_'+idx]) return c[row+'_'+idx];
		let ret;
		if(isLast(rows, row, idx)) ret = rows[row][idx];
		else {
			const l = maxSum(rows, row+ldr, idx+ldi);
			const r = maxSum(rows, row+rdr, idx+rdi);
			ret = rows[row][idx] + Math.max(l,r);
		}
		c[row+'_'+idx] = ret;
		return ret;
	}
	
	return maxSum(rows, startRow, startIdx);
}