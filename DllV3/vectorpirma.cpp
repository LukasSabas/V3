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
#include "pch.h"
#include "Dll.h"
void vectordalinimas(std::vector <Studentas>& s, int& a, int& b, double& c) {
	int g=0;
	std::string vardas, pavarde;
	vardas = "Vardas";
	pavarde = "Pavarde";
	std::vector<Studentas> ting;
	std::vector<Studentas> moks;
	ting.reserve(a);
	moks.reserve(a);
	Timer uu;
		if (g == 0) {
			std::copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas &i) {return i.gal(0) < 5;});
			std::copy_if(s.begin(), s.end(), back_inserter(moks), [](Studentas &i) {return i.gal(0) >= 5;});
		}
		else {
			std::copy_if(s.begin(), s.end(), back_inserter(ting), [](Studentas &i) {return i.gal(1) < 5;});
			std::copy_if(s.begin(), s.end(), back_inserter(moks), [](Studentas &i) {return i.gal(1) >= 5;});
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