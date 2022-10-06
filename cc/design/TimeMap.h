// LeetCode: 981. Time Based Key-Value Store (Medium)
class TimeMap {
public:
    unordered_map <string, map<int, string>> um;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        um[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = um[key].lower_bound(timestamp);
        if (it == um[key].begin() && it->first != timestamp) {
            return "";
        }

        if (it == um[key].end() || it->first != timestamp) {
            it--;
        }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */