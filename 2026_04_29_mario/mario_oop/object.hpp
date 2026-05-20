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
			Object(float width, float height, float vertSpeed, float horixSpeed, char type);
			virtual ~Object() = default;
			
			float x();
			void setX(float new_x);
			float y();
			void setY(float new_y);
			float getWidth();
			float getHeight();
			
			void setPosition(float x, float y);
			bool isCollision(Object& other);
			
			virtual void update() {}
			virtual void draw(Show& showing);
	};
}