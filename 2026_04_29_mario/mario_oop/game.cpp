#include "game.hpp"
#include <windows.h>


using namespace ule;

Game::Game() {
	levelNumber = 1;
	score = 0;
	isRunning = false;
}

Game::~Game() {
    isRunning = false;
}

void Game::init() {
    isRunning = true;
	mario.spawn();
    level.load(1);
}

void Game::run() {
    while (isRunning) {
		input();
        update();
        show();
        Sleep(5);
    }
}

void Game::input() {    
	if (GetKeyState(VK_ESCAPE) < 0) {
		isRunning = false;
	}
	if ((mario.getIsFly() == false) && (GetKeyState(VK_SPACE) < 0)) {
		mario.jump();
	}
	if (GetKeyState('A') < 0) {
		moveHorizonMap(1);
	}
	if (GetKeyState('D') < 0) {
		moveHorizonMap(-1);
	}
	if (mario.getY() > mapHeight) {
		mario.death();
	}
}

void Game::moveHorizonMap(float dx) {
    mario.setX(mario.getX() - dx);
    
    Brick* bricks = level.getBricks();
    for (int i = 0; i < level.getBrickCount(); i++) {
        
        if (mario.isCollision(bricks[i])) {
            mario.setX(mario.getX() + dx);
            return;
        }
    }
    
    mario.setX(mario.getX() + dx);
    
    for (int i = 0; i < level.getBrickCount(); i++) {
        bricks[i].setX(bricks[i].getX() + dx);
    }
    
    Enemy* enemy = level.getEnemies();
    for (int i = 0; i < level.getEnemyCount(); i++) {
        enemy[i].setX(enemy[i].getX() + dx);
    }
    
    Coin* coin = level.getCoins();
    for (int i = 0; i < level.getCoinCount(); i++) {
        coin[i].setX(coin[i].getX() + dx);
    }
}

void Game::update() {
    mario.update();
    mario.vertMovement(level.getBricks(), level.getBrickCount());
	
	if (mario.getReachedFinish()) {
        nextLevel();
        return;
    }
    
    int hitIndex = mario.getHitBrickFromBelow();
    if (hitIndex >= 0) {
        Brick* bricks = level.getBricks();
        if (bricks[hitIndex].getType() == BrickType::MISTERY_BOX) {
            bricks[hitIndex].setType(BrickType::EMPTY_BOX);
            level.spawnCoin(bricks[hitIndex].getX(), bricks[hitIndex].getY());
        }
    }
    
    level.update();
    handleCollisions();
    
    if (!mario.getIsAlive()) {
        system("color 4F");
        Sleep(500);
        level.load(levelNumber);
        mario.spawn();
        score = 0;
    }
}

void Game::handleCollisions() {
    Enemy* enemy = level.getEnemies();
    for (int i = 0; i < level.getEnemyCount(); i++) {
        if (!enemy[i].getIsActive()) continue;
        
        if (mario.upEnemyCollision(&enemy[i])) {
            score += 50;
            level.removeEnemy(i);
        } else if (mario.enemyCollision(&enemy[i])) {
            mario.death();
            return;
        }
    }
    
    Coin* coin = level.getCoins();
    for (int i = 0; i < level.getCoinCount(); i++) {
        if (!coin[i].getIsActive()) continue;
        
        if (mario.coinCollision(&coin[i])) {
            score += 100;
            level.removeCoin(i);
        }
    }
}

void Game::show() {
    showing.clearMap();
    
    Brick* brick = level.getBricks();
    for (int i = 0; i < level.getBrickCount(); i++) {
        if (brick[i].getIsActive()) {
            showing.putObjectOnMap(brick[i]);
        }
    }
    
    Enemy* enemy = level.getEnemies();
    for (int i = 0; i < level.getEnemyCount(); i++) {
        if (enemy[i].getIsActive()) {
            showing.putObjectOnMap(enemy[i]);
        }
    }
    
    Coin* coin = level.getCoins();
    for (int i = 0; i < level.getCoinCount(); i++) {
        if (coin[i].getIsActive()) {
            showing.putObjectOnMap(coin[i]);
        }
    }
    
    showing.putObjectOnMap(mario);
    
    showing.putScoreOnMap(score);
    showing.show();
}

void Game::nextLevel() {
    system("color 2F");
    Sleep(500);
    
    levelNumber++;
    if (levelNumber > 3) {
        levelNumber = 1;
    }
    
    level.load(levelNumber);
    mario.spawn();
	score = 0;
}

