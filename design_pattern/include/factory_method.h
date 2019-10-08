#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include "basic.h"
#include "simple_factory.h"

namespace DP {
	class IFactory {
	public:
		virtual IOperation* CreateOperation() = 0;
	};

	class AddFactory : public IFactory {
	public:
		IOperation* CreateOperation() {
			return new AddOperation();
		}
	};

	class SubFactory : public IFactory {
	public:
		IOperation* CreateOperation() {
			return new SubOperation();
		}
	};

	class MultiFactory : public IFactory {
	public:
		IOperation* CreateOperation() {
			return new MultiOperation();
		}
	};

	class DivFactory : public IFactory {
	public:
		IOperation* CreateOperation() {
			return new DivOperation();
		}
	};
} // namespace DP
#endif // FACTORY_METHOD_H_