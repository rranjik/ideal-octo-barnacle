class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> m;
        for(const auto& p : people) m.insert(p);
        int res{};
        while(m.size()){
            res++;
            int thisboat{};
            thisboat += *m.rbegin();
            int rem = limit-*m.rbegin();
            auto rit = m.rbegin();
            advance(rit, 1);
            m.erase(rit.base());
            if(m.size()){
                auto it = m.upper_bound(rem);
                if(it!=m.end()) cout<<"lower bound of "<<rem<<" is "<<*it<<endl;
                if(it!=m.begin()){
                    it = prev(it);
                    m.erase(it);
                }
            }
        }
        return res;
    }
};
