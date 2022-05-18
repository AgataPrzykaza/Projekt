#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<filesystem>
#include<fstream>
using namespace std;



class Osoba
{
protected:
	string imie;
	string nazwisko;
	string mail;
	string haslo;
	string pesel;
	string adres;
	string nr_dowodu;


public:

	Osoba();
	Osoba(string, string, string, string, string,string,string);
	Osoba(const Osoba& o);

	~Osoba() {};
};

class Transakcja
{
private:

	string data;
	double kwota;
	string	tytul;
	string	typ;
public:
	Transakcja();
	Transakcja(string, double, string,string);
	Transakcja(const Transakcja& t);
	void Dodaj();
	void Odejmij();
	void Show();

	~Transakcja() {};
};

class Przelew :public Transakcja
{
private:
	int nr_odbiorcy;
public:
	Przelew(int,Transakcja);
	Przelew();
	~Przelew() {};
};

class Kredyt :public Transakcja
{
private:
	string okres;
	string rata;
	string procent;
public:
	Kredyt() {};
	void WeryfikacjaZdolnosci() {};
	void Dodaj() {};
	void Odejmij() {};
	void Show() {};
	~Kredyt() {};
};

class Wyplata :public Transakcja
{
private:

public:
	Wyplata();
	void Dodaj();
	void Odejmij();
	void Show();
	~Wyplata();
};
class Konto :private Osoba
{
private:
	int nr_konta;			
	double saldo;
	char typ;		//czy firmowe czy indywidualne

public:
	Konto();
	Konto(int, double, char,Osoba);  //dziala
	string GetImie();
	string GetNazwisko();
	void SetImie(string);
	void SetNazwisko(string);
	string GetMail();
	void SetMail(string);
	string GetHaslo();
	void SetHaslo(string);		
	char GetType();
	void SetType(char);
	int GetNrKonta();
	void SetNrKonta(int);
	string GetPesel();
	void SetPesel(string);
	string GetNrDowodu();
	void SetNrDowodu(string);

	double GetSaldo();				//ok
	void ChangeSaldo(double);		//ok
	void DodajKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void UsunKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void Modyfikacja(vector<pair<Konto, vector<Transakcja*>>>, Konto);
	~Konto() {};

};
class Menu
{

private:
	vector < pair<Konto, vector<Transakcja*>>> baza;	//klienci i historia
	vector<Konto> klienci;								//klienici
	bool status;		//czy zalogowany
	bool uprawnienia;		//czy admin
	int lastUserId;			//do generacji indywidualnych numerów kont

public:
	Menu() {};

	void GetBaza();
	void SaveBaza() {};
	~Menu() {};
};