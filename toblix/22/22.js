"use strict";

const fs = require('fs');

const rects = eval(fs.readFileSync(__dirname + '/../../problems/22.txt')+'')

function isRectRegion(set) {
	if(set.length === 0) return true;
	let x1 = Math.max(...set.map(r=>r[2]));
	let y1 = Math.max(...set.map(r=>r[3]));
	return x1*y1 === set.reduce((s,r)=>s+(r[2]-r[0])*(r[3]-r[1]), 0);
}

console.log(rects.map(isRectRegion).join(','));
