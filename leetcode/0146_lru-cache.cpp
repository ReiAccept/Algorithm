class LRUCache {
    int cap;
    struct Node {
        int key, val;
        Node *pre, *nxt;
        Node(int k, int v) : key(k), val(v), pre(NULL), nxt(NULL) {}
    } *head = NULL, *tail = NULL;
    unordered_map<int, Node*> m;

public:
    LRUCache(int capacity) { cap = capacity; }

    void move_head(Node* p) {
        // printf("move head %d %d\n", p->key, p->val);
        if (p == head) {
            return;
        }
        auto pre = p->pre;
        auto nxt = p->nxt;
        if (pre) {
            pre->nxt = nxt;
        }
        if (nxt) {
            nxt->pre = pre;
        }

        p->pre = NULL;
        p->nxt = head;
        if (head)
            head->pre = p;
        head = p;
        if (tail == p) {
            tail = pre;
        }
    }

    int get(int key) {
        // printf("query %d\n", key);
        if (m.count(key)) {
            move_head(m[key]);
            return m[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            m[key]->val = value;
            move_head(m[key]);
            // printf("change %d %d\n", key, value);
            return;
        }
        // printf("add %d %d\n", key, value);
        auto tmp = new Node(key, value);
        tmp->nxt = head;
        if (head)
            head->pre = tmp;
        head = tmp;
        if (!tail)
            tail = tmp;
        m[key] = tmp;

        if (m.size() > cap) {
            auto tmp = tail;
            // printf("del %d %d\n", tmp->key, tmp->val);
            tail = tail->pre;
            if (tail) {
                tail->nxt = NULL;
            }
            m.erase(tmp->key);
            delete tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */