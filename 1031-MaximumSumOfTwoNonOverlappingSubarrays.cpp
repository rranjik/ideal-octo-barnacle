class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        unordered_map<int, int> p;
        int s = 0;
        for(int i =0 ;i <A.size(); i++){
            s+=A[i];
            //cout<<s<<" ";
            p.insert({i, s});
        }
        cout<<endl;
        int res = 0;
        for(int i = L-1; i<A.size(); i++){
            int sl = p[i]-p[i-(L-1)-1];
            //cout<<"L from "<<i-(L-1)<<" - "<<i<<" = "<<sl<<endl;
            for(int j = 0; j+M-1<(i-(L-1)); j++){
                auto sm = p[j+(M-1)] - p[j-1];
                //cout<<" M from "<<j<<" - "<<j+(M-1)<<" = "<<sm<<endl;
                res = max(res, sl+sm);
            }
            for(int j = i+1; j+M-1<A.size(); j++){
                auto sm = p[j+(M-1)] - p[j-1];
                //cout<<" M from "<<j<<" - "<<j+(M-1)<<" = "<<sm<<endl;
                res = max(res, sl+sm);
            }
        }
        return res;
    }
};
