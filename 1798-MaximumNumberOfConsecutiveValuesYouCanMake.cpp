class Solution {
public:
    int getMaximumConsecutive(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        int p = 0;
        for(int i = 0; i<c.size(); i++){
            int a = c[i];
            if(a>p+1) return p+1;
            p+=a;
        }
        return p+1;
    }
};
