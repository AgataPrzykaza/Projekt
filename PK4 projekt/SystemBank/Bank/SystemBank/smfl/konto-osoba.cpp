#include"klasy.h"

//-----------------OSOBA-----------
Osoba::Osoba(string i, string n, string m, string h, string p, string a, string nr)
	:imie(i), nazwisko(n), mail(m), haslo(h), pesel(p), adres(a), nr_dowodu(nr) {};

Osoba::Osoba() :imie(""), nazwisko(""), mail(""), haslo(""), pesel(""), adres(""), nr_dowodu("") {};
Osoba::Osoba(const Osoba& o) :imie(o.imie), nazwisko(o.nazwisko), mail(o.mail), haslo(o.haslo), pesel(o.pesel),
adres(o.adres), nr_dowodu(o.nr_dowodu) {};


//-----------------KONTO-----------
Konto::Konto() :Osoba(), nr_konta(0), saldo(0), typ() {};
Konto::Konto(int nr, double s, char t, Osoba o)
	:Osoba(o), nr_konta(nr), saldo(s), typ(t) {};

string Konto::GetImie()			//ok
{
	return imie;
}
string Konto::GetNazwisko()			//ok
{
	return nazwisko;
}
void Konto::SetImie(string i)
{
	imie = i;
	return;
}
void Konto::SetNazwisko(string i)
{
	nazwisko = i;
	return;
}
string Konto::GetMail()			//ok
{
	return mail;
}
string Konto::GetHaslo()			//ok
{
	return haslo;
}

void Konto::SetMail(string i)
{
	mail = i;
	return;
}
void Konto::SetHaslo(string i)
{
	haslo = i;
	return;
}
double Konto::GetSaldo()
{
	return saldo;
}
void Konto::ChangeSaldo(double kwota)
{
	saldo = kwota;
}
char Konto::GetType()
{
	return typ;
}
void Konto::SetType(char t)
{
	typ = t;
}
int Konto::GetNrKonta()
{
	return nr_konta;
}
void Konto::SetNrKonta(int nr)
{
	nr_konta = nr;
}
void Konto::SetPesel(string p)
{
	pesel = p;
}
string Konto::GetPesel()
{
	return pesel;
}

void Konto::SetNrDowodu(string nr)
{
	nr_dowodu = nr;
}
string Konto::GetNrDowodu()
{
	return nr_dowodu;
}


//-----------------Transakcja-----------

Transakcja::Transakcja() :data(""), kwota(0), tytul(""), typ(""){};
Transakcja::Transakcja(string data, double kwota, string tytul, string typ) :
	data(data), kwota(kwota), tytul(tytul), typ(typ) {};
Transakcja::Transakcja(const Transakcja& t) :data(t.data), kwota(t.kwota), tytul(t.tytul), typ(t.typ) {};
//-----------------Przelew-----------
Przelew::Przelew() :nr_odbiorcy(0), Transakcja() {};
Przelew::Przelew(int nr, Transakcja t) :nr_odbiorcy(nr), Transakcja(t) {};