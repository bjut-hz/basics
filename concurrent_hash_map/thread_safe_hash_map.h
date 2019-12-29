#ifndef THREAD_SAFE_HASH_MAP_H
#define THREAD_SAFE_HASH_MAP_H

#include <unordered_map>
#include <mutex>
#include <vector>
#include <functional>
#include <memory>

template<typename Key, typename Val>
class HashMap {
public:

	HashMap() {
		mu_ = std::make_shared<std::mutex>();
	}

    void Get(Key key, Val& val) {
        std::lock_guard<std::mutex> lock(*mu_);
        if(map_.count(key)) {
            val = map_[key];
        }
    }

    void Remove(Key key) {
        std::lock_guard<std::mutex> lock(*mu_);
        auto iter = map_.find(key);
        if(iter != map_.end()) {
            map_.remove(iter);
        }
    }

    void Insert(Key key, Val val) {
        std::lock_guard<std::mutex> lock(*mu_);
		map_[key] = val;
    }

private:
	std::shared_ptr<std::mutex>         mu_;
    std::unordered_map<Key, Val>        map_;
};


// use sectional lock 
template<typename Key, typename Val>
class ConcurrentHashMap {
public:
	ConcurrentHashMap() {
		lists_.resize(79);
	}
    void Get(Key key, Val& val) { 
        GetEntry(key).Get(key, val);
    }

    void Remove(Key key) {
        GetEntry(key).Remove(key);
    }

    void Insert(Key key, Val val) {
        GetEntry(key).Insert(key, val);
    }
    
private:
    HashMap<Key, Val>& GetEntry(Key key) {
        size_t hash = std::hash<Key>{}(key);
        size_t idx = hash % lists_.size();
        return lists_[idx];
    }

    std::vector<HashMap<Key, Val>>          lists_;
};


#endif // THREAD_SAFE_HASH_MAP_H