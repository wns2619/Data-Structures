#pragma once

class Polynomial
{
public:
	Polynomial(int max_degree = 100);

	Polynomial(const Polynomial& poly);

	~Polynomial();

	void Run();

	int MaxDegree();

	void NewTerm(const float coef, const int exp);

	Polynomial Add(const Polynomial& poly);

	Polynomial Mult(const Polynomial& poly);

	float Eval(float x);

	void Print();

private:
	int capacity_ = 0; // �׻� ��� ��(term)���� �� �� �ִ� ���� �ƴϱ� ������ size ��� capacity ���
	float* coeffs_ = nullptr;
};