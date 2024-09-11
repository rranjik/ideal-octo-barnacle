class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            s.push_back({nums.begin()+i, nums.end()});
        }
        s.push_back({});
        for(int i = 0; i<n-1; i++){
            auto l = s[s.size()-1];
            l.push_back(nums[i]);
            s.push_back(l);
        }
        for(int i = 0; i<s.size(); i++){
            cout<<"at t = "<<i<<": ";
            print(s[i]);
        }
        vector<int> res;
        for(const auto& q : queries){
            auto t = q[0]; auto i = q[1];
            t=t%(2*n);
            if(i<s[t].size())
                res.push_back(s[t][i]);
            else res.push_back(-1);
        }
        return res;
    }
    void print(const vector<int>& v) {
        for(const auto& n : v) {
            cout<<n<<" ";
        }
        cout<<endl;
    }
};
