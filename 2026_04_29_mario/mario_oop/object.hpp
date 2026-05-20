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
			Object(float width, float height, float vertSpeed, float horizSpeed, char type);
			virtual ~Object() = default;
			
			float x();
			void setX(float newX);
			
			float y();
			void setY(float newY);
			
			float getWidth();
			void setWidth(float newWidth);
			
			float getHeight();
			void setHeight(float newHeight);
			
			char getType();
			
			void setPosition(float x, float y);
			bool isCollision(Object& other);
			
			//virtual void update() {}
			///virtual void draw(Show& showing);
	};
}