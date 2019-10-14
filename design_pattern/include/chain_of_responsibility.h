#ifndef CHAIN_OF_RESPONSIBILITY_H_
#define CHAIN_OF_RESPONSIBILITY_H_

#include <memory>
#include <iostream>
#include <string>
#include "basic.h"

namespace DP {
	struct Request {
		int age;
	};

	class Handler {
	public:
		virtual void SetSuccessor(std::shared_ptr<Handler> successor) {
			successor_ = successor;
		}

		virtual void HandleRequest(const Request&) const = 0;
	protected:
		std::shared_ptr<Handler> successor_;
	};

	class ConcreteHandler1 : public Handler {
	public:
		virtual void HandleRequest(const Request& request) const override {
			if(request.age < 10) {
				std::cout << "ConcreteHandler1 processed ths request." << std::endl;
			} else {
				successor_->HandleRequest(request);
			}
		}
	};

	class ConcreteHandler2 : public Handler {
	public:
		virtual void HandleRequest(const Request& request) const override {
			if(request.age < 20) {
				std::cout << "ConcreteHandler2 processed ths request." << std::endl;
			} else {
				std::cout << "invalid request. can not be preocessed." << std::endl;
			}
		}
	};
} // namespace DP

#endif // CHAIN_OF_RESPONSIBILITY_H_