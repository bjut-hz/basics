#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <exception>
#include <type_traits>

template <typename T, int MAX_SIZE>
class ObjectPool {
    struct Node {
        Node*			next;

        // 这里依赖了T,需要用typename指出type是个类型
        using LenT = typename std::conditional<sizeof(T) >= sizeof(Node*), 
            std::integral_constant<int, sizeof(T) - sizeof(Node*)>, 
            std::integral_constant<int, 0> >::type;
        char 			data[LenT::value];
    };

public:

    ObjectPool() {
        for(int i = 0; i < MAX_SIZE - 1; ++i) {
            pool_[i].next = &pool_[i+1];
        }
        head_ = &pool_[0];
    }
    
    T* Get() {
        if(nullptr == head_) {
            throw std::bad_alloc();
        }

        Node* p = head_;
        head_ = head_->next;
        // placement new
        return new(p)T();
    }

    void Free(T* p) {
        p->~T();
        Node* tmp = (Node*)(p);
        tmp->next = head_;
        head_ = tmp;
    }


private:
    Node 				pool_[MAX_SIZE];
    Node*				head_ = nullptr;
private:
    ObjectPool(const ObjectPool&) = delete;
    ObjectPool& operator=(const ObjectPool&) = delete;
};



#endif // OBJECT_POOL_H