"use strict";

const alive = 'alive';
const killedHere = 'killedHere';
const lost = 'lost';

let thief = alive;
let wizard = alive;
let warrior = alive;
let cleric = alive;

let survivors = 0;

function remainingHeroes(){return ~~(thief === alive) + ~~(wizard === alive) + ~~(warrior === alive) + ~~(cleric === alive)};

for(let i = 0; i < 100; i++) {
	let goblins = i+1
	let someoneWasRessedHere = false;
	
	if(thief === killedHere) thief = lost;
	if(wizard === killedHere) wizard = lost;
	if(warrior === killedHere) warrior = lost;
	if(cleric === killedHere) cleric = lost;
	
	while(goblins > 0) {
		if(thief === alive && goblins > 0) goblins--;
		if(wizard === alive && goblins > 0) goblins = Math.max(0, goblins-10);
		if(warrior === alive && goblins > 0) goblins--;
		if(cleric === alive && !someoneWasRessedHere) {
			if(warrior === killedHere) { warrior = alive; someoneWasRessedHere = true;}
			else if(wizard === killedHere) { wizard = alive; someoneWasRessedHere = true;}
		}
		if(thief === alive && wizard !== alive && warrior !== alive && cleric !== alive) {
			survivors += goblins;
			break;
		}
		if(goblins >= remainingHeroes() * 10) {
			if(warrior === alive) warrior = killedHere;
			else if(wizard === alive) wizard = killedHere;
			else if(cleric === alive) cleric = killedHere;
		}
	}
}
console.log(survivors + remainingHeroes() + 17);