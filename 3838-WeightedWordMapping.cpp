class Solution {
public:
    char getc(int i){
        unordered_map<int, char> m;
        m[25] = 'a';
        m[24] = 'b';
        m[23] = 'c';
        m[22] = 'd';
        m[21] = 'e';
        m[20] = 'f';
        m[19] = 'g';
        m[18] = 'h';
        m[17] = 'i';
        m[16] = 'j';
        m[15] = 'k';
        m[14] = 'l';
        m[13] = 'm';
        m[12] = 'n';
        m[11] = 'o';
        m[10] = 'p';
        m[9] = 'q';
        m[8] = 'r';
        m[7] = 's';
        m[6] = 't';
        m[5] = 'u';
        m[4] = 'v';
        m[3] = 'w';
        m[2] = 'x';
        m[1] = 'y';
        m[0] = 'z';
        return m[i];
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string r;
        for(const auto& w : words){
            int res = 0;
            for(const auto& c : w){
                res+=weights[c-'a'];
            }
            res%=26;
            r+=getc(res);
        }
        return r;
    }
};
