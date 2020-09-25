#include<iostream>
using namespace std;
#include"speechManager.h"
#include<ctime>


int main()
{

	srand((unsigned int)time(NULL));
	speechManager s;

	

	int choose = 0;

	while (true)
	{
		s.show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			s.startSpeech();
			break;
		case 2:
			s.showRecord();
			break;
		case 3:
			break;
		case 0:
			s.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

