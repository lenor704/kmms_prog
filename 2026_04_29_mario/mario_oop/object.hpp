#pragma once

namespace ule {
	class Object {
		protected:
			float x, y;
			float width, height;
			float vertSpeed;
			float horizSpeed;
			bool isFly;
			char type;
		public:
			Object();
			virtual ~Object() = default;
			
			void init(float x, float y, float width, float height, char type);
			
			float x();
			void setX(float newX);
			
			float y();
			void setY(float newY);
			
			float getWidth();
			void setWidth(float newWidth);
			
			float getHeight();
			void setHeight(float newHeight);
			
			float getVertSpeed();
			void setVertSpeed(float speed);
			
			float getHoriztSpeed();
			void setHorizSpeed(float speed);
			
			char getType();
			void setType(char newType);
			
			void setPosition(float x, float y);
			bool isCollision(Object& other);
			
			virtual void update() {}
	};
}