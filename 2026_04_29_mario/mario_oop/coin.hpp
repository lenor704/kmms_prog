#pragma once
#include "object.hpp"

namespace ule{
	class Coin : public Object {
		public:
			Coin();
			~Coin() = default;;
			
			void spawn(float xPos, float yPos);
			
			void update() override;
	};
}
