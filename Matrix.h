#pragma once
#include <iostream>
using namespace std;

class Row {
private:
	double* string;
	int n;
public:
	Row(double* src, int n);
	Row(const Row& other);
	~Row();
	double operator[] (int i);
};

class Matrix
{
protected:
	double** mtr;
	int m, n;
	static int cnt;
public:
	Matrix();
	Matrix(double** mtr1, int m, int n);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix operator +(const Matrix& other)const;
	Matrix operator *(const Matrix& other)const;
	Matrix operator *(double r);
	Row operator[](int i);
	Matrix transpose()const;
	friend ostream& operator<< (ostream& out, Matrix& object);
	int get_n() { return n; }
	int get_m() { return m; }
};
