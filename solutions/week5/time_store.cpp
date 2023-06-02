#include <bits/stdc++.h>
using namespace std;

class TimeMap {
   public:
    unordered_map<string, map<int, string>> hm;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        hm[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto itr2 = hm[key].upper_bound(timestamp);

        if (itr2 == hm[key].begin()) {
            return "";
        }

        itr2--;

        return itr2->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */