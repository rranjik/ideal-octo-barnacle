class Solution {
public:
    vector<int> v;
    unordered_map<int, int> c;
    int dp(int i){
        if(c.find(i)!=c.end()) return c[i];
        //cout<<"i = "<<i<<endl;
        if(i<0){
            c[i] = 0;
            return 0;
        }
        int nnz = i-1;
        while(nnz>=0&&v[nnz]==0) 
            nnz--;
        int nnnz = nnz;
        //if the nnz was to be used, find something else
        if(nnz>=0&&nnz==i-1){
            nnnz = nnz-1;
            while(nnnz>=0&&v[nnnz]==0) 
                nnnz--;
        }
        //cout<<"nnz = "<<nnz<<"; nnnz = "<<nnnz<<endl;
        c[i] = max(dp(nnz), dp(nnnz)+v[i]*i);
        return c[i];
    }
    int deleteAndEarn(vector<int>& nums) {
       vector<int> n(10001, 0);
       for(const auto& num : nums) 
           n[num]++;
       v = n;
       cout<<endl;
       int idx = n.size()-1;
       while(idx>=0&&n[idx]==0) idx--;
       int cpy = idx;
       while(cpy>=0){
           cout<<cpy<<":"<<v[cpy]<<" ";
           cpy--;
       }
       cout<<endl; 
       if(idx<0) return 0;
       return dp(idx);
    }
};
