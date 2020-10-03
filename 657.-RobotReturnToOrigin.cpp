class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> f;
        for(const auto c : moves){
            f[c]++;
        }
        if(f['U']==f['D']&&f['L']==f['R']) return true;
        return false;
    }
};
