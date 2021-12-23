#pragma once
#ifndef _DLLV3_H_
#define _DLLV3_H_

#include <iostream>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <numeric>


#ifdef DLLV3_EXPORTS
#define DLLV3_API __declspec(dllexport)
#else
#define DLLV3_API __declspec(dllimport)
#endif

using std::cout;
using std::endl;
using std::wcout;
using std::wstring;

class Asmuo {
protected:
	std::string var;
	std::string pav;
public:
	inline std::string getvar() const { return var; };
	inline std::string getpav() const { return pav; };
	virtual std::string vardas() = 0;
	virtual std::string pavarde() = 0;

	Asmuo() {}
	Asmuo(std::string Var, std::string Pav) {
		var = Var;
		pav = Pav;
	}
	~Asmuo() {}
};

class Studentas : public Asmuo {
private:
	std::vector<int> nd{};
	double egz;
public:
	Studentas() : egz(0), Asmuo() { }

	std::string vardas() { return var; };
	std::string pavarde() { return pav; };


	Studentas(std::istream& is) {
	readStudent(is);
	}

std::istream& readStudent(std::istream& is) {
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
double gal(int a) {
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
~Studentas() {
}
Studentas(const Studentas& s1) {
	this->var = s1.var;
	this->pav = s1.pav;
	nd = s1.nd;
	egz = s1.egz;
}
Studentas& operator=(const Studentas& s1) {
	if (this == &s1) {
		return *this;
	}
	this->var = s1.var;
	this->pav = s1.pav;
	nd = s1.nd;
	egz = s1.egz;
	return *this;
}

};

extern "C"
DLLV3_API int teigiamas(int& a);

extern "C"
DLLV3_API void skirstymas(std::vector <Studentas>&s, int& a, int& b, double& c);

extern "C"
DLLV3_API void vectordalinimas(std::vector <Studentas>&s, int& a, int& b, double& c);

extern "C"
DLLV3_API void vectorperkelti(std::vector <Studentas>&s, int& a, int& b, double& c);

class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock>start;
public:
	Timer() :start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};

#endif