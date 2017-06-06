#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "rk4.h"

using namespace std;

#define N 2 //iloœæ równañ w uk³adzie
#define ITER 110 //maksymalna iloœæ kroków ca³kowania

double g = 9.81;//przyspieszenie grawitacyjne
double l = 3;//d³ugoœæ wahad³a

void rhs(double x, double y[], double out[]);//funkcja licz¹ca prawe strony równañ
double e_mech(double al, double om);//zwraca energiê mechaniczn¹ na kg masy

int main() {
	ofstream fout = ofstream("output.txt");

	double t0 = 0;//pocz¹tkowy czas
	double tf = 10;//koñcowy czas

	double al0 = M_PI / 6;//pocz¹tkowe wychylenie
	double om0 = M_PI / 4;//pocz¹tkowa prêdkoœæ k¹towa

	cout << "Podaj dlugosc wahadla:\n";
	cin >> l;
	cout << "Podaj poczatkowe wychylenie:\n";
	cin >> al0;
	cout << "Podaj poczatkowa predkosc katowa:\n";
	cin >> om0;

	double h = 0.1;//krok ca³kowania

	double y[ITER][N] = { 0 };//tablica wartoœci wektorów [t][n]

	y[0][0] = al0;
	y[0][1] = om0;

	for (int i = 0; t0 + i*h < tf; i++) {
		vrk4(t0 + i*h, y[i], h, N, rhs, y[i + 1]);//krok ca³kowania
	}

	cout << "t\talfa\tomega\tenergia\n";
	for (int i = 0; i < 100; i++) {
		cout << t0 + i*h << "\t" << y[i][0] << "\t" << y[i][1] << "\t" << e_mech(y[i][0], y[i][1]) << endl;
	}

	//system("notepad output.txt");
	system("pause");
	return 0;
}

void rhs(double x, double y[], double out[]) {
	out[0] = y[1];//alfa'
	out[1] = -g / l*sin(y[0]);//omega'
}

double e_mech(double al, double om) {
	double pot = g*(1 - cos(al))*l;//energia potencjalna grawitacji
	double kin = l*l*om*om / 2;//energia kinetyczna
	return pot + kin;
}
