class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> f;
        for(int i = 0; i<arr1.size(); i++){
            f[arr1[i]]++;
        }
        for(int i = 0; i<arr2.size(); i++){
            f[arr2[i]]++;
        }
        for(int i = 0; i<arr3.size(); i++){
            f[arr3[i]]++;
        }
        vector<int> res;
        for(auto it = f.begin(); it!=f.end(); it++){
            if(it->second==3) res.push_back(it->first);
        }
        return res;
    }
};
