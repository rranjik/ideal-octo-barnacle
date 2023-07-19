class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool changed = false;
        for(int i = 0; i<num.size(); i++){
            auto n = static_cast<int>(num[i]-'0')+0;
            auto c = change[n];
            if(changed&&c<n) break;
            if(c>n){
                changed = true;
                num[i] = static_cast<char>('0'+c);
            }
        }
        return num;
    }
};
