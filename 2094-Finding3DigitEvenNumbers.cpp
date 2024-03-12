class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> df(10);
        for(const auto& d : digits) df[d]++;
        vector<int> res;
        for(int i = 100; i<=999; i++){
            if(i%2) continue;
            auto s = to_string(i);
            auto dff = df;
            int okay = true;
            for(const auto& c : s){
                int d = c-'0';
                dff[d]--;
                if(dff[d]<0) {
                    okay = false;
                    break;
                }
            }
            if(okay) res.push_back(i);
        }
        return res;
    }
};
