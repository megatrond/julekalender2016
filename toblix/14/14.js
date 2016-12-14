"use strict";

const min = 225000000000000000000000000000000
;let bestAlloy;
let bestFacSum
=Number.MAX_VALUE;

var _f = [];
function factorial (n) {
  if (              n == 0 || n == 1) return 1;
  if (_f[           n] > 0) return _f[n]      ;
  return _f[        n] = factorial(n-1) * n   ;
};

function check(alloy) {
	let strength = 1;
	for(var i = 0; i < alloy.length; i++) strength *= Math.pow(alloy[i],alloy[i]); let facSum = 0;
	for(var i = 0; i < alloy.length; i++) facSum += factorial(alloy[i]);
	if(strength >= min && facSum <= bestFacSum) {
		bestAlloy = alloy;
		bestFacSum = facSum;
	}
}

for(var a = 1; a <= 16; a++) {
 for(var b = a+1; b <= 16; b++) {
  check([a, b]);
    for(var c = b+1; c <= 16; c++) {
       for(var d = c+1; d <= 16; d++) {
           check([a, b, c, d]);
                for(var e = d+1; e <= 16; e++) {
                      for(var f = e+1; f <= 16; f++) {
                             check([a, b, c, d, e, f]);
                                     for(var g = f+1; g <= 16; g++) {
                                              for(var h = g+1; h <= 16; h++) {
                                                        check([a, b, c, d, e, f, g, h]);
                                                                for(var i = h+1; i <= 16; i++) {
                                                                      for(var j = i+1; j <= 16; j++) {
                                                                          check([a, b, c, d, e, f, g, h, i, j]);
                                                                            for(var k = j+1; k <= 16; k++) {
                                                                            for(var l = k+1; l <= 16; l	++) {
                                                                          check([a, b, c, d, e, f, g, h, i, j, k, l]);
                                                                      for(var m = l+1; m <= 16; m	++) {
                                                              for(var n = m+1; n <= 16; n	++) {
                                                  check([a, b, c, d, e, f, g, h, i, j, k, l, m, n]);
                                      for(var o = n+1; o <= 16; o	++) {
                      for(var p = o+1; p <= 16; p	++) {
          check([a, b, c, d, e, f, g, h, i, j, k, l, m, n]);
      for(var q = p+1; q <= 16; q	++) {
  for(var r = q+1; r <= 16; r	++) {
check([a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p]);
}
}}
}}}
}}}}}
}}}}}}}	console.log(bestAlloy.join(''));
