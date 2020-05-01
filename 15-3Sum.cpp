class C{
public:
    int a; int b; int c;
    C(int _a, int _b, int _c):a(_a), b(_b), c(_c) {}
    bool operator==(const C& o) const {
        return a==o.a&&b==o.b&&c==o.c;
    } 
};

namespace std{
    template <>
    struct hash<C>{
        size_t operator()(const C& cc) const {
            return (hash<int>()(cc.a)/*^0x29483928*/)^
            (hash<int>()(cc.b)/*^0xFA929B59*/)^
            (hash<int>()(cc.c)/*^0xE492A201*/);
        }
    };
}

class Solution {
public:
    multimap<int, int> v;
    vector<vector<int>> threeSum(vector<int>& ns) {
        vector<int> nums = ns;
        unordered_set<C> rr;
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(ns.begin(), ns.end());
        for(int i = 0; i<nums.size(); i++){
            v.insert({nums[i], i});
        }
        for(int i = 0; (i<nums.size()-1); i++){
            for(int j = i+1; j<nums.size(); j++){
                //cout<<" j = "<<j<<endl;
                int t = (nums[i]+nums[j])*-1;
                auto f = v.equal_range(t);
                if(distance(f.first, f.second)){
                    for(auto it = f.first; it!=f.second; it++){
                        if(it->second!=i&&it->second!=j){
                            //cout<<"found "<<t<<endl;
                            vector<int> r;
                            int a = nums[i];
                            int b = nums[j];
                            int c = t;
                                if (a > b) {
                                std::swap(a, b);
                            }
                            if (a > c) {
                                std::swap(a, c);
                            }
                            if (b > c) {
                                std::swap(b, c);
                            }
                            //r.push_back(nums[i]);
                            //r.push_back(nums[j]);
                            //r.push_back(t);
                            //sort(r.begin(), r.end());
                            auto cc = C(a, b, c);
                            rr.insert(cc);
                            //res.push_back(r);
                            break;
                        }
                    }
                }
                //if(j+1>=nums.size())break;
                while((j+1<nums.size())&&(nums[j+1]==nums[j])) j++;
            }
            while((i+1<nums.size())&&(nums[i+1]==nums[i])) i++;
        }
        cout<<rr.size()<<endl;
        //sort(res.begin(), res.end());
        //res.erase(unique(res.begin(), res.end()), res.end());
        for(const auto& cc: rr){
            vector<int> r{cc.a, cc.b, cc.c};
            res.push_back(r);
            //cout<<cc.a<<" "<<cc.b<<" "<<cc.c<<endl;
        }
        return res;
    }
};
