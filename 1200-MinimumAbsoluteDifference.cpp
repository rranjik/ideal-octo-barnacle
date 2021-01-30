class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        set<int> s(begin(arr), end(arr));
        int mind = numeric_limits<int>::max();
        for(auto it = begin(s); it!=prev(s.end()); it++){
            if(mind>abs(*it - *(next(it)))) mind = abs(*it - *(next(it)));
        }
        set<vector<int>> res;
        for(int i = 0; i<arr.size(); i++){
            int a = arr[i];
            int b = mind + a;
            if(s.find(b)!=s.end()){
                if(a<b) res.insert({a, b});
                else res.insert({b, a});
            }
        }
        vector<vector<int>> rres(begin(res), end(res));
        return rres;
    }
};
