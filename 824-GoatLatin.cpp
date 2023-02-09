class Solution {
public:
    unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string toGoatLatin(string S) {
        vector<string> words;
        stringstream ss(S);
        int i = 1;
        string res;
        while(!ss.eof()){
            auto word = string();
            ss>>word;
            cout<<word;
            if(vowels.find(word[0])==vowels.end()){
                auto first = word[0];
                word = word.substr(1);
                word.push_back(first);
                word+="ma";
                word+=string(i, 'a');
            }else{
                word+="ma";
                word+=string(i, 'a');
            }
            i++;
            res+=word;
            res.push_back(' ');
        }
        if(res.size()) res.pop_back();
        return res;
    }
};
