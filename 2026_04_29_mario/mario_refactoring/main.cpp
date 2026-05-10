#include "mario.hpp"


int maxLvl;


void ule::CreateLevel(int lvl, ule::TObject *mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength, int& score) {
	system("color 9F");
	
	brickLength = 0;
	delete[] brick;
	brick = nullptr;
	
	movingLength = 0;
	delete[] moving;
	moving = nullptr;
	
	ule::InitObject(mario, 39, 10, 3, 3, '@');
	score = 0;
	
	if (lvl == 1) {
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 30, 10, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 50, 10, 5, 3, '?');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 60, 15, 40, 10, '#');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 60, 5, 10, 3, '-');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 70, 5, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 75, 5, 5, 3, '-');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 80, 5, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(brick, brickLength), 85, 5, 10, 3, '-');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 100, 20, 20, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 210, 15, 10, 10, '+');
		
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
	}
	if (lvl == 2) {
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 60, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 80, 20, 20, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 210, 15, 10, 10, '+');

		ule::InitObject(ule::GetNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 65, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 160, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 175, 10, 3, 2, 'o');
	}
	if (lvl == 3) {
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 80, 20, 15, 5, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 120, 15, 15, 10, '#');
		ule::InitObject(ule::GetNewBrick(brick, brickLength), 160, 10, 15, 15, '+');

		ule::InitObject(ule::GetNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 50, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 90, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(moving, movingLength), 130, 10, 3, 2, 'o');
	}
	
	maxLvl = 3;
	
}

void ule::ClearMap(char (&map)[mapHeight][mapWidth + 1]) {
	for (int i = 0; i < mapWidth; i++) {
		map[0][i] = ' ';
	}
	map[0][mapWidth] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		sprintf(map[j], map[0]);
	}
}

void ule::DeleteMoving(int i, ule::TObject *&moving, int &movingLength) {
	movingLength--;
	moving[i] = moving[movingLength];
	
	TObject* newMoving = new TObject[movingLength];
	for (int i = 0; i < movingLength; i++) {
		newMoving[i] = moving[i];
	}
	delete[] moving;
	moving = newMoving;
}

ule::TObject *ule::GetNewBrick(ule::TObject *&brick, int &brickLength) {
	brickLength++;
	
	TObject* newBrick = new TObject[brickLength];
	for (int i = 0; i < brickLength - 1; i++) {
		newBrick[i] = brick[i];
	}
	delete[] brick;
	brick = newBrick;
	return &brick[brickLength - 1];
}

ule::TObject *ule::GetNewMoving(ule::TObject *&moving, int &movingLength) {
	movingLength++;
	
	TObject* newMoving = new TObject[movingLength];
	for (int i = 0; i < movingLength - 1; i++) {
		newMoving[i] = moving[i];
	}
	delete[] moving;
	moving = newMoving;
	return &moving[movingLength - 1];
}


void ule::HorizonMoveMap(float dx, ule::TObject mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength) {
	mario.x -=dx;
	for (int i = 0; i < brickLength; i++) {
		if (IsCollision(mario, brick[i])) {
			mario.x += dx;
			return;
		}
	}
	mario.x += dx;
	
	for (int i = 0; i < brickLength; i++) {
		brick[i].x += dx;
	}
	for (int i = 0; i < movingLength; i++) {
		moving[i].x += dx;
	}
	
}

void ule::HorizonMoveObject (ule::TObject *obj, ule::TObject *mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength, int &level, int& score) {
	obj[0].x += obj[0].horizSpeed;
	
	for (int i = 0; i < brickLength; i++) {
		if (IsCollision(obj[0], brick[i])) {
			obj[0].x -= obj[0].horizSpeed;
			obj[0].horizSpeed = -obj[0].horizSpeed;
			return;
		}
	}
	
	if (obj[0].cType == 'o') {
		ule::TObject tmp = *obj;
		VertMoveObject(&tmp, mario, brick, brickLength, moving, movingLength, level, score);
		if (tmp.IsFly == true) {
			obj[0].x -= obj[0].horizSpeed;
			obj[0].horizSpeed = -obj[0].horizSpeed;
		}
	}
}

void ule::InitObject(ule::TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType) {
	SetObjectPos(obj, xPos, yPos);
	obj->width = oWidth;
	obj->height = oHeight;
	obj->vertSpeed = 0;
	obj->cType = inType;
	obj->horizSpeed = 0.2;
}

bool ule::IsCollision(ule::TObject o1, ule::TObject o2) {
	return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
		   ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}

bool ule::IsPosInMap(int x, int y) {
	return ((x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}

void ule::MarioCollision(ule::TObject mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength, int &level, int& score) {
	for (int i = 0; i < movingLength; i++) {
		if (IsCollision(mario, moving[i])) {
			if (moving[i].cType == 'o') {
				if (   (mario.IsFly == true) 
					&& (mario.vertSpeed > 0)
					&& (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)
					)
				{ 	
					score += 50;
					DeleteMoving(i, moving, movingLength);
					i--;
					continue;					
				} else {
					PlayerDead(mario, brick, brickLength, moving, movingLength, level, score);
				}
			}
			if (moving[i].cType == '$') {
				score += 100;
				DeleteMoving(i, moving, movingLength);
				i--;
				continue;
			}	
			
		}
	}
}

void ule::PlayerDead(ule::TObject &mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength, int &level, int& score) {
	system("color 4F");
	Sleep(500);
	CreateLevel(level, &mario, brick, brickLength, moving, movingLength, score);
}

void ule::PutObjectOnMap(ule::TObject obj, char (&map)[mapHeight][mapWidth + 1]) {
	int ix = round(obj.x);
	int iy = round(obj.y);
	int iWidth = round(obj.width);
	int iHeight = round(obj.height);
	
	for (int i = ix; i < (ix + iWidth); i++) {
		for (int j = iy; j < (iy + iHeight); j++) {
			if (IsPosInMap(i, j)){
				map[j][i] = obj.cType;
			}
		}
	}
}

void ule::PutScoreOnMap(char (&map)[mapHeight][mapWidth + 1], int& score) {
	char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i + 5] = c[i];
	}
}

void ule::setCur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ule::SetObjectPos(ule::TObject *obj, float xPos, float yPos) {
	obj->x = xPos;
	obj->y = yPos;
}

void ule::ShowMap(char (&map)[mapHeight][mapWidth + 1]) {
	map[mapHeight - 1][mapWidth - 1] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		std::cout << map[j];
	}
}

void ule::VertMoveObject(ule::TObject *obj, ule::TObject *mario, ule::TObject *&brick, int &brickLength, ule::TObject *&moving, int &movingLength, int &level, int& score) {
	obj->IsFly = true;
	obj->vertSpeed += 0.05;
	SetObjectPos(obj, obj->x, obj->y + obj->vertSpeed);
	
	for (int i = 0; i < brickLength; i++) {
		if (IsCollision(*obj, brick[i])) {
			if (obj[0].vertSpeed > 0) {
				obj[0].IsFly = false;
			}
			
			if ((brick[i].cType == '?') && (obj[0].vertSpeed < 0) && (obj == mario)) {
				brick[i].cType = '-';
				InitObject(GetNewMoving(moving, movingLength), brick[i].x, brick[i].y - 3, 3, 2, '$');
				moving[movingLength - 1].vertSpeed = -0.7;
			}
			obj->y -= obj->vertSpeed;
			obj->vertSpeed = 0;
			
			if (brick[i].cType == '+') {
				level++;
				if (level > 3) {
					level = 1;
				}
				
				system("color 2F");
				Sleep(500);
				CreateLevel(level, mario, brick, brickLength, moving, movingLength, score);
			}
			break;
		}
	}
	
}

int main() {
	char map[mapHeight][mapWidth + 1];
	ule::TObject mario;
	
	ule::TObject *brick = nullptr;
	int brickLength;
	ule::TObject *moving = nullptr;
	int movingLength;
	
	int level = 1;
	int score;
	
	ule::CreateLevel(level, &mario, brick, brickLength, moving, movingLength, score);
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
			ule::PlayerDead(mario, brick, brickLength, moving, movingLength, level, score);
		}
		
		ule::VertMoveObject(&mario, &mario, brick, brickLength, moving, movingLength, level, score);
		ule::MarioCollision(mario, brick, brickLength, moving, movingLength, level, score);
		
		for (int i = 0; i < brickLength; i++) {
			ule::PutObjectOnMap(brick[i], map);
		}
		for (int i = 0; i < movingLength; i++) {
			ule::VertMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score);
			ule::HorizonMoveObject(moving + i, &mario, brick, brickLength, moving, movingLength, level, score);
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