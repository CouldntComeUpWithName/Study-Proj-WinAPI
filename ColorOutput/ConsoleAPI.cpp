#include"pch.h"
#include"ConsoleAPI.h"
#include"Point.h"

namespace Console 
{
	static const HANDLE ConsoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	void SetColor(unsigned short ColorID)
	{
		SetConsoleTextAttribute(ConsoleOutputHandle, ColorID);
	}

	void SetCursorPosition(short x, short y)
	{
		COORD position{ x,y };
		SetConsoleCursorPosition(ConsoleOutputHandle, position);
	}

	void CursorVisibility(bool flag)
	{
		CONSOLE_CURSOR_INFO cursor;

		GetConsoleCursorInfo(ConsoleOutputHandle, &cursor);

		cursor.bVisible = flag;

		SetConsoleCursorInfo(ConsoleOutputHandle, &cursor);
	}

	std::string GetBinaryRepresentation(int number, const int nBit = 31)
	{
		std::string binary_number(nBit, '0');

		for (int i = nBit - 1; i >= 0; i--, number >>= 1)
			binary_number[i] = number & 1 ? '1' : '0';

		return binary_number;
	}

	unsigned long Fill(const wchar_t symbol, COORD position, int count)
	{
		DWORD WrittenCharacters;

		FillConsoleOutputCharacterW(ConsoleOutputHandle, symbol, count, position, &WrittenCharacters);

		return WrittenCharacters;
	}

	unsigned long FillColor(WORD CharacterAttribute, COORD position, int count)
	{
		DWORD NumberOfWrittenAttributes;
		FillConsoleOutputAttribute(ConsoleOutputHandle, CharacterAttribute, count, position, &NumberOfWrittenAttributes);

		return NumberOfWrittenAttributes;
	}

	unsigned long FillAndColor(const wchar_t symbol, WORD CharacterAttribute, COORD position, const int count)
	{
		Fill(symbol, position, count);
		
		return FillColor(CharacterAttribute, position, count);
	}

	void Clear()
	{
		CONSOLE_SCREEN_BUFFER_INFO buffer_info;
		GetConsoleScreenBufferInfo(ConsoleOutputHandle, &buffer_info);

		FillAndColor(' ', buffer_info.wAttributes, COORD{ 0,0 }, buffer_info.dwSize.X * buffer_info.dwSize.Y);
	}

	void Clear(COORD start_position, int count)
	{
		CONSOLE_SCREEN_BUFFER_INFO buffer_info;
		GetConsoleScreenBufferInfo(ConsoleOutputHandle, &buffer_info);

		FillAndColor(' ', buffer_info.wAttributes, start_position, count);
	}

	void cls()
	{
		system("cls");
	}

	void function(const short rows, const short columns, SMALL_RECT area_coords)
	{
		CHAR_INFO* buffer = (CHAR_INFO*)malloc(sizeof(CHAR_INFO) * rows * columns);

		if(buffer)
		{
			for (int i = 0; i < rows * columns; i++)
			{
				buffer[i].Char.UnicodeChar = 'X';
				buffer[i].Attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			}

			WriteConsoleOutput(ConsoleOutputHandle, buffer, { rows, columns }, { 0, 0 }, &area_coords);
		}

		int get = _getch();
	}

}



