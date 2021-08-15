//O(nlgn) Patience sorting
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> p;
        for(const auto& n : nums){
            if(p.size()==0) {
                p.push_back(n);
                continue;
            }
            auto l = lower_bound(p.begin(), p.end(), n);
            if(l==p.end()) p.push_back(n);
            else {
                *l = n;
            }
        }
        return p.size();
    }
};

/* O(n^2)
class coor{public:int i; int l;coor(int _i, int _l){i = _i; l = _l;}
          bool operator==(const coor& o)const{return i==o.i&&l==o.l;}};
namespace std{template<>struct hash<coor>{size_t operator()(const coor& c)const
{ return hash<int>()(c.i)^(hash<int>()(c.l)<<1);}};}
class Solution {
public:
    vector<int> n;
    unordered_map<coor, int> c;
    int dp(int i, int l){
        auto cr = coor(i,l);
        //if(c.find(coor(i,l))!=c.end()) return c[i];
        if(c.find(cr)!=c.end()) return c[cr];
        if(i<0) {c[cr] = 0;return 0;}
        int res = 0;
        int w, wo;
        w = wo = 0;
        wo = dp(i-1, l);
        if((l<n.size()&&n[i]<n[l])||l>=n.size()) {w = dp(i-1, i)+1;}
        c[cr] = max(w, wo);
        return c[cr];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int j = 1; j<nums.size(); j++){
            for(int i = 0; i<j; i++){
                if(nums[i]<nums[j]) 
                    res[j] = max(res[j], res[i]+1);
            }
        }
        int m = 0;
        for(int i = 0; i<nums.size(); i++){
            if(m<res[i]) m = res[i];
        }
        return m;
    }
};
*/
