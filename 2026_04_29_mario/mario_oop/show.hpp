#pragma once
#include "object.hpp"

namespace ule {
	class Show {
		private:
			int mapHeight = 25;
			int mapWidth = 80;
			char map[mapHeight][mapWidth];
			
			void setCur(int x, int y);			

		public:
			Show();
			~Show() = default;
			
			void clearMap();
			bool isPosInMap(int x, int y);
			void putObjectOnMap(Object& obj);
			void putScoreOnMap(int score);
			void showMap();
	};
}