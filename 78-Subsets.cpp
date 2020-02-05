class Solution {
public:
    vector<int> v;
    void ss(int i, vector<int>& p, vector<vector<int>>& res){
        if(i==v.size()){
            res.push_back(p);
            for(const auto&  e : p){cout<<e<<" ";}
            cout<<endl;
            return;
        }else{
            ss(i+1, p, res);
            p.push_back(v[i]);
            ss(i+1, p, res);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        vector<vector<int>> res;
        vector<int> p;
        ss(0, p, res);
        for(const auto& r : res){
            for(const auto&  e : r){
                cout<<e<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};
