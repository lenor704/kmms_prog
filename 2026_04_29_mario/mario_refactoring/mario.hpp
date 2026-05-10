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
		bool IsFly;
		char cType;
		float horizSpeed;
	} TObject;
	
	void CreateLevel(int lvl, TObject *mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!
	void ClearMap(char (&map)[mapHeight][mapWidth + 1]);
	void DeleteMoving(int i, TObject *&moving, int &movingLength); //!
	TObject *GetNewBrick(TObject *&brick, int &brickLength); 
	TObject *GetNewMoving(TObject *&moving, int &movingLength); //!
	void HorizonMoveMap(float dx, TObject mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!
	void HorizonMoveObject (TObject *obj, TObject *mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!!!
	void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType);
	bool IsCollision(TObject o1, TObject o2);
	bool IsPosInMap(int x, int y);
	void MarioCollision(TObject mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!
	void PlayerDead(TObject &mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!!!
	void PutObjectOnMap(TObject obj, char (&map)[mapHeight][mapWidth + 1]);
	void PutScoreOnMap(char (&map)[mapHeight][mapWidth + 1]);
	void setCur(int x, int y);
	void SetObjectPos(TObject *obj, float xPos, float yPos);
	void ShowMap(char (&map)[mapHeight][mapWidth + 1]);
	void VertMoveObject(TObject *obj, TObject *mario, TObject *&brick, int &brickLength, TObject *&moving, int &movingLength); //!
}

