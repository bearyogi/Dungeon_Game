#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _WIN32_WINNT 0x0500
#pragma warning (disable : 4996)
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "conio.h"
#include <limits>
#include <stdexcept>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>
#include <MMsystem.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;
string PL(const char * text)
{
	std::string result;
	for (; *text; text++)
		switch (*text)
		{
		case 'ą': result += static_cast <char>(0xa5); break;
		case 'ć': result += static_cast <char>(0x86); break;
		case 'ę': result += static_cast <char>(0xa9); break;
		case 'ł': result += static_cast <char>(0x88); break;
		case 'ń': result += static_cast <char>(0xe4); break;
		case 'ó': result += static_cast <char>(0xa2); break;
		case 'ś': result += static_cast <char>(0x98); break;
		case 'ż': result += static_cast <char>(0xbe); break;
		case 'ź': result += static_cast <char>(0xab); break;
		case 'Ą': result += static_cast <char>(0xa4); break;
		case 'Ć': result += static_cast <char>(0x8f); break;
		case 'Ę': result += static_cast <char>(0xa8); break;
		case 'Ł': result += static_cast <char>(0x9d); break;
		case 'Ń': result += static_cast <char>(0xe3); break;
		case 'Ó': result += static_cast <char>(0xe0); break;
		case 'Ś': result += static_cast <char>(0x97); break;
		case 'Ż': result += static_cast <char>(0xbd); break;
		case 'Ź': result += static_cast <char>(0x8d); break;
		default: result += *text; break;
		}
	return result;
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void movement(int & ruch)
{
	unsigned char key;
	key = _getch();
	switch (key)
	{
	case 224:
		key = _getch();
		//cout<<key<<endl;

		switch (key)
		{

		case 75:
			ruch = 1;
			break;
		case 80:
			ruch = 0;
			break;
		case 72:
			ruch = 0;
			break;
		case 77:
			ruch = 2;
			break;
		}

		break;
	case 27:
		ruch = 3;
		break;

	}
}

void wypelnijxy(int  *x, int  *y, int pok)
{
	for (int i = 0; i < pok; i++)
	{
		y[i] = 0;
		x[i] = 0;
	}
}

void gotoxy(int  x, int  y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
string nick(string & name)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	do
	{
		
		gotoxy(19, 10);
		cout << "====================================" << endl;
		gotoxy(19, 11);
		cout << "PODAJ SWOJE IMI" << PL("Ę") << ", " << PL("Ś") << "MIA" << PL("Ł") << "KU:" << endl;
		gotoxy(19, 12);
		cout << "====================================" << endl;
		gotoxy(46, 11);
		getline(cin, name);
		if (name.length() > 9)
		{
			gotoxy(19, 15);
			cout << "NAZWA ZBYT D" << PL("Ł") << "UGA! (MAX 9 ZNAK" << PL("Ó") << "W)";
			Sleep(1000);
			gotoxy(19, 15); cout << "                                 ";
		}
		system("cls");
	} while (name.empty() != 0 || name.length()>9);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("cls");
	return name;
}
void bia1()
{
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD wOldColorAttrs;
		CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

		GetConsoleScreenBufferInfo(h, &csbiInfo);
		wOldColorAttrs = csbiInfo.wAttributes;

		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}
void blu1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void muzyka(int d)
{
	for (int a = 0; a < 5; a++)
	{
		d = d + 100;
		Beep(d, 50);

	}
}
void muzyka1(int d)
{
	for (int a = 0; a < 10; a++)
	{
		d = d - 100;
		Beep(d, 50);

	}
}
void muzyka2(int d)
{
	for (int a = 0; a < 10; a++)
	{
		d = d + 100;
		Beep(d, 50);

	}
}

void rysuj(int  a, int  b)
{
	gotoxy(a, b);
	cout << "#";
	return;
}
void rysujmapa(int  a, int  b)
{
	bia1();
	gotoxy(a-18, b-10);
	cout << "#";
	return;
}
void rysuj2(int  a, int  b)
{
	gotoxy(a, b);
	cout << "=";
	return;
}
void rysuj3(int  a, int  b)
{
	gotoxy(a, b);
	cout << "|" << "|";
	return;
}
void rysuj4(int  a, int  b)
{
	gotoxy(a, b);
	cout << "|";
	return;
}
void wybor1()
{
	gotoxy(25, 2);

}
void obramowka()
{
	for (int i = 4; i <= 14; i++)
	{
		if (i == 4 || i == 14)

		{
			for (int j = 19; j < 56; j++)
				rysuj2(j, i);
		}
		rysuj3(19, i);
		rysuj3(56, i);
	}

}

void obramowka2()
{
	for (int i = 1; i <= 26; i++)
	{
		if (i == 1 || i == 25)

		{
			for (int j = 0; j < 80; j++)
				rysuj(j, i);
		}
		rysuj(0, i);
		rysuj(80, i);
	}

}


void tytul()
{
	gotoxy(22, 23);
	cout << " MADE BY Y&M STUDIO ~ 2018/2019 ";
	gotoxy(37, 8);
	cout << "G";
	Beep(600, 50);
	cout << "R";
	Beep(600, 50);
	cout << "A";
	Beep(600, 50);
	gotoxy(25, 10);
	cout << "J";
	Beep(300, 20);
	Sleep(50);
	cout << "A";
	Beep(300, 20);
	Sleep(50);
	cout << "K";
	Beep(300, 20);
	Sleep(50);
	cout << "I";
	Beep(300, 20);
	Sleep(50);
	cout << "E";
	Beep(300, 20);
	Sleep(50);
	cout << "J";
	Beep(300, 20);
	Sleep(50);
	cout << " ";
	Beep(300, 20);
	Sleep(50);
	cout << PL("Ś");
	Sleep(50);
	cout << "W";
	Beep(300, 20);
	Sleep(50);
	cout << "I";
	Beep(300, 20);
	Sleep(50);
	cout << "A";
	Beep(300, 20);
	Sleep(50);
	cout << "T";
	Beep(300, 20);
	Sleep(50);
	cout << " ";
	Beep(300, 20);
	Sleep(50);
	cout << "N";
	Beep(300, 20);
	Sleep(50);
	cout << "I";
	Beep(300, 20);
	Sleep(50);
	cout << "E";
	Beep(300, 20);
	Sleep(50);
	cout << " ";
	Beep(300, 20);
	Sleep(50);
	cout << "W";
	Beep(300, 20);
	Sleep(50);
	cout << "I";
	Sleep(50);
	cout << "D";
	Beep(300, 20);
	Sleep(50);
	cout << "Z";
	Beep(300, 20);
	Sleep(50);
	cout << "I";
	Beep(300, 20);
	Sleep(50);
	cout << "A";
	Beep(300, 20);
	Sleep(50);
	cout << PL("Ł");
	Beep(300, 20);
	Sleep(50);
	cout << ".";
	Sleep(3000);
	system("cls");

}
void nazwa()
{
	system("cls");
	system("color 2");
	gotoxy(25, 9);
	cout << "===============================" << endl;
	gotoxy(25, 10);
	cout << "------PODZIEMIA & POTWORY------" << endl;
	gotoxy(25, 11);
	cout << "===============================" << endl;
	Sleep(3000);
}
void opcje()
{
	system("cls");
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(0, 2);
	cout << "================================================================================" << endl;
	gotoxy(5, 3);
	cout << "                                OPCJE" << endl;
	gotoxy(0, 4);
	cout << "================================================================================" << endl;

	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 10);
	cout << "DZWIEK WLACZONY" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(5, 14);
	cout << "POWROT DO MENU" << endl;

}
void opcje2()
{
	system("cls");
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(0, 2);
	cout << "================================================================================" << endl;
	gotoxy(5, 3);
	cout << "                                OPCJE" << endl;
	gotoxy(0, 4);
	cout << "================================================================================" << endl;

	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(5, 10);
	cout << "DZWIEK WYLACZONY" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(5, 14);
	cout << "POWROT DO MENU" << endl;
}
void opcje3()
{
	system("cls");
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(0, 2);
	cout << "================================================================================" << endl;
	gotoxy(5, 3);
	cout << "                                OPCJE" << endl;
	gotoxy(0, 4);
	cout << "================================================================================" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

	gotoxy(5, 10);
	cout << "DZWIEK WLACZONY" << endl;

	gotoxy(5, 14);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "POWROT DO MENU" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void opcje4()
{
	system("cls");
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(0, 2);
	cout << "================================================================================" << endl;
	gotoxy(5, 3);
	cout << "                                OPCJE" << endl;
	gotoxy(0, 4);
	cout << "================================================================================" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

	gotoxy(5, 10);
	cout << "DZWIEK WYLACZONY" << endl;

	gotoxy(5, 14);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "POWROT DO MENU" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void  Menu_Opcje(bool & c)
{
	int b = 1;

	char k;
	do
	{

		switch (c)
		{
		case true:
			switch (b)
			{
			case 1:
				opcje();
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 72:
						b = 2;
						break;
					case 80:
						b = 2;
						break;
					}
					break;
				case 13:
					b = 1;
					c = false;
					break;
				}
				break;

			case 2:
				opcje3();
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 72:
						b = 1;
						break;
					case 80:
						b = 1;
						break;
					}
					break;
				case 13:
					b = 5;
					break;
				}
				break;
			}
			break;
		case false:
			switch (b)
			{
			case 1:
				opcje2();
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 72:
						b = 2;
						break;
					case 80:
						b = 2;
						break;
					}
					break;
				case 13:
					b = 1;
					c = true;
					break;
				}
				break;

			case 2:
				opcje4();
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 72:
						b = 1;
						break;
					case 80:
						b = 1;
						break;
					}
					break;
				case 13:
					b = 5;
					break;
				}
				break;
			}
			break;
		}


	} while (b != 5);
}

void red()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);

}
void dark()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_BLUE);

}
void red1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

}
void reds()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);

}
void zie()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_GREEN);

}
void zlo()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void zlo1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
}
void bia()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

void def()
{
	HANDLE hConsole;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_BLUE & BACKGROUND_RED);
}
void pur()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute

	(hConsole, BACKGROUND_RED);
}
void ram()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute

	(hConsole, BACKGROUND_RED);
	pur();
	cout << "  ";
	def();
	cout << "                                                                             ";
	pur();
	cout << "  ";
	def();
}
void rams()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute

	(hConsole, BACKGROUND_RED);
	red();
	cout << "  ";
	def();
	cout << "                                                                             ";
	red();
	cout << "  "; def();
}
void rams1()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute

	(hConsole, BACKGROUND_RED);
	red();
	cout << "  ";
	def();
	cout << "                                                                             ";
	red();
	cout << "  ";
}
void pup()
{
	HANDLE hConsole;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);


}
void d()
{
	HANDLE hConsole;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_INTENSITY);
}
void blu()
{
	HANDLE hConsole;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_BLUE);
}


void graf()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	pur();
	gotoxy(1, 0);
	cout << "             ";
	red();
	cout << "                                  "; def(); cout << "                   "; blu(); cout << "             "; def();
	gotoxy(0, 1);
	pur();
	cout << "  "; pur(); cout << "          ";
	red();
	cout << "                                  ";
	def();
	cout << "                       ";
	blu();
	cout << "          "; blu(); cout << "  ";
	gotoxy(0, 2);
	pur(); cout << "  "; pur(); cout << "  ";
	red();
	cout << "                                        ";
	def();
	cout << "                           ";
	red();
	cout << "      ";
	blu();
	cout << "  "; blu(); cout << "  ";
	gotoxy(0, 3);
	pur();
	cout << "  "; pur(); cout << "  ";
	red();
	cout << "                                      ";
	def();
	cout << "                           ";
	red();
	cout << "        ";
	blu();
	cout << "  "; blu(); cout << "  ";
	gotoxy(0, 4);
	pur(); cout << "  "; pur(); cout << "  ";
	red();
	cout << "                                    ";
	def();
	cout << "                           ";
	red();
	cout << "          ";
	blu();
	cout << "  "; blu(); cout << "  ";
	gotoxy(0, 5);
	pur(); cout << "  "; pur(); cout << "  ";
	red();
	cout << "                                  ";
	def();
	cout << "                           ";
	red();
	cout << "            ";
	blu();
	cout << "  "; blu(); cout << "  ";
	gotoxy(0, 6);
	pur();
	cout << "  ";
	red();
	cout << "                                  ";
	def();
	cout << "                           ";
	red();
	cout << "                ";
	blu();
	cout << "  ";
	gotoxy(0, 7);
	pur(); cout << "  "; red();
	cout << "                                ";
	def();
	cout << "                           ";
	red();
	cout << "                  ";
	blu();
	cout << "  ";
	gotoxy(0, 8);
	pur(); cout << "  "; red();
	cout << "                              ";
	def();
	cout << "                           ";
	red();
	cout << "                    ";
	blu();
	cout << "  ";
	gotoxy(0, 9);
	blu(); cout << "  "; red();
	cout << "                            ";
	def();
	cout << "                           ";
	red();
	cout << "                      ";
	pur();
	cout << "  ";
	gotoxy(0, 10);
	blu(); cout << "  "; red();
	cout << "                          ";
	def();
	cout << "                           ";
	red();
	cout << "                        ";
	pur();
	cout << "  ";
	gotoxy(0, 11);
	blu();
	cout << "  "; red(); cout << "                        ";
	def();
	cout << "                           ";
	red();
	cout << "                          "; pur(); cout << "  ";
	gotoxy(0, 12);
	blu();
	cout << "  "; blu(); cout << "  ";
	red();
	cout << "                    ";
	def();
	cout << "                           ";
	red();
	cout << "                          ";
	pur();
	cout << "  "; pur(); cout << "  ";
	gotoxy(0, 13);
	blu();
	cout << "  "; blu(); cout << "  ";
	red();
	cout << "                  ";
	def();
	cout << "                           ";
	red();
	cout << "                            ";
	pur();
	cout << "  "; pur(); cout << "  ";
	gotoxy(0, 14);
	blu(); cout << "  "; blu(); cout << "  ";
	red();
	cout << "                ";
	def();
	cout << "                           ";
	red();
	cout << "                              ";
	pur();
	cout << "  "; pur(); cout << "  ";
	gotoxy(0, 15);
	blu(); cout << "  "; blu(); cout << "  ";
	red();
	cout << "              ";
	def();
	cout << "                           ";
	red();
	cout << "                                ";
	pur();
	cout << "  "; pur(); cout << "  "; def();
	gotoxy(0, 16);
	blu(); cout << "  "; blu(); cout << "          ";
	red();
	cout << "    ";
	def();
	cout << "                           ";
	red();
	cout << "                          ";
	pur();
	cout << "          "; pur(); cout << "  "; def();
	gotoxy(1, 17);
	blu(); cout << "             ";
	def();
	cout << "                           ";
	red();
	cout << "                          ";
	pur(); cout << "             "; def();
	gotoxy(1, 18);
	red();
	cout << "                                                                               "; def();
	gotoxy(0, 19);
	for (int a = 0; a < 7; a++)
	{
		rams();
		gotoxy(0, 19 + a);

	}
	def();
	gotoxy(0, 25);
	def(); cout << " ";
	red();
	cout << "                                                                               "; def();
	

}
void autorzy()
{
	//obramowka2();
	for (int i = 1; i < 80; i++)
	{
		gotoxy(i, 0); cout << "#";
		gotoxy(i, 25); cout << "#";
	}
	for (int i = 1; i < 25; i++)
	{
		gotoxy(0, i); cout << "#";
		gotoxy(80, i); cout << "#";
	}
	system("color 1E");
	gotoxy(28, 4);
	cout << "========================" << endl;
	gotoxy(28, 5);
	cout << "        Autorzy" << endl;
	gotoxy(28, 6);
	cout << "========================" << endl;
	gotoxy(3, 11);
	cout << "--> project menager, head programmer, intelectual monument   |Yogi" << endl;
}
void pochodnia1()
{
	gotoxy(6, 8);
	pup(); cout << " ";
	gotoxy(7, 9);
	pup(); cout << "  ";
	gotoxy(6, 10);
	pup(); cout << " "; bia(); cout << "  "; pup(); cout << " ";
	gotoxy(7, 11); pur(); cout << "  "; gotoxy(8, 12); pur(); cout << "  "; gotoxy(9, 13); cout << "  ";


}
void pochodnia2()
{
	gotoxy(30, 0);
	pup(); cout << " ";
	gotoxy(31, 1);
	pup(); cout << "  ";
	gotoxy(30, 2);
	pup(); cout << " "; bia(); cout << "  "; pup(); cout << " ";
	gotoxy(31, 3); pur(); cout << "  "; gotoxy(32, 4); pur(); cout << "  "; gotoxy(33, 5); cout << "  ";


}
void pochodnia3()
{
	gotoxy(9, 8);
	pup(); cout << " ";
	gotoxy(7, 9);
	pup(); cout << "  ";
	gotoxy(6, 10);
	pup(); cout << " "; bia(); cout << "  "; pup(); cout << " ";
	gotoxy(7, 11); pur(); cout << "  "; gotoxy(6, 12); pur(); cout << "  "; gotoxy(5, 13); cout << "  ";


}
void pochodnia4()
{
	gotoxy(33, 0);
	pup(); cout << " ";
	gotoxy(31, 1);
	pup(); cout << "  ";
	gotoxy(30, 2);
	pup(); cout << " "; bia(); cout << "  "; pup(); cout << " ";
	gotoxy(31, 3); pur(); cout << "  "; gotoxy(30, 4); pur(); cout << "  "; gotoxy(29, 5); cout << "  ";


}
void redintens()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute
	(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void redintens1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute
	(h, BACKGROUND_RED | BACKGROUND_INTENSITY);
}
void ta()
{
	gotoxy(10, 8);
	blu(); cout << "                           ";
	gotoxy(0, 9);
	for (int a = 9; a < 22; a++)
	{
		if (a <= 11 && a >= 21)
		{
			gotoxy(9, a);
			blu(); cout << "   "; def(); cout << "                       "; blu(); cout << "   "; def();
			gotoxy(0, a + 1);
			a++;
		}
		gotoxy(9, a);
		blu(); cout << "  "; def(); cout << "                         "; blu(); cout << "  "; def();
		gotoxy(0, a + 1);


	}
	gotoxy(10, 22);
	blu(); cout << "                           ";
	gotoxy(0, 23);
	def();
}
void pip()
{
	gotoxy(9, 2);
	pup(); cout << "   "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "  "; def(); cout << "  "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << "  "; d(); cout << " "; def(); cout << "  "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; cout << endl;
	gotoxy(9, 3);
	pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; d(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " " << endl;
	gotoxy(9, 4);
	pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << "  "; pup(); cout << "  "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << "  "; d(); cout << " "; def(); cout << "  "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; def(); cout << " "; pup(); cout << " " << endl;
	gotoxy(9, 5);
	pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; d(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "  "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " " << endl;
	gotoxy(9, 6);
	pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << "  "; def(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << "  "; d(); cout << " "; def(); cout << "  "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << "  "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << "   "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " "; def(); cout << " "; pup(); cout << " "; def(); cout << " " << endl;
	def();
	gotoxy(43, 7);
	d(); cout << " ";
	def();
	gotoxy(42, 8);
	d(); cout << " ";
	def();
	gotoxy(43, 9);
	d(); cout << " ";
	def();
	gotoxy(43, 10);
	d(); cout << " ";
	def();
	gotoxy(43, 11);
	d(); cout << " ";
	def();
}
void pochodnietemp()
{
	for (int i = 5; i < 11; i++)
	{
		for (int j = 8; j < 14; j++)
		{
			gotoxy(i, j);
			red();
			cout << " ";
		}
	}
	for (int i = 29; i < 35; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			gotoxy(i, j);
			red();
			cout << " ";
		}
	}

}
void rama()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	pur();
	gotoxy(1, 0);
	cout << "                                                                               ";
	gotoxy(1, 25);
	cout << "                                                                               ";
	gotoxy(0, 1);
	cout << "        ";
	def();
	cout << "                                                                 ";
	pur();
	cout << "        ";
	gotoxy(0, 2);
	cout << "       ";
	def();
	cout << "                                                                   ";
	pur();
	cout << "       ";
	gotoxy(0, 3);
	pur();
	cout << "      ";
	def();
	cout << "                                                                     ";
	pur();
	cout << "      ";
	gotoxy(0, 4);
	cout << "     ";
	def();
	cout << "                                                                       ";
	pur();
	cout << "     ";
	gotoxy(0, 5);
	cout << "    ";
	def();
	cout << "                                                                         ";
	pur();
	cout << "    ";
	gotoxy(0, 6);
	cout << "   ";
	def();
	cout << "                                                                           ";
	pur();
	cout << "   ";
	gotoxy(0, 7);

	for (int a = 0; a < 13; a++)
	{
		ram();
		gotoxy(0, 7 + a);
	}
	pur();
	cout << "   ";
	def();
	cout << "                                                                           ";
	pur();
	cout << "   ";
	gotoxy(0, 20);
	pur();
	cout << "    ";
	def();
	cout << "                                                                         ";
	pur();
	cout << "    ";
	gotoxy(0, 21);
	cout << "     ";
	def();
	cout << "                                                                       ";
	pur();
	cout << "     ";
	gotoxy(0, 22);
	cout << "      ";
	def();
	cout << "                                                                     ";
	pur();
	cout << "      ";
	gotoxy(0, 23);
	cout << "       ";
	def();
	cout << "                                                                   ";
	pur();
	cout << "       ";
	gotoxy(0, 24);
	cout << "        ";
	def();
	cout << "                                                                 ";
	pur();
	cout << "        ";

}
void czaszka()
{
	gotoxy(50, 8);
	red();
	cout << "                ";
	def();
	cout << endl;
	gotoxy(48, 9);
	red();
	cout << "                    ";
	def();
	cout << endl;
	gotoxy(46, 10);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(46, 11);
	red();
	cout << "    ";
	def();
	cout << "   ";
	red();
	cout << "          ";
	def();
	cout << "   ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 12);
	red();
	cout << "    ";
	def();
	cout << "  ";
	pur();
	cout << " ";
	def();
	cout << " ";
	red();
	cout << "        ";
	def();
	cout << " ";
	pur();
	cout << " ";
	def();
	cout << "  ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 13);
	red();
	cout << "    ";
	def();
	cout << "  ";
	pur();
	cout << " ";
	def();
	cout << "   ";
	red();
	cout << "    ";
	def();
	cout << "   ";
	pur();
	cout << " ";
	def();
	cout << "  ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 14);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(46, 15);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(48, 16);
	red();
	cout << "                    ";
	def();
	cout << endl;
	gotoxy(48, 17);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 18);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 19);
	red();
	cout << " ";
	def();
	cout << "                  ";
	red();
	cout << " ";
	def();
	cout << endl;
	//gotoxy(48,19);
	//red();
	//cout<<" ";
	//def();
	//cout<<"                  ";
	//red();
	//cout<<" ";
	//def();
	//cout<<endl;
	gotoxy(48, 20);
	red();
	cout << " ";
	def();
	cout << "                  ";
	red();
	cout << " ";
	def();
	cout << endl;
	gotoxy(48, 21);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 22);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 23);
	red();
	cout << "                    ";
	def();

}
void czaszka1()
{
	gotoxy(50, 8);
	red();
	cout << "                ";
	def();
	cout << endl;
	gotoxy(48, 9);
	red();
	cout << "                    ";
	def();
	cout << endl;
	gotoxy(46, 10);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(46, 11);
	red();
	cout << "    ";
	def();
	cout << "   ";
	red();
	cout << "          ";
	def();
	cout << "   ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 12);
	red();
	cout << "    ";
	def();
	cout << "   ";
	def();
	cout << " ";
	red();
	cout << "        ";
	def();
	cout << "  ";
	def();
	cout << "  ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 13);
	red();
	cout << "    ";
	def();
	cout << "   ";
	def();
	cout << "   ";
	red();
	cout << "    ";
	def();
	cout << "    ";
	def();
	cout << "  ";
	red();
	cout << "    ";
	def();
	cout << endl;
	gotoxy(46, 14);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(46, 15);
	red();
	cout << "                        ";
	def();
	cout << endl;
	gotoxy(48, 16);
	red();
	cout << "                    ";
	def();
	cout << endl;
	gotoxy(48, 17);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 18);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 19);
	red();
	cout << " ";
	def();
	cout << "                  ";
	red();
	cout << " ";
	def();
	cout << endl;
	gotoxy(48, 20);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 21);
	red();
	cout << " ";
	def();
	cout << " ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << "  ";
	bia();
	cout << "    ";
	def();
	cout << " ";
	red();
	cout << " ";
	cout << endl;
	gotoxy(48, 22);
	red();
	cout << "                    ";
	def();
}
int statywybor(int staty, int*s, int a)
{
	gotoxy(9, 2);
	bia1();
	cout << "R O Z D A J   P U N K T Y : " << a;
	gotoxy(20, 7); cout << "    ";
	gotoxy(30, 10); cout << "    ";
	gotoxy(36, 13); cout << "    ";
	gotoxy(22, 16); cout << "    ";
	gotoxy(30, 19); cout << "    ";
	if (a < 10)
	{
		gotoxy(38, 2);
		cout << " ";
	}
	

	if (staty == 1)
	{
		blu1();
	}
	gotoxy(6, 7);
	cout << "S I " << PL("Ł") << " A" << " < " << s[3] << " >"; if (staty == 1)cout << " <--";
	bia1();
	gotoxy(6, 10);

	if (staty == 2)
	{

		blu1();
	}
	cout << "Z R " << PL("Ę") << " C Z N O " << PL("Ś") << " " << PL("Ć") << " < " << s[4] << " >"; if (staty == 2)cout << " <--";
	bia1();
	gotoxy(6, 13);

	if (staty == 3)
	{

		blu1();
	}
	cout << "W Y T R Z Y M A " << PL("Ł") << " O " << PL("Ś") << " " << PL("Ć") << " < " << s[5] << " >"; if (staty == 3)cout << " <--";
	bia1();
	gotoxy(6, 16);

	if (staty == 4)
	{

		blu1();
	}
	cout << "M A G I A" << " < " << s[6] << " >"; if (staty == 4)cout << " <--";
	bia1();
	gotoxy(6, 19);

	if (staty == 5)
	{

		blu1();
	}
	cout << "S Z C Z " << PL("Ę") << " " << PL("Ś") << " C I E" << " < " << s[7] << " >"; if (staty == 5)cout << " <--";
	bia1();
	if (staty == 1)
	{
		s[3] += 1;
		s[3] -= 1;
	}
	if (staty == 2)
	{
		s[4] += 1;
		s[4] -= 1;
	}
	if (staty == 3)
	{
		s[5] += 1;
		s[5] -= 1;
	}
	if (staty == 4)
	{
		s[6] += 1;
		s[6] -= 1;
	}
	if (staty == 5)
	{
		s[7] += 1;
		s[7] -= 1;
	}
	return (*s);
}
int lvlup(int *s)
{
	rama();
	int a = 4;
	char k;
	int staty = 1;
	statywybor(staty, s, a);

	do
	{
		switch (staty)
		{
		case 1:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 2;
					statywybor(staty, s, a);
					break;
				case 72:
					staty = 5;
					statywybor(staty, s, a);
					break;

				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;


			}
			break;
		case 2:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					staty = 1;
					statywybor(staty, s, a);
					break;
				case 80:
					staty = 3;
					statywybor(staty, s, a);
					break;

				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;

			}
			break;
		case 3:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					staty = 2;
					statywybor(staty, s, a);
					break;
				case 80:
					staty = 4;
					statywybor(staty, s, a);
					break;

				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;
			}
			break;
		case 4:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 5;
					statywybor(staty, s, a);
					break;
				case 72:
					staty = 3;
					statywybor(staty, s, a);
					break;

				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;
			}
			break;

		case 5:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 1;
					statywybor(staty, s, a);
					break;
				case 72:

					staty = 4;
					statywybor(staty, s, a);
					break;

				}
				break;

			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;

				a--;
				statywybor(staty, s, a);
				break;
			}
			break;




		}
	} while (a != 0);
	Sleep(500);
	system("cls");
	return (*s);
}
void hpbar(float shp, float shpdef)
{
	gotoxy(58, 2);
	pur();
	float i = shp / shpdef * 10;
	if (i < 0)
		i == 0;
	int k = 10 - i;
	for (int j = 0; j < ceil(i); j++)
	{
		cout << " ";
	}
	gotoxy(58 + ceil(i), 2);
	for (int j = 0; j < k; j++)
	{
		blu();
		cout << " ";
	}
	def();
}
void hpbar1(int *s, float ghpmax)
{
	gotoxy(63, 20);
	bia1();
	cout << "HP:";
	gotoxy(67, 20);
	pur();
	float a = s[8];
	float i = a / ghpmax * 10;
	if (i < 0)
		i == 0;
	int k = 10 - i;
	for (int j = 0; j < ceil(i); j++)
	{
		cout << " ";
	}
	for (int j = 0; j < k; j++)
	{
		red();
		cout << " ";
	}
	def();
}
void manabar(int *s, float manamax)
{
	gotoxy(61, 23);
	bia1();
	cout << "MANA:";
	gotoxy(67, 23);
	float a = s[9];
	float i = a / manamax * 10;
	if (i < 0)
		i == 0;
	if (i > 10)
		i == 10;
	int k = 10 - i;
	for (int j = 0; j < ceil(i); j++)
	{
		blu();
		cout << " ";
		def();
	}
	for (int j = 0; j < k; j++)
	{
		red();
		cout << " ";
	}
	
	def();
	//gotoxy(77, 23); cout << "  "; red(); cout << "  "; gotoxy(0, 24); cout << "  "; gotoxy(2, 24); def(); cout << "     ";
}
void walkamenu(int g)
{
	gotoxy(77, 24);
	def(); cout << "  ";
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	bia1();
	gotoxy(7, 20);
	if (g == 1)
		blu1();
	cout << "ATAK";
	gotoxy(7, 23);
	bia1();
	if (g == 2)
		blu1();
	cout << "OBRONA";
	gotoxy(20, 20);
	bia1();
	if (g == 3)
		blu1();
	cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć");
	gotoxy(20, 23);
	bia1();
	if (g == 4)
		blu1();
	cout << "CZAR";
	gotoxy(40, 20);
	bia1();
	if (g == 5)
		blu1();
	cout << "HPOT";
	gotoxy(40, 23);
	bia1();
	if (g == 6)
		blu1();
	cout << "MPOT";
	red();
}
void czarymenu(int g)
{
	gotoxy(77, 24);
	def(); cout << "  ";
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	bia1();
	gotoxy(7, 20);
	if (g == 1)
		blu1();
	cout << "MAGICZNA STRZA"<<PL("Ł")<<"A <30MP>";
	gotoxy(7, 23);
	bia1();
	if (g == 2)
		blu1();
	cout << "PODPALENIE <20MP>";
	gotoxy(40, 20);
	bia1();
	if (g == 3)
		blu1();
	cout << "PODZIELENIE DUCHA <40MP>";
	gotoxy(40, 23);
	bia1();
	if (g == 4)
		blu1();
	cout << "ODNOWIENIE ( WYT <10>  MP <30>)";
}
int eq(int *s)
{
	s[16] = 0;
	s[17] = 0;
	s[18] = 0;
	s[19] = 0;
	s[20] = 0;
	char k;
	int d = 1;
	int a;
	int u1 = 0;
	int u2 = 0;
	int u3 = 0;
	int u4 = 0;
	int u5 = 0;
	int u21 = 0;
	int u22 = 0;
	int u23 = 0;
	int u24 = 0;
	int u25 = 0;
	system("cls");
	for (int i = 0; i < (6 + s[0]*3); i++)
	{
		a = rand() % 5 + 1;
		if (a == 1)
			u1++;
		if (a == 2)
			u2++;
		if (a == 3)
			u3++;
		if (a == 4)
			u4++;
		if (a == 5)
			u5++;
	}
	for (int i = 0; i < (6 + s[0]*3); i++)
	{
		a = rand() % 5 + 1;
		if (a == 1)
			u21++;
		if (a == 2)
			u22++;
		if (a == 3)
			u23++;
		if (a == 4)
			u24++;
		if (a == 5)
			u25++;
	}
	rama();
	for (int i = 4; i < 25; i++)
	{
		Beep(60, 40);
		gotoxy(40, i);
		pur();
		cout << "  ";
		def();
	}
	gotoxy(29, 1);
	pur(); cout << " "; def();
	gotoxy(29, 2);
	pur(); cout << " "; def();
	gotoxy(29, 3);
	pur(); cout << " "; def();
	gotoxy(53, 1);
	pur(); cout << " "; def();
	gotoxy(53, 2);
	pur(); cout << " "; def();
	gotoxy(53, 3);
	pur(); cout << " "; def();
	gotoxy(29, 4);
	pur(); cout << "                         "; def();
	gotoxy(12, 4);
	bia1();
	cout << "BRO" << PL("Ń") << " NR 1";
		gotoxy(60, 4);
	bia1();
	cout << "BRO" << PL("Ń") << " NR 2";
	gotoxy(31, 2);
	bia1();
	cout << "W Y B I E R Z   D A R";
	gotoxy(6, 7);
	cout << "S I " << PL("Ł") << " A" << " < " << u1 << " >";
	bia1();
	gotoxy(6, 10);
	cout << "Z R " << PL("Ę") << " C Z N O " << PL("Ś") << " " << PL("Ć") << " < " << u2 << " >";
	bia1();
	gotoxy(6, 13);
	cout << "W Y T R Z Y M A " << PL("Ł") << " O " << PL("Ś") << " " << PL("Ć") << " < " << u3 << " >";
	bia1();
	gotoxy(6, 16);
	cout << "M A G I A" << " < " <<u4 << " >";
	bia1();
	gotoxy(6, 19);
	cout << "S Z C Z " << PL("Ę") << " " << PL("Ś") << " C I E" << " < " << u5 << " >";


	gotoxy(46, 7);
	cout << "S I " << PL("Ł") << " A" << " < " << u21 << " >";
	bia1();
	gotoxy(46, 10);
	cout << "Z R " << PL("Ę") << " C Z N O " << PL("Ś") << " " << PL("Ć") << " < " << u22 << " >";
	bia1();
	gotoxy(46, 13);
	cout << "W Y T R Z Y M A " << PL("Ł") << " O " << PL("Ś") << " " << PL("Ć") << " < " << u23 << " >";
	bia1();
	gotoxy(46, 16);
	cout << "M A G I A" << " < " << u24 << " >";
	bia1();
	gotoxy(46, 19);
	cout << "S Z C Z " << PL("Ę") << " " << PL("Ś") << " C I E" << " < " << u25 << " >";
	gotoxy(14, 22);
	blu1();
	cout << "W Y B I E R A M";
	def();
	do
	{
		switch (d)
		{
		case 1:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 77:
					d = 2;
					
					break;
				}
				break;
			}
			break;
		case 2:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 75:
					d = 1;

					break;
				}
				break;
			}
			break;

		}
		gotoxy(14, 22);
		cout << "                ";
		gotoxy(52, 22);
		cout << "                ";
		if (d == 1)
		{
			gotoxy(14, 22);
			blu1();
			cout << "W Y B I E R A M";
			def();
		}
		if (d == 2)
		{
			gotoxy(52, 22);
			blu1();
			cout << "W Y B I E R A M";
			def();
		}
	} while (k != 13);
	if (d == 1)
	{
		s[16] += u1;
		s[17] += u2;
		s[18] += u3;
		s[19] += u4;
		s[20] += u5;
	}
	if (d == 2)
	{
		s[16] += u21;
		s[17] += u22;
		s[18] += u23;
		s[19] += u24;
		s[20] += u25;
	}

	Sleep(500);
	return (*s);
}
void gracz(int *s)
{
	gotoxy(22, 17); zie(); cout << "                 "; def();
	gotoxy(23, 16); zie(); cout << " "; zlo1(); cout << "            "; zie(); cout << "  "; def();
	gotoxy(24, 15); zlo1(); cout << "             "; def();
	gotoxy(25, 14); zlo1(); cout << "            "; def();
	gotoxy(26, 13); zlo1(); cout << "          "; def();
	gotoxy(27, 12); zlo1(); cout << "         "; def();
	gotoxy(28, 11); zlo1(); cout << "       "; def();
	if (s[1] == 1)
	{
		gotoxy(40, 12); bia(); cout << "  "; def();
		gotoxy(39, 13); bia(); cout << "   "; def();
		gotoxy(38, 14); bia(); cout << "   "; def();
		gotoxy(37, 15); bia(); cout << "   "; def();
		gotoxy(37, 16); bia(); cout << " "; def(); blu(); cout << " "; bia(); cout << " "; def();
		gotoxy(38, 17); bia(); cout << "   "; def();
	}
	if (s[1] == 2)
	{
		gotoxy(36, 11); dark(); cout << " "; def();
		gotoxy(37, 12); dark(); cout << " "; def();
		gotoxy(38, 13); dark(); cout << " "; def();
		gotoxy(38, 14); dark(); cout << "  "; def();
		gotoxy(37, 15); bia(); cout << "  "; dark(); cout << " "; bia(); cout << "   "; def();
		gotoxy(38, 16); dark(); cout << "  "; def();
		gotoxy(38, 17); dark(); cout << " "; def();
	}
	if (s[1] == 3)
	{
		gotoxy(36, 12); pur(); cout << "        "; def();
		for (int i = 13; i < 17; i++)
		{
			gotoxy(37, i); pur(); cout << " "; red(); cout << "    "; pur(); cout << " "; def();
		}
		gotoxy(38, 17); pur(); cout << "    "; def();
	}
	if (s[1] == 4)
	{
		gotoxy(37, 10); dark(); cout << "   "; def();
		for (int i = 11; i < 14; i++)
		{
			gotoxy(36, i); dark(); cout << " "; redintens1(); cout << "   "; dark(); cout << " "; def();
		}
		gotoxy(37, 14); dark(); cout << "   "; def();
		for (int i = 15; i < 18; i++)
		{
			gotoxy(38, i);
			dark(); cout << " "; def();
		}
	}
	if (s[1] == 5)
	{
		gotoxy(38, 11); bia(); cout << " "; def();
		gotoxy(37, 12); bia(); cout << "  "; def();
		gotoxy(36, 13); bia(); cout << "  "; def(); gotoxy(40, 13); bia(); cout << " "; def();
		gotoxy(39, 14); bia(); cout << "  "; def();
		gotoxy(38, 15); bia(); cout << "  "; def();
		gotoxy(37, 16); bia(); cout << "  "; def();
	}
}
void skrzynia(int kasa)
{
	gotoxy(49, 1);
	zlo1(); cout << "    ";
	gotoxy(48, 2);
	zlo1(); cout << "      ";
	gotoxy(45, 3);
	zlo1(); cout << " ";
	gotoxy(47, 3);
	zlo1(); cout << "         ";
	gotoxy(44, 4);
	red(); cout << "  "; pur(); cout << "      "; pur(); cout << "    "; red(); cout << "  "; def();
	gotoxy(44, 5);
	red(); cout << "  "; pur(); cout << "      "; pur(); cout << "    "; red(); cout << "  "; def();
	gotoxy(44, 6);
	red(); cout << "  "; pur(); cout << "      "; pur(); cout << "    "; red(); cout << "  "; def();
	gotoxy(40, 7);
	zlo1(); cout << "  ";
	gotoxy(44, 7);
	red(); cout << "              "; def(); cout << " "; zlo1(); cout << " "; def();
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	gotoxy(10, 21);
	bia1();
	cout << "ODNALAZ"<<PL("Ł")<<"E"<<PL("Ś")<<" KUFER PE"<<PL("Ł")<<"EN Z"<<PL("Ł")<<"OTA!";
	gotoxy(10, 23);
	bia1();
	cout <<  "Z" << PL("Ł") << "OTO + " << kasa ;
	Sleep(2100);
}
void sklepmenu(int g, int *s)
{
	gotoxy(48, 1);
	pur(); cout << "   "; def(); cout << "   "; blu(); cout << "   ";
	gotoxy(49, 2); pur(); cout << " "; def(); cout << "     "; blu(); cout << " ";
	gotoxy(47, 3);
	pur(); cout << "     "; def(); cout << " "; blu(); cout << "     ";
	gotoxy(45, 4);
	zlo1(); cout << "               ";
	gotoxy(45, 5);
	zlo1(); cout << "               ";
	gotoxy(45, 6);
	zlo1(); cout << "               ";
	gotoxy(59, 7);
	zlo1(); cout << " ";
	gotoxy(59, 8);
	zlo1(); cout << " ";
	gotoxy(45, 7);
	zlo1(); cout << " ";
	gotoxy(45, 8);
	zlo1(); cout << " ";
	gotoxy(47, 4);
	pur(); cout << "     "; zlo1(); cout << " "; blu(); cout << "     ";
	gotoxy(47, 5);
	pur(); cout << "     "; zlo1(); cout << " "; blu(); cout << "     "; def();
	gotoxy(77, 24);
	def(); cout << "  ";
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	bia1();
	gotoxy(7, 20);
	if (g == 1)
		blu1();
	cout << "KUP HPOT - 1500";
	gotoxy(7, 23);
	bia1();
	if (g == 2)
		blu1();
	cout << "KUP MPOT - 500";
	gotoxy(30, 20);
	bia1();
	if (g == 3)
		blu1();
	cout << "WYLECZENIE - 10 ZA PUNKT";
	gotoxy(30, 23);
	bia1();
	if (g == 4)
		blu1();
	cout << "KUP LOSOW" << PL("Ą") << " STATYSTYK" << PL("Ę")<<" -4000";
	bia1();
	gotoxy(65, 20);
	cout << "<ESC>-KONIEC";
	gotoxy(65, 22);
	cout << "HP: "<<s[8];
	gotoxy(65, 23);
	cout << "KASA: "<<s[12];
		red();
}
int sklep(int *s)
{
	int v = 0;
	char k;
	int g = 1;
	sklepmenu(g,s);
	do
	{
		sklepmenu(g, s);
		do
		{
			switch (g)
			{
			case 1:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						sklepmenu(g, s);
						break;
					case 72:
						g = 1;
						sklepmenu(g, s);
						break;
					case 75:
						g = 1;
						sklepmenu(g, s);
						break;
					case 77:
						g = 3;
						sklepmenu(g, s);
						break;
					}
					break;
				case 27:
					return(*s);
					break;
				}
				break;
			case 2:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						sklepmenu(g, s);
						break;
					case 72:
						g = 1;
						sklepmenu(g, s);
						break;
					case 75:
						g = 2;
						sklepmenu(g, s);
						break;
					case 77:
						g = 4;
						sklepmenu(g, s);
						break;
					
					}
					break;
				case 27:
					return(*s);
					break;
				}
				break;
			case 3:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						sklepmenu(g, s);
						break;
					case 72:
						g = 3;
						sklepmenu(g, s);
						break;
					case 75:
						g = 1;
						sklepmenu(g, s);
						break;
					}
					break;
				case 27:
					return(*s);
					break;
				}
				break;
			case 4:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						sklepmenu(g, s);
						break;
					case 72:
						g = 3;
						sklepmenu(g, s);
						break;
					case 75:
						g = 2;
						sklepmenu(g, s);
						break;
					
					}
					break;
				case 27:
					return(*s);
					break;
				}
				break;
			}
		} while (k != 13);
		if (g == 1)
		{
			if (s[12] >= 1500)
			{
				s[12] -= 1500;
				s[10]++;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				gotoxy(10, 21);
				bia1();
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O KASY!!";
				Sleep(800);
			}
		}
		if (g == 2)
		{
			if (s[12] >= 500)
			{
				s[12] -= 500;
				s[11]++;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				gotoxy(10, 21);
				bia1();
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O KASY!!";
				Sleep(800);
			}
		}
		if (g == 3)
		{
			int hpmax = 100 + s[5] * 10 + s[18] * 10;
			if (s[8] < hpmax)
			{
				do
				{
					if (s[12] >= 10)
					{
						s[8] += 1;
						s[12] -= 10;
					}
					

				} while (s[8]<hpmax && s[12]>9);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				gotoxy(10, 21);
				bia1();
				cout << "HP 100%";
				Sleep(800);
			}
		}
		if (g == 4)
		{
			if (s[12] >= 4000)
			{
				int ls = rand() % 5 + 3;
				s[ls]++;
				s[12] -= 4000;
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				gotoxy(10, 21);
				bia1();
				cout << "DODANO +1 W "; 
				if (s[ls] == 3)cout << "SI" << PL("Ł") << "E!!"; 
				if (s[ls] == 4)cout << "ZR" << PL("Ę") << "CZNO" << PL("Ś") << PL("Ć")<<"!!"; 
				if (s[ls] == 5)cout << "WYTRZYMA" << PL("Ł") << "O" << PL("Ś") << PL("Ć")<<"!!"; 
				if (s[ls] == 6)cout << "MAGI" << PL("Ę")<<"!!"; 
				if (s[ls] == 7)cout << "SZCZ" << PL("Ę") << PL("Ś") << "CIE!! ";
				Sleep(1500);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				gotoxy(10, 21);
				bia1();
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O KASY!!";
				Sleep(800);
			}
		}

	}while (v != 1);
	return (*s);
}
int boss(int *s,float ghpmax, float manamax)
{
	int podpal = 0;
	float shpdef = 300 + s[0] * 100 - 100;
	float shp = 300 + s[0] * 100 - 100;
	char k;
	int special = 1;
	int atk;
	int unik;
	int kryt;
	int g = 1;
	int load = 0;
	int satk;
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	//gotoxy(77, 24);
	//def();
	//cout << "  ";
	//gotoxy(80, 25);
	//red();
	//cout << "    ";
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	def();
	gotoxy(48, 0);
	zlo1(); cout << " "; redintens1(); cout << " "; zlo1(); cout << " "; redintens1(); cout << " "; zlo1(); cout << " "; def();
	gotoxy(48, 1);
	blu(); cout << "     "; def();
	gotoxy(46, 2);
	pur(); cout << " "; red(); cout << " "; pur(); cout << " "; blu(); cout << "   "; pur(); cout << "   "; def();
	gotoxy(44, 3);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << " "; red(); cout << " "; pur(); cout << " "; blu(); cout << " "; pur(); cout << "   "; def(); cout << " "; pur(); cout << "  "; def();
	gotoxy(44, 4);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; red(); cout << " "; pur(); cout << "    "; def(); cout << " "; pur(); cout << "  "; def();
	gotoxy(44, 5);
	pur(); cout << "  "; def(); cout << "  "; pur(); cout << "  "; red(); cout << " "; pur(); cout << "  "; def(); cout << "  "; pur(); cout << "  "; def();
	gotoxy(43, 6);
	zlo1(); cout << "    "; def(); cout << " "; pur(); cout << "   "; red(); cout << " "; pur(); cout << " "; def(); cout << " "; zlo1(); cout << "    "; def();
	gotoxy(43, 7);
	zlo1(); cout << "    "; def(); cout << " "; pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def(); cout << " "; zlo1(); cout << "    "; def();
	gotoxy(48, 8);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def();
	gotoxy(48, 9);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def();
	def();
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	def();
	bia1();
	gotoxy(7, 20);
	cout << "ATAK";
	gotoxy(7, 23);
	cout << "OBRONA";
	gotoxy(20, 20);
	cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć");
	gotoxy(20, 23);
	cout << "CZAR";
	gotoxy(40, 20);
	cout << "HPOT";
	gotoxy(40, 23);
	cout << "MPOT";
	red();
	for (int i = 19; i < 25; i++)
	{
		gotoxy(52, i);
		cout << "  ";
	}
	def();
	//gracz(s);
	do
	{
		walkamenu(g);
		hpbar(shp, shpdef);
		hpbar1(s, ghpmax);
		manabar(s, manamax);
		def();
		do
		{
			switch (g)
			{
			case 1:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			case 2:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			case 3:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			case 4:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			case 5:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			case 6:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 75:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						def();
						break;
					}
					break;

				}
				break;
			}
		} while (k != 13);
		unik = rand() % (100 / (s[4] + s[17])) + 1;
		kryt = rand() % (100 / (s[7] + s[20])) + 1;
		if (g == 1)
		{
			satk = 30 + s[0] * 5 + (rand() % 10 - 5);
			if (s[1] == 1)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
				}

			}
			if (s[1] == 2)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 3)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 4)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 5)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
				}
			}

			
			

				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
			gotoxy(4, 20);
			bia1();
			cout << "ZADAJESZ WIELKIEMU SZEFOWI "; if (kryt == 1)cout << "KRYTYCZNIE!"; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
			if (unik != 1 && shp>0)
			{
				if (load == 3)
				{
					gotoxy(4, 22);
					cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					s[8] -= satk;
					if (shp < 0)
						shp = 0;
					load = 0;
				}
				if (load < 3)
					load++;
				
			}
			if (unik == 1)
			{
				gotoxy(4, 22);
				cout << "UNIKASZ ATAKU!";
			}
			if (shp > 0)
				Sleep(1000);
		}
		if (g == 2)
		{
			if (s[9] >= 2)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				s[9] -= 2;
				s[8] += 8 + s[6] * 0.5;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				bia1();
				gotoxy(4, 20);
				cout << "BRONISZ SI" << PL("Ę") << " I REGENERUJESZ ZDROWIE!";
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O ENERGI!";
				Sleep(1000);
			}
		}
		if (g == 3)
		{
			satk = 30 + s[0] * 5 + (rand() % 10 - 5);
			if (special == 1)
			{
				if (s[1] == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - SILNY CIOS!";
					gotoxy(4, 21);
					cout << "ATAK X2!";

				
					
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (load == 3)
					{
						if (shp > 0)
							s[8] -= satk;
						if (shp < 0)
							shp = 0;
						gotoxy(4, 23);
						cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						load = 0;
					}
					if (load < 3)
						load++;
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 2)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3))*1.7;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 + -3))*1.7;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ELITARNY STRZELEC!";
					gotoxy(4, 21);
					cout << "ATAK X1.7 + UNIKASZ ATAKU!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (load < 3)
						load++;
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 3)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - BOSKA CHWA" << PL("Ł") << "A !";
					gotoxy(4, 21);
					cout << "ATAK X1.5 + LECZENIE!";
					s[8] += 10 + s[0] * 8;
				
					
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (load == 3)
					{
						if (shp > 0)
							s[8] -= satk;
						if (shp < 0)
							shp = 0;
						gotoxy(4, 23);
						cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						load = 0;
					}
					if (load < 3)
						load++;
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 4)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ARMAGEDON!";
					gotoxy(4, 21);
					cout << "OBOSTRONNY CHAOS!";
					s[8] -= satk;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ARMAGEDON RANI WIELKIEGO SZEFA ZA "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ARMAGEDON RANI CIE ZA "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (load < 3)
						load++;
					if (shp > 0)
						Sleep(3000);
				}
				if (s[1] == 5)
				{

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - GRAD OSTRZY!";
					gotoxy(4, 21);
					cout << "ATAK SZTYLET X7";
					for (int i = 0; i < 7; i++)
					{
						shp -= (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						atk = (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						if (i % 2 == 0)
							gotoxy(4, 22);
						if (i % 2 != 0)
							gotoxy(4, 23);
						bia1();
						cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						Sleep(300);
					}
					if (load == 3)
					{
						if (shp < 0)
							shp = 0;
						if (shp > 0)
							s[8] -= satk;
						gotoxy(4, 23);
						cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					}
					if (load < 3);
					load++;
					
					if (shp > 0)
						Sleep(2000);
				}
				special -= 1;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć") << " WYKORZYSTANA!";
				Sleep(1000);
			}
		}
		if (g == 4)
		{

			if (g == 4)
			{

				int v = 0;
				char k;
				int g = 1;
				czarymenu(g);
				do
				{
					czarymenu(g);
					do
					{
						switch (g)
						{
						case 1:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								case 77:
									g = 3;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 2:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;
								case 77:
									g = 4;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 3:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 4:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						}
					} while (k != 13 && v != 1);
					v = 1;
					if (g == 1 && k != 27)
					{
						satk = 30 + s[0] * 5 + (rand() % 10 - 5);
						if (s[9] >= 30)
						{
							shp -= 6 * s[6] + 6*s[19];
							atk = 6 * s[6] + 6 * s[19];
							s[9] -= 30;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - MAGICZNA STRZA" << PL("Ł") << "A!";

							if (shp < 0)
								shp = 0;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (load == 3 && shp > 0)
							{
								s[8] -= satk;
								gotoxy(4, 23);
								cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							}
							if (load < 3)
								load++;
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 2 && k != 27)
					{
						satk = 30 + s[0] * 5 + (rand() % 10 - 5);
						if (s[9] >= 20)
						{
							s[9] -= 20;
							podpal++;
							shp -= 1 * s[6] + 1 * s[19];
							atk = 1 * s[6] + 1 *s[19];

							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODPALENIE!";
							gotoxy(4, 21);
							cout << "OBRA" << PL("Ż") << "EIA CZASOWE! (MO" << PL("Ż") << "LIWY STACK)";

							if (shp < 0)
								shp = 0;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (load == 3 && shp > 0)
							{
								s[8] -= satk;
								gotoxy(4, 23);
								cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							}
							if (load < 3)
								load++;
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 3 && k != 27)
					{
						satk = 30 + s[0] * 5 + (rand() % 10 - 5);
						if (s[9] >= 40)
						{
							shp -= shpdef * 4 / 10;
							atk = shpdef * 4 / 10;
							s[9] -= 40;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODZIELENIE DUCHA!";
							gotoxy(4, 21);
							cout << "HP WROGA -40% MAXYMALNEGO";
							if (shp < 0)
								shp = 0;
							
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ WIELKIEMU SZEFOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (load == 3 && shp>0)
							{
									s[8] -= satk;
								gotoxy(4, 23);
								cout << "WIELKI SZEF ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							}
							if (load < 3)
								load++;
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 4 && k != 27)
					{
						if (s[9] >= 30 && s[5] >= 10)
						{
							s[9] -= 30;
							s[8] += ghpmax * 35 / 100;
							if (s[8] > ghpmax)
								s[8] = ghpmax;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - ODNOWIENIE!";
							gotoxy(4, 21);
							cout << "HP +35%!";
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE POSIADASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MP LUB WYTRZYM!!";
							Sleep(800);
						}
					}

				} while (v != 1);


			}


		}
		if (g == 5 && s[8] < ghpmax)
		{
			if (s[10] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO HP POTION!";
				s[10] -= 1;
				s[8] += 50;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK HP!";
				Sleep(1000);
			}
		}
		if (g == 6 && s[9] < manamax)
		{
			if (s[11] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO MP POTION!";
				s[11] -= 1;
				s[9] += 20;
				if (s[9] > manamax)
					s[9] = manamax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK MP!";
				Sleep(1000);
			}
		}
		for (int i = 0; i < podpal; i++)
		{
			shp -= 1 * s[6];
		}
	} while (shp > 0 && s[8] > 0);

	if (s[8] > 0)
	{
		graf();
		gracz(s);
		s[15] += 3000+s[0]*100;
		s[12] += 1500+s[0]*150;
		gotoxy(4, 20);
		bia1();
		cout << "POKONANO WIELKIEGO SZEFA!";
		gotoxy(4, 22);
		cout << "EXP + " << 3000+s[0]*100 << " !";
		gotoxy(4, 23);
		cout << "KASA + "<< 1500 + s[0] * 150<<" !";
	}

	Sleep(1500);
	for (int i = 16; i < 77; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	system("cls");
	return (*s);
}
int szkielet(int *s, float ghpmax, float manamax)
{
	int podpal = 0;
	float shpdef = 100 + s[0] * 15;
	float shp = 100 + s[0] * 15;
	char k;
	int special = 1;
	int atk;
	int unik;
	int kryt;
	int g = 1;
	int satk;
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	//gotoxy(79, 24);
	//red();
	//cout << "  ";
	//gotoxy(80, 25);
	//red();
	//cout << "    ";
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
		gotoxy(51, 0);
	red(); cout << "   ";
	gotoxy(50, 1);
	red(); cout << " "; redintens1(); cout << " "; red(); cout << " ";  redintens1(); cout << " "; red(); cout << " ";
	gotoxy(51, 2);
	red(); cout << "   ";
	gotoxy(50, 3);
	red(); cout << " "; def(); cout << " "; red(); cout << " "; def(); cout << " "; red(); cout << " ";
	gotoxy(49, 4);
	red(); cout << " "; def(); cout << " "; red(); cout << "   "; def(); cout << " "; red(); cout << " ";
	gotoxy(49, 5);
	red(); cout << " "; def(); cout << "  "; red(); cout << " "; def(); cout << "  "; red(); cout << " ";
	gotoxy(49, 6);
	red(); cout << " "; def(); cout << " "; red(); cout << "   "; def(); cout << " "; red(); cout << " ";
	gotoxy(51, 7);
	red(); cout << " "; def(); cout << " "; red(); cout << " ";
	gotoxy(50, 8);
	red(); cout << "  "; def(); cout << " "; red(); cout << "  ";
	def();
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	bia1();
	gotoxy(7, 20);
	cout << "ATAK";
	gotoxy(7, 23);
	cout << "OBRONA";
	gotoxy(20, 20);
	cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć");
	gotoxy(20, 23);
	cout << "CZAR";
	gotoxy(40, 20);
	cout << "HPOT";
	gotoxy(40, 23);
	cout << "MPOT";
	red();
	for (int i = 19; i < 25; i++)
	{
		gotoxy(52, i);
		cout << "  ";
	}
	def();
	//gracz(s);
	do
	{
		
		walkamenu(g);
		hpbar(shp, shpdef);
		hpbar1(s, ghpmax);
		manabar(s, manamax);
		do
		{
			switch (g)
			{
			case 1:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 2:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 3:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 4:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 5:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 6:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			}
		} while (k != 13);
		unik = rand() % (100 / (s[4] + s[17])) + 1;
		kryt = rand() % (100 / (s[7] + s[20])) + 1;
		if (g == 1)
		{
			satk = 5 + s[0] * 2 + (rand() % 7 - 3);
			if (s[1] == 1)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3))*2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3))*2;
				}
				
			}	
			if (s[1] == 2)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 3)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 4)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 5)
			{
				if (kryt !=1)
				{
					shp -= 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			
			if (shp < 0)
				shp = 0;
			if (shp > 0)
			
			for (int i = 2; i < 78; i++)
			{
				for (int j = 19; j < 25; j++)
				{
					gotoxy(i, j);
					def(); cout << " ";
				}
			}
			gotoxy(4, 20);
			bia1();
			cout << "ZADAJESZ SZKIELETOWI "; if (kryt == 1)cout << "KRYTYCZNIE!"; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
			if (unik != 1 && shp>0)
			{
				gotoxy(4, 22);
				cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
				s[8] -= satk;
			}
			if (unik == 1)
			{
				gotoxy(4, 22);
				cout << "UNIKASZ ATAKU!";
		}
			if(shp>0)
			Sleep(1000);
		}
		if (g == 2)
		{
			if (s[9] >= 2)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				s[9] -= 2;
				s[8] += 8 + s[6]*0.5;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				bia1();
				gotoxy(4, 20);
				cout << "BRONISZ SI" << PL("Ę") << " I REGENERUJESZ ZDROWIE!";
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WYSTARCZAJ"<<PL("Ą")<<"CO DU"<<PL("Ż")<<"O ENERGI!";
				Sleep(1000);
			}
		}
		if (g == 3)
		{
			satk = 5 + s[0] * 2 + (rand() % 7 - 3);
			if (special == 1)
			{
				if (s[1] == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3))*2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) *2;

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - SILNY CIOS!";
					gotoxy(4, 21);
					cout << "ATAK X2!";
					
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					Sleep(2000);
				}
				if (s[1] == 2)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3))*1.7;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 + -3))*1.7;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ELITARNY STRZELEC!";
					gotoxy(4, 21);
					cout << "ATAK X1.7 + UNIKASZ ATAKU!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					Sleep(2000);
				}
				if (s[1] == 3)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - BOSKA CHWA"<<PL("Ł")<<"A !";
					gotoxy(4, 21);
					cout << "ATAK X1.5 + LECZENIE!";
					s[8] += 10 + s[0] * 8;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					Sleep(2000);
				}
				if (s[1] == 4)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3))*5;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3))*5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ARMAGEDON!";
					gotoxy(4, 21);
					cout << "OBOSTRONNY CHAOS!";
					s[8] -= satk*4;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
					gotoxy(4, 22);
					bia1();
					cout << "ARMAGEDON RANI SZKIELETA ZA "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ARMAGEDON RANI CIE ZA "; redintens(); cout << satk*4; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					Sleep(3000);
				}
				if (s[1] == 5)
				{
					
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - GRAD OSTRZY!";
					gotoxy(4, 21);
					cout << "ATAK SZTYLET X7";
					for (int i = 0; i < 7; i++)
					{
						shp -= (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						atk = (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						if(i%2==0)
						gotoxy(4, 22);
						if (i % 2 != 0)
							gotoxy(4, 23);
						bia1();
						cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						Sleep(300);
					}
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 23);
					cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
					Sleep(2000);
				}
				special -= 1;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "UMIEJ"<<PL("Ę")<<"TNO"<<PL("Ś")<<PL("Ć")<<" WYKORZYSTANA!";
				Sleep(1000);
			}
		}
		if (g == 4)
		{
			if (g == 4)
			{

				int v = 0;
				char k;
				int g = 1;
				czarymenu(g);
				do
				{
					czarymenu(g);
					do
					{
						switch (g)
						{
						case 1:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								case 77:
									g = 3;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 2:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;
								case 77:
									g = 4;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 3:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 4:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						}
					} while (k != 13 && v != 1);
					v = 1;
					if (g == 1 && k != 27)
					{
						satk = 5 + s[0] * 2 + (rand() % 7 - 3);
						if (s[9] >= 30)
						{
							shp -= 6 * s[6] + 6 * s[19];
							atk = 6 * s[6] + 6 * s[19];
							s[9] -= 30;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - MAGICZNA STRZA" << PL("Ł") << "A!";

							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 2 && k != 27)
					{
						satk = 5 + s[0] * 2 + (rand() % 7 - 3);
						if (s[9] >= 20)
						{
							s[9] -= 20;
							podpal++;
							shp -= 1 * s[6] + 1 * s[19];
							atk = 1 * s[6] + 1 * s[19];

							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODPALENIE!";
							gotoxy(4, 21);
							cout << "OBRA" << PL("Ż") << "EIA CZASOWE! (MO" << PL("Ż") << "LIWY STACK)";

							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 3 && k != 27)
					{
						satk = 5 + s[0] * 2 + (rand() % 7 - 3);
						if (s[9] >= 40)
						{
							shp -= shpdef * 4 / 10;
							atk = shpdef * 4 / 10;
							s[9] -= 40;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODZIELENIE DUCHA!";
							gotoxy(4, 21);
							cout << "HP WROGA -40% MAXYMALNEGO";
							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ SZKIELETOWI "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "SZKIELET ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 4 && k != 27)
					{
						if (s[9] >= 30 && s[5] >= 10)
						{
							s[9] -= 30;
							s[8] += ghpmax * 35 / 100;
							if (s[8] > ghpmax)
								s[8] = ghpmax;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - ODNOWIENIE!";
							gotoxy(4, 21);
							cout << "HP +35%!";
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE POSIADASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MP LUB WYTRZYM!!";
							Sleep(800);
						}
					}

				} while (v != 1);


			}



		}
		if (g == 5 && s[8] < ghpmax)
		{
			if (s[10] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO HP POTION!";
				s[10] -= 1;
				s[8] += 50;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI"<<PL("Ę")<<"CEJ POTEK HP!";
				Sleep(1000);
			}
		}
		if (g == 6 && s[9] < manamax)
		{
			if (s[11] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO MP POTION!";
				s[11] -= 1;
				s[9] += 20;
				if (s[9] > manamax)
					s[9] = manamax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK MP!";
				Sleep(1000);
			}
		}
		for (int i = 0; i < podpal; i++)
		{
			shp -= 1 * s[6];
		}
	} while (shp > 0 && s[8] > 0);
	
	if (s[8] > 0)
	{
		graf();
		gracz(s);
		s[15] += 400 + s[0] * 100;
		s[12] += 700 + s[0] * 150;
		gotoxy(4, 20);
		bia1();
		cout << "POKONANO SZKIELETA!";
		gotoxy(4, 22);
		cout << "EXP + " << 400 + s[0] * 100 << "!";
		gotoxy(4, 23);
		cout << "KASA + " << 700 + s[0] * 150 << "!";
	}
	
	Sleep(1500);
	for (int i = 16; i < 77; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	system("cls");
	return (*s);
}
int zombie(int *s, float ghpmax, float manamax)
{
	float shpdef = 120 + s[0] * 35;
	float shp = 120 + s[0] * 35;
	char k;
	int special = 1;
	int atk;
	int unik;
	int podpal = 0;
	int kryt;
	int g = 1;
	int satk;
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	//gotoxy(79, 24);
	//red();
	//cout << "  ";
	//gotoxy(80, 25);
	//red();
	//cout << "    ";
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	gotoxy(48, 1);
	zie(); cout << "     "; def();
	gotoxy(48, 2);
	zie(); cout << " "; def(); cout << " "; zie(); cout << " "; def(); cout << " "; zie(); cout << " "; def();
	gotoxy(48, 3);
	zie(); cout << "     "; def();
	gotoxy(46, 4);
	dark(); cout << "   "; redintens1(); cout << " "; dark(); cout << "     "; def();
	gotoxy(46, 5);
	dark(); cout << "    "; redintens1(); cout << "  "; dark(); cout << "   "; def();
	gotoxy(46, 6);
	dark(); cout << "  "; zie(); cout << " "; dark(); cout << "      "; def();
	gotoxy(46, 7);
	zie(); cout << "  "; pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; zie(); cout << "  "; def();
	gotoxy(48, 8);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def();
	gotoxy(48, 9);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def();
	gotoxy(48, 10);
	pur(); cout << "  "; def(); cout << " "; pur(); cout << "  "; def();
	def();
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	bia1();
	gotoxy(7, 20);
	cout << "ATAK";
	gotoxy(7, 23);
	cout << "OBRONA";
	gotoxy(20, 20);
	cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć");
	gotoxy(20, 23);
	cout << "CZAR";
	gotoxy(40, 20);
	cout << "HPOT";
	gotoxy(40, 23);
	cout << "MPOT";
	red();
	for (int i = 19; i < 25; i++)
	{
		gotoxy(52, i);
		cout << "  ";
	}
	def();
	//gracz(s);
	do
	{

		walkamenu(g);
		hpbar(shp, shpdef);
		hpbar1(s, ghpmax);
		manabar(s, manamax);
		do
		{
			switch (g)
			{
			case 1:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 2:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 3:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 4:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 5:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 6:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			}
		} while (k != 13);
		unik = rand() % (100 / (s[4]+s[17])) + 1;
		kryt = rand() % (100 / (s[7]+s[20])) + 1;
		if (g == 1)
		{
			satk = 4 + s[0] * 1 + (rand() % 7 - 3);
			if (s[1] == 1)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
				}

			}
			if (s[1] == 2)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 3)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 4)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 5)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
				}
			}

			if (shp < 0)
				shp = 0;
			if (shp > 0)

				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
			gotoxy(4, 20);
			bia1();
			cout << "ZADAJESZ ZOMBIE "; if (kryt == 1)cout << "KRYTYCZNIE!"; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
			if (unik != 1 && shp>0)
			{
				gotoxy(4, 22);
				cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
				s[8] -= satk;
			}
			if (unik == 1)
			{
				gotoxy(4, 22);
				cout << "UNIKASZ ATAKU!";
			}
			if (shp > 0)
				Sleep(1000);
		}
		if (g == 2)
		{
			if (s[9] >= 2)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				s[9] -= 2;
				s[8] += 8 + s[6] * 0.5;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				bia1();
				gotoxy(4, 20);
				cout << "BRONISZ SI" << PL("Ę") << " I REGENERUJESZ ZDROWIE!";
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O ENERGI!";
				Sleep(1000);
			}
		}
		if (g == 3)
		{
			satk = 4 + s[0] * 1 + (rand() % 7 - 3);
			if (special == 1)
			{
				if (s[1] == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - SILNY CIOS!";
					gotoxy(4, 21);
					cout << "ATAK X2!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 2)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3))*1.7;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 + -3))*1.7;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ELITARNY STRZELEC!";
					gotoxy(4, 21);
					cout << "ATAK X1.7 + UNIKASZ ATAKU!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 3)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - BOSKA CHWA" << PL("Ł") << "A !";
					gotoxy(4, 21);
					cout << "ATAK X1.5 + LECZENIE!";
					s[8] += 10 + s[0] * 8;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 4)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ARMAGEDON!";
					gotoxy(4, 21);
					cout << "OBOSTRONNY CHAOS!";
					s[8] -= satk * 4;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ARMAGEDON RANI ZOMBIE ZA "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ARMAGEDON RANI CIE ZA "; redintens(); cout << satk * 4; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(3000);
				}
				if (s[1] == 5)
				{

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - GRAD OSTRZY!";
					gotoxy(4, 21);
					cout << "ATAK SZTYLET X7";
					for (int i = 0; i < 7; i++)
					{
						shp -= (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						atk = (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						if (i % 2 == 0)
							gotoxy(4, 22);
						if (i % 2 != 0)
							gotoxy(4, 23);
						bia1();
						cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						Sleep(300);
					}
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 23);
					cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				special -= 1;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć") << " WYKORZYSTANA!";
				Sleep(1000);
			}
		}
		if (g == 4)
		{

			int v = 0;
			char k;
			int g = 1;
			czarymenu(g);
			do
			{
				czarymenu(g);
				do
				{
					switch (g)
					{
					case 1:
						k = _getch();
						switch (k)
						{
						case -32:
							k = _getch();
							switch (k)
							{
							case 80:
								g = 2;
								czarymenu(g);
								break;
							case 72:
								g = 1;
								czarymenu(g);
								break;
							case 75:
								g = 1;
								czarymenu(g);
								break;
							case 77:
								g = 3;
								czarymenu(g);
								break;
							}
							break;
						case 27:
							v = 1;
							break;
						}
						break;
					case 2:
						k = _getch();
						switch (k)
						{
						case -32:
							k = _getch();
							switch (k)
							{
							case 80:
								g = 2;
								czarymenu(g);
								break;
							case 72:
								g = 1;
								czarymenu(g);
								break;
							case 75:
								g = 2;
								czarymenu(g);
								break;
							case 77:
								g = 4;
								czarymenu(g);
								break;

							}
							break;
						case 27:
							v = 1;
							break;
						}
						break;
					case 3:
						k = _getch();
						switch (k)
						{
						case -32:
							k = _getch();
							switch (k)
							{
							case 80:
								g = 4;
								czarymenu(g);
								break;
							case 72:
								g = 3;
								czarymenu(g);
								break;
							case 75:
								g = 1;
								czarymenu(g);
								break;
							}
							break;
						case 27:
							v = 1;
							break;
						}
						break;
					case 4:
						k = _getch();
						switch (k)
						{
						case -32:
							k = _getch();
							switch (k)
							{
							case 80:
								g = 4;
								czarymenu(g);
								break;
							case 72:
								g = 3;
								czarymenu(g);
								break;
							case 75:
								g = 2;
							czarymenu(g);
								break;

							}
							break;
						case 27:
							v = 1;
							break;
						}
						break;
					}
				} while (k != 13 && v != 1);
				v = 1;
				if (g == 1 && k!=27)
				{
					satk = 4 + s[0] * 1 + (rand() % 7 - 3);
					if (s[9] >= 30)
					{
						shp -= 6*s[6] + 6 * s[19];
						atk = 6*s[6] + 6 * s[19];
						s[9] -= 30;
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						bia1();
						gotoxy(4, 20);
						cout << "WYKORZYSTANO CZAR - MAGICZNA STRZA"<<PL("Ł")<<"A!";

						if (shp < 0)
							shp = 0;
						if (shp > 0)
							s[8] -= satk;
						gotoxy(4, 22);
						bia1();
						cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						gotoxy(4, 23);
						cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						if (shp > 0)
							Sleep(2000);
					}
					else
					{
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						gotoxy(10, 21);
						bia1();
						cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
						Sleep(800);
					}
				}
				if (g == 2 && k != 27)
				{
					satk = 4 + s[0] * 1 + (rand() % 7 - 3);
					if (s[9] >= 20)
					{
						s[9] -= 20;
						podpal++;
						shp -= 1*s[6] + 1 * s[19];
						atk = 1 * s[6] + 1 * s[19];

						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						bia1();
						gotoxy(4, 20);
						cout << "WYKORZYSTANO CZAR - PODPALENIE!";
						gotoxy(4, 21);
						cout << "OBRA"<<PL("Ż")<<"EIA CZASOWE! (MO"<<PL("Ż")<<"LIWY STACK)";

						if (shp < 0)
							shp = 0;
						if (shp > 0)
							s[8] -= satk;
						gotoxy(4, 22);
						bia1();
						cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						gotoxy(4, 23);
						cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						if (shp > 0)
							Sleep(2000);
					}
					else
					{
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						gotoxy(10, 21);
						bia1();
						cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
						Sleep(800);
					}
				}
				if (g == 3 && k != 27)
				{
					satk = 4 + s[0] * 1 + (rand() % 7 - 3);
					if (s[9] >= 40)
					{
						shp -= shpdef* 4 / 10;
						atk = shpdef * 4 / 10;
						s[9] -= 40;
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						bia1();
						gotoxy(4, 20);
						cout << "WYKORZYSTANO CZAR - PODZIELENIE DUCHA!";
						gotoxy(4, 21);
						cout << "HP WROGA -40% MAXYMALNEGO";
						if (shp < 0)
							shp = 0;
						if (shp > 0)
							s[8] -= satk;
						gotoxy(4, 22);
						bia1();
						cout << "ZADAJESZ ZOMBIE "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						gotoxy(4, 23);
						cout << "ZOMBIE ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						if (shp > 0)
							Sleep(2000);
					}
					else
					{
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						gotoxy(10, 21);
						bia1();
						cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
						Sleep(800);
					}
				}
				if (g == 4 && k != 27)
				{
					if (s[9] >= 30 && s[5]>=10)
					{
						s[9] -= 30;
						s[8] += ghpmax * 35 / 100;
						if (s[8] > ghpmax)
							s[8] = ghpmax;
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						bia1();
						gotoxy(4, 20);
						cout << "WYKORZYSTANO CZAR - ODNOWIENIE!";
						gotoxy(4, 21);
						cout << "HP +35%!";
					}
					else
					{
						for (int i = 2; i < 78; i++)
						{
							for (int j = 19; j < 25; j++)
							{
								gotoxy(i, j);
								def(); cout << " ";
							}
						}
						gotoxy(10, 21);
						bia1();
						cout << "NIE POSIADASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MP LUB WYTRZYM!!";
						Sleep(800);
					}
				}

			} while (v != 1);


		}
		if (g == 5 && s[8] < ghpmax)
		{
			if (s[10] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO HP POTION!";
				s[10] -= 1;
				s[8] += 50;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK HP!";
				Sleep(1000);
			}
		}
		if (g == 6 && s[9] < manamax)
		{
			if (s[11] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO MP POTION!";
				s[11] -= 1;
				s[9] += 20;
				if (s[9] > manamax)
					s[9] = manamax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK MP!";
				Sleep(1000);
			}
		}
		for (int i = 0; i < podpal; i++)
		{
			shp -= 1 * s[6];
		}
	} while (shp > 0 && s[8] > 0);

	if (s[8] > 0)
	{
		graf();
		gracz(s);
		s[15] += 300+s[0]*100;
		s[12] += 550+s[0]*150;
		gotoxy(4, 20);
		bia1();
		cout << "POKONANO ZOMBIE!";
		gotoxy(4, 22);
		cout << "EXP + "<< 300 + s[0] * 100<<"!";
		gotoxy(4, 23);
		cout << "KASA + "<< 550 + s[0] * 150 <<"!";
	}

	Sleep(1500);
	for (int i = 16; i < 77; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	system("cls");
	return (*s);
}
int oko(int *s, float ghpmax, float manamax)
{
	int podpal = 0;
	float shpdef = 50 + s[0] * 15;
	float shp = 50 + s[0] * 15;
	char k;
	int special = 1;
	int atk;
	int unik;
	int kryt;
	int g = 1;
	int satk;
	for (int i = 2; i < 78; i++)
	{
		for (int j = 19; j < 25; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	//gotoxy(79, 24);
	//red();
	//cout << "  ";
	//gotoxy(80, 25);
	//red();
	//cout << "    ";
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	gotoxy(47, 3);
	pur(); cout << "        "; def();
	for (int i = 4; i < 8; i++)
	{
		gotoxy(45, i); pur(); cout << "  "; bia(); cout << "        "; pur(); cout << "  "; def();
	}
	gotoxy(47, 8);
	pur(); cout << "        "; def();
	gotoxy(49, 5);
	dark(); cout << "  "; redintens1(); cout << " "; dark(); cout << " "; def();
	gotoxy(49, 6);
	redintens1(); cout << " "; dark(); cout << "  "; redintens1(); cout << " "; def();
	def();
	hpbar(shp, shpdef);
	hpbar1(s, ghpmax);
	manabar(s, manamax);
	bia1();
	gotoxy(7, 20);
	cout << "ATAK";
	gotoxy(7, 23);
	cout << "OBRONA";
	gotoxy(20, 20);
	cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć");
	gotoxy(20, 23);
	cout << "CZAR";
	gotoxy(40, 20);
	cout << "HPOT";
	gotoxy(40, 23);
	cout << "MPOT";
	red();
	for (int i = 19; i < 25; i++)
	{
		gotoxy(52, i);
		cout << "  ";
	}
	def();
	//gracz(s);
	do
	{

		walkamenu(g);
		hpbar(shp, shpdef);
		hpbar1(s, ghpmax);
		manabar(s, manamax);
		do
		{
			switch (g)
			{
			case 1:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 2:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 3:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 1;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 4:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 2;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 5:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 3;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			case 6:
				k = _getch();
				switch (k)
				{
				case -32:
					k = _getch();
					switch (k)
					{
					case 80:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 72:
						g = 5;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 75:
						g = 4;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					case 77:
						g = 6;
						walkamenu(g);
						hpbar1(s, ghpmax);
						manabar(s, manamax);
						break;
					}
					break;

				}
				break;
			}
		} while (k != 13);
		unik = rand() % (100 / (s[4] + s[17])) + 1;
		kryt = rand() % (100 / (s[7] + s[20])) + 1;
		if (g == 1)
		{
			satk = 15 + s[0] * 3 + (rand() % 7 - 3);
			if (s[1] == 1)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
				}

			}
			if (s[1] == 2)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 3)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 4)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 2;
				}
			}
			if (s[1] == 5)
			{
				if (kryt != 1)
				{
					shp -= 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
					atk = 10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3);
				}
				if (kryt == 1)
				{
					shp -= (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.7 + s[4] * 0.2 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3)) * 2;
				}
			}

			if (shp < 0)
				shp = 0;
			if (shp > 0)

				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
			gotoxy(4, 20);
			bia1();
			cout << "ZADAJESZ OKU "; if (kryt == 1)cout << "KRYTYCZNIE!"; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
			if (unik != 1 && shp>0)
			{
				gotoxy(4, 22);
				cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
				s[8] -= satk;
			}
			if (unik == 1)
			{
				gotoxy(4, 22);
				cout << "UNIKASZ ATAKU!";
			}
			if (shp > 0)
				Sleep(1000);
		}
		if (g == 2)
		{
			if (s[9] >= 2)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				s[9] -= 2;
				s[8] += 8 + s[6] * 0.5;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				bia1();
				gotoxy(4, 20);
				cout << "BRONISZ SI" << PL("Ę") << " I REGENERUJESZ ZDROWIE!";
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O ENERGI!";
				Sleep(1000);
			}
		}
		if (g == 3)
		{
			satk = 15 + s[0] * 3 + (rand() % 7 - 3);
			if (special == 1)
			{
				if (s[1] == 1)
				{
					shp -= (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;
					atk = (10 + s[3] * 0.9 + s[4] * 0.3 + s[6] * 0.1 + s[16] * 1 + (rand() % 7 - 3)) * 2;

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - SILNY CIOS!";
					gotoxy(4, 21);
					cout << "ATAK X2!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 2)
				{
					shp -= (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 - 3))*1.7;
					atk = (10 + s[3] * 0.5 + s[4] * 0.7 + s[6] * 0.2 + s[17] * 1 + (rand() % 7 + -3))*1.7;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ELITARNY STRZELEC!";
					gotoxy(4, 21);
					cout << "ATAK X1.7 + UNIKASZ ATAKU!";

					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 3)
				{
					shp -= (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					atk = (10 + s[3] * 0.8 + s[4] * 0.2 + s[6] * 0.3 + s[18] * 1 + (rand() % 7 - 3))*1.5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - BOSKA CHWA" << PL("Ł") << "A !";
					gotoxy(4, 21);
					cout << "ATAK X1.5 + LECZENIE!";
					s[8] += 10 + s[0] * 8;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 22);
					bia1();
					cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				if (s[1] == 4)
				{
					shp -= (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					atk = (10 + s[3] * 0.2 + s[4] * 0.3 + s[6] * 0.8 + s[19] * 1 + (rand() % 7 - 3)) * 5;
					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - ARMAGEDON!";
					gotoxy(4, 21);
					cout << "OBOSTRONNY CHAOS!";
					s[8] -= satk * 2.5;
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						gotoxy(4, 22);
					bia1();
					cout << "ARMAGEDON RANI OKO ZA "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					gotoxy(4, 23);
					cout << "ARMAGEDON RANI CIE ZA "; redintens(); cout << satk * 2.5; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(3000);
				}
				if (s[1] == 5)
				{

					for (int i = 2; i < 78; i++)
					{
						for (int j = 19; j < 25; j++)
						{
							gotoxy(i, j);
							def(); cout << " ";
						}
					}
					bia1();
					gotoxy(4, 20);
					cout << "WYKORZYSTANO SKILL - GRAD OSTRZY!";
					gotoxy(4, 21);
					cout << "ATAK SZTYLET X7";
					for (int i = 0; i < 7; i++)
					{
						shp -= (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						atk = (10 + s[3] * 0.7 + s[4] * 0.5 + s[6] * 0.1 + s[20] * 1 + (rand() % 7 - 3))*0.3;
						if (i % 2 == 0)
							gotoxy(4, 22);
						if (i % 2 != 0)
							gotoxy(4, 23);
						bia1();
						cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
						Sleep(300);
					}
					if (shp < 0)
						shp = 0;
					if (shp > 0)
						s[8] -= satk;
					gotoxy(4, 23);
					cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
					if (shp > 0)
						Sleep(2000);
				}
				special -= 1;
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "UMIEJ" << PL("Ę") << "TNO" << PL("Ś") << PL("Ć") << " WYKORZYSTANA!";
				Sleep(1000);
			}
		}
		if (g == 4)
		{

			if (g == 4)
			{

				int v = 0;
				char k;
				int g = 1;
				czarymenu(g);
				do
				{
					czarymenu(g);
					do
					{
						switch (g)
						{
						case 1:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								case 77:
									g = 3;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 2:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 2;
									czarymenu(g);
									break;
								case 72:
									g = 1;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;
								case 77:
									g = 4;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 3:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 1;
									czarymenu(g);
									break;
								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						case 4:
							k = _getch();
							switch (k)
							{
							case -32:
								k = _getch();
								switch (k)
								{
								case 80:
									g = 4;
									czarymenu(g);
									break;
								case 72:
									g = 3;
									czarymenu(g);
									break;
								case 75:
									g = 2;
									czarymenu(g);
									break;

								}
								break;
							case 27:
								v = 1;
								break;
							}
							break;
						}
					} while (k != 13 && v != 1);
					v = 1;
					if (g == 1 && k != 27)
					{
						satk = 15 + s[0] * 3 + (rand() % 7 - 3);
						if (s[9] >= 30)
						{
							shp -= 6 * s[6] + 6 * s[19];
							atk = 6 * s[6] + 6 * s[19];
							s[9] -= 30;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - MAGICZNA STRZA" << PL("Ł") << "A!";

							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 2 && k != 27)
					{
						satk = 15 + s[0] * 3 + (rand() % 7 - 3);
						if (s[9] >= 20)
						{
							s[9] -= 20;
							podpal++;
							shp -= 1 * s[6] + 1 * s[19];
							atk = 1 * s[6] + 1 * s[19];

							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODPALENIE!";
							gotoxy(4, 21);
							cout << "OBRA" << PL("Ż") << "EIA CZASOWE! (MO" << PL("Ż") << "LIWY STACK)";

							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 3 && k != 27)
					{
						satk = 15 + s[0] * 3 + (rand() % 7 - 3);
						if (s[9] >= 40)
						{
							shp -= shpdef * 4 / 10;
							atk = shpdef * 4 / 10;
							s[9] -= 40;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - PODZIELENIE DUCHA!";
							gotoxy(4, 21);
							cout << "HP WROGA -40% MAXYMALNEGO";
							if (shp < 0)
								shp = 0;
							if (shp > 0)
								s[8] -= satk;
							gotoxy(4, 22);
							bia1();
							cout << "ZADAJESZ OKU "; redintens(); cout << atk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							gotoxy(4, 23);
							cout << "OKO ZADAJE "; redintens(); cout << satk; bia1(); cout << " OBRA" << PL("Ż") << "E" << PL("Ń") << "!";
							if (shp > 0)
								Sleep(2000);
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE MASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MANY!!";
							Sleep(800);
						}
					}
					if (g == 4 && k != 27)
					{
						if (s[9] >= 30 && s[5] >= 10)
						{
							s[9] -= 30;
							s[8] += ghpmax * 35 / 100;
							if (s[8] > ghpmax)
								s[8] = ghpmax;
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							bia1();
							gotoxy(4, 20);
							cout << "WYKORZYSTANO CZAR - ODNOWIENIE!";
							gotoxy(4, 21);
							cout << "HP +35%!";
						}
						else
						{
							for (int i = 2; i < 78; i++)
							{
								for (int j = 19; j < 25; j++)
								{
									gotoxy(i, j);
									def(); cout << " ";
								}
							}
							gotoxy(10, 21);
							bia1();
							cout << "NIE POSIADASZ WYSTARCZAJ" << PL("Ą") << "CO DU" << PL("Ż") << "O MP LUB WYTRZYM!!";
							Sleep(800);
						}
					}

				} while (v != 1);


			}


		}
		if (g == 5 && s[8] < ghpmax)
		{
			if (s[10] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO HP POTION!";
				s[10] -= 1;
				s[8] += 50;
				if (s[8] > ghpmax)
					s[8] = ghpmax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK HP!";
				Sleep(1000);
			}
		}
		if (g == 6 && s[9] < manamax)
		{
			if (s[11] > 0)
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "WYPITO MP POTION!";
				s[11] -= 1;
				s[9] += 20;
				if (s[9] > manamax)
					s[9] = manamax;
				Sleep(1000);
			}
			else
			{
				for (int i = 2; i < 78; i++)
				{
					for (int j = 19; j < 25; j++)
					{
						gotoxy(i, j);
						def(); cout << " ";
					}
				}
				bia1();
				gotoxy(4, 20);
				cout << "NIE MASZ WI" << PL("Ę") << "CEJ POTEK MP!";
				Sleep(1000);
			}
		}
		for (int i = 0; i < podpal; i++)
		{
			shp -= 1 * s[6];
		}
	} while (shp > 0 && s[8] > 0);

	if (s[8] > 0)
	{
		graf();
		gracz(s);
		s[15] += 600 + s[0] * 100;
		s[12] += 800 + s[0] * 150;
		gotoxy(4, 20);
		bia1();
		cout << "POKONANO MROCZNE OKO!";
		gotoxy(4, 22);
		cout << "EXP + "<<600+s[0]*100<<"!";
		gotoxy(4, 23);
		cout << "KASA + "<<800+s[0]*150<<"!";
	}

	Sleep(1500);
	for (int i = 16; i < 77; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			gotoxy(i, j);
			def(); cout << " ";
		}
	}
	system("cls");
	return (*s);
}
void rasawybor(int rasa)
{

	gotoxy(8, 2);
	bia1();

	cout << "T W " << PL("Ó") << " J   S T Y L   W A L K I ?";
	gotoxy(28, 7); cout << "   ";
	gotoxy(20, 10); cout << "   ";
	gotoxy(20, 13); cout << "   ";
	gotoxy(12, 16); cout << "   ";
	gotoxy(20, 19); cout << "   ";
	gotoxy(6, 7);

	if (rasa == 1)
	blu1();
	cout << "B A R B A R Z Y " << PL("Ń") << " C A"; if (rasa == 1)cout << " <--";
	bia1();
	gotoxy(6, 10);

	if (rasa == 2)
	blu1();
	cout << PL("Ł") << " U C Z N I K"; if (rasa == 2)cout << " <--";
	bia1();
	gotoxy(6, 13);

	if (rasa == 3)
	blu1();
	cout << "P A L A D Y N"; if (rasa == 3)cout << " <--";
	bia1();
	gotoxy(6, 16);

	if (rasa == 4)
	blu1();
	cout << "M A G"; if (rasa == 4)cout << " <--";
	bia1();
	gotoxy(6, 19);

	if (rasa == 5)
	blu1();
	cout << PL("Ł") << " O T R Z Y K"; if (rasa == 5)cout << " <--";
	bia1();
}
void klasawybor(int klasa)
{
	gotoxy(13, 2);
	bia1();
	cout << "K I M   J E S T E " << PL("Ś") << " ?";
	gotoxy(22, 7); cout << "   ";
	gotoxy(12, 10); cout << "   ";
	gotoxy(24, 13); cout << "   ";
	gotoxy(16, 16); cout << "   ";
	gotoxy(22, 19); cout << "   ";
	gotoxy(6, 7);

	if (klasa == 1)
		blu1();
	cout << "C Z "<<PL("Ł")<<" O W I E K"; if (klasa == 1)cout << " <--";
	bia1();
	gotoxy(6, 10);

	if (klasa == 2)
		blu1();
	cout << "E L F"; if (klasa == 2)cout << " <--";
	bia1();
	gotoxy(6, 13);

	if (klasa == 3)
		blu1();
	cout << "K R A S N O L U D"; if (klasa == 3)cout << " <--";
	bia1();
	gotoxy(6, 16);

	if (klasa == 4)
		blu1();
	cout << "D E M O N"; if (klasa == 4)cout << " <--";
	bia1();
	gotoxy(6, 19);

	if (klasa == 5)
		blu1();
	cout <<"M I N O T A U R"; if (klasa == 5)cout << " <--";
	bia1();
}

int intro(int *s)
{
	system("cls");
	string rasaname;
	string klasaname;
	s[3] = 0;
	s[4] = 0;
	s[5] = 0;
	s[6] = 0;
	s[7] = 0;
	rama();
	for (int i = 1; i < 25; i++)
	{
		Beep(60, 40);
		gotoxy(40, i);
		pur();
		cout << "  ";
		def();
	}
	s[1] = 1;
	int rasa = s[1];
	rasawybor(rasa);
	
	char k;
	do
	{
		 rasa = s[1];
		switch (s[1])
		{
		case 1:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[1] = 2;
					rasa = s[1];
					rasawybor(rasa);
					break;
				case 72:
					s[1] = 5;
					rasa = s[1];
					rasawybor(rasa);
					break;
				}
				break;

		

			}
			break;
		case 2:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					s[1] = 1;
					rasa = s[1];
					rasawybor(rasa);
					break;
				case 80:
					s[1] = 3;
					rasa = s[1];
					rasawybor(rasa);
					break;
				}
				break;
			

			}
			break;
		case 3:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					s[1] = 2;
					rasa = s[1];
					rasawybor(rasa);
					break;
				case 80:
					s[1] = 4;
					rasa = s[1];
					rasawybor(rasa);
					break;

				}
				break;
			}
			break;
		case 4:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[1] = 5;
					rasa = s[1];
					rasawybor(rasa);
					break;
				case 72:
					s[1] = 3;
					rasa = s[1];
					rasawybor(rasa);
					break;
				}
				break;
			}
			break;

		case 5:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[1] = 1;
					rasa = s[1];
					rasawybor(rasa);
					break;
				case 72:
		
					s[1] = 4;
					rasa = s[1];
					rasawybor(rasa);
					break;
				}
				break;
			

			}
			break;
	



		}
		
	} while (k != 13);
	
	if (s[1] == 1)
	{
		rasaname = "BARBARZY" + PL("Ń") + "CO";
		s[3] += 3;
		s[4] += 1;
		s[5] += 2;
	

	}
	if (s[1] == 2)
	{
		rasaname = PL("Ł") + "UCZNIKU";
		s[3] += 1;
		s[4] += 3;
		s[7] += 2;
		}
	if (s[1] == 3)
	{
		rasaname = "PALADYNIE";
		s[3] += 2;
			s[5] += 2;
			s[6] += 1;
			s[7] += 1;
		}
	if (s[1] == 4)
	{
		rasaname = "CZARNOKSI" + PL("Ę") + PL("Ż") + "NIKU";
		s[3] += 1;
			s[5] += 1;
			s[6] += 3;
			s[7] += 1;
		}
	if (s[1] == 5)
	{
		rasaname = PL("Ł") + "OTRZYKU";
		s[3] += 1;
		s[4] += 2;
			s[7] += 3;
		}
			


	Sleep(500);
	system("cls");

	rama();
	for (int i = 1; i < 25; i++)
	{
		Beep(60, 40);
		gotoxy(40, i);
		pur();
		cout << "  ";
		def();
	}
	s[2] = 1;
	int klasa = s[2];
	klasawybor(klasa);

	do
	{
		klasa = s[2];
		switch (s[2])
		{
		case 1:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[2] = 2;
					klasa = s[2];
					klasawybor(klasa);
					break;
				case 72:
					s[2] = 5;
					klasa = s[2];
					klasawybor(klasa);
					break;
				}
				break;



			}
			break;
		case 2:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					s[2] = 1;
					klasa = s[2];
					klasawybor(klasa);
					break;
				case 80:
					s[2] = 3;
					klasa = s[2];
					klasawybor(klasa);
					break;
				}
				break;


			}
			break;
		case 3:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					s[2] = 2;
					klasa = s[2];
					klasawybor(klasa);
					break;
				case 80:
					s[2] = 4;
					klasa = s[2];
					klasawybor(klasa);
					break;

				}
				break;
			}
			break;
		case 4:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[2] = 5;
					klasa = s[2];
					klasawybor(klasa);
					break;
				case 72:
					s[2] = 3;
					klasa = s[2];
					klasawybor(klasa);
					break;
				}
				break;
			}
			break;

		case 5:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					s[2] = 1;
					klasa = s[2];
					klasawybor(klasa);
					break;
				case 72:

					s[2] = 4;
					klasa = s[2];
					klasawybor(klasa);
					break;
				}
				break;


			}
			break;




		}
	} while (k != 13);

	if (s[2] == 1)
	{
		klasaname = "CZ"+PL("Ł")+"OWIEKU";
		s[3] += 2;
		s[4] += 1;
		s[5] += 2;
		s[6] += 1;
		s[7] += 1;
	}
	if (s[2] == 2)
	{
		klasaname = "ELFIE";

			s[4] += 3;
	
			s[6]+= 2;
		s[7] += 2;
	}
	if (s[2] == 3)
	{
		klasaname = "KRASNOLUDZIE";
		s[3] += 2;
		
			s[5] += 3;
		
			s[7] += 2;
	}
	if (s[2] == 4)
	{
		klasaname = "DEMONIE";
		s[3]+= 1;
		s[4] += 1;
		s[5] += 1;
		s[6] += 2;
		s[7] += 2;
	}
	if (s[2] == 5)
	{
		klasaname = "MINOTAURZE";
		s[3] += 3;
	
			s[5] += 3;
	
			s[7] += 1;
	}

	
	Sleep(500);
	rama();
	int a = 10;
	for (int i = 1; i < 25; i++)
	{
		Beep(60, 40);
		gotoxy(40, i);
		pur();
		cout << "  ";
		def();
	}
	int staty = 1;
	statywybor(staty,s,a);

	do
	{
		switch (staty)
		{
		case 1:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 2;
					statywybor(staty, s,a);
					break;
				case 72:
					staty = 5;
					statywybor(staty, s,a);
					break;
				
				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;


			}
			break;
		case 2:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					staty = 1;
					statywybor(staty, s, a);
					break;
				case 80:
					staty = 3;
					statywybor(staty, s, a);
					break;
				
				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;

			}
			break;
		case 3:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					staty = 2;
					statywybor(staty, s, a);
					break;
				case 80:
					staty = 4;
					statywybor(staty, s, a);
					break;
				
				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;
			}
			break;
		case 4:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 5;
					statywybor(staty, s, a);
					break;
				case 72:
					staty = 3;
					statywybor(staty, s, a);
					break;
				
				}
				break;
			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				a--;
				statywybor(staty, s, a);
				break;
			}
			break;

		case 5:
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					staty = 1;
					statywybor(staty, s, a);
					break;
				case 72:

					staty = 4;
					statywybor(staty, s, a);
					break;
				
				}
				break;

			case 13:
				if (staty == 1)
					s[3]++;
				if (staty == 2)
					s[4]++;
				if (staty == 3)
					s[5]++;
				if (staty == 4)
					s[6]++;
				if (staty == 5)
					s[7]++;
				
				a--;
				statywybor(staty, s, a);
				break;
			}
			break;




		}
	} while (a != 0);
	Sleep(500);
	system("cls");





	rama();
	czaszka1();
	for (int i = 1; i < 25; i++)
	{
		Beep(60, 40);
		gotoxy(40, i);
		pur();
		cout << "  ";
		def();
	}
	gotoxy(8 , 2);
	bia1();
	string c = "WITAJ, " + klasaname +" " + rasaname;
	string c1 = "WIDZ"+PL("Ę")+", "+PL("Ż")+"E KOLEJNA BARWNA ISTOTA";
	string c2 = "PR"+PL("Ó")+"BUJE SPROSTA"+PL("Ć")+" TEMU "+PL("Ś")+"WIATU.";
	string c3 = "OSTRZEGAM, CZEKA CI"+PL("Ę")+" DROGA PE"+PL("Ł")+"NA";
	string c4 = "NIEBEZPIECZE"+PL("Ń")+"STW, ALE TE"+PL("Ż")+" PRZYG"+PL("Ó")+"D.";
	string c5 = "JEDYNIE TWOJA PRAWDZIWA DETERMINACJA";
	string c6 = "POKONA Z"+PL("Ł")+"O PANUJ"+PL("Ą")+"CE NA TYM "+PL("Ś")+"WIECIE.";
	string c7 = "Z A C Z N I J M Y   N O W "+PL("Ą")+"   G R "+PL("Ę");
	for (int i = 0; i < c.length(); i++)
	{
		cout << c[i];
		Sleep(30);
	}
	gotoxy(3, 7);
	for (int i = 0; i < c1.length(); i++)
	{
		cout << c1[i];
		Sleep(30);
	}

	gotoxy(3, 9);
	for (int i = 0; i < c2.length(); i++)
	{
		cout << c2[i];
		Sleep(30);
	}
	gotoxy(3, 11);
	for (int i = 0; i < c3.length(); i++)
	{
		cout << c3[i];
		Sleep(30);
	}
	gotoxy(3, 13);
	for (int i = 0; i < c4.length(); i++)
	{
		cout << c4[i];
		Sleep(30);
	}
	gotoxy(3, 15);
	for (int i = 0; i < c5.length(); i++)
	{
		cout << c5[i];
		Sleep(30);
	}
	gotoxy(3, 17);
	for (int i = 0; i < c6.length(); i++)
	{
		cout << c6[i];
		Sleep(30);
	}
	gotoxy(4, 19);
	for (int i = 0; i < c7.length(); i++)
	{
		redintens();
		cout << c7[i];
		Sleep(100);
		def();
	}
	for (int i = 0; i < 4; i++)
	{
		czaszka();
		for (int j = 0; j < 5; j++)
		{
			Beep(60, 80);
		}
		czaszka1();
		for (int j = 0; j < 5; j++)
		{
			Beep(60, 80);
		}
	}
	Sleep(1000);
	return (*s);
}
void rekordsort()
{
	int k = 0;
	rama();
	fstream plik;
	int help = 0;
	int i = 0;
	int licz = 0;
	string dane;
	vector <string> tab;

	plik.open("wyniki.txt", ios::in | ios::out | ios::app);
	while (!plik.eof())
	{
		getline(plik, dane);
		tab.push_back(dane);
		i++;
	}
	gotoxy(14, 3);
	for (int j = 0; j < 15; j++)
	{
		gotoxy(14, 3+k);
		bia1();
		if(i>j)
		cout << tab[j] << endl;
		licz++;
		if (licz == 3)
		{
			k++;
			gotoxy(14, 3 + k);
			cout << "------------------------------------------------------" << endl;
			licz = 0;
		}
		k++;
	}
	k = 0;
	for (int j = 15; j < 30; j++)
	{
		gotoxy(29, 3 + k);
		bia1();
		if (i > j)
		cout << tab[j] << endl;
		licz++;
		if (licz == 3)
		{
			k++;
			licz = 0;
		}
		k++;
	}
	k = 0;
	for (int j = 30; j < 45; j++)
	{
		gotoxy(44, 3 + k);
		bia1();
		if (i > j)
		cout << tab[j] << endl;
		licz++;
		if (licz == 3)
		{
			k++;
			licz = 0;
		}
		k++;
	}
	k = 0;
	for (int j = 45; j < 60; j++)
	{
		gotoxy(59, 3 + k);
		bia1();
		if (i > j)
		cout << tab[j] << endl;
		licz++;
		if (licz == 3)
		{
			k++;
			licz = 0;
		}
		k++;
	}
	k = 0;
	for (int j = 0; j < 5; j++)
	{
		gotoxy(9, 3 + 3 * k + help);
		zlo1();
		cout << "NICK"; def();
		gotoxy(9, 4 + 3 * k + help);
		blu();
		cout << "LVL "; def();
		gotoxy(9, 5 + 3 * k + help);
		redintens1();
		cout << "PKT "; def();
		licz++;
		if (licz == 1)
		{
			help++;
			licz = 0;
		}
		k++;
	}
	k = 0;
	plik.close();
	tab.clear();
}
void menu0(bool c)
{
	HANDLE hConsole;

	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	if (c == 1)
		Beep(60, 300);
	cout << "S T A R T   G R Y" << endl;
	Sleep(500);
	gotoxy(16, 13);
	if (c == 1)
		Beep(80, 300);
	cout << "O P C J E" << endl;
	Sleep(500);
	gotoxy(16, 15);
	if (c == 1)
		Beep(100, 300);
	cout << "R E K O R D Y" << endl;
	Sleep(500);
	gotoxy(16, 17);
	if (c == 1)
		Beep(120, 300);
	cout << "A U T O R Z Y" << endl;
	Sleep(500);
	gotoxy(16, 19);
	if (c == 1)
		Beep(140, 300);
	cout << "K O N I E C" << endl;
}
void menu1(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "S T A R T   G R Y" << endl;
	SetConsoleTextAttribute

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	gotoxy(16, 13);
	cout << "O P C J E" << endl;
	gotoxy(16, 15);
	cout << "R E K O R D Y" << endl;
	gotoxy(16, 17);
	cout << "A U T O R Z Y" << endl;
	gotoxy(16, 19);
	cout << "K O N I E C" << endl;

	czaszka1();



	if (c == 1)
		Beep(200, 300);
}
void koniec(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	rama();
	pip();
	//ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


	czaszka1();



	if (c == 1)
		Beep(200, 300);
}
void menu2(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	cout << "S T A R T   G R Y" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(16, 13);
	cout << "O P C J E" << endl;
	SetConsoleTextAttribute

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	gotoxy(16, 15);
	cout << "R E K O R D Y" << endl;
	gotoxy(16, 17);
	cout << "A U T O R Z Y" << endl;
	gotoxy(16, 19);
	cout << "K O N I E C" << endl;
	czaszka();
	if (c == 1)
		Beep(200, 300);
}
void menu3(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	cout << "S T A R T   G R Y" << endl;
	gotoxy(16, 13);
	cout << "O P C J E" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(16, 15);
	cout << "R E K O R D Y" << endl;
	SetConsoleTextAttribute

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	gotoxy(16, 17);
	cout << "A U T O R Z Y" << endl;
	gotoxy(16, 19);
	cout << "K O N I E C" << endl;
	czaszka1();
	if (c == 1)
		Beep(200, 300);
}
void menu4(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	cout << "S T A R T   G R Y" << endl;
	gotoxy(16, 13);
	cout << "O P C J E" << endl;
	gotoxy(16, 15);
	cout << "R E K O R D Y" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(16, 17);
	cout << "A U T O R Z Y" << endl;
	SetConsoleTextAttribute

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	gotoxy(16, 19);
	cout << "K O N I E C" << endl;
	czaszka();
	if (c == 1)
		Beep(200, 300);
}
void menu5(bool c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	rama();
	pip();
	ta();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(16, 11);
	cout << "S T A R T   G R Y" << endl;
	gotoxy(16, 13);
	cout << "O P C J E" << endl;
	gotoxy(16, 15);
	cout << "R E K O R D Y" << endl;
	gotoxy(16, 17);
	cout << "A U T O R Z Y" << endl;
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(16, 19);
	cout << "K O N I E C" << endl;
	SetConsoleTextAttribute

	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	czaszka1();
	if (c == 1)
		Beep(200, 300);
}
void menu(bool & c, int *x, string *y)
{
	gotoxy(5, 8);
	int a = 1;

	char k;
	do
	{
		switch (a)
		{
		case 1:
			menu1(c);
			k = _getch();
			//cout<<k<<endl;
			//Sleep(5000);
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					a = 2;
					break;
				case 72:
					a = 5;
					break;
				}
				break;

			case 13:
				a = 6;
				break;

			}
			break;
		case 2:
			menu2(c);
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					a = 1;
					break;
				case 80:
					a = 3;
					break;
				}
				break;
			case 13:
				system("cls");
				Menu_Opcje(c);
				a = 2;
				break;

			}
			break;
		case 3:
			menu3(c);
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 72:
					a = 2;
					break;
				case 80:
					a = 4;
					break;

				}
				break;
			case 13:
				system("cls");
				rekordsort();

				do
				{
					k = _getch();
					system("cls");
					rekordsort();
				} while (k != 13);
				a = 3;
				break;
			}
			break;
		case 4:
			menu4(c);
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					a = 5;
					break;
				case 72:
					a = 3;
					break;
				}
				break;
			case 13:
				system("cls");
				autorzy();

				do
				{
					k = _getch();
					system("cls");
					autorzy();
				} while (k != 13);
				a = 4;
				break;
			}
			system("color 7");
			break;

		case 5:
			menu5(c);
			k = _getch();
			switch (k)
			{
			case -32:
				k = _getch();
				switch (k)
				{
				case 80:
					a = 1;
					break;
				case 72:
					a = 4;
					break;
				}
				break;
			case 13:
				a = 7;
				break;

			}
			break;
		case 7:
			//koniec(c);
			rama();
			gotoxy(28, 12);
			redintens();
			cout << "DO ZOBACZENIA, WOJOWNIKU!";
			Sleep(3000);
			system("cls");
			bia1();
			exit(0);
			break;



		}
	} while (a != 6);
}
void ekran()
{
	system("color 2");
	gotoxy(25, 10);
	cout << "===========================" << endl;
	gotoxy(25, 11);
	cout << " IN MEMORY OF GAMEBOY(1989)" << endl;
	gotoxy(28, 12);
	cout << " Y&M STUDIO PRESENTS" << endl;
	gotoxy(25, 13);
	cout << "===========================" << endl;
	Sleep(3000);
	system("cls");
}
void ramka()
{
	for (int i = 6; i <= 16; i++)
	{
		for (int j = 30; j < 49; j++)
		{
			if (i == 6 || i == 16)
			{
				rysuj2(j, i);
			}
			else
			{
				int z = 30, v = 34;

				rysuj4(z, i);
				rysuj4(v, i);
				rysuj4(48, i);
			}
		}
		cout << " ";
	}
}
void obst(int & pom, int  x[], int  y[])
{
	int b = 1;
	if (pom == 1)
	{
		for (int i = 6; i < 14; i++)
		{
			do
			{
				x[b] = (rand() % 3) + 31;
			} while (x[b] == x[b - 1] && x[b] == x[b - 2]);
			y[b] = i + 1;
			gotoxy(x[b], y[b]);
			cout << "#" << endl;
			b++;


		}

	}
	if (pom > 1)

	{
		int f = x[0];
		for (int i = 9; i > 1; i--)
			x[i] = x[i - 1];
		do
		{
			x[1] = (rand() % 3) + 31;
		} while (x[1] == x[2] && x[1] == x[3]);

		y[9] = 15;
		for (int d = 1; d <= 9; d++)
		{

			gotoxy(x[d], y[d]);
			cout << "#" << endl;


		}




	}
	pom += 1;
}
void check(int & pkt, int *x, int *y, int & ruch, bool c)
{




	if (x[8] == x[0])
	{
		system("cls");
		HANDLE hConsole;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute
		(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("color 9");
		gotoxy(29, 8);
		cout << "======================" << endl;
		gotoxy(29, 9);
		cout << "    !!!YOU LOSE!!! " << endl;
		gotoxy(29, 10);
		cout << "  TWOJE PUNKTY TO: " << pkt << endl;
		gotoxy(29, 11);
		cout << "======================" << endl;
		SetConsoleTextAttribute
		(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if (c == 1)
		{
			muzyka2(0);
			muzyka1(1000);
			muzyka2(0);
			muzyka1(1000);
			muzyka2(0);
			muzyka1(1000);
		}
		else
			if (c == 0)
				Sleep(2000);
		Sleep(1000);
		ruch = 3;
	}

}
void punkty(int & pkt)
{
	fstream plik;
	plik.open("wyniki.txt", ios::in | ios::out | ios::app);
	if (plik)
	{
		plik << pkt;



	}
	else
	{
		cout << "cos... cos sie popsulo" << endl;
	}
	plik.close();
}
void nick1(string & name)
{
	fstream plik;
	plik.open("wyniki.txt", ios::in | ios::out | ios::app);
	if (plik)
	{
		plik << endl;
		plik << name << endl;


	}
	else
	{
		cout << "cos... cos sie popsulo" << endl;
	}
	system("cls");
	plik.close();
}
void mapatab(int *x, int *y, int ilosc_pokoji,int u,int t,int a ,int*s)
{
	gotoxy(14, 1);
	pur(); cout << "                                                     "; def();
	gotoxy(14, 16);
	pur(); cout << "                                                     ";
	for (int i = 2; i < 16; i++)
	{
		gotoxy(14, i);
		pur();
		cout << "  ";
		def();
		gotoxy(65, i);
		pur();
		cout << "  ";
		def();
	}
	for(int i=2;i<16;i++)
	{
		for (int j = 16; j < 65; j++)
		{
			gotoxy(j, i);
			def();
			cout << " ";
		}
	}
	pur();
	for (int i = 0; i < ilosc_pokoji; i++)
	{
		rysujmapa(x[i], y[i]);
	}
	bia1();
	gotoxy(17, 3);
	cout << "TAB - ZAMKNIJ";
	gotoxy(17, 4);
	cout << "G - GRACZ";
	gotoxy(17, 5);
	cout << "M - BOSS";
	gotoxy(17, 6);
	cout << "S - SKLEP";
	pur();
	gotoxy(x[0] - 18, y[0] - 10);
	cout << "S";
	gotoxy(x[u]-18, y[t]-10);
	cout << "G";
	gotoxy(x[9]-18, y[9]-10);
	cout << "M";
	int d;
	do {
	 d = _getch();
	} 
	while (d != 9);
	graf();
	gracz(s);
	switch (a)
	{
	case -1: {pochodnia1(); pochodnia2(); }
			 break;
	case 0: {pochodnia1(); pochodnia4(); }
			break;
	case 1: {pochodnia3(); pochodnia2(); }
			break;
	case 2: {pochodnia3(); pochodnia4(); }
			break;

	}
}
int ruch(int *s,int *x, int*y, int ilosc_pokoji, int c) {
	int  g = 0, d = 0, p = 0, l = 0, u = 0, t = 0;
	int pocz = 0;
	int a=0;
	int kasa;
	int px = x[0];
	int py = y[0];
	int px1 = 0;
	int py1 = 0;
	char k;
	int walkaszansa;
	int skrzyniaszansa;
	int enemy;
	int licz = 0;
	int licz1 = 0;
	s[8] = 100 + s[5] * 10 + s[18] * 10;

	do {
		
		graf();
		gracz(s);
		switch (a)
		{
		case -1: {pochodnia1(); pochodnia2(); }
				 break;
		case 0: {pochodnia1(); pochodnia4(); }
				break;
		case 1: {pochodnia3(); pochodnia2(); }
				break;
		case 2: {pochodnia3(); pochodnia4(); }
				break;

		}

		float maxhp = 100 + s[5] * 10 + s[18]*10;
		float maxmana = 10 + s[6] * 9 + s[19]*9;
		gotoxy(14, 19);
		red();
		cout << " ";
		gotoxy(14, 20);
		red();
		cout << " ";
		gotoxy(14, 21);
		red();
		cout << " ";
		gotoxy(14, 22);
		red();
		cout << " ";
		gotoxy(14, 23);
		red();
		cout << " ";
		gotoxy(14, 24);
		red();
		cout << " ";
		g = 0;
		d = 0;
		p = 0;
		l = 0;
		gotoxy(21, 20);
		bia1();
		cout << "HP : " << s[8]<<"/"<<maxhp;
		gotoxy(19, 21);
		cout << "MANA : " << s[9]<<"/"<<maxmana;
		gotoxy(17, 22);
		cout << "LVL UP : " << 1000*s[14]-s[15];
		gotoxy(17, 23);
		cout << "POZIOM : " << s[14];
		gotoxy(41, 22);
		cout << "MAPA <TAB>";
		gotoxy(41, 23);
		cout << "RUCH <STRZA" << PL("Ł") << "KI>";
		gotoxy(35, 20);
		cout << "WYPIJ HPOT <1>";
		gotoxy(35, 21);
		cout << "WYPIJ MPOT <2>";
		gotoxy(65, 20);
		cout << "HPOT  : " << s[10];
		gotoxy(65, 21);
		cout << "MPOT  : " << s[11];
		gotoxy(65, 22);
		cout << "KASA  : " << s[12];
		gotoxy(65, 23);
		cout << "WYNIK : " << s[13];
		for (int i = 0; i < ilosc_pokoji; i++) {
			if (x[i] == x[u] + 1 && y[i] == y[t]) {
				gotoxy(11, 21);
				zlo();
				cout << "\\";
				gotoxy(11, 22);
				zlo();
				cout << "/";
				gotoxy(9, 21);
				zlo();
				cout << " -";
				gotoxy(9, 22);
				zlo();
				cout << " -";
				p = 1;
				break;
			}
			else {
				gotoxy(11, 21);
				reds();
				cout << "\\";
				gotoxy(11, 22);
				reds();
				cout << "/";
				gotoxy(9, 21);
				reds();
				cout << " -";
				gotoxy(9, 22);
				reds();
				cout << " -";
			}
		}
		for (int i = 0; i < ilosc_pokoji; i++) {
			if (x[i] == x[u] - 1 && y[i] == y[t]) {
				gotoxy(4, 21);
				zlo();
				cout << "/";
				gotoxy(4, 22);
				zlo();
				cout << "\\";
				gotoxy(5, 21);
				zlo();
				cout << "- ";
				gotoxy(5, 22);
				zlo();
				cout << "- ";
				l = 1;
				break;
			}
			else {
				gotoxy(4, 21);
				reds();
				cout << "/";
				gotoxy(4, 22);
				reds();
				cout << "\\";
				gotoxy(5, 21);
				reds();
				cout << "- ";
				gotoxy(5, 22);
				reds();
				cout << "- ";
			}
		}
		for (int i = 0; i < ilosc_pokoji; i++) {
			if (y[i] == y[t] - 1 && x[i] == x[u]) {
				gotoxy(7, 20);
				zlo();
				cout << "/\\";
				gotoxy(7, 21);
				zlo();
				cout << "||";
				g = 1;
				break;
			}
			else {
				gotoxy(7, 20);
				reds();
				cout << "/\\";
				gotoxy(7, 21);
				reds();
				cout << "||";
			}
		}
		for (int i = 0; i < ilosc_pokoji; i++) {
			if (y[i] == y[t] + 1 && x[i] == x[u]) {
				gotoxy(7, 23);
				zlo();
				cout << "\\/";
				gotoxy(7, 22);
				zlo();
				cout << "||";
				d = 1;
				break;
			}
			else {
				gotoxy(7, 23);
				reds();
				cout << "\\/";
				gotoxy(7, 22);
				reds();
				cout << "||";
			}
		}
		k = _getch();
	
	
		
		if (k == 9)
		{
			mapatab(x, y, ilosc_pokoji,u,t,a,s);
			continue;
		}
		if (k == 49 && s[10]>0 && s[8]<maxhp)
		{
			s[10]--;
			s[8] += 50;
			if (s[8] > maxhp)
				s[8] = maxhp;
		}
		if (k == 50 && s[11] > 0 && s[9]<maxmana)
		{
			s[11]--;
			s[9] += 20;
			if (s[9] > maxmana)
				s[9] = maxmana;
		}
		if (k == 72 && g == 1) {
			py = py - 1;
		}
		if (k == 80 && d == 1) {
			py = py + 1;
		}
		if (k == 77 && p == 1) {
			px = px + 1;
		}
		if (k == 75 && l == 1) {
			px = px - 1;
		}
		for (int i = 0; i < ilosc_pokoji; i++) {
			for (int j = 0; j < ilosc_pokoji; j++) {
				if (px == x[i] && py == y[j]) {
					u = i; t = j;
				}
			}
		}
		if (x[u] == px && y[t] == py) {
			gotoxy(x[u], y[t]);
			pur();
			if(px1!=px || py1!=py)
			{ 
				pochodnietemp();
				a = (rand() % 4) - 1;
				switch (a)
				{
				case -1: {pochodnia1(); pochodnia2(); }
						 break;
				case 0: {pochodnia1(); pochodnia4(); }
						break;
				case 1: {pochodnia3(); pochodnia2(); }
						break;
				case 2: {pochodnia3(); pochodnia4(); }
						break;

				}
				if (x[u] == x[0] && y[t] == y[0] && pocz>0)
				{
					sklep(s);
				}

			if(c==1)
				Beep(100, 300);
			walkaszansa = rand() % 4 + 1;
				if (walkaszansa == 1&& (x[u] != x[9] || y[t] != y[9]) && (x[u] != x[0] || y[t] != y[0]))
				{
				enemy = rand() % 3 + 1;
				if (enemy == 1)
				{
					szkielet(s,maxhp,maxmana);
					if(s[8]>0)
					s[13] += 550;
				}

				if (enemy == 2)
				{
					zombie(s,maxhp,maxmana);
					if (s[8] > 0)
					s[13] += 400;
				}
				if (enemy == 3)
				{
					oko(s,maxhp,maxmana);
					if (s[8] > 0)
					s[13] += 800;
				}
				if (s[15] >= 1000 * s[14])
				{
					lvlup(s);
					s[14]++;
					s[15] = 0;
				}
				}
				if (walkaszansa == 2 && (x[u] != x[9] || y[t] != y[9]) && (x[u] != x[0] || y[t] != y[0]))
				{
					skrzyniaszansa = rand() % 3 + 1;
					if (skrzyniaszansa == 1)
					{

						kasa = rand() % 1100 + 700;
						s[12] += kasa;
						skrzynia(kasa);
						s[13] += 1000;
					}
				}
			
			}
			
			
		}
		
		px1 = px;
		py1 = py;
		for (int i = 16; i < 78; i++)
		{
			for (int j = 19; j < 24; j++)
			{
				gotoxy(i, j);
				def(); cout << " " << endl;
			}
		}
		gotoxy(79, 24);
		red();
		cout << "  ";
		gotoxy(0, 25);
		red();
		cout << "    ";
		pocz++;
	} while (!(x[u] == x[9] && y[t] == y[9]) && s[8]>0);
	float maxhp = 100 + s[5] * 10 + s[18] * 10;
	float maxmana = 10 + s[6] * 9 + s[19] * 9;

		
	if (x[u] == x[9] && y[t] == y[9])
	{
		if (s[8] > 0)
		{
			boss(s, maxhp, maxmana);
			if (s[8] > 0)
			s[13] += 2500;
		}
			
		if (s[15] >= 1000 * s[14])
		{
			lvlup(s);
			s[14]++;
			s[15] = 0;
		}
		if(s[0]!=10 && s[8]>0)
		eq(s);
	}
	if (s[8]<=0)
	{
		string c = "WRAZ Z OSTATNIM ODDECHEM CZUJESZ W";
		string c1 = "SWOIM CIELE ODN" + PL("Ó") + PL("Ż") + "E MONSTRUM";
		string c2 = "ROZRYWAJ" + PL("Ą") + "CE TWOJE WN" + PL("Ę") + "TRZNO" + PL("Ś") + "CI.";
		string c3 = "UPADAJ" + PL("Ą") + "C NA ZIEMI" + PL("Ę") + " MY" + PL("Ś") + "LISZ:";
		string c4 = "ZAWIOD" + PL("Ł") + "EM?";
		string c5 = "ALE DOP" + PL("Ó") + "KI KTO" + PL("Ś")+" WALCZY";
		string c6 = PL("Ś") + "WIAT NIE POGR" + PL("Ą") + PL("Ż") + "Y SI" + PL("Ę");
		string c7 = "Z A C Z N I J M Y   N O W " + PL("Ą") + "   G R " + PL("Ę");
		string c8 = "W CHAOSIE, RACJA?";
		system("cls");
		rama();
		czaszka();
		for (int i = 1; i < 25; i++)
		{
			Beep(60, 40);
			gotoxy(40, i);
			pur();
			cout << "  ";
			def();
		}
		gotoxy(3, 7);
		bia1();
		for (int i = 0; i < c.length(); i++)
		{
			cout << c[i];
			Sleep(30);
		}
		gotoxy(3, 8);
		bia1();
		for (int i = 0; i < c1.length(); i++)
		{
			cout << c1[i];
			Sleep(30);
		}
		gotoxy(3, 9);
		bia1();
		for (int i = 0; i < c2.length(); i++)
		{
			cout << c2[i];
			Sleep(30);
		}
		gotoxy(3, 10);
		bia1();
		for (int i = 0; i < c3.length(); i++)
		{
			cout << c3[i];
			Sleep(30);
		}
		gotoxy(13, 12);
		redintens();
		for (int i = 0; i < c4.length(); i++)
		{
			cout << c4[i];
			Sleep(450);
		}
		gotoxy(3, 14);
		bia1();
		for (int i = 0; i < c5.length(); i++)
		{
			cout << c5[i];
			Sleep(30);
		}
		gotoxy(3, 15);
		bia1();
		for (int i = 0; i < c6.length(); i++)
		{
			cout << c6[i];
			Sleep(30);
		}
		gotoxy(3, 16);
		bia1();
		for (int i = 0; i < c8.length(); i++)
		{
			cout << c8[i];
			Sleep(30);
		}
		gotoxy(3, 18);
		redintens();
		for (int i = 0; i < c7.length(); i++)
		{
			cout << c7[i];
			Sleep(100);
		}
		Sleep(3000);
		system("cls");
	}
	return(*s,x,y,ilosc_pokoji, c);
}
void rekordinsert(string gracza,int *s)
{
	rama();
	fstream plik;
	string dane;
	string tmp; 
	_itoa(s[14], (char*)tmp.c_str(), 10);
	string lvl = tmp.c_str();
	_itoa(s[13], (char*)tmp.c_str(), 10);
	string wynik = tmp.c_str();
	plik.open("wyniki.txt", ios::in | ios::out | ios::app);
	plik << gracza << endl;
	plik << lvl << endl;
	plik << wynik << endl;
	
	plik.close();
}
int mapa(int *s, int c)
{
	int z = 60;
	int j = 20;
	gotoxy(z, j);
	int ilosc_pokoji = 8 + (s[0] * 4);
	int k = 1, d = 0, g = 0, p = 0, l = 0, a = 0, b = 0;
	int *x = new int[ilosc_pokoji];
	int *y = new int[ilosc_pokoji];
	wypelnijxy(x, y, ilosc_pokoji);
	do
	{
		int ile_pokoji = (rand() % 3) + 1;

		do
		{
			for (int i = 0; i < k; i++)
			{
				if ((x[i] == z && y[i] == j + 1))
				{
					g = 1;

				}
				if ((x[i] == z && y[i] == j - 1) || (j - 1 < 10) || (j - 1 == 10 && z == 10))
				{
					d = 1;

				}
				if ((x[i] == z - 1 && y[i] == j) || (j == 10 && z - 1 == 10))
				{
					l = 1;

				}
				if ((x[i] == z + 1 && y[i] == j) || (j == 10 && z + 1 == 10))
				{
					p = 1;
				}
			}

			int gdzie = (rand() % 4) + 1;
			if (gdzie == 1 && l == 0)
			{
				x[a] = z - 1;
				y[a] = j;
				a++;
				k++;
				ile_pokoji--;

			}
			if (gdzie == 2 && g == 0)
			{
				x[a] = z;
				y[a] = j + 1;
				a++;
				k++;
				ile_pokoji--;

			}
			if (gdzie == 3 && p == 0)
			{
				x[a] = z + 1;
				y[a] = j;
				a++;
				k++;
				ile_pokoji--;

			}
			if (gdzie == 4 && d == 0)
			{
				x[a] = z;
				y[a] = j - 1;
				a++;
				k++;
				ile_pokoji--;

			}

			if (g == 1 && d == 1 && l == 1 && p == 1)
			{
				a--;
				break;
			}



		} while (ile_pokoji > 0);
		z = x[b];
		j = y[b];
		b++;
		g = 0;
		d = 0;
		p = 0;
		l = 0;



	} while (k <= ilosc_pokoji);

	//for (int i = 1; i < ilosc_pokoji; i++)
	//{
	//	rysuj(x[i], y[i]);
	//}
	//gotoxy(x[0], y[0]);
	//cout << "G" << endl;
	//gotoxy(x[9], y[9]);
	//cout << "M" << endl;
	ruch(s,x, y, ilosc_pokoji,c);
	return(*s, c);
}


void gra(string gracza, int c1)
{
	int a;
	int b;
	int s[21] = {1,1,1,1,1,1,20,1,100,10,3,3,1000,0,1,0,0,0,0,0,0};
	intro(s);
	
	system("cls");
	s[8] = 100 + s[5] * 10;
	s[9] = 10 + s[6] * 9;
	gracz(s);
	do
	{
		
		rama();
		gotoxy(36, 12);
		redintens();
		cout << "POZIOM " << s[0];
		Sleep(3000);
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 81; j++)
			{
				gotoxy(j, i); def(); cout << " ";
			}
		}
		graf();
		gracz(s);
		
		mapa(s,c1);
		Sleep(500);
		system("cls");
		s[0]++;
	} while (s[0] <= 10 && s[8]>0);
	s[13] += s[14] * 1000;
	s[13] += s[12];
	if (s[8] > 0)
	{
		rekordinsert(gracza,s);
		string c = "GRATULACJE DZIELNY BOHATERZE!";
		string c1 = "DOKONA"+PL("Ł")+"E"+PL("Ś")+" TEGO,CO UDAJE";
		string c2 = "SI"+PL("Ę")+" TYLKO NIELICZNYM!";
		string c3 = "TWOJE IMI"+PL("Ę")+" ZOSTANIE ZAPISANE";
		string c5 = "W HISTORII TEJ KRAINY NA WIEKI!";
		string c6 = "LECZ ZOSTA"+PL("Ł")+"O JESZCZE WIELE DO";
		string c7 = "Z A C Z N I J M Y   N O W " + PL("Ą") + "   G R " + PL("Ę");
		string c8 = "ZROBIENIA, TAK WI" + PL("Ę") + "C...";
		system("cls");
		rama();
		czaszka1();
		for (int i = 1; i < 25; i++)
		{
			Beep(60, 40);
			gotoxy(40, i);
			pur();
			cout << "  ";
			def();
		}
		gotoxy(3, 7);
		zlo();
		for (int i = 0; i < c.length(); i++)
		{
			cout << c[i];
			Sleep(30);
		}
		gotoxy(3, 9);
		bia1();
		for (int i = 0; i < c1.length(); i++)
		{
			cout << c1[i];
			Sleep(30);
		}
		gotoxy(3, 10);
		bia1();
		for (int i = 0; i < c2.length(); i++)
		{
			cout << c2[i];
			Sleep(30);
		}
		gotoxy(3, 11);
		bia1();
		for (int i = 0; i < c3.length(); i++)
		{
			cout << c3[i];
			Sleep(30);
		}
		gotoxy(3, 12);
		bia1();
		for (int i = 0; i < c5.length(); i++)
		{
			cout << c5[i];
			Sleep(30);
		}
		gotoxy(3, 13);
		bia1();
		for (int i = 0; i < c6.length(); i++)
		{
			cout << c6[i];
			Sleep(30);
		}
		gotoxy(3, 14);
		bia1();
		for (int i = 0; i < c8.length(); i++)
		{
			cout << c8[i];
			Sleep(30);
		}
		Sleep(1000);
		gotoxy(3, 17);
		redintens();
		for (int i = 0; i < c7.length(); i++)
		{
			cout << c7[i];
			Sleep(70);
		}
		Sleep(3000);
		system("cls");
	}
	system("cls");
}
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height;
	Rect.Right = Width;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
void SetWindow1(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}







int main()
{
	SetWindow1(80, 40);
	int dx = 1, i = 5, l = 0;

	while (l < 1)
	{
		i = i + dx;
		if ((i < 1) || (i > 10)) { dx = -dx; l++; }

		SetWindow1(10 * i, 5 * i);
	}

	SetWindow(80, 25);
	system("MODE CON: COLS=81 LINES=26");
	remove_scrollbar();
	ShowConsoleCursor(false);
	system("cls");
	srand(static_cast<int>(time(NULL)));
	string name, r_nicki[10];
	char key;
	int r_wyniki[10];
	int pom = 1, ruch, pkt = 0;
	bool c = true;
	ekran();
	obramowka();
	tytul();
	nazwa();
	system("cls");
	ShowConsoleCursor(true);
	nick(name);
	ShowConsoleCursor(false);
	system("cls");

	do
	{
		menu0(c);
		menu(c, r_wyniki, r_nicki);
		system("color 7");
		gra(name,c);
	} while (c == 0 || c == 1);
	system("PAUSE");
	return 0;
}