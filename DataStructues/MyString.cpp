#include "MyString.h"
#include <iostream>
#include <assert.h>


using namespace std;

MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

MyString::MyString(const char* init)
{
	while (init[size_++] != '\0');

	str_ = new char[size_];
	memcpy(str_, init, size_);
}

MyString::MyString(const MyString& str)
{
	size_ = str.size_;
	str_ = new char[size_];
	memcpy(str_, str.str_, size_);
}

MyString::~MyString()
{
	if (str_ != nullptr)
	{
		delete[] str_;
		str_ = nullptr;
		size_ = 0;
	}
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str)
{
	if (size_ != str.size_)
		return false;

	for (int i = 0; i < size_; ++i) if (str_[i] != str.str_[i]) return false;
	return true;
}

int MyString::Length()
{
    return size_;
}

void MyString::Resize(int new_size)
{
	if (new_size != size_)
	{
		char* new_str = new char[new_size];

		int size = new_size < size_ ? new_size : size_;
		memcpy(new_str, str_, size);

		delete[]str_;
		str_ = new_str;
		size_ = new_size;
	}

}

MyString MyString::Substr(int start, int num)
{
	assert(start + num - 1 < this->size_);

	MyString temp;
	temp.Resize(num);

	for (int i = 0; i < num; ++i)
		temp.str_[i] = this->str_[start + i];

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;
	temp.Resize(this->size_ + app_str.size_);

	memcpy(temp.str_, this->str_, this->size_);
	memcpy(&temp.str_[this->size_], app_str.str_, app_str.size_);

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;
	temp.Resize(size_ + t.size_);

	for (int i = 0; i < start; ++i)
		temp.str_[i] = str_[i];

	for (int i = start; i < start + t.size_; ++i)
		temp.str_[i] = t.str_[i - start];

	for (int i = start + t.size_; i < size_ + t.size_; ++i)
		temp.str_[i] = str_[i - t.size_];

	return temp;
}

int MyString::Find(MyString pat)
{
	for (int start = 0; start <= Length() - pat.Length(); start++)
	{
		for (int j = 0; j < pat.Length(); ++j)
		{
			if (str_[start + j] != pat.str_[j])
				break;

			if (j == pat.Length() - 1)
				return start;
		}
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; ++i)
		std::cout << str_[i];
	cout << endl;
}

void MyString::Run()
{
	// 持失切, MyString::Print()
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		str1.Print();
	}

	// Find()
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		cout << str1.Find(MyString("hell")) << endl;

		cout << "Found at " << MyString("ABCDEF").Find(MyString("A")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("AB")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("CDE")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EF")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EFG")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EFGHIJ")) << endl;
	}

	// 差紫 持失切
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		MyString str2 = str1; // MyString str2(str1);
		str2.Print();
	}

	// IsEqual()
	{
		MyString str3("Hello, World!");
		cout << boolalpha;
		cout << str3.IsEqual(MyString("Hello, World!")) << endl;
		cout << str3.IsEqual(MyString("Hay, World!")) << endl;
	}

	// Insert()
	{
		MyString str4("ABCDE");
		for (int i = 0; i <= str4.Length(); i++)
		{
			MyString str5 = str4.Insert(MyString("123"), i);
			str5.Print();
		}
	}

	// Substr()
	{
		MyString str("ABCDEFGHIJ");

		str.Substr(3, 4).Print();
	}

	// Concat()
	{
		MyString str1("Hello, ");
		MyString str2("World!");

		MyString str3 = str1.Concat(str2);

		str3.Print();
	}
}
