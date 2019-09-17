#ifndef DUMP_VECTOR_H_
#define DUMP_VECTOR_H_

#include<vector>
#include<string>
#include<strstream>

template<typename T>
std::string Dump(std::vector<T>& vec) {
	std::ostringstream buf;
	if(std::is_arithmetic_v<T>) {
		for(auto& ele : vec) {
			buf << std::to_string(ele) << " ";
		}
		buf << std::endl;
	} else if(std::is_convertible_v<T, std::string>) {
		for(auto& ele : vec) {
			buf << ele << " ";
		}
		buf << std::endl;
	} else {
		throw("unsupport types.....");
	}
	return buf.str();
}

#endif // DUMP_VECTOR_H_