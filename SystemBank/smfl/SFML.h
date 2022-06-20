#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "source.h"
#include "klasy.h"


using namespace std;

class Okno
{
public:

	int width = 2400;
		
	int	height = 2000;
	sf::Text text;
	sf::Font font;
	sf::FloatRect KontoBtnObszar1;
	sf::FloatRect KontoBtnObszar2;
	sf::FloatRect KontoBtnObszar3;
	sf::Text NoweKontoBtn;
	sf::Text NoweKontoBtn2;
	sf::Text CofnijBtn;
	sf::Text loginBtn;                             //przycisk login
	sf::Text rejestracjaBtn;                         //przycisk rejestracji
	sf::RectangleShape poleM;        //pole do wpisywania mail
	sf::Text login;                               //napis email
	sf::RectangleShape poleH;       //pole do wpisywania haslo
	sf::Text haslo;                          //napis haslo
	sf::Text wyswietlMail;                  //wyswietlony wpisany mail
	sf::Text wyswietlHaslo; //wyswietlone wpisane haslo
	int title,loginBtnW, loginBtnH, rejestracjaBtnW, rejestracjaBtnH, loginW, hasloW;
	sf::Text alert;
	string mail;
	string password;
	bool boolMail = false;
	bool boolPassword = false;

	sf::Text Btn;
	sf::Text Btn2;
	sf::Text Btn3;
	sf::Text Btn4;
	sf::Text WyplataBtn;
	sf::Text WplataBtn;

	//Rejestracja
	sf::RectangleShape poleI;
	sf::Text imieT;
	sf::RectangleShape poleN;
	sf::Text nazwiskoT;
	sf::RectangleShape poleMR;
	sf::Text mailT;
	sf::RectangleShape poleHR;
	sf::Text hasloT;
	sf::RectangleShape poleP;
	sf::Text peselT;
	sf::RectangleShape poleA;
	sf::Text adresT;
	sf::RectangleShape poleD;
	sf::Text nrdowodT;

	vector<bool> statusPola;
	string imie;
	string nazwisko;
	string mailR;
	string hasloR;
	string pesel;
	string adres;
	string dowod;

	sf::Text registerBtn;

	sf::Text ZmienHaslo;

	//Transakcja
	
	string kwota;
	string tytul;
	

	//prezlew
	string nr_odbiorcy;

	//kredyt
	string okres;
	

	vector<bool> statusPolTransakcja;
		
	sf::RectangleShape poleKwota;
	sf::Text kwotaT;
	sf::RectangleShape poleTytul;
	sf::Text tytulT;


	sf::RectangleShape poleOdbiorcy;
	sf::Text odbiorcaT;
	sf::RectangleShape poleOkres;
	sf::Text okresT;


	string IdOsoby;
	sf::Text IdOsobyT;
	sf::RectangleShape poleIdOsoby;
	bool IdOsobyB;

	string stareHaslo;
	string noweHaslo;
	bool boolstareHaslo = false;
	bool boolnoweHaslo = false;

	sf::Text starehasloT;
	sf::Text nowehasloT;

	sf::RectangleShape poleStareHaslo;
	sf::RectangleShape poleNoweHalso;

	bool boolid;
	bool boolmailNew;
	string id;
	sf::Text idT;
	sf::RectangleShape poleid;
	string mailNew;
	sf::Text mailNewT;
	sf::RectangleShape polemailNew;

	//Metody
	Konto UstawKonto;


	void SetTexts();
	void ZaladujCzcionke();
	sf::Text Napis(string tekst, int wielkosc, int x, int y);
	void Panel0(sf::RenderWindow &window,sf::Event event,Menu &menu,int&);
	void Panel1(sf::RenderWindow& window, sf::Event event, Menu &menu, int&);
	void Panel2(sf::RenderWindow& window, sf::Event event, Menu &menu, int&);
	void Zalogowany(sf::RenderWindow& window,Menu menu);
	void PanelKontaBankowego4(sf::RenderWindow& window, sf::Event event, Konto k, Menu &menu,int&);
	void Panel3Transakcja(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	void Panel5ZmianaHasla(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	void Panel6Admin(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	string markPassword(string pass);
	sf::Text Pole(string s, int x, int y);

	void Panel7UsunUzytkownika(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	void Panel8ZnajdzKonto(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	void Panel9KontozTrans(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	
	void Panel10Modyfikuj(sf::RenderWindow& window, sf::Event event, Menu& menu, int& panel);
	void Panel11OsobyZKontem(sf::RenderWindow& window, sf::Event event, Menu menu, int& panel);
	void ZerujTransakcje();
};



