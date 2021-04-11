class Solution {
public:
    string sortString(string s) {
        map<char, int> m1;
        map<char, int, greater<char>> m2;
        string res;
        int len = s.length();
        for(const auto& c : s){
            m1[c]++;
            m2[c]++;
        }
        while(res.size()<len){
            auto m1c = m1;
            auto m2c = m2;
            for(auto it : m1){
                res+=it.first;
                if(it.second==1) {
                    m1c.erase(m1c.find(it.first));
                    m2c.erase(m2c.find(it.first));
                }else{
                    m1c[it.first]--;
                    m2c[it.first]--;
                }
            }
            m1 = m1c;
            m2 = m2c;
            m1c = m1;
            m2c = m2;
            for(auto it : m2){
                res+=it.first;
                if(it.second==1) {
                    m1c.erase(m1c.find(it.first));
                    m2c.erase(m2c.find(it.first));
                }else{
                    m1c[it.first]--;
                    m2c[it.first]--;
                }
            }
            m1 = m1c;
            m2 = m2c;
        }
        return res;
    }
};
