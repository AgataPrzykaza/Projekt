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

void Menu::GetKlienci()	//zrobiæ by ostania linia nie czytana bo endl
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-dane.txt");


	ifstream file(pth);
	
	vector<Osoba> osoby;

	Osoba o;
	while (!file.eof())
	{
		file >> o;
		osoby.push_back(o);
	}
	klienci = osoby;
	file.close();

}

void Menu::SaveKlienci()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-dane2.txt");

	string tekst;
	ofstream file(pth);

	for (auto i:klienci)
	{
		file << i<<endl;
	}


	file.close();
}