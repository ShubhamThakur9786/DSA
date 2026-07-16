class SnapshotArray {
public:
    vector<vector<pair<int,int>>> history;
    int snapId = 0;

    SnapshotArray(int length) {
        history.resize(length);

        for(int i = 0; i < length; i++) {
            history[i].push_back({0,0});
        }
    }

    void set(int index, int val) {

        if(history[index].back().first == snapId) {
            history[index].back().second = val;
        }
        else {
            history[index].push_back({snapId, val});
        }
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {

        auto &arr = history[index];

        int st = 0;
        int end = arr.size() - 1;
        int ans = 0;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid].first <= snap_id) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return arr[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */