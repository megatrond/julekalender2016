var prev = [1, 2];
var fib = 0;
var sum = 2;
while(fib < 4000000000) { //4000000000
if(fib % 2 === 0) sum += fib;
	fib = prev[0]+prev[1];
	prev = [prev[1],fib];
}
console.log(sum);
	