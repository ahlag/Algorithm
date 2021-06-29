// https://www.geeksforgeeks.org/uniform-initialization-in-c/
class MyHashMap {
private:
    static const int arraySize = 10;
    list<pair<int, int>> hashTable[arraySize];

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        // Default construction
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        bool keyExists = false;
        
        int hashCode = hashFunction(key);
        auto& cell = hashTable[hashCode];
        auto itr = cell.begin();
        for (; itr != cell.end(); itr++) {
            if (key == itr->first) {
                keyExists = true;
                itr->second = value;
                cout << "[INFO] Replaced existing key" << endl;
                break;
            }
        }
        if (!keyExists) {
            cell.emplace_back(make_pair(key, value));
            cout << "[INFO] Added new key" << endl;
        }
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (isEmpty()) return -1;
        int hashCode = hashFunction(key);
        auto& cell = hashTable[hashCode];
        auto itr = cell.begin();
        for (; itr != cell.end(); itr++) {
            if (key == itr->first) {
                cout << "[INFO] Key found, returning value" << endl;
                return itr->second;
            }
        }
        
        cout << "[INFO] Key not found. Returning -1" << endl;
        return -1;
    }
    
    bool isEmpty() {
        int sum{};
        for (int i{}; i < arraySize; i++) {
            sum += hashTable[i].size();
        }
        if (!sum) return true;
        return false;
    }
    
    
    int hashFunction(int key) {
        return key % arraySize;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (isEmpty()) return;
        bool keyExists = false;
        int hashCode = hashFunction(key);
        auto& cell = hashTable[hashCode];
        auto itr = cell.begin();
        for (; itr != cell.end(); itr++) {
            if (key == itr->first) {
                itr = cell.erase(itr);
                cout << "[INFO] Key found and erased." << endl;
                return;
            } 
        }

        cout << "[INFO] Key doesn't exist." <<endl;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */