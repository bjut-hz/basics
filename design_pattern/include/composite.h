#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "basic.h"
#include <memory>
#include <string>
#include <iostream>
#include <list>
#include <assert.h>

namespace DP {
	class Component {
	public:
		Component(std::string name) {
			name_ = name;
		}
		virtual ~Component() {}
		virtual void Add(std::shared_ptr<Component>) = 0;
		virtual void Remove(std::shared_ptr<Component>) = 0;
		virtual void Display(int depth) = 0;
	protected:
		std::string name_;
	};

	class Leaf : public Component {
	public:
		Leaf(std::string name) : Component(name) {}

		virtual void Add(std::shared_ptr<Component>) override {
			assert(false);
		}
		virtual void Remove(std::shared_ptr<Component>) override {
			assert(false);
		}

		virtual void Display(int depth) override {
			std::cout << std::string(depth, '-') << name_ << std::endl;
		}

	};

	class Composite : public Component {
	public:
		Composite(std::string name) : Component(name) {}

		virtual void Add(std::shared_ptr<Component> c) override {
			components_.push_back(c);
		}
		virtual void Remove(std::shared_ptr<Component> c) override {
			components_.remove_if([&c](const std::shared_ptr<Component>& component){
				return c == component;
			});
		}

		virtual void Display(int depth) override {
			std::cout << std::string(depth, '-') << name_ << std::endl;
			for(auto& c : components_) {
				c->Display(depth + 2);
			}
		}
	private:
		std::list<std::shared_ptr<Component>> components_;
	};
} // namespace DP

#endif // COMPOSITE_H_