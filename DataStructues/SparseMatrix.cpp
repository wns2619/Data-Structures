#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO:
	num_rows_ = num_rows;
	num_cols_ = num_cols;
	capacity_ = capacity;

	terms_ = new MatrixTerm[capacity_];
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
	capacity_ = capacity_;
	num_terms_ = b.num_terms_;

	terms_ = new MatrixTerm[capacity_]();
	memcpy(terms_, b.terms_, sizeof(MatrixTerm) * b.num_terms_);
}

SparseMatrix::~SparseMatrix()
{
	// TODO:
	if (terms_ != nullptr)
	{
		delete[] terms_;
		terms_ = nullptr;
	}
}

void SparseMatrix::Run()
{
	SparseMatrix m1(4, 6, 6); // 4 by 6 matrix, Non-zero term 6개

	// 정렬되지 않은 순서로 추가
	m1.SetValue(2, 3, 5.0f);
	m1.SetValue(0, 5, 2.0f);
	m1.SetValue(1, 1, 1.0f);
	m1.SetValue(0, 0, 1.0f);
	m1.SetValue(0, 3, 7.0f);
	m1.SetValue(1, 2, 3.0f);

	// m1.SetValue(2, 3, 4.0f); // <- 덮어쓰는 경우

	m1.PrintTerms();
	m1.Print();

	cout << endl;

	SparseMatrix tr = m1.Transpose(); // 전치행렬

	tr.PrintTerms();
	tr.Print();

}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value가 0이 아닌 term만 저장

	// TODO:
	if (num_terms_ >= capacity_)
	{
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1;
		MatrixTerm* new_term = new MatrixTerm[capacity_]();

		memcpy(new_term, terms_, sizeof(MatrixTerm) * num_terms_);

		if (terms_ != nullptr) delete[] terms_;
		terms_ = new_term;
	}

	int key = col + num_cols_ * row;
	int i = 0;
	for (i = 0; i < num_terms_; ++i)
	{
		int key_i = terms_[i].col + num_cols_ * terms_[i].row;
		if (key_i == key)
		{
			terms_[i].row = row;
			terms_[i].col = col;
			terms_[i].value = value;
			return;
		}
		else if (key_i > key)
			break;
	}

	assert(capacity_ > num_terms_);
	num_terms_++;
	for (int j = num_terms_ - 1; j > i; --j)
		terms_[j] = terms_[j - 1];
	terms_[i].col = col;
	terms_[i].row = row;
	terms_[i].value = value;
}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;
	int key = col + num_cols_ * row;
	for (int i = 0; i < num_terms_; ++i)
	{
		int compareKey = terms_[i].col + num_cols_ * terms_[i].row;
		if (key == compareKey)
			return terms_[i].value;
		else if (compareKey > key)
			return 0.0f;
	}

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for (int r = 0; r < temp.num_rows_; ++r)
	{
		for (int i = 0; i < num_terms_; ++i)
		{
			if (terms_[i].col == r)
			{
				temp.terms_[temp.num_terms_].value = terms_[i].value;
				temp.terms_[temp.num_terms_].col = terms_[i].row;
				temp.terms_[temp.num_terms_].row = terms_[i].col;
				temp.num_terms_++;
			}
		}
	}
		

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}