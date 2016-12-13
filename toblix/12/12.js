"use strict";

const msg = "Your message was received with gratitude! We do not know about you, but Christmas is definitely our favourite holiday. The tree, the lights, all the presents to unwrap. Could there be anything more magical than that?! We wish you a happy holiday and a happy new year!";
const a1 = [];
const a2 = [];

msg.split('').forEach((c)=>{
	const val = c.toUpperCase().charCodeAt(0)-64;
	if(val < 1 || val > 26) return;
	const p1 = Math.floor(val / 2);
	const p2 = val - p1;
	a1.push(p2);
	a2.push(p1);
});

const romanz = ['0', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX', 'X', 'XI', 'XII', 'XIII'];
console.log([...a1, ...a2.reverse()].map((c)=>romanz[c]).join());
