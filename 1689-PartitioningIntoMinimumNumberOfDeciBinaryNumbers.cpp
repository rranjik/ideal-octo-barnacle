class Solution {
public:
    int minPartitions(string n) {
        int res{};
        for(const auto& c : n){
            int x = c-'0';
            res=max(res,x);
        }
        return res;
    }
};
