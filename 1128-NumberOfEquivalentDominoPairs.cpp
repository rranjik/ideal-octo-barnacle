class Solution {
public:
    using it = vector<vector<int>>::iterator;
    void msort(it l, it r, int& res){
        //cout<<"l = "<<l-b<<"; r = "<<r-b<<endl;
        if(r-l<=1) return;
        auto m = l+(r-l)/2;
        msort(l, m, res);
        msort(m, r, res);
        //cout<<"after merging "<<l-b<<"..."<<r-b;
        //for(auto i = l; i<r; i++) cout<<"("<<(*i)[0]<<", "<<(*i)[1]<<"), ";
        //cout<<endl;
        for(auto i = l, j = m; i<m;){
            int counti{};
            int countj{};
            auto v = *i;
            while(i<m&&*i==v) counti++, i++;
            while(j<r&&*j<v) j++;
            while(j<r&&*j==v) countj++, j++;
            //cout<<"adding "<<counti*countj<<endl;
            res+=counti*countj;
        }
        inplace_merge(l, m, r);
    }
    it b;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        b = dominoes.begin();
        for(auto& d : dominoes){
            if(d[0]>d[1]) swap(d[0], d[1]);
        }
        int res{};
        msort(begin(dominoes), end(dominoes), res);
        return res;
    }
};
