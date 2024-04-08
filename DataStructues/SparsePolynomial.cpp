#include "SparsePolynomial.h"

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

// 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함

SparsePolynomial::SparsePolynomial(const SparsePolynomial& rhs)
{
	this->capacity_ = rhs.capacity_;
	this->num_terms_ = rhs.num_terms_;
	terms_ = new Term[capacity_];
	for (int i = 0; i < capacity_; i++)
		terms_[i] = rhs.terms_[i];
	// memcpy() 사용도 가능
}

void SparsePolynomial::Run()
{
	// 희소 다항식
	// 1 + 2*x^10000000 을 앞의 방식으로는 10000000 + 1 크기의 배열이 필요하지만 
	// 여기서는 Term 2개로 가능

	SparsePolynomial p1; // max_degree는 기본값으로 설정

	// exp가 작은 항부터 추가한다고 가정
	p1.NewTerm(1.0f, 0);	// 1 * x^0 = 1
	p1.NewTerm(1.5f, 1);	// 1.5 * x^1
	p1.NewTerm(2.0f, 2);	// 2 * x^2

	p1.Print(); // 1 + 1.5*x^1 + 2*x^2

	cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
	cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
	cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

	cout << endl;

	// Add() Test1
	cout << "Add() Test" << endl;
	{
		SparsePolynomial p1; // max_degree는 기본값으로 설정

		// exp가 작은 항부터 추가한다고 가정
		p1.NewTerm(1.0f, 0);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(2.0f, 2);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2

		SparsePolynomial p2;

		// exp가 작은 항부터 추가한다고 가정
		p2.NewTerm(1.0f, 1);
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(5.0f, 7);
		p2.NewTerm(2.0f, 11);

		p2.Print(); // 1*x^1 + 3*x^2 + 5*x^7 + 2*x^11

		cout << endl;

		SparsePolynomial psum = p1.Add(p2);
		psum.Print(); // 1 + 2.5*x^1 + 5*x^2 + 5*x^7 + 2*x^11

		cout << endl;
	}

	// Add() Test2
	cout << "Add() Test2" << endl;
	{
		SparsePolynomial p1; // max_degree는 기본값으로 설정

		// exp가 작은 항부터 추가한다고 가정
		p1.NewTerm(1.0f, 0);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(2.0f, 2);
		p1.NewTerm(5.0f, 7);
		p1.NewTerm(3.5f, 10);
		p1.NewTerm(5.5f, 20);
		p1.NewTerm(5.0f, 1000);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2 + 5*x^7 + 3.5*x^10 + 5.5*x^20 + 5*x^1000

		SparsePolynomial p2;

		// exp가 작은 항부터 추가한다고 가정
		p2.NewTerm(3.2f, 0);
		p2.NewTerm(1.0f, 1);
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(2.0f, 11);

		p2.Print(); // 3.2 + 1*x^1 + 3*x^2 + 2*x^11

		cout << endl;

		SparsePolynomial psum = p1.Add(p2);
		psum.Print(); // 4.2 + 2.5*x^1 + 5*x^2 + 5*x^7 + 3.5*x^10 + 2*x^11 + 5.5*x^20 + 5*x^1000

		cout << endl;
	}

}

// exp항이 이미 존재하면 거기에 coef를 더해준다.
// 존재하지 않는다면 exp 오름 차순으로 정렬된 상태로 새로 추가한다.
void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f) return; // 0이면 추가하지 않음

	if (num_terms_ >= capacity_)
	{
		// capacity 증가 (num_terms는 일단 고정)
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; // 2배씩 증가
		Term* new_term = new Term[capacity_];

		// 원래 가지고 있던 데이터 복사
		memcpy(new_term, terms_, sizeof(Term) * num_terms_);

		// 메모리 교체
		if (terms_) delete[] terms_;
		terms_ = new_term;
	}

	terms_[num_terms_].coef = coef;
	terms_[num_terms_].exp = exp;

	num_terms_++;
}

float SparsePolynomial::Eval(float x)
{
	float temp = 0.0f;

	// TODO:
	for (int i = 0; i < num_terms_; ++i)
		temp += terms_[i].coef * powf(x, terms_[i].exp);

	return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	// this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
	// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

	// 간단한 방법 (메모리를 더 사용하는 방법)
	// - 1. 최대 exp를 찾는다.
	// - 2. 필요한 크기의 Polynomial을 만든다. (Sparse 아님)
	// - 3. 더하면서 Polynomial에 업데이트 한다. 구조가 고정되어 있어서 쉽다.
	// - 4. Polynomial을 SparsePolynomial로 변환한다.
	SparsePolynomial temp;

	int i = 0, j = 0;

	while ((i < this->num_terms_) && (j < poly.num_terms_))
	{
		if ((terms_[i].exp == poly.terms_[j].exp))
		{
			// TODO: temp.NewTerm() 사용
			float sum = terms_[i].coef + poly.terms_[j].coef;
			if (sum != 0.0f)
				temp.NewTerm(sum, terms_[i].exp);

			++i;
			++j;
		}
		else if ((terms_[i].exp > poly.terms_[j].exp))
		{
			// TODO: temp.NewTerm() 사용
			temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
			++j;
		}
		else
		{
			temp.NewTerm(this->terms_[i].coef, this->terms_[i].exp);
			++i;
		}
	}

	// 남은 term들 추가
	for (; i < num_terms_; i++)
	{
		// TODO: temp.NewTerm() 사용
		temp.NewTerm(this->terms_[i].coef, this->terms_[i].exp);
	}

	// 남은 term들 추가
	for (; j < poly.num_terms_; j++)
	{
		// TODO: temp.NewTerm() 사용
		temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
	}

	return temp;
}

void SparsePolynomial::Print()
{
	bool is_first = true; // 더하기 출력시 확인용

	for (int i = 0; i < num_terms_; i++)
	{
		// 0이 아닌 항들만 골라서 출력할 필요가 없음

		if (!is_first)
			cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

		cout << terms_[i].coef;

		if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

		is_first = false;
	}

	cout << endl;
}