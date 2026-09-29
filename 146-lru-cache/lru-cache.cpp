class LRUCache {
public:
    list<int> dll;
    int n;
    unordered_map<int, pair<list<int>::iterator, int>> mp;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecentlyUsed(int key){
        int val = mp[key].second;
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key] = {dll.begin(), val};
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        int val = mp[key].second;
        makeRecentlyUsed(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            makeRecentlyUsed(key);
            mp[key].second = value;
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n<0){
                int to_be_dltd = dll.back();
                mp.erase(to_be_dltd);
                dll.pop_back();
                n++;
            }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */