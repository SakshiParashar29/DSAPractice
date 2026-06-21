// TC: O(1) and SC: O(n)
class LRUCache {
public:
    int c;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        dll.erase(mp[key].second);

        dll.push_front(key);
        
        mp[key].second = dll.begin();

        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].first = value;
            get(key);
            return;
        }


        if(dll.size() == c){
            int cache = dll.back();
            dll.pop_front();
            mp.erase(cache);
        }

        dll.push_front(key);

        mp[key] = {value, dll.begin()};
    }
};
