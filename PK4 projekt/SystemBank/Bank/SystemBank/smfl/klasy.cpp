#include"klasy.h"
#include<filesystem>


//-----------------MENU----------

void Menu::GetBaza()		//otwiera dobrze,tylko zmodyfikowac by czytala wszystko
{
	filesystem::path pth = std::filesystem::current_path();
	//cout << pth << endl;
	pth /= ("test-dane.txt");

	string tekst;
	ifstream file(pth);
	getline(file, tekst);
	file.close();
	cout << tekst;

}

