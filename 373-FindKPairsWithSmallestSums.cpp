struct node{
    int i; int j; int v;
    node(int _i, int _j, int _v):i(_i), j(_j), v(_v){}
    bool operator<(const node& n) const{
        return v>n.v;
    }
    bool operator==(const node& n)const{
        return i==n.i&&j==n.j;
    }
};

namespace std{
    template<>
    struct hash<node>{
        size_t operator()(const node& n) const{
            return (n.i^0x29473929)^
            (n.j^0x48294733);
        }
    };
}
class Solution {
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!nums1.size()||!nums2.size()) return {};
        vector<vector<int>> res;
        priority_queue<node> q;
        q.push(node(0, 0, nums1[0]+nums2[0]));
        unordered_set<node> seen;
        seen.insert(node(0, 0, nums1[0]+nums2[0]));
        while(k&&q.size()){
            auto f = q.top();
            q.pop();
            res.push_back({nums1[f.i], nums2[f.j]});
            if(f.i+1<nums1.size()){
                auto nn = node(f.i+1, f.j, nums1[f.i+1]+nums2[f.j]);
                if(seen.find(nn)==seen.end()){
                    seen.insert(nn);
                    q.push(nn);
                }
            }
            if(f.j+1<nums2.size()){
                auto nn = node(f.i, f.j+1, nums1[f.i]+nums2[f.j+1]);
                if(seen.find(nn)==seen.end()){
                    seen.insert(nn);
                    q.push(nn);
                }
            }
            k--;
        }
        return res;
    }
};
