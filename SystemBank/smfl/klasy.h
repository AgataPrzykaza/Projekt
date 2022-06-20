#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include<vector>
#include<filesystem>
#include<fstream>
#include <regex>
#include<ranges>
#include<algorithm>
#include<ctime>
#include<windows.h>
#include<WinBase.h>
import funkcje;

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
	Osoba operator=(const Osoba& o);
	friend istream& operator>>(istream& s, Osoba& o);				//ok
	friend ostream& operator<<(ostream& s, const Osoba& o);			//ok

	string Show();
	int GetIdOsoby();			//ok
	void SetIdOsoby(int);		//ok

	string GetImie();			//ok
	void SetImie(string);		//ok

	string GetNazwisko();		//ok
	void SetNazwisko(string);	//ok

	string GetMail();			//ok
	void SetMail(string);		//ok

	string GetHaslo();			//ok
	void SetHaslo(string);		//ok

	string GetPesel();			//ok
	void SetPesel(string);		//ok

	string GetAdres();			//ok
	void SetAdres(string);		//ok
	string GetNrDowodu();		//ok
	void SetNrDowodu(string);	//ok
	
	


	~Osoba() {};
};

class Transakcja
{
protected:
	int nr_konta;
	string data;
	double kwota;
	string	tytul;
	string	typ;
public:
	

	Transakcja();
	Transakcja(int, string, double, string, string);
	Transakcja(const Transakcja& t);

	string GetData();
	void SetData(string);
	double GetKwota();
	void SetKwota(double);
	string GetTytul();
	void SetTytul(string);
	string GetTyp();
	void SetTyp(string);
	int GetNrKonta();
	void SetNrKonta(int);


	virtual void  Dodaj() =0;
	
	virtual string Show()=0;
	virtual string  GiveTransakcja()=0;
	virtual string Nazwa()=0;
	virtual double Aktualizuj() = 0;
	
	//virtual void PanelTransakcji(sf::RenderWindow&)=0;
	
	~Transakcja() {};
};

class Przelew :public Transakcja
{
private:
	int nr_odbiorcy;
public:
	Przelew(int, Transakcja);
	Przelew();
	Przelew(int, int, string, double, string);

	friend istream& operator>>(istream& s, Przelew& p);			//ok	
	friend ostream& operator<<(ostream& s, const Przelew& p);	//ok		

	void SetNr_odbiorcy(int);
	int GetNr_odbiorcy();

	void Dodaj(){};
	void Odejmij() {};
	string Show() ;
	
	string GiveTransakcja();
	string Nazwa();
	double  Aktualizuj() { return 0.0; };
	
	//void PanelTransakcji(sf::RenderWindow&);

	~Przelew() {};
};

class Kredyt :public Transakcja
{
private:
	int okres;
	double rata;

public:
	Kredyt();

	friend istream& operator>>(istream& s, Kredyt& k);			    //ok	
	friend ostream& operator<<(ostream& s, const Kredyt& k);		//ok	
	string GiveTransakcja() { return ""; };
	string Nazwa() ;
	
	double GetRata()
	{
		return rata;
	}

	//void PanelTransakcji(sf::RenderWindow&) { return; };
	void WeryfikacjaZdolnosci() {};
	void Dodaj() {};
	
	void Odejmij() {};
	string Show();
	double Aktualizuj();
	~Kredyt() {};
};

class Wyplata :public Transakcja
{
public:
	Wyplata();
	Wyplata(int, string, double, string);

	friend istream& operator>>(istream& s, Wyplata& w);			//ok		
	friend ostream& operator<<(ostream& s, const Wyplata& w);	//ok			

	void Dodaj(){};
	void Odejmij() {};
	string Show();
	
	//void PanelTransakcji(sf::RenderWindow&) { return; };
	string GiveTransakcja() { return ""; };
	string Nazwa();
	double Aktualizuj() { return 0.0; };
	~Wyplata() {};
};
class Konto :public Osoba
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


	
	
	string GetType();
	void SetType(char);
	int GetNrKonta();
	void SetNrKonta(int);

	double GetSaldo();												//ok
	void SetSaldo(double);										//ok
	
	void SetOsoba(Osoba);
	
	void Operacja(int money);

	string Show();

	void DodajKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void UsunKonto(vector<pair<Konto, vector<Transakcja*>>>);
	void Modyfikacja(vector<pair<Konto, vector<Transakcja*>>>, Konto);

	string GiveKontoInString();
	~Konto() {};

};

class Admin:public Osoba
{
public:
	Admin() :Osoba() {};
	Admin(int, string, string, string, string, string, string, string);
	
	/*void UsunKlienta(Menu& menu, Konto k);
	void ZmienHaslo(Menu& menu, string nowe);*/

	friend istream& operator>>(istream& s, Admin& o);				//ok
	friend ostream& operator<<(ostream& s, const Admin& o);			//ok
	
	~Admin() {};
};

class Menu
{

private:
public:
	vector < pair<Konto, vector<Transakcja*>>> baza;	//klienci i historia
	vector<Osoba> klienci;								//klienici
	vector<Konto> konta;
	vector<Transakcja*> transakcje;
	bool status;										//czy zalogowany
	bool uprawnienia;									//czy admin
	int lastUserId = 30000;										//do generacji indywidualnych numerów kont
	Transakcja* operacja;
	vector<Admin> pracownicy;

	Osoba logged;
	Konto WybraneKonto;


	Menu() {};

	void GetKlienci();									//ok
	void SaveKlienci();									//ok

	Osoba GetSpecificKlient(int);
	Osoba GetSpecificKlient(string mail);
	bool GetStatus();
	void SetStatus(bool);
	void Setlogged(Osoba);

	void GetKonta();									//ok
	void SaveKonta();									//ok

	bool MailAvailable(string);							//ok
	bool GoodPassword(string, string);	
	bool GoodPassword2(string, string);	//ok
	string GetTypeOfTransakcja(string s);	//ok;

	void GetTransakcje();								//ok
	void SaveTransakcje();								//ok

	void GetKredyty();									//ok
	void SaveKredyty();									//ok

	void showT();										//ok

	void GetBaza();										//ok
	void SaveBaza();									//ok

	void CreateNewKonto(string s);
	void GetPracownicy();
	void SavePracownicy();
	
	
	void ModifyPassword() {};
	void ModifyMail(string mail,string id);
	void DeleteAccount(string id);
	void CreateAccount() {  };

	bool SameAccount(string id,Osoba o);
	bool SameAccount2(string id, Konto o);
	bool CzyJestTakieId(string id);
	bool IsKonto(string id);

	void ChangePassword(string nowe);
	int OstatnieID();
	bool Email_check(string email)
	{
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		return regex_match(email, pattern);
	}

	vector<Konto> IleKont(Osoba);

	int LastKontoNr();

	vector<Transakcja*> TransakcjeDlaKonta(Konto k);
	Konto KontoDlaNr(string nr);

	void AktualizujDlaKontaPrzelew(int odbiorca, int kwota);
	void AktualizujSaldo(int kwota);
	void KredytAktualizuj(Konto&);
	void KredytyOdswiezone();
	bool IsAdmin(string);
	bool CzyNieMaKontoB(Osoba o);

	void DeleteKonto(Konto k);


	~Menu() {};
};






vector<Transakcja*> Sortowanie(vector<Transakcja*>);
bool CzyWiekszaData(string a, string b);
bool SaldoNieUjemne(Konto k);







//bool CzyLiczba(string s);
//bool CzyTekst(string s);
//string Round2(double);


//string GetDataNow();
//double Rata(string kwota, string okres);
//bool checkKredytData(string data);