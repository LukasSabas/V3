#include "../DllV3/DllV3.h"
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

int main()
{
	for (int kiek = 1000;kiek < 100001;kiek = kiek * 10) {
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
	system("pause");
}