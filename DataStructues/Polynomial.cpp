#include "Polynomial.h"
#include <iostream>
#include <assert.h>
using namespace std;

Polynomial::Polynomial(int max_degree)
{
	assert(max_degree > 0);

	// - ����� ����
	// - �� : max_degree�� 2�̸� c0 * x^0 + c1 * x^1 + c2 * x^2 �� 3���� �׵�
	capacity_ = max_degree + 1;

	// ���� �޸� �Ҵ�
	coeffs_ = new float[capacity_];

	// 0���� �ʱ�ȭ
	for (int i = 0; i < capacity_; ++i)
		coeffs_[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->capacity_ = poly.capacity_;
	coeffs_ = new float[capacity_];
	memcpy(coeffs_, poly.coeffs_, capacity_);
}

Polynomial::~Polynomial()
{
	if (coeffs_ != nullptr)
	{
		delete[]coeffs_;
		coeffs_ = nullptr;
	}
}

void Polynomial::Run()
{
	Polynomial p1; // max_degree�� �⺻������ ����

	p1.NewTerm(1, 0);		// 1 * x^0 = 1
	p1.NewTerm(1.5f, 1);	// 1.5 * x^1
	p1.NewTerm(2, 2);		// 2 * x^2

	p1.Print(); // 1 + 1.5*x^1 + 2*x^2

	cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
	cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
	cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

	cout << endl;

	Polynomial p2;

	p2.NewTerm(1, 1);
	p2.NewTerm(3, 2);

	p2.Print(); // 1*x^1 + 3*x^2

	cout << endl;

	cout << "Add()" << endl;

	Polynomial psum = p1.Add(p2);
	psum.Print(); // 1 + 2.5*x^1 + 5*x^2

	cout << endl;

	cout << "Mult()" << endl;

	p1.Print();	  // 1 + 1.5*x^1 + 2*x^2
	p2.Print();	  // 1*x^1 + 3*x^2

	Polynomial pmul = p1.Mult(p2);
	pmul.Print(); // 1*x^1 + 4.5*x^2 + 6.5*x^3 + 6*x^4
}

int Polynomial::MaxDegree()
{
	return capacity_ - 1;
}

// coeft�� �տ� �ٴ� ����, exp�� �������ڸ� �ǹ���.
void Polynomial::NewTerm(const float coef, const int exp)
{
	assert(exp < capacity_); // exp�� �ʹ� ũ�� resize �ϵ��� ������ ���� �ִ�.

	coeffs_[exp] = coef;
}

Polynomial Polynomial::Add(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_); // ������ �ܼ�ȭ�ϱ� ���� ����

	Polynomial temp(this->MaxDegree());

	// TODO :
	for (int i = 0; i < capacity_; ++i)
	{
		if (coeffs_[i] == 0.0f && poly.coeffs_[i] == 0.0f)
			continue;

		temp.coeffs_[i] = this->coeffs_[i] + poly.coeffs_[i];
	}

	return temp;
}

Polynomial Polynomial::Mult(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_); // ������ �ܼ�ȭ�ϱ� ���� ����

	// coeff[i]�� 0.0f�� �ƴ� ��쿡 ���ؼ��� ��� (���ϸ� 0�� �Ǳ� �����̴�)
	
	Polynomial temp(this->MaxDegree());

	// TODO : �׻� �ε��� ���� ����
	for (int i = 0; i < this->capacity_; ++i)
	{
		if (coeffs_[i] == 0.0f)
			continue;

		for (int j = 0; j < poly.capacity_; ++j)
		{
			if (poly.coeffs_[j] == 0.0f)
				continue;

			if (i + j > poly.capacity_)
				break;

			int index = i + j;
			temp.coeffs_[index] += coeffs_[i] * poly.coeffs_[j];
		}
	}

	return temp;
}

float Polynomial::Eval(float x)
{
	// Ư�� x�� ���� ���ؼ� ������̾� ��ü�� ���� ����ϴ� �Լ�
	float temp = 0.0f;

	// TODO
	// std::powf(2.0f, float(3)); // 2.0f^3.0f = 8.0f (2.0f�� 3.0f�� ����)
	for (int i = 0; i < this->capacity_; ++i)
		temp += coeffs_[i] * powf(x, float(i));

    return temp;
}

void Polynomial::Print()
{
	bool is_first = true; // ���ϱ� ��½� Ȯ�ο�

	for (int i = 0; i < capacity_; ++i)
	{
		if (coeffs_[i] != 0.0f) // ���� : 0�� �ƴ� �׵鸸 ���
		{
			if (!is_first)
				cout << " + "; // ù ���� �ƴ϶�� ���̻��̿� ���ϱ� ���

			cout << coeffs_[i];

			if (i != 0) cout << "*" << "*^" << i;

			is_first = false;
		}
	}

	cout << endl;
}
