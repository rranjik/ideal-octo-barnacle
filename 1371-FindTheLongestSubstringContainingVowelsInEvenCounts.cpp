class Solution {
public:
    int findTheLongestSubstring(string s) {
        //what do these number do 
        vector<int> m = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        int mask = 0;
        int res = 0;
        //why 32
        vector<int> seen(32, -1);
        for(int i = 0; i<s.size(); i++){
            mask ^= m[s[i]-'a'];
            if(mask&&seen[mask]==-1){
                seen[mask] = i;
            }
            res = max(res, i-seen[mask]);
        }
        return res;
    }
};
