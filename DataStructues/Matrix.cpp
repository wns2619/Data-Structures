#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix()
{

}

Matrix::Matrix(int num_rows, int num_cols)
{
	// TODO:
	num_rows_ = num_rows;
	num_cols_ = num_cols;

	values_ = new float[num_rows_ * num_cols_]();
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b)
{
	// TODO:
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;

	values_ = new float[num_rows_ * num_cols_]();
	memcpy(values_, b.values_, num_rows_ * num_cols_);
}

Matrix::~Matrix()
{
	// TODO:
	if (nullptr != values_)
	{
		delete [] values_;
		values_ = nullptr;
	}
}

void Matrix::Run()
{
	Matrix m1(3, 4);
	m1.SetValue(0, 0, 1.0f);
	m1.SetValue(0, 1, 2.0f);
	m1.SetValue(0, 2, 3.0f);
	m1.SetValue(1, 0, 0.0f);
	m1.SetValue(1, 1, 4.0f);
	m1.SetValue(1, 2, 5.0f);
	m1.SetValue(2, 3, 7.0f);

	m1.Print();

	cout << endl;

	Matrix add = m1.Add(m1); // 자기 자신과 더하기
	add.Print();

	cout << endl;

	Matrix tr = m1.Transpose(); // 전치행렬
	tr.Print();
}

void Matrix::SetValue(int row, int col, float value)
{
	// values_[TODO] = value;
	values_[col + num_cols_ * row] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	return values_[col + num_cols_ * row];
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for (int i = 0; i < num_rows_; ++i)
	{
		for (int j = 0; j < num_cols_; ++j)
			temp.SetValue(j, i, this->GetValue(i, j));
	}

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	// TODO
	for (int i = 0; i < num_rows_; ++i)
	{
		for (int j = 0; j < num_cols_; ++j)
		{
			temp.SetValue(i, j, this->GetValue(i, j) + b.GetValue(i, j));
		}
	}

	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}