#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "rk4.h"

using namespace std;

#define N 2 //ilo�� r�wna� w uk�adzie
#define ITER 110 //maksymalna ilo�� krok�w ca�kowania

double g = 9.81;//przyspieszenie grawitacyjne
double l = 1;//d�ugo�� wahad�a

void rhs(double x, double y[], double out[]);

int main() {
	ofstream fout = ofstream("output.txt");

	double t0 = 0;//pocz�tkowy czas
	double tf = 10;//ko�cowy czas

	double al0 = M_PI / 6;//pocz�tkowe wychylenie
	double om0 = 0;//pocz�tkowa pr�dko�� k�towa

	double h = 0.1;//krok ca�kowania

	double y[ITER][N] = { 0 };//tablica warto�ci wektor�w [t][n]

	y[0][0] = al0;
	y[0][1] = om0;

	for (int i = 0; t0 + i*h < tf; i++) {
		vrk4(t0 + i*h, y[i], h, N, rhs, y[i + 1]);
	}

	for (int i = 0; i < 100; i++) {
		fout << y[i][0] << "\t" << y[i][1] << endl;
	}

	//system("pause");
	return 0;
}

void rhs(double x, double y[], double out[]) {
	out[0] = y[1];//omega
	out[1] = -g / l*sin(y[0]);//alfa
}
