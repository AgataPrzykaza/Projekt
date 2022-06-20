#include<iostream>
#include<regex>
#include<filesystem>
#include<fstream>

#include "klasy.h";

using namespace std;

Admin::Admin(int id, string i, string n, string m, string h, string p, string a, string nr)
	: Osoba(id, i, n, m, h, p, a, nr ){};



istream& operator>>(istream& s, Admin& o)
{
	regex slowa("[^\\s]+");
	string ss;
	getline(s, ss);
	auto words_begin = sregex_iterator(ss.begin(), ss.end(), slowa);
	auto words_end = sregex_iterator();
	int i = 1;

	for (sregex_iterator k = words_begin; k != words_end; ++k)
	{
		smatch match = *k;
		if (i == 1)
			o.SetIdOsoby(stoi(match.str()))  ;
		if (i == 2)
			o.SetImie(match.str());
		if (i == 3)
			o.SetNazwisko(match.str());
		if (i == 4)
			o.SetMail(match.str());
		if (i == 5)
			o.SetHaslo(match.str());
		if (i == 6)
			o.SetPesel(match.str());
		if (i == 7)
			o.SetAdres(match.str());
		if (i == 8)
			o.SetAdres(o.GetAdres()+" "+ match.str());
		if (i == 9)
			o.SetNrDowodu(match.str());
		i++;
	}
	return s;

}

ostream& operator<<(ostream& s, const Admin& o)
{
	s << o.idOsoby << " " << o.imie << " " << o.nazwisko << " " << o.mail << " " << o.haslo << " " <<
		o.pesel << " " << o.adres << " " << o.nr_dowodu;
	return s;
}

void Menu::GetPracownicy()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-pracownicy.txt");


	ifstream file(pth);

	vector<Admin> a;

	Admin o;
	while (!file.eof())
	{
		file >> o;
		a.push_back(o);
	}
	a.pop_back();

	pracownicy = a;

	file.close();

}

void Menu::SavePracownicy()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-pracownicy.txt");


	ofstream file(pth);

	for (auto i : pracownicy)
	{
		file << i << endl;
	}


	file.close();
}
bool Menu::GoodPassword2(string mail, string password)
{
	for (auto i : pracownicy)
	{
		if (mail == i.GetMail())
		{
			if (password == i.GetHaslo())
				return true;
			break;
		}
	}
	return false;
}

bool Menu::IsAdmin(string m)
{
	for (auto i : pracownicy)
	{
		if (i.GetMail() == m)
			return true;
	}
	return false;
}