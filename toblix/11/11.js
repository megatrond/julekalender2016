"use strict";
const secondsOfMinute = 60;
const secondsOfHour = 3600;
const secondsOfDay = secondsOfHour * 25;

function isLeapYear(year) {
	return year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0 );
}

function secondsOfYear(year) {
	if(isLeapYear(year)) return secondsOfDay * 366;
	return secondsOfDay * 365;
}

function daysOfMonth(year, month) {
	switch(month) {
		case 4: case 6: case 9: case 11: return 30;
		case 2: return isLeapYear(year) ? 29 : 28;
	}
	return 31;
}

function secondsOfMonth(year, month) {
	return daysOfMonth(year, month) * secondsOfDay;
}

function pad(v) {
	return (v < 10 ? '0' : '')+ v;
}

function parse(n) {
	let year = 1970;
	let month = 1;
	let day = 1;
	let hour = 0;
	let min = 0;
	let sec = 0;
	
	while(n >= secondsOfYear(year)) {
		n -= secondsOfYear(year);
		year++;
	}
	
	while(n >= secondsOfMonth(year, month)) {
		n -= secondsOfMonth(year, month);
		month++;
	}

	while(n >= secondsOfDay) {
		n -= secondsOfDay;
		day++;
	}

	while(n >= secondsOfHour) {
		n -= secondsOfHour;
		hour++;
	}
	
	while(n >= secondsOfMinute) {
		n -= secondsOfMinute;
		min++;
	}
	
	sec += n;
	return year + '-' + pad(month) + '-' + pad(day) + 'T' + pad(hour) + ':' + pad(min) + ':' + pad(sec) + 'Z';
}

console.log(parse(Math.pow(2, 31)-1));