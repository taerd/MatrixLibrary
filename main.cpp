#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "SquareMatrix.h"
#include "InvertibleMatrix.h"
using namespace std;

void fill_mtr1(double** mtr, int m, int n) {
	if (m > 0 && n > 0) {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mtr[i][j] = (rand() % 4);
			}
		}
	}
}

void fill_mtr2(double** mtr, int m, int n) {
	if (m > 0 && n > 0) {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mtr[i][j] = (rand() % 4);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int m = 5;
	int n = 5;
	int m1 = 5;
	int n1 = 5;

	double** mtr = new double* [m];
	for (int i = 0; i < m; i++) {
		mtr[i] = new double[n];
	}
	fill_mtr1(mtr, m, n);
	Matrix a(mtr, m, n);
	cout << "Matrix a" << endl << a << endl;

	double** mtr1 = new double* [m1];
	for (int i = 0; i < m1; i++) {
		mtr1[i] = new double[n1];
	}
	fill_mtr2(mtr1, m1, n1);

	Matrix b(mtr1, m1, n1);
	cout <<endl<< "Matrix b" << endl << b << endl;

	Matrix c;
	cout <<endl<< "Matrix c" << endl << c << endl;

	//THE EQUAL
	c = a;
	cout << endl << "Matrix c = a" << endl << c << endl;

	//THE SUM
	try {
		c = a + b;
		cout << endl << "Matrix c = a + b" << endl << c << endl;
	}
	catch (const char* a) {
		cout <<endl<< "c = a + d : "<< a << endl;
	}

	//THE MULTIPLICATION
	try {
		c = a * b;
		cout << endl << "Matrix c = a * d" << endl << c << endl;
	}
	catch (const char* a) {
		cout <<endl<< "c = a * d : " << a << endl;
	}

	//THE MULTIPLICATION OF MATRIX BY NUMBER
	c = c * 0.1;
	cout << endl << "Matrix c = c * 0.1" << endl << c << endl;

	//TRANSPOSE MATRIX
	Matrix d;
	d = c.transpose();
	cout << endl << "Matrix d = c.transpose()" << endl << d;

	//THE ELEMENT OF MATRIX
	try {
		cout << endl << "Value of c[0][0] is : " << c[0][0] << "  ,Value of c[0][n1-1] is : " << c[0][n1 - 1] << endl;
		cout << endl << "Value of c[m-1][0] is : " << c[m - 1][0] << "  ,Value of c[m-1][n1-1] is : " << c[m - 1][n1 - 1] << endl;
	}
	catch (const char* a) {
		cout << endl << "c[i][j] :  " << a << endl;
	}

	
	SquareMatrix e;
	//SquareMatrix = Matrix
	try {
		e = a;
	}
	catch (const char* a) {
		cout << endl << "e = a " << a << endl;
	}
	cout <<endl<< "SquareMatrix e" << endl << e << endl;
	
	//DETERMINANT OF SquareMatrix
	try {
		cout << endl << "e.determinant : " << e.determinant() << endl;
	}
	catch (const char* a) {
		cout << "e.determinant : " << a << endl;
	}

	InvertibleMatrix f;
	//InvertibleMatrix = Matrix
	try {
		f = a;
	}
	catch (const char* a) {
		cout << endl << "f = a " << a << endl;
	}
	cout << endl << "InvertibleMatrix f" << endl << f << endl;

	//Inverse InvertibleMatrix
	InvertibleMatrix g;
	g = f.Inverse();
	cout << endl << "InvertibleMatrix g" << endl << g << endl;

	SquareMatrix proverka;
	proverka = f * g;
	cout << endl << "SquareMatrix proverka" << endl << proverka << endl;

	for (int i = 0; i < m; i++) {
		delete[]mtr[i];
	}
	delete[]mtr;

	for (int i = 0; i < m1; i++) {
		delete[]mtr1[i];
	}
	delete[]mtr1;

	return 0;
}