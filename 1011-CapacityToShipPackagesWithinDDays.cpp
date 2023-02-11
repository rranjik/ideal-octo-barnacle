class Solution {
public:
    int possible(int c){
        int d = 1;
        int cc = 0;
        for(int i = 0; i<w.size(); i++){
            if(cc+w[i]<=c) {
                cc+=w[i];
            }else{
                d+=1;
                cc = w[i];
            }
        }
        if(d==D) return 0;
        else if(d<D) return 1;
        else return -1;
    }
    int D;
    vector<int> w;
    int shipWithinDays(vector<int>& weights, int D) {
        this->D = D;
        w = weights;
        auto l = *(std::max_element(w.begin(), w.end()));
        auto r = std::accumulate(w.begin(), w.end(), 0);
        cout<<"l = "<<l<<" r = "<<r<<endl;
        int res = r;
        while(l<=r){
            auto m = l+(r-l)/2;
            auto p = possible(m);
            cout<<"m = "<<m<<" is "<<p<<endl;
            if(0==p){
                res = min(res, m);
                r = m-1;
            }else if(-1==p){
                l = m+1;
            }else {
                res = min(res, m);
                r = m-1;
            }
        }
        return res;
    }
};
