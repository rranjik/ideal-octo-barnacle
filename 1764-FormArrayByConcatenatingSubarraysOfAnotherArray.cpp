class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        unordered_set<int> u;
        int last = -1;
        for(int i = 0; i<groups.size(); i++){
            auto g = groups[i];
            if(m.find(g[0])==m.end()) return false;
            auto found = false;
            cout<<" finding "<<g[0]<<endl;
            for(const auto& s : m[g[0]]){
                //if(u.find(s)!=u.end()) continue;
                cout<<"s = "<<s<<endl;
                auto len = g.size();
                if(s<=last) continue;
                cout<<"checking from "<<s<<" to "<<s+len<<endl;
                if(s+len<=nums.size()&&
                   vector<int>(nums.begin()+s, nums.begin()+s+len) == g){
                    found = true;
                    cout<<"equal"<<endl;
                    last = s+len-1;
                    break;
                }
            }
            if(!found) return false;
        }
        //if(u.size()==groups.size()) return true;
        return true;
    }
};
