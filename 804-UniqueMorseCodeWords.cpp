class Solution {
public:
    unordered_map<char, string> mc= {{'a', ".-"},
                                     {'b',"-..."},
                                     {'c',"-.-."},
                                     {'d',"-.."},
                                     {'e',"."},
                                     {'f',"..-."},
                                     {'g',"--."},
                                     {'h',"...."},
                                     {'i',".."},
                                     {'j',".---"},
                                     {'k',"-.-"},
                                     {'l',".-.."},
                                     {'m',"--"},
                                     {'n',"-."},
                                     {'o',"---"},
                                     {'p',".--."},
                                     {'q',"--.-"},
                                     {'r',".-."},
                                     {'s',"..."},
                                     {'t',"-"},
                                     {'u',"..-"},
                                     {'v',"...-"},
                                     {'w',".--"},
                                     {'x',"-..-"},
                                     {'y',"-.--"},
                                     {'z',"--.."}};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> u;
        for(int i = 0; i<words.size(); i++){
            string m;
            for(const auto& c : words[i]){
                m+=mc[c];
            }
            u.insert(m);
        }
        return u.size();
    }
};
