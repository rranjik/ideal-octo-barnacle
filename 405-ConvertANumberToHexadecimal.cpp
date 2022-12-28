class Solution {
public:
    unordered_map<int, char> m = {
        {0, '0'},
        {1, '1'},
        {2, '2'},
        {3, '3'},
        {4, '4'},
        {5, '5'},
        {6, '6'},
        {7, '7'},
        {8, '8'},
        {9, '9'},
        {10, 'a'},
        {11, 'b'},
        {12, 'c'},
        {13, 'd'},
        {14, 'e'},
        {15, 'f'}
    };
    string toHex(uint num) {
        if(!num) return "0";
        string res;
        while(num){
            res.push_back(m[num&15]);
            num>>=4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
