struct linkedNode {
    linkedNode(){}
    linkedNode(int _key, int _value): key(_key), value(_value) {}
    int key, value;
    linkedNode* prev;
    linkedNode* next;
};

class LRUCache {
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new linkedNode();
        tail = new linkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto iter = this->cache.find(key);
        if (iter == this->cache.end()) {
            return -1;
        } else {
            moveToHead(iter->second);
            return iter->second->value;
        }
    }
    
    void put(int _key, int _value) {
        auto iter = this->cache.find(_key);
        if (iter != this->cache.end()) {
            iter->second->value = _value;
            moveToHead(iter->second);            
        } else  {
            auto temp = new linkedNode(_key, _value);
            addToHead(temp);
            this->cache.insert(pair<int, linkedNode*>(_key, temp));
            ++size;
            if (this->size > this->capacity) {
                auto removed = removeTail();
                this->cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    } 

    void addToHead(linkedNode* node) {
        this->head->next->prev = node;
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next = node;
    }

    void removeNode(linkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    linkedNode* removeTail() {
        auto temp = this->tail->prev;
        removeNode(temp);
        return temp;
    }

    void moveToHead(linkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

private:
    unordered_map<int, linkedNode*> cache;
    int capacity;
    int size;
    linkedNode* head;
    linkedNode* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */