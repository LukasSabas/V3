#include "pch.h"
#include "DllV3.h"
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>

using namespace std;
/*
int main()
{
	for (int kiek = 1000;kiek < 1000001;kiek = kiek * 10) {
		int m, t = 0, d = 10, l;
		double laikas2, laikas13, laikas23, laikas33;
		l = kiek;
		//cout << "Iveskite kiek norite sugeneruoti duomenu: 1000, 10000, 100000, 1000000, 10000000" << endl;
		//cin >> l;
		string prad = "duom";
		string pab = ".txt";
		auto kiekis = std::to_string(l);
		string failas = prad + kiekis + pab;
		std::vector<Studentas> stud;
		std::vector<Studentas> stud1;
		std::vector<Studentas> stud2;
		ifstream f;
		f.open(failas);
		if (f.is_open()) {
			m = 0;
			string o, b;
			getline(f, b);
			int k = 0, g = 0;
			while (g < b.length()) {
				if (b[g] == ' ' && b[g + 1] != ' ') {
					k = k + 1;
				}
				g = g + 1;
			}
			k = k - 2;
			while (getline(f, o))
			{
				m = m + 1;
			}
			f.close();
			f.open(failas);
			if (getline(f, b)) {}
			Timer kk;
			for (int i = 0;i < l;i++) {
				Studentas st;
				st.readStudent(f);
				stud.push_back(st);
				st.~Studentas();
			}
			laikas2 = kk.elapsed();
			f.close();
		}
		std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
			return a.getpav() < b.getpav();
			});
		//cout << "Jei norite is karto rasyti i faila spauskite '0', jei norite dalinti i du failus spauskite '1', jei norite tik tinginius perkelti i kita faila spauskite '2':" << endl;
		//cin >> rasymas;
		stud1 = stud;
		stud2 = stud;
		int rasymas;
		for (int skir = 0;skir < 3;skir++) {
			rasymas = skir;
			if (rasymas == 0) {
				skirstymas(stud, l, d, laikas13);
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "Skirstymo metodas" << endl;
				cout << l << " Eiluciu nuskaitymas i vector uztruko: " << laikas2 << endl;
				if (laikas13 != 0) {
					cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus is vector uztruko: " << laikas13 << endl;
				}
				cout << l << " Eiluciu visa programa su vector veike: " << laikas2 + laikas13 << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << endl;
				cout << endl;
			}
			if (rasymas == 1) {
				vectordalinimas(stud1, l, d, laikas23);
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "Dalinimo metodas" << endl;
				cout << l << " Eiluciu nuskaitymas i vector uztruko: " << laikas2 << endl;
				if (laikas23 != 0) {
					cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus is vector uztruko: " << laikas23 << endl;
				}
				cout << l << " Eiluciu visa programa su vector veike: " << laikas2 + laikas23 << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << endl;
				cout << endl;
			}
			if (rasymas == 2) {
				vectorperkelti(stud2, l, d, laikas33);
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "Perkelimo metodas" << endl;
				cout << l << " Eiluciu nuskaitymas i vector uztruko: " << laikas2 << endl;
				if (laikas33 != 0) {
					cout << l << " Eiluciu skirstymas i dvi gruopes ir surasymas i du atskirus failus is vector uztruko: " << laikas33 << endl;
				}
				cout << l << " Eiluciu visa programa su vector veike: " << laikas2 + laikas33 << endl;
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << endl;
				cout << endl;
			}
		}
	}
}



void skirstymas(std::vector <Studentas>& s, int& a, int& b, double& c) {
	int g = 0;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	Timer uu;
	std::string n = "ND";
	std::ofstream mf1("moksliukai.txt");
	std::ofstream mf2("tinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		mf2 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		for (auto& i : s) {
			if (g == 0) {
				if (i.gal(g) < 5.0) {
					mf2 << std::left << std::setw(20) << i.getpav() << std::left << std::setw(20) << i.getvar() << i.gal(g) << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << i.getpav() << std::left << std::setw(20) << i.getvar() << i.gal(g) << std::endl;
				}
			}
			else {
				if (i.gal(g) < 5) {
					mf2 << std::left << std::setw(20) << i.getpav() << std::left << std::setw(20) << i.getvar() << i.gal(g) << std::endl;
				}
				else {
					mf1 << std::left << std::setw(20) << i.getpav() << std::left << std::setw(20) << i.getvar() << i.gal(g) << std::endl;
				}
			}
		}
		s.clear();
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	mf1.close();
	mf2.close();
	c = uu.elapsed();
}



Asmuo::Asmuo() {}
Asmuo::Asmuo(std::string Var, std::string Pav) {
	var = Var;
	pav = Pav;
}
Asmuo::~Asmuo() {}

Studentas::Studentas(std::istream& is) {
	readStudent(is);
}
std::istream& Studentas::readStudent(std::istream& is) {
	is >> this->var >> this->pav;
	this->nd.reserve(10);
	int suma;
	for (int i = 0;i < 10;i++) {
		int x;
		is >> x;
		this->nd.push_back(x);
	}
	is >> this->egz;
}
double Studentas::gal(int a) {
	double med, vid, gal;
	double suma;
	suma = std::accumulate(nd.begin(), nd.end(), 0);
	if (a == 0) {
		vid = suma / nd.size();
		gal = 0.4 * vid + 0.6 * egz;
	}
	else {
		std::sort(nd.begin(), nd.end());
		if (nd.size() % 2) {
			med = 0.5 * (nd[nd.size() / 2 - 1] + nd[nd.size() / 2]);
		}
		else {
			med = nd[nd.size() / 2];
		}
		gal = 0.4 * med + 0.6 * egz;
	}
	return gal;
}
Studentas::~Studentas() {
}

Studentas::Studentas(const Studentas& s1) {
	this->var = s1.var;
	this->pav = s1.pav;
	nd = s1.nd;
	egz = s1.egz;
}
Studentas& Studentas::operator=(const Studentas& s1) {
	if (this == &s1) {
		return *this;
	}
	this->var = s1.var;
	this->pav = s1.pav;
	nd = s1.nd;
	egz = s1.egz;
	return *this;
}


int teigiamas(int& a) {
	if (a < 0) {
		throw std::invalid_argument("Mokiniu skaicius turi buti teigiamas skaicius");
	}
	return (a);
}


void vectordalinimas(std::vector <Studentas>& s, int& a, int& b, double& c) {
	int g = 0;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	std::vector<Studentas> ting;
	std::vector<Studentas> moks;
	ting.reserve(a);
	moks.reserve(a);
	Timer uu;
	if (g == 0) {
		std::copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas& i) {return i.gal(0) < 5;});
		std::copy_if(s.begin(), s.end(), back_inserter(moks), [](Studentas& i) {return i.gal(0) >= 5;});
	}
	else {
		std::copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas& i) {return i.gal(1) < 5;});
		std::copy_if(s.begin(), s.end(), back_inserter(moks), [](Studentas& i) {return i.gal(1) >= 5;});
	}
	s.clear();
	c = uu.elapsed();
	std::ofstream mf1("moksliukai.txt");
	std::ofstream mf2("tinginiai.txt");
	if (mf1.is_open() && mf2.is_open()) {
		mf1 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		mf2 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		if (g == 0) {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.getpav() << std::left << std::setw(20) << t.getvar() << t.gal(g) << std::endl;
			}
			for (auto& m : moks) {
				mf1 << std::left << std::setw(20) << m.getpav() << std::left << std::setw(20) << m.getvar() << m.gal(g) << std::endl;
			}
		}
		else {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.getpav() << std::left << std::setw(20) << t.getvar() << t.gal(g) << std::endl;
			}
			for (auto& m : moks) {
				mf1 << std::left << std::setw(20) << m.getpav() << std::left << std::setw(20) << m.getvar() << m.gal(g) << std::endl;
			}
		}
		ting.clear();
		moks.clear();
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	mf1.close();
	mf2.close();
}


void vectorperkelti(std::vector <Studentas>& s, int& a, int& b, double& c) {
	std::vector<Studentas> ting;
	ting.reserve(a);
	int g = 0;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	std::ofstream mf1("moksliukai.txt");
	std::ofstream mf2("tinginiai.txt");
	int minus;
	Timer uu;
	if (g == 0) {
		std::remove_copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas& i) {return i.gal(0) >= 5;});
		std::remove_if(s.begin(), s.end(), [](Studentas& i) { return i.gal(0) < 5;});
	}
	else {
		std::remove_copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas& i) {return i.gal(1) >= 5;});
		std::remove_if(s.begin(), s.end(), [](Studentas& i) { return i.gal(1) < 5;});
	}
	minus = ting.size();
	s.resize(a - minus);
	c = uu.elapsed();

	if (mf1.is_open() && mf2.is_open()) {
		mf1 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		mf2 << std::left << std::setw(20) << vardas << std::left << std::setw(20) << pavarde << "Galutinis" << std::endl;
		if (g == 0) {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.getpav() << std::left << std::setw(20) << t.getvar() << t.gal(g) << std::endl;
			}
			for (auto& m : s) {
				mf1 << std::left << std::setw(20) << m.getpav() << std::left << std::setw(20) << m.getvar() << m.gal(g) << std::endl;
			}
		}
		else {
			for (auto& t : ting) {
				mf2 << std::left << std::setw(20) << t.getpav() << std::left << std::setw(20) << t.getvar() << t.gal(g) << std::endl;
			}
			for (auto& m : s) {
				mf1 << std::left << std::setw(20) << m.getpav() << std::left << std::setw(20) << m.getvar() << m.gal(g) << std::endl;
			}
		}
		s.clear();
		ting.clear();
	}
	else {
		std::cout << "File could not open" << std::endl;
	}
	mf1.close();
	mf2.close();
}
*/