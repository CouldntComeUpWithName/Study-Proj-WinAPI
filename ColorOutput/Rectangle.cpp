#include "pch.h"
#include"ConsoleAPI.h"
#include "Rectangle.h"

void Console::Rectangle::RenderNewPosition(COORD Previous_Anchor_Position, COORD New_Anchor_Position)
{
}

Console::Rectangle::Rectangle(int height, int width, COORD spawn_position, unsigned char fill, unsigned short color_attribute)
	: height{height}, width{width}, position{spawn_position}, symbol{fill}, color{color_attribute}
{ }

void Console::Rectangle::Move(Direction direction)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	ClearAll();
	
	switch (direction)//Setting Anchor Point position with a collision check
	{
	case Direction::TOP: 
		if (position.Y - 1 < 0)
			return;
		position.Y -= 1;
		break;
	case Direction::LEFT:
		if (position.X - 1 < 0)
			return;
		position.X -= 1;
		break;
	case Direction::RIGHT: 
		if (position.X + 1 == csbi.srWindow.Right - csbi.srWindow.Left + 1 - 6)
			return;
		position.X += 1;
		break;
	case Direction::DOWN: 
		position.Y += 1;
		break;
	}
}

void Console::Rectangle::Draw()
{
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	HANDLE Ouput_Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Ouput_Handle, &buffer_info);

	SetColor(color);
	
	for (int y = 0; y < height; y++)
	{
		SetCursorPosition(position.X, position.Y + y);
		
		for (int x = 0; x < width; x++)
			std::cout << symbol;
	}
	
	SetColor(buffer_info.wAttributes);
}

void Console::Rectangle::ClearAll()
{

	SetColor(COLOR_BACKGROUND | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	for (int y = 0; y < height; y++)
	{
		SetCursorPosition(position.X, position.Y + y);

		for (int x = 0; x < width; x++)
			std::cout << ' ';
	}
}
