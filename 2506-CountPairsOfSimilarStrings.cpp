class Solution {
public:
    bool issim(string a, string b){
        unordered_set<char> as(a.begin(), a.end());
        unordered_set<char> bs(b.begin(), b.end());
        return as==bs;
    }
    int similarPairs(vector<string>& words) {
        int res = 0;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(issim(words[i], words[j])){
                    res++;
                }
            }
        }
        return res;
    }
};
