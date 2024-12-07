class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        vector<int>pf(n+1,0);
        for(int i=0;i<gain.size();i++)
        {
            pf[i+1]= pf[i]+gain[i];
        }
        int a = *max_element(pf.begin(),pf.end());
        return a;
    }
};
