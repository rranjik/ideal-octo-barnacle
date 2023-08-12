class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> l;
        unordered_map<int, int> r;
        int n = flowers.size();
        vector<int> ps(n+1, 0);
        unordered_set<int> bs;
        ps[1] = flowers[0]>0?flowers[0]:0;
        l[flowers[0]] = 0;
        for(int i = 1; i<n; i++){
            auto v = flowers[i];
            //cout<<"v = "<<v<<endl;
            if(v>0)
                ps[i+1] = ps[i]+v;
            else ps[i+1] = ps[i];
            //cout<<"finished ps"<<endl;
            bs.insert(v);
            if(l.find(v)==l.end()){
                l[v] = i;
            }else{
                r[v] = i;
            }
        }
        int res = -1e9;
        for(int i = 0; i<ps.size(); i++){
            //cout<<ps[i]<<" ";
        }
        //cout<<endl;
        //cout<<"computed ps, l, r"<<endl;
        for(const auto& b : bs){
            if(l.find(b)!=l.end()&&r.find(b)!=r.end()){
                auto i = l[b];
                auto j = r[b];
                //cout<<"i = "<<i<<"j = "<<j<<endl;
                res = max(res, ps[j+1]-ps[i]+(b<0?2*b:0));
            }
        }
        return res;
    }
};
