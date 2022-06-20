#include"klasy.h"
#include<filesystem>


//-----------------MENU----------

void Menu::GetBaza()	
{	
	
	vector < pair<Konto, vector<Transakcja*>>> b;
	for (auto k : konta)
	{
		int numer = k.GetNrKonta();
		vector<Transakcja*> transaction;
		for (auto t : transakcje)
		{
			if (numer == t->GetNrKonta())
				transaction.push_back(t);
			
		}
		pair<Konto, vector<Transakcja*>> para = make_pair(k, transaction);
		b.push_back(para);
	}
	

	baza = b;
}

void Menu::SaveBaza() {
	SaveKlienci();
	SaveKonta();
	SaveTransakcje();
	SaveKredyty();
}
void Menu::GetKlienci()	//zrobiæ by ostania linia nie czytana bo endl
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-dane2.txt");


	ifstream file(pth);
	
	vector<Osoba> osoby;

	Osoba o;
	while (!file.eof())
	{
		file >> o;
		osoby.push_back(o);
	}
	osoby.pop_back();
	klienci = osoby;
	file.close();

}


void Menu::SaveKlienci()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-dane2.txt");

	
	ofstream file(pth);

	for (auto i:klienci)
	{
		file << i<<endl;
	}


	file.close();
}

Osoba Menu::GetSpecificKlient(int id)
{
	for (auto i : klienci)
	{
		if (id == i.GetIdOsoby())
			return i;
	}
}
Osoba Menu::GetSpecificKlient(string mail)
{
	for (auto i : klienci)
	{
		if (mail == i.GetMail())
			return i;
	}
}

void Menu::GetKonta()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-konta2.txt");


	ifstream file(pth);

	vector<Konto> accounts;

	Konto k;
	while (!file.eof())
	{
		file >> k;
		k.SetOsoba(GetSpecificKlient(k.GetIdOsoby()));
		accounts.push_back(k);
	}
	accounts.pop_back();
	konta = accounts;
	file.close();
}

void Menu::SaveKonta()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-konta2.txt");


	ofstream file(pth);

	for (auto i : konta)
	{
		file << i << endl;
	}


	file.close();
}

bool Menu::MailAvailable(string mail)
{
	for (auto i : klienci)
	{
		if (mail == i.GetMail())
			return false;
	}
	return true;
}

bool Menu::GoodPassword(string mail, string password)
{
	for (auto i : klienci)
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

void Menu::GetTransakcje()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-transakcje2.txt");


	ifstream file(pth);

	
	while (!file.eof())
	{
		
		string s;
		getline(file, s);

		stringstream ss(s);
		string type=GetTypeOfTransakcja(s);

		if (type == "przelew")
		{
			Przelew* p = new Przelew;
			ss >> *p;
			transakcje.push_back(p);
		}
		else if (type == "wplata/wyplata")
		{
			Wyplata* w = new Wyplata;
			ss >> *w;
			transakcje.push_back(w);
		}
				
	
		
	}
	//transakcje.pop_back();
	
	file.close();
}

void Menu::showT()
{
	for (auto i : transakcje)
		cout<<i->GetData() << endl;

}

void Menu::SaveTransakcje()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-transakcje2.txt");


	ofstream file(pth);

	for (auto &i : transakcje)
	{
		if (i->GetTyp() == "przelew")
		{
			file << *dynamic_cast<Przelew*>(i);
		}
		else if (i->GetTyp() == "wplata/wyplata")
		{
			file << *dynamic_cast<Wyplata*>(i);
		}
	}
	file.close();
}
void Menu::GetKredyty()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-kredyt2.txt");


	ifstream file(pth);

	while (!file.eof())
	{
		
		
		string s;
		getline(file, s);
		stringstream ss(s);
		Kredyt* k = new Kredyt;
		ss >> *k;
		transakcje.push_back(k);

	}
	transakcje.pop_back();
	file.close();
}

void Menu::SaveKredyty()
{
	filesystem::path pth = std::filesystem::current_path();
	pth /= ("test-kredyt2.txt");


	ofstream file(pth);

	for (auto& i : transakcje)
	{
		if (i->GetTyp() == "kredyt")
		{
			file << *dynamic_cast<Kredyt*>(i);
		}
	
	}
	file.close();

}
string Menu::GetTypeOfTransakcja(string s)	//zwraca typ transakcji
{
	regex slowa("[^\\s]+");	
	auto words_begin = sregex_iterator(s.begin(), s.end(), slowa);
	auto words_end = sregex_iterator();
	
	string typ;
	for (sregex_iterator n = words_begin; n != words_end; ++n)
	{
		smatch match = *n;
		
		typ = match.str();
	}
	return typ;
}

bool Menu::GetStatus()  //czy zalogowana
{
	return status;
}

void Menu::SetStatus(bool s)	//czy zalogowana ustawienie
{
	status = s;
}


vector<Konto> Menu::IleKont(Osoba o)		//ile osoba ma kont
{
	vector<Konto> k;
	for (auto i : konta)
	{
		if (i.GetIdOsoby() == o.GetIdOsoby())
		{
			k.push_back(i);

		}
	}
	return k;
}

void Menu::CreateNewKonto(string s)      // nie dziala wyjatek!
{
	Konto k(LastKontoNr()+1,0.0,s,Osoba(logged.GetIdOsoby(),logged.GetImie(),logged.GetNazwisko(),logged.GetMail(),logged.GetHaslo(),logged.GetPesel(),logged.GetAdres(),logged.GetNrDowodu()));
	konta.push_back(k);
	vector<Transakcja*> t;
	//t.push_back(NULL);
	//t.pop_back();
	pair<Konto, vector<Transakcja*>> para = make_pair(k, t);
	baza.push_back(para);

	
}

int Menu::LastKontoNr()				//ostatni uzyty numer konta
{

	int max = 0;
	for (auto k : konta)
	{
		if (k.GetNrKonta() > max)
		{
			max = k.GetNrKonta();
		}
	}
	return max;
}

vector<Transakcja*> Menu::TransakcjeDlaKonta(Konto k)
{
	for (auto para : baza)
	{
		if (para.first.GetNrKonta() == k.GetNrKonta())
			return para.second;
	}
}

void Menu::Setlogged(Osoba o)
{
	logged = o;
}


void Menu::AktualizujDlaKontaPrzelew(int odbiorca, int kwota)
{
	for (int i=0;i<konta.size();i++)
	{
		if (konta[i].GetNrKonta() == odbiorca)
		{
			konta[i].SetSaldo(konta[i].GetSaldo() + kwota);
			
		}

		if (konta[i].GetNrKonta() == WybraneKonto.GetNrKonta())
		{
			konta[i].Operacja(-kwota);
		}
	}
	
	GetBaza();

}
void Menu::AktualizujSaldo(int kwota)
{
	for (int i = 0; i < konta.size(); i++)
	{
		if (konta[i].GetNrKonta() == WybraneKonto.GetNrKonta())
		{
			konta[i].Operacja(kwota);
		}
	}
	GetBaza();
}






void Menu::ChangePassword(string nowe)
{
	for (auto& i : klienci)
	{
		if (i.GetIdOsoby() == logged.GetIdOsoby())
		{
			i.SetHaslo(nowe);

			break;
		}
	}

	for (auto& i : konta)
	{
		if (i.GetIdOsoby() == logged.GetIdOsoby())
		{
			i.SetHaslo(nowe);

			break;
		}
	}
	
	WybraneKonto.SetHaslo(nowe);
	GetBaza();

}

int Menu::OstatnieID()
{
	int maxN = 0;
	for (auto i : klienci)
	{
		if (i.GetIdOsoby() > 0)
		{
			maxN = i.GetIdOsoby();

		}
	}
	return maxN;
}

void Menu::KredytAktualizuj(Konto &k)
{


	for (auto& i : transakcje)
	{
		if (k.GetNrKonta() == i->GetNrKonta())
		{
			if (i->Nazwa() == "Kredyt" && checkKredytData(i->GetData()) == true)
			{
				k.SetSaldo(k.GetSaldo() - i->Aktualizuj());

			}
		}
	}
	for (auto& i : konta)
	{
		if (i.GetNrKonta() == k.GetNrKonta())
		{
			i = k;
		}
	}

	
}
void Menu::KredytyOdswiezone()
{
	for (auto i : baza)
	{
		
		KredytAktualizuj(i.first);
	}
	GetBaza();
}

bool Menu::CzyJestTakieId(string id)
{
	for (auto i : klienci)
	{
		if (i.GetIdOsoby() == stoi(id))
			return true;
	}
	return false;
}

void Menu::DeleteAccount(string id)
{
	for (int i = 0; i < klienci.size(); i++)
	{
		if (SameAccount(id, klienci[i]))
		{
			klienci.erase(klienci.begin() + i);
		}
	}

	for (int i = 0; i < konta.size(); i++)
	{
		if (SameAccount2(id, konta[i]))
		{
			konta.erase(konta.begin() + i);
		}
	}

	GetBaza();
}


bool Menu::SameAccount(string id,Osoba o)
{
	if (stoi(id) == o.GetIdOsoby())
		return true;
	else
		return false;
}
bool Menu::SameAccount2(string id, Konto o)
{
	if (stoi(id) == o.GetIdOsoby())
		return true;
	else
		return false;
}
bool Menu::IsKonto(string id)
{
	for (auto i : konta)
	{
		if (i.GetNrKonta() == stoi(id))
			return true;

	}
	return false;
}

Konto Menu::KontoDlaNr(string nr)
{
	for (auto i : konta)
	{
			if (i.GetNrKonta() == stoi(nr))
				return i;
	}

	Konto k;
	return k;
}

void Menu::ModifyMail(string mail,string id)
{
	for (int i = 0; i < klienci.size(); i++)
	{
		if (SameAccount(id, klienci[i]))
		{
			klienci[i].SetMail(mail);
			break;
		}
	}

	for (int i = 0; i < konta.size(); i++)
	{
		if (SameAccount2(id, konta[i]))
		{
			konta[i].SetMail(mail);
		}
	}

	GetBaza();
}

bool Menu::CzyNieMaKontoB(Osoba o)
{
	for (auto i : konta)
	{
		if (i.GetIdOsoby() == o.GetIdOsoby())
		{
			return false;
		}
	}

	return true;
}

bool SaldoNieUjemne(Konto k)
{
	if (k.GetSaldo() >= 0)
		return true;
	return false;
}

void Menu::DeleteKonto(Konto k)
{
	for (int i = 0; i < konta.size(); i++)
	{
		if (konta[i].GetNrKonta()==k.GetNrKonta())
		{
			konta.erase(konta.begin() + i);
		}
	}

	GetBaza();
}