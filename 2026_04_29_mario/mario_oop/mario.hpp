#pragma once
#include "object.hpp"

namespace ule {
	class Mario : public Object {
		public:
			Mario();
			Mario::~Mario() = default;
			
			void jump();
			void gravity();
			void death();
			
			bool isFly();
			
			void setVertSpeed(float speed);
			void setIsFly(bool fly);
		};
}