#include "Matrix.h"

int Matrix::cnt = 0;

Matrix::Matrix()
{
	m = 5;
	n = 5;
	mtr = new double* [m];
	for (int i = 0; i < m; i++) {
		mtr[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mtr[i][j] = 0;
		}
	}
	cnt++;
}

Matrix::Matrix(double** mtr1, int m1, int n1)
{
	if (mtr1 && m1 > 0 && n1 > 0) {

		mtr = new double* [m1];
		for (int i = 0; i < m1; i++) {
			mtr[i] = new double[n1];
		}

		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < n1; j++) {
				mtr[i][j] = mtr1[i][j];
			}
		}

		m = m1;
		n = n1;
	}
	else Matrix();
	cnt++;
}

Matrix::Matrix(const Matrix& other)
{
	m = other.m;
	n = other.n;

	mtr = new double* [m];
	for (int i = 0; i < m; i++) {
		mtr[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			this->mtr[i][j] = other.mtr[i][j];
		}
	}

	cnt++;
}

Matrix::~Matrix()
{
	if (mtr) {
		for (int i = 0; i < m; i++) {
			delete[]mtr[i];
		}
		delete[]mtr;
	}
	cnt--;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other) return *this;

	if (mtr) {
		for (int i = 0; i < m; i++) {
			delete[]mtr[i];
		}
		delete[]mtr;
	}

	m = other.m;
	n = other.n;

	mtr = new double* [m];
	for (int i = 0; i < m; i++) {
		mtr[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mtr[i][j] = other.mtr[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& other)const
{
	if ((m == other.m) && (n == other.n)) {

		double** src = new double* [m];//матрица хранящая в себе сумму элементов двух матриц
		for (int i = 0; i < m; i++) {
			src[i] = new double[n];
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				src[i][j] = mtr[i][j] + other.mtr[i][j];
			}
		}

		Matrix b(src, m, n);

		for (int i = 0; i < m; i++) {
			delete[]src[i];
		}
		delete[]src;

		return b;
	}
	else {
		throw "Different size of matrix";
	}
}

Matrix Matrix::operator*(const Matrix& other)const
{
	if (n == other.m) {

		const double EPS = 1E-9;

		double** src = new double* [m];//матрица хранящая в себе произведение элементов двух матриц
		for (int i = 0; i < m; i++) {
			src[i] = new double[other.n];
		}

		Matrix r(other);
		Matrix d;
		d = r.transpose();

		for (int i = 0; i < m; i++) {//умножение на транспонированную и запись(если матрицы квадратные так быстрее)
			for (int j = 0; j < other.n; j++) {
				src[i][j] = 0;
				for (int k = 0; k < n; k++) {
					src[i][j] += mtr[i][k] * d.mtr[j][k];
					if (abs(src[i][j]) < EPS) { src[i][j] = 0; }
				}
			}
		}

		Matrix b(src, m, other.n);

		for (int i = 0; i < m; i++) {
			delete[]src[i];
		}
		delete[]src;

		return b;
	}
	else throw "Different size of matrix";
}

Matrix Matrix::operator*(double r)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mtr[i][j] = r * mtr[i][j];
		}
	}
	return *this;
}

Row Matrix::operator[](int i)
{
	if (i >= 0 && i <= m) {
		Row b(mtr[i], n);
		return b;
	}
	else throw "i is out of range matrix";
}

Matrix Matrix::transpose()const
{
	double** copy = new double* [n];
	for (int i = 0; i < n; i++) {
		copy[i] = new double[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = mtr[j][i];
		}
	}

	Matrix tr(copy, n, m);

	for (int i = 0; i < n; i++) {
		delete[]copy[i];
	}
	delete[]copy;

	return tr;
}

ostream& operator<<(ostream& out, Matrix& object)
{
	for (int i = 0; i < object.m; i++) {
		for (int j = 0; j < object.n; j++) {
			out << object.mtr[i][j] << " ";
		}
		out << endl;
	}
	out <<endl<< "Объектов : " << Matrix::cnt;
	return out;
}

Row::Row(double* src, int n)
{
	if (src) {
		this->n = n;
		string = new double[n];
		for (int i = 0; i < n; i++) {
			string[i] = src[i];
		}
	}
	else {
		string = new double[5];
		for (int i = 0; i < 5; i++) {
			string[i] = 0;
		}
		this->n = 5;
	}
}

Row::Row(const Row& other)
{
	n = other.n;
	string = new double[n];
	for (int i = 0; i < n; i++) {
		string[i] = other.string[i];
	}
}

Row::~Row()
{
	if (string) {
		delete[]string;
	}
}

double Row::operator[](int i)
{
	if (i >= 0 && i < n) {
		return string[i];
	}
	else throw "i is out of range row";
}
