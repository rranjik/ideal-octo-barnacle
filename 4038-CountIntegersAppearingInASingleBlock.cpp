class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(-1);
        unordered_map<int, int> m;
        unordered_set<int> res;
        int last = -1;
        for(int i = 0; i<n; i++){
            int a = nums[i];
            if(last!=a){
                res.insert(a);
            }
            if(m.find(a)==m.end()||m[a]==i-1){
                m[a] = i;
                last = a;
                continue;   
            }
            if(m.find(a)!=m.end()&&m[a]<(i-1)){
                if(res.find(a)!=res.end()) res.erase(a);
            }
        }
        return res.size();
    }
};
