class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) {
            return "";
        }

        auto &arr = mp[key];
        int st = 0;
        int end = arr.size()-1;
        string ans = "";

        while(st <= end) {
            int mid = st + (end-st)/2;
            if(arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                st = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */