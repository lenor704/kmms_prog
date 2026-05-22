#pragma once
#include "object.hpp"

namespace ule {
	enum struct BrickType {
		MISTERY_BOX = '?',
		BRICK = '#',
		EMPTY_BOX = '-',
		NEXT_LVL = '+',
	};

	class Brick : public Object {
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
			void setType(BrickType newType);
			bool isFinish();
			bool getWasHit();
	};
}
