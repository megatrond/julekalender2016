"use strict";

const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
	input: fs.createReadStream(__dirname + '/../../problems/17.txt')
});

const wormholes = [];

rl.on('line', function(line) {
	const parts = line.trim().split('-').map(s=>s.trim());
	const from = parts[0].split(',').map(p=>parseInt(p));
	const to = parts[1].split(',').map(p=>parseInt(p));
	wormholes.push([from, to]);
});

rl.on('close', () => {
	console.log(minSteps(start, end, wormholes, 0));
});

function steps(from, to){return Math.abs(from[0]-to[0])+Math.abs(from[1]-to[1])};

const start = [0,0], end = [99999,99999];

const cache = {};
function minSteps(from, to, wormholes) {
	const cacheKey = ""+from+to+wormholes;
	if(cache[cacheKey]) return cache[cacheKey];
	let shortest = steps(from, to);
	for (let i = 0, len = wormholes.length; i < len; i++) {
		const wh = wormholes[i];
		const aw = wormholes.filter(w=>w!==wh);
		shortest = Math.min(
			shortest,
			steps(from, wh[0]) + minSteps(wh[1], to, aw),
			steps(from, wh[1]) + minSteps(wh[0], to, aw)
		);
	}
	cache[cacheKey] = shortest;
	return shortest;
}
