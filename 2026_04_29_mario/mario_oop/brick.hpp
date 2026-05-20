#pragma once
#include "object.hpp"

namespace ule {
	enum struct BrickType {
		char MISTERY_BOX = '?',
		char BRICK = '#',
		char EMPTY_BOX = '-',
		char NEXT_LVL = '+',
	};

	class Brick : public GameObject {
		private:
			BrickType brickType;
			bool wasHit;

		public:
			Brick();
			~Brick() = default;
			
			void spawn(float xPos, float yPos, float newWidth, float newHeight, BrickType bType);
			bool hit();
			void toEmpty();
			
			BrickType getType();
			bool isFinish();
			bool getWasHit();
	};
}
