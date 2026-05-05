#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <windows.h>

namespace ule {
	typedef struct SObject {
		float x, y;
		float width, height;
		float vertSpeed;
		bool IsFly;
		char cType;
		float horizSpeed;
	} TObject;
	
	void ClearMap();
	void ShowMap();
	void SetObjectPos(TObject *obj, float xPos, float yPos);
	void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType);
	TObject *GetNewBrick();
	TObject *GetNewMoving();
	void PlayerDead();
	void VertMoveObject(TObject *obj);
	void DeleteMoving(int i);
	void MarioCollision();
	void HorizonMoveObject (TObject *obj);
	bool IsPosInMap(int x, int y);
	void PutObjectOnMap(TObject obj);
	void setCur(int x, int y);
	void HorizonMoveMap(float dx);
	bool IsCollision(TObject o1, TObject o2);
	void PutScoreOnMap();
	void CreateLevel(int lvl);
}

