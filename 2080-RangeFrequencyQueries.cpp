class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i<arr.size(); i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return distance(lower_bound(m[value].begin(), m[value].end(), left), 
                        upper_bound(m[value].begin(), m[value].end(), right));
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
