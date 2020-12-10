class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> f;
        for(const auto& c: chars){
            f[c]++;
        }
        int count = 0;
        for(const auto& w : words){
            auto ff = f;
            bool add = true;
            for(const auto& c : w){
                if(ff.find(c)==ff.end()) add = false;
                else if(ff[c]){
                    ff[c]--;
                }else {
                    add = false;
                }
            }
            if(add) count+=w.length();
        }
        return count;
    }
};
