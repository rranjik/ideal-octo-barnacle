class Solution {
public:
    unordered_map<char, char> strob = {
        {'6', '9'}, 
        {'8', '8'},
        {'9', '6'}, 
        {'1', '1'}, 
        {'0', '0'}, 
    };
    bool isStrobogrammatic(string num) {
        string s;
        for(const auto& x : num){
            if(strob.find(x)==strob.end()) return false;
            s += strob[x];
        }
        reverse(s.begin(), s.end());
        return s == num;
    }
};
