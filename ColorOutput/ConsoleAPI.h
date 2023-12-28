#pragma once
#include"pch.h"

namespace Console
{
	void SetColor(unsigned short Color);
	void SetCursorPosition(short x, short y);
	void CursorVisibility(bool flag);

	std::string GetBinaryRepresentation(int, const int);

	unsigned long Fill(const wchar_t symbol, COORD position, int count = 1);
	unsigned long FillColor(WORD CharacterAttribute, COORD position, int count);
	unsigned long FillAndColor(const wchar_t symbol, WORD CharacterAttribute, COORD position, const int count);
	
	void Clear();
	void Clear(COORD start_position, int count);
	void Clear(COORD start_position, COORD last_position);
	void cls();
	void function(const short rows, const short columns, SMALL_RECT area_coords);



}

