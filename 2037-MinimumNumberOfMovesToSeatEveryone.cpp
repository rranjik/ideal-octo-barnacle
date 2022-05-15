class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& st) {
        sort(s.begin(), s.end());
        sort(st.begin(), st.end());
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=st[i]){
                res += abs(st[i]-s[i]);
            }
        }
        return res;
    }
};
