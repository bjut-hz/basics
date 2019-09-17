#include "slice.h"
#include<iostream>
#include<string>
#include<stdexcept>

template<typename T>
std::string Dump(slice<T> s) {
	using type = typename std::enable_if<std::is_arithmetic<T>::value, void>::type;
	
	std::string str = "";
	for (int i = 0; i < s.len(); ++i) {
		str = str + std::to_string(s[i]) + " ";
	}
	return str;
}


template<>
std::string Dump<std::string>(slice<std::string> s) {
	std::string str = "";
	for (int i = 0; i < s.len(); ++i) {
		str = str + s[i] + " ";
	}
	return str;
}


std::string ToHexString(const uint8_t* buf, int len, std::string tok = "")
{
	std::string output;
	char temp[8];
	for (int i = 0; i < len; ++i)
	{
		sprintf_s(temp, "0x%.2x", (uint8_t)buf[i]);
		output.append(temp, 4);
		output.append(tok);
	}

	return output;
}

class NoDefault {
public:
	NoDefault() = delete;
};

slice<int> tt(int x) {
	const int i = 10;
	return slice<int>(x, 10);
}

void test() {
	// constructor
	slice<int> s1(5, 10);
	s1[0] = 0;
	s1[1] = 1;
	s1[2] = 2;
	s1[3] = 3;
	int&& num = 4;
	int& num1 = num;
	s1.Append(num);
	s1.Append(num1);

	std::cout << Dump(s1) << std::endl;

	slice<int> s2(s1, 1, 4);
	s2[0] = 98;
	assert(s1[1] == 98);
	s1[2] = 100;
	assert(s2[1] == 100);

	s2.Append(991, 992); // s2 should expand memory
	std::cout << Dump(s2) << std::endl;
	s2[1] = 9999;
	assert(s1[2] == 100); // s1[2] do not change any more

	std::vector<int> vec = { 77, 78, 79 };
	//vec.push_back
	slice<int> s3(vec);

	std::cout << Dump(s3);

	slice<std::string> s4(1, 1);
	s4.Append("0", "1", "ggggggg", "666666666666666666");
	std::cout << Dump(s4) << std::endl;

	//// assignment
	s2 = s2;
	s2 = s1;

	slice<int> s5(s2);

	std::vector<slice<int>> vec1;
	vec1.push_back(slice<int>(0));
	slice<int> s6(tt(1));


	//slice<NoDefault> t(10);
}

int main() {

	test();

	_CrtDumpMemoryLeaks();
}