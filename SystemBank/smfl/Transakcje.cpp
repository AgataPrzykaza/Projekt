#include "klasy.h"

//-----------------Transakcja-----------

Transakcja::Transakcja() :nr_konta(0),data(""), kwota(0), tytul(""), typ("") {};
Transakcja::Transakcja(int nrkonta, string data, double kwota, string tytul, string typ) :
	data(data), nr_konta(nrkonta), kwota(kwota), tytul(tytul), typ(typ) {};
Transakcja::Transakcja(const Transakcja& t) :data(t.data), kwota(t.kwota), nr_konta(t.nr_konta), tytul(t.tytul), typ(t.typ) {};

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

int Transakcja::GetNrKonta()
{
	return nr_konta;
}

//-----------------Przelew-----------
Przelew::Przelew() :nr_odbiorcy(0), Transakcja() {};
//Przelew::Przelew(int nr, Transakcja t) :nr_odbiorcy(nr), Transakcja(t) {};
Przelew::Przelew(int nrodbior, int nrkonta, string data, double kwota, string tytul) :nr_odbiorcy(nrodbior), Transakcja(nrkonta, data, kwota, tytul, "przelew") {};

istream& operator>>(istream& s, Przelew& p)
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
			p.nr_konta = stoi(match.str());
		if (i == 2)
			p.nr_odbiorcy = stoi(match.str());
		if (i == 3)
			p.data = match.str();
		if (i == 4)
			p.kwota = stod(match.str());
		if (i == 5)
			p.tytul = match.str();
		if (i == 6)
			p.typ = match.str();
		i++;
	}
	return s;
}

ostream& operator<<(ostream& s, const Przelew& p)
{
	s << p.nr_konta << " " << p.nr_odbiorcy << " " << p.data << " " << p.kwota << " " << p.tytul << " " << p.typ << endl;
	return s;
}

int Przelew::GetNr_odbiorcy()
{
	return nr_odbiorcy;
}

void Przelew::SetNr_odbiorcy(int nr)
{
	nr_odbiorcy = nr;
}

string Przelew::GiveTransakcja()
{
	return "Odbiorca: " + to_string(nr_odbiorcy) + " " + data + " "+to_string(kwota)+" "+tytul+" "+typ;
}

string Przelew::Show()
{
	string slowa= "Typ: " + typ+ " Data: " + data + " Operacja: " + Round2(kwota)
		+ " Odbiorca: "+to_string(nr_odbiorcy)
		+" Tytul: "+tytul;
	return slowa;
}

//void Przelew::PanelTransakcji(sf::RenderWindow& window)
//{
//	sf::Text text;
//	text.setString("Przelew");
//	text.setFillColor(sf::Color::White);
//	text.setCharacterSize(100);
//	int t = text.getLocalBounds().width;
//	text.setPosition((2400 / 2 - t / 2), 100);
//	window.draw(text);
//
//}
// 
string Przelew::Nazwa()
{
	return "Przelew";
}


//-----------------Wyplata-----------
Wyplata::Wyplata() :Transakcja() {};
Wyplata::Wyplata(int nrkonta, string data, double kwota, string tytul) :Transakcja(nrkonta, data, kwota, tytul, "wyplata/wplata") {};

istream& operator>>(istream& s, Wyplata& w)
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
			w.nr_konta = stoi(match.str());
		if (i == 2)
			w.data = match.str();
		if (i == 3)
			w.kwota = stod(match.str());
		if (i == 4)
			w.tytul = match.str();
		if (i == 5)
			w.typ = match.str();
		i++;
	}
	return s;
}

ostream& operator<<(ostream& s, const Wyplata& w)
{
	s << w.nr_konta << " " << w.data << " " << w.kwota << " " << w.tytul << " " << w.typ << endl;
	return s;
}


string Wyplata::Show()
{
	string slowa = "Typ: " + typ+ " Data: " + data + " Operacja: " + Round2(kwota)
		+ " Tytul: " + tytul ;
	return slowa;
}

string Wyplata::Nazwa()
{
	return "Wyplata/Wplata";
}


//-----------------Kredyt-----------

Kredyt::Kredyt() :Transakcja(), okres(0), rata(0.0) {};
istream& operator>>(istream& s, Kredyt& k)
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
			k.nr_konta = stoi(match.str());
		if (i == 2)
			k.data = match.str();
		if (i == 3)
			k.okres = stoi(match.str());
		if (i == 4)
			k.kwota = stod(match.str());
		if (i == 5)
			k.rata = stod(match.str());
		if (i == 6)
			k.tytul = match.str();
		if (i == 7)
			k.typ = match.str();
		i++;
	}
	return s;

}

ostream& operator<<(ostream& s, const Kredyt& k)
{
	s << k.nr_konta << " " << k.data << " " << k.okres << " " << k.kwota << " " << k.rata << " " << k.tytul << " " << k.typ << endl;
	return s;
}

double Kredyt::Aktualizuj()
{
	if (kwota > 0)
	{
		kwota = kwota - rata;
		data = GetDataNow();
		return rata;
	}
	else if (kwota < 0)
	{
		kwota = 0.0;
		data = GetDataNow();
	}
	
	return 0.0;
}

string Kredyt::Show()
{
	
	string slowa = "Typ: " + typ + " Data: " + data + " Kwota: " + Round2(kwota)
		+" Okres: "+ to_string(okres)+" Rata: "+Round2(rata)+" Tytul: " + tytul;
	return slowa;
}

string Kredyt::Nazwa()
{
	return "Kredyt";
}

//string Round2(double l)
//{
//	string tmp = to_string(l);
//	tmp.erase(tmp.end() - 4, tmp.end());
//	return tmp;
//}
vector<Transakcja*> Sortowanie(vector<Transakcja*> v)
{
	vector<Transakcja*> tmp=v;
	
	int j;
	Transakcja* pom;
	for (int i = 1; i < v.size(); i++)
	{
		pom = v[i];
		j = i - 1;

		while (j >= 0 && CzyWiekszaData(v[j]->GetData(), pom->GetData()))
		{
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = pom;
	}

	return v;
}

bool CzyWiekszaData(string a, string b) //co mlodsze
{
	string tmp1 ;
	tmp1.assign(a.end() - 4,a.end());

	string tmp2;
	tmp2.assign(b.end() - 4, b.end());

	if (a == b)
		return false;

	if (stoi(tmp1) > stoi(tmp2))
		return true;
	else if (stoi(tmp1) < stoi(tmp2))
		return false;
	else
	{
		tmp1.assign(a.end() - 7, a.end() - 5);
		tmp2.assign(b.end() - 7, b.end() - 5);
		if (stoi(tmp1) > stoi(tmp2))
			return true;
		else if (stoi(tmp1) < stoi(tmp2))
			return false;
		else
		{
			tmp1.assign(a.begin(), a.end() - 8);
			tmp2.assign(b.begin(), b.end() - 8);

			if (stoi(tmp1) > stoi(tmp2))
				return true;
			else if (stoi(tmp1) < stoi(tmp2))
				return false;
			else
				return false;

		}
	}
}