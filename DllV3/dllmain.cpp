#include "pch.h"
#include "DllV3.h"
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
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
*/

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