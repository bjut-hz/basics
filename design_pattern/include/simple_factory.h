#ifndef SIMPLE_FACTORY_H_
#define SIMPLE_FACTORY_H_

#include "basic.h"

namespace DP {
	using NumberType = double;
	class IOperation {
	public:
		enum OperationType {
			kAdd,
			kSub,
			kMulti,
			kDiv,
		};

	public:
		NumberType lhs_ = 0;
		NumberType rhs_ = 0;

	public:
		virtual NumberType GetResult() const = 0;
	};


	class AddOperation : public IOperation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ + rhs_;
		}
	};

	
	class SubOperation : public IOperation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ - rhs_;
		}
	};

	class MultiOperation : public IOperation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ * rhs_;
		}
	};

	class DivOperation : public IOperation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ / rhs_;
		}
	};

	class OperationFactory {
	public:
		static IOperation* CreateOperation(IOperation::OperationType operate) {
			IOperation* oper;
			switch (operate)
			{
			case IOperation::kAdd:
				oper = new AddOperation();
				break;
			case IOperation::kSub:
				oper = new SubOperation();
				break;
			
			case IOperation::kMulti:
				oper = new MultiOperation();
				break;
											
			case IOperation::kDiv:
				oper = new DivOperation();
				break;
			default:
				break;
			}

			return oper;
		}
	};
} // namespace DP


#endif // SIMPLE_FACTORY_H_