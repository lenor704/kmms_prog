#include "mario.hpp"

#define mapWidth 80
#define mapHeight 25


char map[mapHeight][mapWidth + 1];
ule::TObject mario;

ule::TObject *brick = NULL;
int brickLength;

ule::TObject *moving = NULL;
int movingLength;

int level = 1;
int score;
int maxLvl;

void ule::ClearMap() {
	for (int i = 0; i < mapWidth; i++) {
		map[0][i] = ' ';
	}
	map[0][mapWidth] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		sprintf(map[j], map[0]);
	}
}

void ule::ShowMap() {
	map[mapHeight - 1][mapWidth - 1] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		printf("%s", map[j]);
	}
}

void ule::SetObjectPos(ule::TObject *obj, float xPos, float yPos) {
	(*obj).x = xPos;
	(*obj).y = yPos;
}

void ule::InitObject(ule::TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType) {
	SetObjectPos(obj, xPos, yPos);
	(*obj).width = oWidth;
	(*obj).height = oHeight;
	(*obj).vertSpeed = 0;
	(*obj).cType = inType;
	(*obj).horizSpeed = 0.2;
}

void ule::PlayerDead() {
	system("color 4F");
	Sleep(500);
	CreateLevel(level);
}

void ule::VertMoveObject(ule::TObject *obj) {
	(*obj).IsFly = true;
	(*obj).vertSpeed += 0.05;
	SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);
	
	for (int i = 0; i < brickLength; i++) {
		if (IsCollision(*obj, brick[i])) {
			if (obj[0].vertSpeed > 0) {
				obj[0].IsFly = false;
			}
			
			if ((brick[i].cType == '?') && (obj[0].vertSpeed < 0) && (obj == &mario)) {
				brick[i].cType = '-';
				InitObject(GetNewMoving(), brick[i].x, brick[i].y - 3, 3, 2, '$');
				moving[movingLength - 1].vertSpeed = -0.7;
			}
			(*obj).y -= (*obj).vertSpeed;
			(*obj).vertSpeed = 0;
			
			if (brick[i].cType == '+') {
				level++;
				if (level > 3) {
					level = 1;
				}
				
				system("color 2F");
				Sleep(500);
				CreateLevel(level);
			}
			break;
		}
	}
	
}

void ule::DeleteMoving(int i) {
	movingLength--;
	moving[i] = moving[movingLength];
	moving = (ule::TObject*)realloc(moving, sizeof(*moving) * movingLength);
}

void ule::MarioCollision() {
	for (int i = 0; i < movingLength; i++) {
		if (IsCollision(mario, moving[i])) {
			if (moving[i].cType == 'o') {
				if (   (mario.IsFly == true) 
					&& (mario.vertSpeed > 0)
					&& (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)
					)
				{ 	
					score += 50;
					DeleteMoving(i);
					i--;
					continue;					
				} else {
					PlayerDead();
				}
			}
			if (moving[i].cType == '$') {
				score += 100;
				DeleteMoving(i);
				i--;
				continue;
			}
				
			
		}
	}
}

void ule::HorizonMoveObject (ule::TObject *obj) {
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
		VertMoveObject(&tmp);
		if (tmp.IsFly == true) {
			obj[0].x -= obj[0].horizSpeed;
			obj[0].horizSpeed = -obj[0].horizSpeed;
		}
	}
	 
	
}

bool ule::IsPosInMap(int x, int y) {
	return ((x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}

void ule::PutObjectOnMap(ule::TObject obj) {
	int ix = (int)round(obj.x);
	int iy = (int)round(obj.y);
	int iWidth = (int)round(obj.width);
	int iHeight = (int)round(obj.height);
	
	for (int i = ix; i < (ix + iWidth); i++) {
		for (int j = iy; j < (iy + iHeight); j++) {
			if (IsPosInMap(i, j)){
				map[j][i] = obj.cType;
			}
		}
	}
}

void ule::setCur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ule::HorizonMoveMap(float dx) {
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

bool ule::IsCollision(ule::TObject o1, ule::TObject o2) {
	return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
		   ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}

ule::TObject *ule::GetNewBrick() {
	brickLength++;
	brick = (ule::TObject*)realloc(brick, sizeof(*brick) * brickLength);
	return brick + brickLength - 1;
}

ule::TObject *ule::GetNewMoving() {
	movingLength++;
	moving = (ule::TObject*)realloc(moving, sizeof(*moving) * movingLength);
	return moving + movingLength - 1;
}

void ule::PutScoreOnMap() {
	char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i + 5] = c[i];
	}
}

void ule::CreateLevel(int lvl) {
	system("color 9F");
	
	brickLength = 0;
	brick = (ule::TObject*)realloc(brick, 0);
	movingLength = 0;
	moving = (ule::TObject*)realloc(moving, 0);
	
	ule::InitObject(&mario, 39, 10, 3, 3, '@');
	score = 0;
	
	if (lvl == 1) {
		ule::InitObject(ule::GetNewBrick(), 20, 20, 40, 5, '#');
			ule::InitObject(ule::GetNewBrick(), 30, 10, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(), 50, 10, 5, 3, '?');
		ule::InitObject(ule::GetNewBrick(), 60, 15, 40, 10, '#');
			ule::InitObject(ule::GetNewBrick(), 60, 5, 10, 3, '-');
			ule::InitObject(ule::GetNewBrick(), 70, 5, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(), 75, 5, 5, 3, '-');
			ule::InitObject(ule::GetNewBrick(), 80, 5, 5, 3, '?');
			ule::InitObject(ule::GetNewBrick(), 85, 5, 10, 3, '-');
		ule::InitObject(ule::GetNewBrick(), 100, 20, 20, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 120, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(), 150, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 210, 15, 10, 10, '+');
		
		ule::InitObject(ule::GetNewMoving(), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 80, 10, 3, 2, 'o');
	}
	if (lvl == 2) {
		ule::InitObject(ule::GetNewBrick(), 20, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 60, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(), 80, 20, 20, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 120, 15, 10, 10, '#');
		ule::InitObject(ule::GetNewBrick(), 150, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 210, 15, 10, 10, '+');

		ule::InitObject(ule::GetNewMoving(), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 80, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 65, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 120, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 160, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 175, 10, 3, 2, 'o');
	}
	if (lvl == 3) {
		ule::InitObject(ule::GetNewBrick(), 20, 20, 40, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 80, 20, 15, 5, '#');
		ule::InitObject(ule::GetNewBrick(), 120, 15, 15, 10, '#');
		ule::InitObject(ule::GetNewBrick(), 160, 10, 15, 15, '+');

		ule::InitObject(ule::GetNewMoving(), 25, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 50, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 80, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 90, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 120, 10, 3, 2, 'o');
		ule::InitObject(ule::GetNewMoving(), 130, 10, 3, 2, 'o');
	}
	
	maxLvl = 3;
	
}


int main() {
	ule::CreateLevel(level);
	
	do {
		ule::ClearMap();
		
		if ((mario.IsFly == false) && (GetKeyState(VK_SPACE) < 0)) {
			mario.vertSpeed = -1;
		}
		if (GetKeyState('A') < 0) {
			ule::HorizonMoveMap(1);
		}
		if (GetKeyState('D') < 0) {
			ule::HorizonMoveMap(-1);
		}
		
		if (mario.y > mapHeight) {
			ule::PlayerDead();
		}
		
		ule::VertMoveObject(&mario);
		ule::MarioCollision();
		
		for (int i = 0; i < brickLength; i++) {
			ule::PutObjectOnMap(brick[i]);
		}
		for (int i = 0; i < movingLength; i++) {
			ule::VertMoveObject(moving + i);
			ule::HorizonMoveObject(moving + i);
			if (moving[i].y > mapHeight) {
				ule::DeleteMoving(i);
				i--;
				continue;					
			}
			ule::PutObjectOnMap(moving[i]);
		}
		ule::PutObjectOnMap(mario);
		ule::PutScoreOnMap();
		
		ule::setCur(0, 0);
		ule::ShowMap();
		
		Sleep(10);
	} while (GetKeyState(VK_ESCAPE) >= 0);
	
	
	return 0;
}