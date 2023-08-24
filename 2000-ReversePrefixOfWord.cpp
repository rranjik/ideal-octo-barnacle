class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i<word.size(); i++){
            if(word[i]==ch){
                auto p = word.substr(0, i+1);
                reverse(p.begin(), p.end());
                return p+word.substr(i+1);
            }
        }
        return word;
    }
};
