#include "InvertibleMatrix.h"
InvertibleMatrix::InvertibleMatrix()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				mtr[i][i] = 1;
			}
		}
	}
}

InvertibleMatrix::InvertibleMatrix(double** _mtr, int _n) : SquareMatrix(_mtr, _n)
{
	if (determinant() == 0) { 
		throw "This Matrix isnt InvertibleMatrix";
	}
}

InvertibleMatrix::InvertibleMatrix(const InvertibleMatrix& other) : SquareMatrix(other)
{
}

InvertibleMatrix::InvertibleMatrix(const Matrix& other) : SquareMatrix(other)
{
	if (determinant() == 0) {
		throw "Second Matrix isnt InvertibleMatrix";
	}
}

InvertibleMatrix InvertibleMatrix::Inverse()
{
	double determinant = this->determinant();

	InvertibleMatrix transp = this->transpose();

	double** inv = new double* [size];
	for (int i = 0; i < size; i++) {
		inv[i] = new double[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			inv[i][j] = pow(-1, i + j) * double(1 / determinant) * minor(transp, i, j);
		}
	}

	InvertibleMatrix c(inv, size);

	for (int i = 0; i < size; i++) {
		delete[] inv[i];
	}
	delete[] inv;

	return c;
}

double InvertibleMatrix::minor(const InvertibleMatrix& other, int _i, int _j)
{
	double** min = new double* [other.size - 1];
	for (int i = 0; i < other.size - 1; i++) {
		min[i] = new double[other.size - 1];
	}

	for (int i = 0; i < other.size - 1; i++) {
		for (int j = 0; j < other.size - 1; j++) {
			if (i < _i) {
				if (j < _j) { min[i][j] = other.mtr[i][j]; }//до
				else { min[i][j] = other.mtr[i][j + 1]; }//после
			}
			else {
				if (j < _j) { min[i][j] = other.mtr[i + 1][j]; }
				else { min[i][j] = other.mtr[i + 1][j + 1]; }
			}
		}
	}

	SquareMatrix minor(min, other.size - 1);

	double res = minor.determinant();

	for (int i = 0; i < other.size - 1; i++) {
		delete[]min[i];
	}
	delete[]min;

	return res;
}
