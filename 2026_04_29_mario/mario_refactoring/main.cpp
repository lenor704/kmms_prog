#include "mario.hpp"

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
	
	ule::CreateLevel(level, &mario, brick, brickLength, moving, movingLength, score, maxLvl);
	do {
		ule::ClearMap(map);
		
		if ((mario.IsFly == false) && (GetKeyState(VK_SPACE) < 0)) {
			mario.vertSpeed = -1;
		}
		if (GetKeyState('A') < 0) {
			ule::HorizonMoveMap(1, mario, brick, brickLength, moving, movingLength);
		}
		if (GetKeyState('D') < 0) {
			ule::HorizonMoveMap(-1, mario, brick, brickLength, moving, movingLength);
		}
		
		if (mario.y > mapHeight) {
			ule::PlayerDead(mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		}
		
		ule::VertMoveObject(&mario, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		ule::MarioCollision(mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
		
		for (int i = 0; i < brickLength; i++) {
			ule::PutObjectOnMap(brick[i], map);
		}
		for (int i = 0; i < movingLength; i++) {
			ule::VertMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
			ule::HorizonMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score, maxLvl);
			if (moving[i].y > mapHeight) {
				ule::DeleteMoving(i, moving, movingLength);
				i--;
				continue;					
			}
			ule::PutObjectOnMap(moving[i], map);
		}
		ule::PutObjectOnMap(mario, map);
		ule::PutScoreOnMap(map, score);
		
		ule::setCur(0, 0);
		ule::ShowMap(map);
		
		Sleep(10);
	} while (GetKeyState(VK_ESCAPE) >= 0);
	
	
	return 0;
}