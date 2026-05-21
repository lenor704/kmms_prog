#include "show.hpp"
#include <windows.h>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace ule;

Show::Show() {
	for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            map[i][j] = ' ';
        }
        map[i][mapWidth] = '\0';
    }
}

void Show::show() {
    setCur(0, 0);
    for (int j = 0; j < mapHeight; j++) {
        std::cout << map[j] << std::endl;
    }
}

void Show::setCur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Show::clearMap() {
	for (int i = 0; i < mapWidth; i++) {
		map[0][i] = ' ';
	}
	map[0][mapWidth] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		sprintf(map[j], map[0]);
	}
}

bool Show::isPosInMap(int x, int y) {
	return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

void Show::putObjectOnMap(const Object& obj) {
	int ix = round(obj.getX());
	int iy = round(obj.getY());
	int iWidth = round(obj.getWidth());
	int iHeight = round(obj.getHeight());
	
	for (int i = ix; i < (ix + iWidth); i++) {
		for (int j = iy; j < (iy + iHeight); j++) {
			if (isPosInMap(i, j)){
				map[j][i] = obj.getType();
			}
		}
	}
}

void Show::putScoreOnMap(int score) {
	char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i + 5] = c[i];
	}
}

void Show::showMap() {
    map[mapHeight - 1][mapWidth - 1] = '\0';
	for (int j = 0; j < mapHeight; j++) {
		std::cout << map[j];
	}
}