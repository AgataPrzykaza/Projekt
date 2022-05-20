#include"klasy.h"

//-----------------OSOBA-----------
Osoba::Osoba(int id,string i, string n, string m, string h, string p, string a, string nr)
	:idOsoby(id),imie(i), nazwisko(n), mail(m), haslo(h), pesel(p), adres(a), nr_dowodu(nr) {};

Osoba::Osoba() :idOsoby(0),imie(""), nazwisko(""), mail(""), haslo(""), pesel(""), adres(""), nr_dowodu("") {};
Osoba::Osoba(const Osoba& o) :idOsoby(o.idOsoby),imie(o.imie), nazwisko(o.nazwisko), mail(o.mail), haslo(o.haslo), pesel(o.pesel),
adres(o.adres), nr_dowodu(o.nr_dowodu) {};

istream& operator>>(istream& s, Osoba& o)
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
			o.idOsoby = stoi(match.str());
		if (i == 2)
			o.imie = match.str();
		if (i == 3)
			o.nazwisko = match.str();
		if (i == 4)
			o.mail = match.str();
		if (i == 5)
			o.haslo = match.str();
		if (i == 6)
			o.pesel = match.str();
		if (i == 7)
			o.adres = match.str();
		if (i == 8)
			o.adres = o.adres + " " + match.str();
		if (i == 9)
			o.nr_dowodu = match.str();
		i++;
	}
	return s;

}
ostream& operator<<(ostream& s, const Osoba& o)
{
	s << o.idOsoby << " " << o.imie << " " << o.nazwisko << " " << o.mail << " " << o.haslo << " " <<
		o.pesel << " " << o.adres << " " << o.nr_dowodu;
	return s;
}
//-----------------KONTO-----------
Konto::Konto() :Osoba(), nr_konta(0), saldo(0), typ("") {};
Konto::Konto(int nr, double s, string t, Osoba o)
	:Osoba(o), nr_konta(nr), saldo(s), typ(t) {};

istream& operator>>(istream& s, Konto& k)
{
	regex slowa("[^\\s]+");
	string ss;
	getline(s, ss);
	auto words_begin = sregex_iterator(ss.begin(), ss.end(), slowa);
	auto words_end = sregex_iterator();
	int i = 1;

	for (sregex_iterator n = words_begin; n != words_end; ++n)
	{
		smatch match = *n;
		
		if (i == 1)
			k.idOsoby = stoi(match.str());
		if (i == 2)
			k.nr_konta = stoi(match.str());
		if (i == 3)
			k.saldo= stod(match.str());
		if (i == 4)
			k.typ = match.str();
		i++;
	}
	return s;
}
ostream& operator<<(ostream& s, const Konto& k)
{
	s <<k.idOsoby << " " << k.nr_konta << " " << k.saldo << " " << k.typ;
	return s;
}
string Konto::GetAdres()
{
	return adres;
}
int Konto::GetIdOsoby()
{
	return idOsoby;
}
void Konto::SetIdOsoby(int id)
{
	idOsoby = id;
}
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
string Konto::GetType()
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

string Transakcja::GetData()
{
	return data;
}
void Transakcja::SetData(string d)
{
	data = d;
}
double Transakcja::GetKwota()
{
	return kwota;
}
void Transakcja::SetKwota(double k)
{
	kwota = k;
}

string Transakcja::GetTytul()
{
	return tytul;
}
void Transakcja::SetTytul(string t)
{
	tytul = t;
}

string Transakcja::GetTyp()
{
	return typ;
}

void Transakcja::SetTyp(string t)
{
	typ = t;
}


//-----------------Przelew-----------
Przelew::Przelew() :nr_odbiorcy(0), Transakcja() {};
Przelew::Przelew(int nr, Transakcja t) :nr_odbiorcy(nr), Transakcja(t) {};

//-----------------Wyplata-----------
Wyplata::Wyplata() :Transakcja() {};
