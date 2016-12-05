var counters = [];

for(var i = 1; i < 1338; i++) {
	var counterIdx = 0;
	console.log(i, next(0));
}

function next(lvl) {
	if(counters.length === lvl) counters.push(1);
	var number = counters[lvl]++;
	if((""+number).indexOf('7') !== -1 || number % 7 === 0) return next(lvl+1);
	return number;
}