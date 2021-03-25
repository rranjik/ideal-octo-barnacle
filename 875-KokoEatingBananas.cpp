class Solution {
public:
    int eat(int k){
        if(!k) return numeric_limits<int>::max();
        int res = 0;
        for(const auto& p : piles) {res+=p/k; res+=((p%k)?1:0);}
        return res;
    }
    vector<int> piles;
    int minEatingSpeed(vector<int>& piles, int H) {
        this->piles = piles;
        int h = 0;
        for(const auto& b : piles) h = max(h, b);
        int l = 1;
        while(l<=h){
            cout<<"l = "<<l<<"; h = "<<h<<endl;
            auto m = (h-l)/2+l;
            auto me = eat(m);
            cout<<me<<" hours @ "<<m<<" bananas/hr"<<endl;
            auto me1 = eat(m-1);
            cout<<me1<<" hours @ "<<m-1<<" bananas/hr"<<endl;
            if(me<=H&&me1>H) return m;
            if(me<H) h = m-1;
            else l = m+1;
        }
        return 0;
    }
};
