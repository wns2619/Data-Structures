#pragma once

class MyString
{
public:
	MyString(); // ����ִ� Mystring() ����
	MyString(const char* init); // �� �ڿ� �� ĳ���� '\0'�� ����ִ� ���ڿ� �ʱ�ȭ
	MyString(const MyString& str); // Mystring�� �ٸ� instance �ʱ�ȭ
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(int new_size); 

	MyString Substr(int start, int num); // �ε��� start��ġ�� ���ں��� num���� ���ڷ� ���ο� ���ڿ� �����
	MyString Concat(MyString app_str); // �ڿ� ������ ���ο� ���ڿ� ��ȯ(append)
	MyString Insert(MyString t, int start); // �߰� ����

	int Find(MyString pat);
	
	void Print();
	
	void Run();

private:
	char* str_ = nullptr; // �������� '\0' ����.
	int size_ = 0; // ���ڼ�
};

