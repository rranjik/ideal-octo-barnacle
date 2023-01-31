class Solution {
public:
    int maxRepeating(string sequence, string word) {
        auto oword = word;
        if(sequence.find(word)==string::npos) return 0;
        int res = 1;
        word+=oword;
        while(sequence.find(word)!=string::npos){
            res++;
            word+=oword;
        }
        return res;
    }
};
