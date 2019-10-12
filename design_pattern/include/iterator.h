#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "basic.h"
#include <memory>
#include <vector>

namespace DP {
	template <typename T>
	class Iterator {
	public:
		virtual ~Iterator() {}
		virtual T& First() = 0;
		virtual void Next() = 0;
		virtual bool IsDone() const = 0;
		virtual T& CurrentItem() const = 0;
	};

	template <typename T>
	class Collection {
	public:
		virtual ~Collection() {}
		virtual std::shared_ptr<Iterator<T>> CreateIterator() const = 0;
	};

	template <typename T>
	class MyList : public Collection<T> {
	public:
		class MyIterator : public Iterator<T> {
		public:
			MyIterator(MyList* list) : list_(list) {}
			~MyIterator() {} 

			T& First() override {
				index_ = 0;
				return list_->vec_[0];
			}

			void Next() override {
				 ++index_;
			}

			bool IsDone() const override {
				return index_ >= list_->vec_.size();
			}

			T& CurrentItem() const override {
				return list_->vec_[index_];
			}
		private:
			MyList* list_;
			std::size_t index_ = 0;
		};
	public:
		~MyList() {}
		std::shared_ptr<Iterator<T>> CreateIterator() const override {
			return std::make_shared<MyIterator>(const_cast<MyList*>(this));
		}
		void Add(T ele) {
			vec_.push_back(ele);
		}
	public:
		std::vector<T> vec_;
	};
} // namespace DP

#endif // ITERATOR_H_