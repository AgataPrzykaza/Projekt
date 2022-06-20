#include"klasy.h"

//-----------------OSOBA-----------
Osoba::Osoba(int id,string i, string n, string m, string h, string p, string a, string nr)
	:idOsoby(id),imie(i), nazwisko(n), mail(m), haslo(h), pesel(p), adres(a), nr_dowodu(nr) {};

Osoba::Osoba() :idOsoby(0),imie(""), nazwisko(""), mail(""), haslo(""), pesel(""), adres(""), nr_dowodu("") {};
Osoba::Osoba(const Osoba& o) :idOsoby(o.idOsoby),imie(o.imie), nazwisko(o.nazwisko), mail(o.mail), haslo(o.haslo), pesel(o.pesel),
adres(o.adres), nr_dowodu(o.nr_dowodu) {};


int Osoba::GetIdOsoby()
{
	return idOsoby;
}

void Osoba::SetIdOsoby(int id)
{
	idOsoby = id;
}


string Osoba::GetImie()
{
	return imie;
}
void Osoba::SetImie(string i)
{
	imie = i;
	return;
}

string Osoba::GetNazwisko()			//ok
{
	return nazwisko;
}


void Osoba::SetNazwisko(string i)
{
	nazwisko = i;
	return;
}


string Osoba::GetMail()			//ok
{
	return mail;
}

void Osoba::SetMail(string i)
{
	mail = i;
	return;
}
string Osoba::GetHaslo()			//ok
{
	return haslo;
}
void Osoba::SetHaslo(string i)
{
	haslo = i;
	return;
}

string Osoba::GetPesel()
{
	return pesel;
}


void Osoba::SetPesel(string p)
{
	pesel = p;
}

string Osoba::GetAdres()
{
	return adres;
}
void Osoba::SetAdres(string a)
{
	adres = a;
}

string Osoba::GetNrDowodu()
{
	return nr_dowodu;
}

void Osoba::SetNrDowodu(string nr)
{
	nr_dowodu = nr;
}

Osoba Osoba::operator=(const Osoba& o)
{
	idOsoby = o.idOsoby;
	imie = o.imie;
	nazwisko = o.nazwisko;
	mail = o.mail;
	haslo = o.haslo;
	pesel = o.pesel;
	adres = o.adres;
	nr_dowodu = o.nr_dowodu;
	return *this;
}

string Osoba::Show()
{
	return to_string(idOsoby) + " " + imie + " " + nazwisko + " Mail:" + mail + " Halso:" + haslo + " Pesel:" + pesel + " Adres:" +
		adres + " " + nr_dowodu;
}
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


string Konto::Show()
{
	string t;
	if (typ == "I")
		t = "indywidualne";
	else
		t = "firmowe";

	return to_string(idOsoby) + " " + imie + " " + nazwisko + +" Nr konta:" + to_string(nr_konta)
		+ " Saldo:" + Round2(saldo) + "zl " + t;
}
double Konto::GetSaldo()
{
	return saldo;
}
void Konto::SetSaldo(double kwota)
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


void Konto::SetOsoba(Osoba o)
{
	SetImie(o.GetImie());
	SetNazwisko(o.GetNazwisko());
	SetMail(o.GetMail());
	SetHaslo(o.GetHaslo());
	SetPesel(o.GetPesel());
	SetAdres(o.GetAdres());
	SetNrDowodu(o.GetNrDowodu());


}

string Konto::GiveKontoInString()
{
	string t;
	if (typ == "I")
		t = "indywidualne";
	else
		t = "firmowe";
	return " " + to_string(nr_konta) + " saldo: " + Round2(saldo) + "zl typ: " + t;
}

void Konto::Operacja(int money)
{
	saldo = saldo + money;
}
