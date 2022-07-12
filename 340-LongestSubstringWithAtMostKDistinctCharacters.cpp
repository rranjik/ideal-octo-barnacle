class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> lastseen;
        unordered_set<char> seen;
        int i = 0;
        int j = 0;
        int res = 0;
        while(j<s.length()){
            seen.insert(s[j]);
            lastseen[s[j]] = j;
            if(seen.size()>k){
                char to_rem{};
                //nothing can end after s.length() so it is a good upper bound
                auto earliestend = s.length();
                for(auto& it : lastseen){
                    if(it.second<earliestend){
                        earliestend = it.second;
                        to_rem = it.first;
                    }
                }
                seen.erase(seen.find(to_rem)); 
                lastseen.erase(lastseen.find(to_rem));
                i = earliestend+1;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
