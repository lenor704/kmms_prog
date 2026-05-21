#pragma once
#include "mario.hpp"
#include "show.hpp"
#include "level.hpp"

namespace ule {
	class Game {
		private:
			Level level;
			Mario mario;
			Show showing;
			
			int levelNumber;
			int score;
			bool isRunning;
			
			void input();
			
			void moveHorizonMap(float dx);
			
			void handleCollisions();
			void nextLevel();
			
		public:
			Game();
			~Game();
			
			void init();
			void update();
			void run();
			void show();
			void stop();
	};
}