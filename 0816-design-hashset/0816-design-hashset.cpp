
class MyHashSet {
public:
    int size = 1000001;
    vector<bool> store;
    MyHashSet() {
        store.resize(size);
    }
    
    void add(int key) {
       store[key] = true;
    }
    
    void remove(int key) {
        store[key] = false;
    }
    
    bool contains(int key) {
        return store[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */