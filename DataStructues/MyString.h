#pragma once

class MyString
{
public:
	MyString(); // 비어있는 Mystring() 생성
	MyString(const char* init); // 맨 뒤에 널 캐릭터 '\0'가 들어있는 문자열 초기화
	MyString(const MyString& str); // Mystring의 다른 instance 초기화
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(int new_size); 

	MyString Substr(int start, int num); // 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
	MyString Concat(MyString app_str); // 뒤에 덧붙인 새로운 문자열 반환(append)
	MyString Insert(MyString t, int start); // 중간 삽입

	int Find(MyString pat);
	
	void Print();
	
	void Run();

private:
	char* str_ = nullptr; // 마지막에 '\0' 없음.
	int size_ = 0; // 글자수
};

