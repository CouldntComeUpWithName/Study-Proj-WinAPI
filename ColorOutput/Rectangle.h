#pragma once

namespace Console
{
	
	enum Key
	{
		ESC				= 27,
		ARROW_UP		= 72,
		ARROW_LEFT		= 75,
		ARROW_RIGHT		= 77,
		ARROW_DOWN		= 80
		
	};
	
	enum class Direction : int
	{
		TOP,
		LEFT,
		RIGHT,
		DOWN
	};

	class Rectangle
	{
	private:
		unsigned short color;
		unsigned char symbol;
		int height;
		int width;
		COORD position;

		void RenderNewPosition(COORD Previous_Anchor_Position, COORD New_Anchor_Position);

	public:
		
		Rectangle() = default;
		Rectangle(int height, int width, COORD spawn_position, unsigned char fill, unsigned short color_attribute);

		void Draw();
		void Move(Direction direction);
		void ClearAll();
	};

}

