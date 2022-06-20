module;

#include<iostream>
#include<ranges>
#include<regex>
#include<string>
#include<ctime>
#include<windows.h>
#include<WinBase.h>


export module funkcje;

using namespace std;


export string Round2(double l)
{
	string tmp = to_string(l);
	tmp.erase(tmp.end() - 4, tmp.end());
	return tmp;
};

export double Rata(string kwota, string okres)
{
	double rata;
	rata = (stod(kwota) * 1.13) / stod(okres);

	return rata;
}

export bool checkKredytData(string data) {
	string tmp1;
	SYSTEMTIME st;
	GetSystemTime(&st);
	string month = to_string(st.wMonth);
	string year = to_string(st.wYear);

	tmp1.assign(data.end() - 4, data.end());
	int dataYear = stoi(tmp1.assign(data.end() - 4, data.end()));
	int dataMonth = stoi(tmp1.assign(data.end() - 7, data.end() - 5));

	if (st.wMonth > dataMonth || (st.wMonth <= dataMonth && st.wYear > dataYear)) {
		return true;
	}
	return false;
}

export string GetDataNow() {
	SYSTEMTIME st;
	GetSystemTime(&st);

	string day = to_string(st.wDay);
	string month = to_string(st.wMonth);
	string year = to_string(st.wYear);
	if (stoi(month) < 10) {
		month = "0" + month;
	}
	string data = day + "." + month + "." + year;

	return data;
}

export bool CzyTekst(string s)
{
	bool test = false;
	for (auto i : s)
	{
		if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122) || (i >= 48 && i <= 57))
		{
			test = true;
		}
		else
		{
			test = false;
			break;
		}
	}
	return test;
}

export bool CzyLiczba(string s)
{
	bool test = false;
	for (auto i : s)
	{
		if (i >= 48 && i <= 57)
		{
			test = true;
		}
		else
		{
			test = false;
			break;
		}
	}
	return test;
}


