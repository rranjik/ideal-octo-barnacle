class Solution {
public:
    int maximum69Number (int num) {
        auto sn = to_string(num);
        auto pos = sn.find('6', 0);
        if(pos!=string::npos){
            sn[pos] = '9';
        }
        return stoi(sn);
    }
};
