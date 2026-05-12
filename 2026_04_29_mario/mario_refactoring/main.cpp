#include "mario_func.hpp"

int main() {
	char map[mapHeight][mapWidth + 1];
	ule::TObject mario;
	
	ule::TObject *brick = nullptr;
	int brickLength;
	ule::TObject *moving = nullptr;
	int movingLength;
	
	int level = 1;
	int score;
	int maxLvl;
	
	ule::createLevel(level, &mario, brick, brickLength, moving, movingLength, score, maxLvl);
	do {
		ule::clearMap(map);
		
		if ((mario.isFly == false) && (GetKeyState(VK_SPACE) < 0)) {
			mario.vertSpeed = -1;
		}
		if (GetKeyState('A') < 0) {
			ule::horizonMoveMap(1, mario, brick, brickLength, moving, movingLength);
		}
		if (GetKeyState('D') < 0) {
			ule::horizonMoveMap(-1, mario, brick, brickLength, moving, movingLength);
		}
		
		if (mario.y > mapHeight) {
			ule::playerDead(mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		}
		
		ule::vertMoveObject(&mario, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		ule::marioCollision(mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		
		for (int i = 0; i < brickLength; i++) {
			ule::putObjectOnMap(brick[i], map);
		}
		for (int i = 0; i < movingLength; i++) {
			ule::vertMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
			ule::horizonMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
			if (moving[i].y > mapHeight) {
				ule::deleteMoving(i, moving, movingLength);
				i--;
				continue;					
			}
			ule::putObjectOnMap(moving[i], map);
		}
		ule::putObjectOnMap(mario, map);
		ule::putScoreOnMap(map, score);
		
		ule::setCur(0, 0);
		ule::showMap(map);
		
		Sleep(10);
	} while (GetKeyState(VK_ESCAPE) >= 0);
	
	
	return 0;
}