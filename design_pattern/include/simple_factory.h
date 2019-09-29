#ifndef SIMPLE_FACTORY_H_
#define SIMPLE_FACTORY_H_

namespace DP {
	using NumberType = double;
	class Operation {
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


	class AddOperation : public Operation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ + rhs_;
		}
	};

	
	class SubOperation : public Operation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ - rhs_;
		}
	};

	class MultiOperation : public Operation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ * rhs_;
		}
	};

	class DivOperation : public Operation {
	public:
		virtual NumberType GetResult() const override {
			return lhs_ / rhs_;
		}
	};

	class OperationFactory {
	public:
		static Operation* CreateOperation(Operation::OperationType operate) {
			Operation* oper;
			switch (operate)
			{
			case Operation::kAdd:
				oper = new AddOperation();
				break;
			case Operation::kSub:
				oper = new SubOperation();
				break;
			
			case Operation::kMulti:
				oper = new MultiOperation();
				break;
											
			case Operation::kDiv:
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