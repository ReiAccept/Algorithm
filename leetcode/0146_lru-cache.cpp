class LRUCache {
    int cap;
    list< pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            dq.splice(dq.begin(), dq, m[key]);
            return m[key]->second;
        }
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            dq.splice(dq.begin(), dq, m[key]);
            m[key]->second=value;
            return;
        }

        if (dq.size() >= cap) {
            int lst = dq.back().first;
            dq.pop_back();
            m.erase(lst);
        }

        dq.push_front({key, value});
        m[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */