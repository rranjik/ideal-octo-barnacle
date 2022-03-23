class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;
        for(const auto& a : answers){
            if(m.find(a+1)==m.end()){
                res+=(a+1);
                if(a) m[a+1] = a;
            }else{
                m[a+1]--;
                if(!m[a+1]) m.erase(m.find(a+1));
            }
        }
        return res;
    }
};
