class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //last seen
        unordered_map<char, int> ls;
        unordered_set<char> seen;
        int i = 0; int j = 0;
        
        int res = 0;
        while(j<s.length()){
            seen.insert(s[j]);
            ls[s[j]] = j;
            if(seen.size()>=3){
                //min last seen
                //any valid index cannot be larger than 
                //s.length() - so don't use numeric_limits::max
                int minls = s.length();
                //char to delete
                char ctodel{};
                for(auto it : ls){
                    if(minls>it.second){
                        ctodel = it.first;
                        minls = it.second;
                    }
                }
                i = minls+1;
                seen.erase(seen.find(ctodel));
                ls.erase(ls.find(ctodel));
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
