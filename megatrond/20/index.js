const permutator = input => {
	let results = [];

	const permute = (arr, memo) => {
		let cur;

		for (var i = 0; i < arr.length; i++) {
	      cur = arr.splice(i, 1);
	      if (arr.length === 0) {
	        results.push(memo.concat(cur));
	      }
	      permute(arr.slice(), memo.concat(cur));
	      arr.splice(i, 0, cur[0]);
	    }

	    return results;
	}

	return permute(input, []);
}

const permutations = permutator([0,1,2,3,4,5,6,7,8,9]);

let highest = {
	result: 0
};

for (let i = permutations.length-1;i>=0;i--) {
	
	for (let j = permutations[i].length-2;j>=1;j--) {
		const perm = permutations[i].slice(0);
		const first = parseInt(perm.splice(0, j).join('')) || 0;
		const second = parseInt(perm.join('')) || 0;
		const result = first * second;

		if (result > highest.result) {
			console.log(first, second, result);
			highest.result = result;
			highest.first = first;
			highest.second = second;
		}
	}
}

console.log(highest);