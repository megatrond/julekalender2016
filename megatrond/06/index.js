let position = {x:0, y:0};

let visited = {};

const nextMove = (pos) => {
	const positionValue = pos.x+pos.y;
	if (visited[''+pos.x+pos.y] === 1000) {
		visited[''+pos.x+pos.y] = 0;
	} else {
		visited[''+pos.x+pos.y] = 1000;
	}
	
	let possibleMoves = [
		{x:pos.x-2, y:pos.y-1},
		{x:pos.x-1, y:pos.y-2},
		{x:pos.x+1, y:pos.y-2},
		{x:pos.x+2, y:pos.y-1},
		{x:pos.x+2, y:pos.y+1},
		{x:pos.x+1, y:pos.y+2},
		{x:pos.x-2, y:pos.y+1},
		{x:pos.x-1, y:pos.y+2},
	];

	let diff = Number.MAX_SAFE_INTEGER;
	let move;
	for (let i = possibleMoves.length - 1; i >= 0; i--) {
		let moveKey = '' + possibleMoves[i].x + possibleMoves[i].y;
		let added = 0;
		if (visited[moveKey]) {
			added = visited[moveKey]
		}
		let moveValue = possibleMoves[i].x + possibleMoves[i].y + added;
		let moveDiff = Math.abs(positionValue - moveValue);
		if (moveDiff < diff) {
			diff = moveDiff;
			move = possibleMoves[i];
		} else if(moveDiff === diff) {
			if (possibleMoves[i].x < move.x) {
				diff = moveDiff;
				move = possibleMoves[i];
			} else if (possibleMoves[i].x === move.x) {
				if (possibleMoves[i].y < move.y) {
					diff = moveDiff;
					move = possibleMoves[i];
				}
			}
		}
	}
	return move;
}

let count = 1;

while (count < 1000000000000000) {
	position = nextMove(position);
	count += 1000000000000000;
}

console.log(3*1000000000000000 - 3);