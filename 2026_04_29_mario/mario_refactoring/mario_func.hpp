#pragma once

#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>

#define mapHeight 25
#define mapWidth 80

namespace ule {
	typedef struct SObject {
		float x, y;
		float width, height;
		float vertSpeed;
		bool isFly;
		char cType;
		float horizSpeed;
	} TObject;
	
	void createLevel(const int lvl, TObject *mario, 
					 TObject *&brick, int &brickLength, 
					 TObject *&moving, int &movingLength, 
					 int& score, int& maxLvl); 
					 
	void clearMap(char (&map)[mapHeight][mapWidth + 1]);
	void deleteMoving(int i, TObject *&moving, int &movingLength); 
	TObject *getNewBrick(TObject *&brick, int &brickLength); 
	TObject *getNewMoving(TObject *&moving, int &movingLength); 
	
	void horizonMoveMap(float dx, TObject mario, 
						TObject *&brick, int &brickLength, 
						TObject *&moving, int &movingLength);
						
	void horizonMoveObject (TObject *obj, TObject *mario, 
							TObject *&brick, int &brickLength, 
							TObject *&moving, int &movingLength, 
							int &level, int& score, int& maxLvl);
							
	void initObject(TObject *obj, float xPos, float yPos, 
					float oWidth, float oHeight, char inType);
					
	bool isCollision(TObject o1, TObject o2);
	bool isPosInMap(int x, int y);
	
	void marioCollision(TObject mario, 
						TObject *&brick, int &brickLength, 
						TObject *&moving, int &movingLength, 
						int &level, int& score, int& maxLvl); 
						
	void playerDead(TObject &mario, 
					TObject *&brick, int &brickLength, 
					TObject *&moving, int &movingLength, 
					int &level, int& score, int& maxLvl); 
					
	void putObjectOnMap(TObject obj, char (&map)[mapHeight][mapWidth + 1]);
	void putScoreOnMap(char (&map)[mapHeight][mapWidth + 1], const int& score); 
	void setCur(int x, int y);
	void setObjectPos(TObject *obj, float xPos, float yPos);
	void showMap(char (&map)[mapHeight][mapWidth + 1]);
	
	void vertMoveObject(TObject *obj, TObject *mario, 
						TObject *&brick, int &brickLength, 
						TObject *&moving, int &movingLength, 
						int &level, int& score, int& maxLvl); 
}

