#include"pch.h"
#include<dbnetlib.h>
#include<functional>
#include"ConsoleAPI.h"
#include"Rectangle.h"
#include"Examples.h"

//struct ARGB
//{
//private:
//	int alpha : 8;
//	int red : 8;
//	int green : 8;
//	int blue : 8;
//public:
//	ARGB() = default;
//	ARGB(int A, int R, int G, int B)
//		:alpha{A}, red{R}, green{G}, blue{B}
//	{
//
//	}
//};
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
//{
//	ARGB color( 20, 255, 127, 169 );
//	
//	//HWND window = CreateWindow(L"EDIT", L"Hello", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 200, 200, nullptr, nullptr, hInstance, nullptr);
//	const WCHAR*  name = L"Sample";
//	
//	WNDCLASS wc = { };
//
//	wc.lpfnWndProc = WindowProc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = name;
//
//	RegisterClass(&wc);
//
//	HWND window = CreateWindowExW(NULL, name, L"The fun has just begun!!!", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, nullptr);
//	
//	if (window)
//	{
//		ShowWindow(window, nCmdShow);
//		MSG msg{};
//
//		while (GetMessageW(&msg, nullptr, 0, 0))
//		{
//			TranslateMessage(&msg);
//			DispatchMessageW(&msg);
//		}
//	}
//
//	
//	//SetWindowTextW(window, L"Hello world.");
//	return 0;
//}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// All painting occurs here, between BeginPaint and EndPaint.
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hwnd, &ps);
	}
	return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

#define SIZE 6

int main()
{
	

	//int keyPressed{};
	
	//while(true)
		DrawA();
		//keyPressed = _getch();

	return 0;
}

//Console API Info
/*
	BOOL SetConsoleTextAttribute(HANDLE, WORD); - встановлює атрибути кольору фона і тексту.

		HANDLE - дескриптор/ідентифікатор вікна(консолі), значення, за допомогою якого можна ідентифікувати ресурс.
		Є вказівником на деякий ресурс. typedef void* HANDLE;

		WORD - typedef unsigned short, тип WORD представляє 16 бітне ціле число, є псевдонімом unsigned short int;

		BOOL - булевий тип даних визначений як псевдонім int. Зберігає зазвичай TRUE або FALSE. Повертає код помилки або 0, якщо все пройшло успішно

	Як отримати дескриптор вікна? :

		HANDLE GetStdHandle(DWORD nStdHandle) - використати функцію GetStdHandle яка повертає ідентифікатор вікна, якщо все пройшло ок, а NULL - якщо ні.
		
		DWORD - це цілочисельний тип який має 32 біти, в двічі більше за WORD. Тому і називається D(ouble)WORD.
		Є псевдонімом unsigned long int, бо на відміну від int, він буде мати розмір 4 байти(32 біти) на всіх конфігураціях.

		Для того, щоб отримати дескриптор консольного вікна, є визначений макрос(константа) STD_OUTPUT_HANDLE, яка каже про те, що прикладний
		програміст хоче отримати ідентифікатор стандартного пристрою вводу-виводу.
		
		Зазвичай змінні які зберігають хендлери, починаються з маленької літери hName. Але це не суворі вимоги до іменування. 
		
		Тож, щоб отримати дескриптор, оголошуємо змінну типу HANDLE і присвоюємо результат повернення функції GetStdHandle:
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	Заміна заголовку Консолі: 
		
		SetConsoleTitle(LPCWSTR) - макрос який викликає SetConsoleTitleW(LPCWSTR) для зміни вікна консолі.
		
		LPCWSTR - псевдонім для визначення вказівника на константний WCHAR(typedef wchar_t) для зберігання константного Unicode рядка.
		Еквівалентно до const wchar_t* або const WCHAR*.
		
		Рядкові літерали Unicode записуються так: L"Some Text"

		system("title YourConsoleTitleName") - також змінити заголовок консолі можна через функцію system(const char*);

		Функція system(const char*) виконує стандарті текстові команди DOS( Disk Operating System ), для консолі.

	Макрос FillConsoleOutputCharacter(HANDLE, TCHAR, DWORD, COORD, LPDWORD) У вікні, ідентифікатор якого приймаєтья аргументом HANDLE, 
 друкує символ типу TCHAR(typedef WCHAR) певну кількість разів, задану параметром DWORD(typedef unsigned long) починаючи з місця COORD. 
 LPDWORD - вказівник на змінну, яка отримає кількість символів, надрукованих по факту. 
 Викликає функції FillConsoleOutputCharacterA(HANDLE, CHAR, DWORD, COORD, LPDWORD) та FillConsoleOutputCharacterW(HANDLE, WCHAR, DWORD, COORD, LPDWORD), 
 для різних кодових таблиць символів.


*/