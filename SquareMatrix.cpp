#include "SquareMatrix.h"
SquareMatrix::SquareMatrix():Matrix() 
{
	size = n;
}
SquareMatrix::SquareMatrix(double** mtr, int n) : Matrix(mtr, n, n) 
{
	size = this->n;
}
SquareMatrix::SquareMatrix(const SquareMatrix& other):Matrix (other)
{
	size = n;
}
SquareMatrix::SquareMatrix(const Matrix& other) : Matrix(other)
{
	if (n == m) {
		size = n;
	}
	else {
		throw "Second matrix isnt SquareMatrix";
	}
}

double SquareMatrix::determinant()
{
	double det = 1;
	const double EPS = 1E-9;

	double ** copy = new double* [m];

	for (int i = 0; i < m; i++) {
		copy[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			copy[i][j] = this->mtr[i][j];
		}
	}

	for (int i = 0; i < size; ++i) {
		int k = i;

		for (int j = i + 1; j < size; ++j) {
			if (abs(copy[j][i]) > abs(copy[k][i])) k = j;//������ ������ j ������� ������� i  ����� �������
		}

		if (abs(copy[k][i]) < EPS) {//���� �� ��������� ���� 0 �� ������������ = 0
			det = 0;
			break;
		}

		swap(copy[i],copy[k]);//�������� ������� ������ � ����� ������� ��������� i
		if (i != k) det = -det;//���� ���� ������������ �����

		det *= copy[i][i];

		for (int j = i + 1; j < size; ++j) {
			copy[i][j] /= copy[i][i];//������� �������� 0 � �������� ���� ������,
														 //�� ���������� �������� ��������� ��� �������� �������� � �������
		}

		for (int j = 0; j < size; ++j) {
			if (j != i && abs(copy[j][i]) > EPS) {
				for (int k = i + 1; k < size; ++k) {
					copy[j][k] -= copy[i][k] * copy[j][i];//��������� �� ��������� � ���������
				}
			}
		}

	}

	for (int i = 0; i < m; i++) {
		delete[]copy[i];
	}
	delete[]copy;

	return det;
}

