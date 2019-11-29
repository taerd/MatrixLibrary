#pragma once
#include "Matrix.h"
class SquareMatrix :
	public Matrix
{
protected:
	int size;
public:
	SquareMatrix();
	SquareMatrix(double** mtr, int n);
	SquareMatrix(const SquareMatrix& other);
	SquareMatrix(const Matrix& other);
	double determinant();//гауссом
};

