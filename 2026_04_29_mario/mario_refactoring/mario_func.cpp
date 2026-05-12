#include "mario_func.hpp"


void ule::createLevel(const int lvl, ule::TObject *mario, 
					  ule::TObject *&brick, int &brickLength, 
					  ule::TObject *&moving, int &movingLength, 
					  int& score, int& maxLvl) {
	system("color 9F");
	
	brickLength = 0;
	delete[] brick;
	brick = nullptr;
	
	movingLength = 0;
	delete[] moving;
	moving = nullptr;
	
	ule::initObject(mario, 39, 10, 3, 3, '@');
	score = 0;
	
	if (lvl == 1) {
		ule::initObject(ule::getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
			ule::initObject(ule::getNewBrick(brick, brickLength), 30, 10, 5, 3, '?');
			ule::initObject(ule::getNewBrick(brick, brickLength), 50, 10, 5, 3, '?');
		ule::initObject(ule::getNewBrick(brick, brickLength), 60, 15, 40, 10, '#');
			ule::initObject(ule::getNewBrick(brick, brickLength), 60, 5, 10, 3, '-');
			ule::initObject(ule::getNewBrick(brick, brickLength), 70, 5, 5, 3, '?');
			ule::initObject(ule::getNewBrick(brick, brickLength), 75, 5, 5, 3, '-');
			ule::initObject(ule::getNewBrick(brick, brickLength), 80, 5, 5, 3, '?');
			ule::initObject(ule::getNewBrick(brick, brickLength), 85, 5, 10, 3, '-');
		ule::initObject(ule::getNewBrick(brick, brickLength), 100, 20, 20, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 210, 15, 10, 10, '+');
		
		ule::initObject(ule::getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
	}
	if (lvl == 2) {
		ule::initObject(ule::getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 60, 15, 10, 10, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 80, 20, 20, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 210, 15, 10, 10, '+');

		ule::initObject(ule::getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 65, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 160, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 175, 10, 3, 2, 'o');
	}
	if (lvl == 3) {
		ule::initObject(ule::getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 80, 20, 15, 5, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 120, 15, 15, 10, '#');
		ule::initObject(ule::getNewBrick(brick, brickLength), 160, 10, 15, 15, '+');

		ule::initObject(ule::getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 50, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 90, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		ule::initObject(ule::getNewMoving(moving, movingLength), 130, 10, 3, 2, 'o');
	}
	
	maxLvl = 3;
	
}

void ule::clearMap(char (&map)[mapHeight][mapWidth + 1]) {
	for (int i = 0; i < mapWidth; i++) {
		map[0][i] = ' ';
	}
	map[0][mapWidth] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		sprintf(map[j], map[0]);
	}
}

void ule::deleteMoving(int i, ule::TObject *&moving, int &movingLength) {
	movingLength--;
	moving[i] = moving[movingLength];
	
	TObject* newMoving = new TObject[movingLength];
	for (int i = 0; i < movingLength; i++) {
		newMoving[i] = moving[i];
	}
	delete[] moving;
	moving = newMoving;
}

ule::TObject *ule::getNewBrick(ule::TObject *&brick, int &brickLength) {
	brickLength++;
	
	TObject* newBrick = new TObject[brickLength];
	for (int i = 0; i < brickLength - 1; i++) {
		newBrick[i] = brick[i];
	}
	delete[] brick;
	brick = newBrick;
	return &brick[brickLength - 1];
}

ule::TObject *ule::getNewMoving(ule::TObject *&moving, int &movingLength) {
	movingLength++;
	
	TObject* newMoving = new TObject[movingLength];
	for (int i = 0; i < movingLength - 1; i++) {
		newMoving[i] = moving[i];
	}
	delete[] moving;
	moving = newMoving;
	return &moving[movingLength - 1];
}


void ule::horizonMoveMap(float dx, ule::TObject mario, 
						 ule::TObject *&brick, int &brickLength, 
						 ule::TObject *&moving, int &movingLength) {
	mario.x -= dx;
	for (int i = 0; i < brickLength; i++) {
		if (isCollision(mario, brick[i])) {
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

void ule::horizonMoveObject (ule::TObject *obj, ule::TObject *mario, 
							 ule::TObject *&brick, int &brickLength, 
							 ule::TObject *&moving, int &movingLength, 
							 int &level, int& score, int& maxLvl) {
	obj->x += obj->horizSpeed;
	
	for (int i = 0; i < brickLength; i++) {
		if (isCollision(obj[0], brick[i])) {
			obj->x -= obj->horizSpeed;
			obj->horizSpeed = -obj->horizSpeed;
			return;
		}
	}
	
	if (obj->cType == 'o') {
		ule::TObject tmp = *obj;
		vertMoveObject(&tmp, mario, 
					   brick, brickLength, 
					   moving, movingLength, 
					   level, score, maxLvl);
		if (tmp.isFly == true) {
			obj->x -= obj->horizSpeed;
			obj->horizSpeed = -obj->horizSpeed;
		}
	}
}

void ule::initObject(ule::TObject *obj, float xPos, float yPos, 
					 float oWidth, float oHeight, char inType) {
	setObjectPos(obj, xPos, yPos);
	obj->width = oWidth;
	obj->height = oHeight;
	obj->vertSpeed = 0;
	obj->cType = inType;
	obj->horizSpeed = 0.2;
}

bool ule::isCollision(ule::TObject o1, ule::TObject o2) {
	return o1.x + o1.width > o2.x && o1.x < o2.x + o2.width &&
		   o1.y + o1.height > o2.y && o1.y < o2.y + o2.height;
}

bool ule::isPosInMap(int x, int y) {
	return (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight);
}

void ule::marioCollision(ule::TObject mario, 
						 ule::TObject *&brick, int &brickLength, 
						 ule::TObject *&moving, int &movingLength, 
						 int &level, int& score, int& maxLvl) {
	for (int i = 0; i < movingLength; i++) {
		if (isCollision(mario, moving[i])) {
			if (moving[i].cType == 'o') {
				if (   (mario.isFly == true) 
					&& (mario.vertSpeed > 0)
					&& (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)
					)
				{ 	
					score += 50;
					deleteMoving(i, moving, movingLength);
					i--;
					continue;					
				} else {
					playerDead(mario, 
							   brick, brickLength, 
							   moving, movingLength, 
							   level, score, maxLvl);
				}
			}
			if (moving[i].cType == '$') {
				score += 100;
				deleteMoving(i, moving, movingLength);
				i--;
				continue;
			}	
		}
	}
}

void ule::playerDead(ule::TObject &mario, 
					 ule::TObject *&brick, int &brickLength, 
					 ule::TObject *&moving, int &movingLength, 
					 int &level, int& score, int& maxLvl) {
	system("color 4F");
	Sleep(500);
	createLevel(level, &mario, 
				brick, brickLength, 
				moving, movingLength, 
				score, maxLvl);
}

void ule::putObjectOnMap(ule::TObject obj, char (&map)[mapHeight][mapWidth + 1]) {
	int ix = round(obj.x);
	int iy = round(obj.y);
	int iWidth = round(obj.width);
	int iHeight = round(obj.height);
	
	for (int i = ix; i < (ix + iWidth); i++) {
		for (int j = iy; j < (iy + iHeight); j++) {
			if (isPosInMap(i, j)){
				map[j][i] = obj.cType;
			}
		}
	}
}

void ule::putScoreOnMap(char (&map)[mapHeight][mapWidth + 1], const int& score) {
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

void ule::setObjectPos(ule::TObject *obj, float xPos, float yPos) {
	obj->x = xPos;
	obj->y = yPos;
}

void ule::showMap(char (&map)[mapHeight][mapWidth + 1]) {
	map[mapHeight - 1][mapWidth - 1] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		std::cout << map[j];
	}
}

void ule::vertMoveObject(ule::TObject *obj, ule::TObject *mario, 
						 ule::TObject *&brick, int &brickLength, 
						 ule::TObject *&moving, int &movingLength, 
						 int &level, int& score, int& maxLvl) {
	obj->isFly = true;
	obj->vertSpeed += 0.05;
	setObjectPos(obj, obj->x, obj->y + obj->vertSpeed);
	
	for (int i = 0; i < brickLength; i++) {
		if (isCollision(*obj, brick[i])) {
			if (obj->vertSpeed > 0) {
				obj->isFly = false;
			}
			
			if ((brick[i].cType == '?') && (obj->vertSpeed < 0) && (obj == mario)) {
				brick[i].cType = '-';
				initObject(getNewMoving(moving, movingLength), brick[i].x, brick[i].y - 3, 3, 2, '$');
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
				createLevel(level, mario, 
							brick, brickLength, 
							moving, movingLength, 
							score, maxLvl);
			}
			break;
		}
	}	
}