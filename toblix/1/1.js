for(var i = 6;; i+=10) {
	var s = ""+i;
	var j = s.charAt(s.length-1) + s.substr(0, s.length-1);
	if(j / i !== 4) continue;
	console.log(i);
	return;
}