#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<filesystem>
#include<fstream>
#include <regex>
using namespace std;



class Osoba
{
protected:
	int		idOsoby;
	string imie;
	string nazwisko;
	string mail;
	string haslo;
	string pesel;
	string adres;
	string nr_dowodu;


public:

	Osoba();
	Osoba(int,string, string, string, string, string,string,string);
	Osoba(const Osoba& o);
	friend istream& operator>>(istream& s, Osoba& o);				//ok
	friend ostream& operator<<(ostream& s, const Osoba& o);			//ok
	~Osoba() {};
};
class Pracownik
{
public:
	Pracownik();
	~Pracownik(){};
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

	string GetData();
	void SetData(string);
	double GetKwota();
	void SetKwota(double);
	string GetTytul();
	void SetTytul(string);
	string GetTyp();
	void SetTyp(string);



	void virtual Dodaj(){};
	void virtual Odejmij(){};
	void virtual Show(){};

	~Transakcja() {};
};

class Przelew :public Transakcja
{
private:
	int nr_odbiorcy;
public:
	Przelew(int,Transakcja);
	Przelew();

	void Dodaj() {};
	void Odejmij() {};
	void Show() {};

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
	void Dodaj(){};
	void Odejmij(){};
	void Show(){};
	~Wyplata();
};
class Konto :private Osoba
{
private:

	int nr_konta;			
	double saldo;
	string typ;		//czy firmowe czy indywidualne

public:
	Konto();
	Konto(int, double, string,Osoba);								//dziala
	friend istream& operator>>(istream& s, Konto& k);				//ok
	friend ostream& operator<<(ostream& s, const Konto& k);			//ok


	string GetImie();
	string GetNazwisko();
	void SetImie(string);
	void SetNazwisko(string);
	string GetMail();
	void SetMail(string);
	string GetHaslo();
	void SetHaslo(string);		
	string GetType();
	void SetType(char);
	int GetNrKonta();
	void SetNrKonta(int);
	string GetPesel();
	void SetPesel(string);
	string GetNrDowodu();
	void SetNrDowodu(string);
	int GetIdOsoby();
	void SetIdOsoby(int);
	string GetAdres();


	double GetSaldo();												//ok
	void ChangeSaldo(double);										//ok
	
	
	void DodajKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void UsunKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void Modyfikacja(vector<pair<Konto, vector<Transakcja*>>>, Konto);
	~Konto() {};

};
class Menu
{

private:
	vector < pair<Konto, vector<Transakcja*>>> baza;	//klienci i historia
	vector<Osoba> klienci;								//klienici
	bool status;										//czy zalogowany
	bool uprawnienia;									//czy admin
	int lastUserId;										//do generacji indywidualnych numerów kont
	Konto logged;

public:
	Menu() {};

	void GetKlienci();
	void SaveKlienci();
	void GetBaza();
	void SaveBaza() {};
	~Menu() {};
};