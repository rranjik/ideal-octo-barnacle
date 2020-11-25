class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, 
                      vector<int>& score) {
        int possibilities = pow(2, words.size());
        int i = 0;
        vector<int> pfreq(26);
        for(const auto& c : letters){
            pfreq[c-'a']++;
        }
        int res = 0;
        while(i<possibilities){
            bitset<32> possibility = i;
            vector<string> wip;
            for(int j = 0; j<words.size(); j++){
                if(possibility[j]){
                    wip.push_back(words[j]);
                }
            }
            vector<int> freq(26, 0);
            int sop = 0;
            for(const auto& w : wip){
                for(const auto& c : w){
                    freq[c-'a']++;
                    sop+=score[c-'a'];
                }
            }
            bool valid = true;
            for(int j = 0; valid&&j<26; j++){
                if(freq[j]>pfreq[j]) valid = false;
            }
            if(valid){
                res = max(res, sop);
            }
            i++;
        }
        return res;
    }
};
