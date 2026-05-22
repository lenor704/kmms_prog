#pragma once
#include "object.hpp"
#include "mapSize.hpp"

namespace ule {
	class Show {
		private:
			char map[mapHeight][mapWidth + 1];
			
			void setCur(int x, int y);			

		public:
			Show();
			~Show() = default;
			
			void show();
			void clearMap();
			bool isPosInMap(int x, int y);
			void putObjectOnMap(const Object& obj);
			void putScoreOnMap(int score);
			void showMap();
	};
}