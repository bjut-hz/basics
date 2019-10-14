#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <memory>
#include <iostream>
#include <string>
#include "basic.h"

namespace DP {
	struct Context {
		std::string input;
	};

	class AbstractExpression {
	public:
		virtual ~AbstractExpression() {}
		virtual void Interpret(Context&) const = 0;
	};

	class TerminalExpression : public AbstractExpression {
	public:
		virtual ~TerminalExpression() {}
		void Interpret(Context& context) const override {
			std::cout << "TerminalExpression: " << context.input << std::endl;
		}
	};

	class NonterminalExpression : public AbstractExpression {
	public:
		virtual ~NonterminalExpression() {}
		void Interpret(Context& context) const override {
			std::cout << "NonterminalExpression: " << context.input << std::endl;
		}
	};
} // namespace DP

#endif // INTERPRETER_H_