#include"pch.h"
#include"ConsoleAPI.h"
#include"Rectangle.h"
#include "Examples.h"

//outputs a table with color blocks and its value within in binary representation using std::bitset
void ConsoleColorTable(bool executable = true)
{
	if(executable)
	{
		Console::SetColor(BACKGROUND_INTENSITY);
		system("cls");

		int color;
		for (int IR = 0; IR <= 3; IR++)//IR число, що представлятиме значення INTENSITY та RED у кольорі |   Пояснення: на дані про кольор у нашому
			for (int i = 0; i < 3; i++)//стовпець для прямокутної форми							         |   випадку виділяється 4 біти IRGB. Максимальне
			{																						   //|	 int значення, яке може зберігати дані у 2-х бітах
				for (int GB = 0; GB <= 3; GB++)//													     |   - це(2^2) - 1, тобто 3. Тому ітеруємося по 3 рази.
				{
					color = (IR << 6) + (GB << 4);

					Console::SetColor(color);

					std::bitset<4> color_bitset(color >> 4);

					if (i == 1)
						std::cout << "  " << color_bitset << "  ";
					else
						std::cout << "        ";
				}
				std::cout << "\n";
			}

		Console::SetColor(BACKGROUND_INTENSITY);
		_getch();
	}
}

void RectangleMoving(bool executable = true)
{
	if (executable)
	{
		SetConsoleTitleW(L"Rectangle Moving!");
		Console::CursorVisibility(false);

		Console::Rectangle rectangle(5, 7, { 5,6 }, ' ', BACKGROUND_GREEN | BACKGROUND_RED);

		int pressed_Key{};
		while (true)
		{
			if (GetAsyncKeyState(Console::Key::ESC) & 0x8000)
				return;

			rectangle.Draw();

			pressed_Key = _getch();

			switch (pressed_Key)
			{
			case Console::Key::ARROW_UP:
				rectangle.Move(Console::Direction::TOP);
				break;
			case Console::Key::ARROW_LEFT:
				rectangle.Move(Console::Direction::LEFT);
				break;
			case Console::Key::ARROW_RIGHT:
				rectangle.Move(Console::Direction::RIGHT);
				break;
			case Console::Key::ARROW_DOWN:
				rectangle.Move(Console::Direction::DOWN);
				break;
			}

		}
	}
}

void DrawA(bool executable = true)
{
	if (executable)
	{
		SetConsoleTitleW(L"Drawing A!!!");
		Console::SetColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		Console::cls();

		const int row = 10;
		const int col = 10;
	
		bool A[row * col]
		{
		  0,0,0,0,1,1,0,0,0,0,
		  0,0,0,1,0,0,1,0,0,0,
		  0,0,0,1,0,0,1,0,0,0,
		  0,0,1,0,0,0,0,1,0,0,
		  0,0,1,0,0,0,0,1,0,0,
		  0,0,1,1,1,1,1,1,0,0,
		  0,1,0,0,0,0,0,0,1,0,
		  0,1,0,0,0,0,0,0,1,0,
		  1,0,0,0,0,0,0,0,0,1,
		  1,0,0,0,0,0,0,0,0,1,

		};

		CONSOLE_SCREEN_BUFFER_INFO csbInfo;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbInfo);


		CHAR_INFO PicBuffer[row * col];

		for (int i = 0; i < row * col; i++)
		{
			PicBuffer[i].Char.UnicodeChar = L' ';
			PicBuffer[i].Attributes = csbInfo.wAttributes;
		}

		for(int i = 0; i < row * col; i++)
				if(A[i] == 1)
					PicBuffer[i].Attributes = 0;

		int AnchorPositionX = 5;
		int AnchorPositionY = 5;


		SMALL_RECT WriteArea = { AnchorPositionX, AnchorPositionY, AnchorPositionX + col, AnchorPositionY + row };

		while (true)
		{
			if (GetKeyState(VK_ESCAPE))
				return;
		
			WriteConsoleOutputW(GetStdHandle(STD_OUTPUT_HANDLE), PicBuffer, { col, row }, { 0,0 }, &WriteArea);
		}
	}

}
