#pragma once
#include "SquareMatrix.h"
class InvertibleMatrix :
	public SquareMatrix
{
public:
	InvertibleMatrix();
	InvertibleMatrix(double** _mtr, int _n);
	InvertibleMatrix(const InvertibleMatrix& other);
	InvertibleMatrix(const Matrix& other);
	InvertibleMatrix Inverse();
	double minor(const InvertibleMatrix& other, int _i, int _j);
};

