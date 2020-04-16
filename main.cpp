#include <Windows.h>
#include <iostream>
#include <thread>

using namespace std;

bool clicking = false;

void LeftClick()
{
	INPUT    Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}


void Clicker()
{
	while (true)
	{
		Sleep(20);
		if (!clicking)
			continue;

		LeftClick();

	}
}

int main()
{
	SetConsoleTitle("Simple AutoClicker program");


	thread clickerthread(Clicker);

	cout << "Press F8 to start clicking. \n\n";

	// Wait for input
	while (true)
	{
		// Toggle clicking
		if (GetAsyncKeyState(VK_F8) & 1)
		{
			clicking = !clicking;
			if (clicking)
				cout << "Clicking: on\n";
			else
			{
				cout << "Clicking: off\n";
			}
		}
	}
	return 0;
}
