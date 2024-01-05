class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> c;
        for(int i = 0; i<bank.size(); i++){
            int cc = 0;
            for(int j = 0; j<bank[i].size(); j++){
                if(bank[i][j]=='1') cc++;
            }
            if(cc)
                c.push_back(cc);
        }
        int res = 0;
        for(int i = 1; i<c.size(); i++){
            res += c[i]*c[i-1];
        }
        return res;
    }
};
