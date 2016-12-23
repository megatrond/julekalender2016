"use strict";

const BigNumber = require('bignumber.js');

const cache = {};

const ONE = new BigNumber(1);
const TWO = new BigNumber(2);
const THREE = new BigNumber(3);

function ways(steps) {
	if(steps.equals(ONE)) return new BigNumber(1);
	if(steps.equals(TWO)) return new BigNumber(2);
	if(steps.equals(THREE)) return new BigNumber(4);
	if (cache[steps.toString()]) return cache[steps.toString()];
	cache[steps.toString()] = ways(steps.minus(1)).plus(ways(steps.minus(2))).plus(ways(steps.minus(3)));
	return cache[steps.toString()];
}

console.log(ways(new BigNumber(250)).toFixed(0));