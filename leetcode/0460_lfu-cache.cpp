class LFUCache {
    int cap, fmin; // 容量上限, 最低使用频率
    typedef list<int> LI;
    struct Node {
        int freq, val;   // 频率, val
        LI::iterator it; // 指向频率链表中当前key的指针
    };
    unordered_map<int, Node> m;  // key-val 关系 map
    unordered_map<int, LI> freq; // 访问次数-list<key> 关系 map
public:
    LFUCache(int capacity) { cap = capacity; }

    void freq_plus(int key) {
        auto [freq, val, it] = m[key];

        this->freq[freq].erase(it);

        if (0 == this->freq[freq].size() && fmin == freq) { // 若当前freq等于最小ferq, 且没没有同样为当前freq的key
            fmin++;
        }

        this->freq[freq + 1].push_front(key);
        m[key] = {freq + 1, val, this->freq[freq + 1].begin()};
    }

    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }
        freq_plus(key);
        return m[key].val;
    }

    void put(int key, int value) {
        // 已存在的节点
        if (m.count(key)) {
            m[key].val = value;
            freq_plus(key);
            return;
        }

        // 删除多余节点
        // 由于塞进新节点会把 fmin 置为 1 所以要先删节点再加节点
        if (m.size() >= cap) {
            m.erase(freq[fmin].back());
            freq[fmin].pop_back();
        }

        // 新节点
        freq[1].push_front(key);
        m[key] = {1, value, freq[1].begin()};
        fmin = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */