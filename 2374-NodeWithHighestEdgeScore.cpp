class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> v = vector<long long>(edges.size());
        for(int i = 0; i<edges.size(); i++){
            v[edges[i]]+=i;
        }
        long long res = 0;
        long long resi = 0;
        for(int i =0; i<v.size(); i++){
            //cout<<"i = "<<i<<" v = "<<v[i]<<endl;
            if(res<v[i]) {
                res = v[i];
                resi = i;
            }
        }
        return resi;
    }
};
