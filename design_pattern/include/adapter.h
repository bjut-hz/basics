#ifndef ADAPTOR_H_
#define ADAPTOR_H_

#include <memory>
#include <iostream>
#include <string>
#include "basic.h"

namespace DP {
	class Target {
	public:
		virtual void Request() const  = 0;
	};

	class Adaptee {
	public:
		void SpecificRequest() {
			std::cout << "Adaptee::SpecificRequest" << std::endl;
		}
	};

	class Adapter : public Target {
	public:
		void Request() const override {
			if(adaptee_) {
				adaptee_->SpecificRequest();
			}
		}
	private:
		std::unique_ptr<Adaptee> adaptee_ = std::make_unique<Adaptee>();
	};
} // namespace DP

#endif // ADAPTOR_H_