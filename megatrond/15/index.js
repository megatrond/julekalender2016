let s = '1111321112321111';

const las = s => {
	let res = [];
	for (let i = 0; i < s.length; i++) {
		const char = s[i];
		let count = 1;
		for (let j = i; j < s.length; j++) {
			if (s[j+1] === s[i]) {
				count++;
			} else {
				i = j;
				break;
			}
		}
		res.push(''+count, char);
	}
	return res.join('');
}

for (let i = 0; i < 50; i++) {
	s = las(s);
}

console.log(s.length);