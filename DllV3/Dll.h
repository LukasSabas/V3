#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <windows.h>


#ifdef DLLV3_EXPORTS
#define DLLV3_API __declspec(dllv3export)
#else
#define DLLV3_API __declspec(dllv3import)
#endif

extern "C"
DLLV3_API class Asmuo {
protected:
	std::string var;
	std::string pav;
public:
	Asmuo(std::string, std::string);
	Asmuo();
	~Asmuo();
	inline std::string getvar() const { return var; };
	inline std::string getpav() const { return pav; };
	virtual std::string vardas() = 0;
	virtual std::string pavarde() = 0;

};

extern "C"
DLLV3_API class Studentas : public Asmuo {
private:
	std::vector<int> nd{};
	double egz;
public:
	Studentas() : egz(0), Asmuo() { }
	Studentas(std::istream& is);

	std::istream& readStudent(std::istream& is);
	double gal(int a);
	std::string vardas() { return var; };
	std::string pavarde() { return pav; };
	Studentas(const Studentas& s1);
	Studentas& operator=(const Studentas& s1);
	~Studentas();

};

extern "C"
DLLV3_API int teigiamas(int& a);

extern "C"
DLLV3_API void skirstymas(std::vector <Studentas>&s, int& a, int& b, double& c);

extern "C"
DLLV3_API void vectordalinimas(std::vector <Studentas>&s, int& a, int& b, double& c);

extern "C"
DLLV3_API void vectorperkelti(std::vector <Studentas>&s, int& a, int& b, double& c);

extern "C"
DLLV3_API class Timer {
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