#ifndef PROXY_H_
#define PROXY_H_

#include<iostream>

namespace DP {
	class Subject {
	public:
		virtual void Request() = 0;
	};

	class RealSubject : public Subject {
	public:
		void Request() override {
			std::cout << "RealSubject::Request" << std::endl;
		}
	};

	class Proxy : public Subject {
	public:
		void Request() override {
			real_subject_.Request();
		}
	
	private:
		RealSubject real_subject_;
	};
} // namespace DP

#endif // PROXY_H_