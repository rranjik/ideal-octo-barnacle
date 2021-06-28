class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = -1;
        while((pos = s.find(part))!=string::npos){
            auto after = s.substr(pos+part.size());
            s = s.substr(0, pos) + after;
        }
        return s;
    }
};
