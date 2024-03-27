class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int i = 0; int j = i;
        vector<int> l;
        vector<int> e;
        vector<int> g;
        for(int i = 0; i<nums.size(); i++){
            int a = nums[i];
            if(a<p) l.push_back(a);
            else if(a==p) e.push_back(a);
            else g.push_back(a);
        }
        vector<int> res;
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), e.begin(), e.end());
        res.insert(res.end(), g.begin(), g.end());
        return res;
    }
};
