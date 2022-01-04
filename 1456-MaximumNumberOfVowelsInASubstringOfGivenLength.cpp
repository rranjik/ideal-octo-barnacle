class Solution {
public:
    int maxVowels(string s, int k) {
        int res{};
        int i{};
        int nvowels{};
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int j = 0; j<s.length(); j++){
            if(v.find(s[j])!=v.end()) nvowels++;
            if(j-i+1==k){
                res = max(res, nvowels);
                if(v.find(s[i])!=v.end()) nvowels--;
                i++;
            }
        }
        return res;
    }
};
