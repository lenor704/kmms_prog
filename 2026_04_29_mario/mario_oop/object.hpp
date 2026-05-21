#pragma once

namespace ule {
	class Object {
		protected:
			float x, y;
			float width, height;
			float vertSpeed;
			float horizSpeed;
			bool isFly;
			bool isActive;
			char type;
		public:
			Object();
			virtual ~Object() = default;
			
			void init(float xPos, float yPos, float w, float h, char newType);
			
			float getX() const;
			void setX(float newX);
			
			float getY() const;
			void setY(float newY);
			
			float getWidth() const;
			void setWidth(float newWidth);
			
			float getHeight() const;
			void setHeight(float newHeight);
			
			float getVertSpeed() const;
			void setVertSpeed(float speed);
			
			float getHoriztSpeed() const;
			void setHorizSpeed(float speed);
			
			char getType() const;
			void setType(char newType);
			
			void setPosition(float xPos, float yPos);
			bool isCollision(const Object& other) const;
			
			void setIsFly(bool fly);
			bool getIsFly() const;
			
			bool getIsActive() const;
			void setIsActive(bool active);
			
			void deactivate();
			
			virtual void update() {}
	};
}