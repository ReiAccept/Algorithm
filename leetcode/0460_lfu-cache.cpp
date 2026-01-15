class LFUCache {
    int cap;
    typedef list<int> LI;

    int min_freq = 0;

    struct Node{
        int freq, val;
        LI::iterator it;
    };

    unordered_map<int, LI> use;
    unordered_map<int, Node> c;

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    void recent(int key) {
        int freq = c[key].freq;
        int val = c[key].val;
        auto it = c[key].it;

        use[freq].erase(it);
        if (use[freq].size()<=0) {
            use.erase(freq);
            if (freq == min_freq) {
                min_freq++;
            }
        }

        use[freq+1].push_front(key);
        c[key]={freq+1, val, use[freq+1].begin()};

    }

    int get(int key) {
        if (c.count(key)) {
            recent(key);
            return c[key].val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (c.count(key)) {
            c[key].val = value;
            recent(key);
            return;
        }

        if (c.size() >= cap) {
            int rm = use[min_freq].back();
            use[min_freq].pop_back();
            c.erase(rm);

            if (use[min_freq].size()==0) {
                use.erase(min_freq);
            }
        }

        min_freq=1;

        use[1].push_front(key);
        c[key]= {1, value, use[1].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */