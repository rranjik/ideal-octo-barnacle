class Solution {
public:
    int maxUniqueSplit(string s) {
        int l = 1<<s.length();
        int i{};
        int res{};
        unordered_set<string> ws;
        int bestd{};
        while(i<l){
            ws.clear();
            bitset<16> b(i);
            auto ci = i;
            auto cci = __builtin_popcount(i);
            if(cci < bestd){
                i++;
                continue;
            }
            int last{};
            int here{};
            //cout<<"i = "<<i<<endl;
            for(int j = 0; j<s.length(); j++){
                if(b[j]){
                    string w = s.substr(last, j-last+1);
                    if(ws.find(w)!=ws.end()) break;
                    last = j+1;
                    here++;
                    ws.insert(w);
                    if(res<here){
                        res = here;
                        bestd = cci;
                    }
                }
            }
            i++;
        }
        return res;
    }
};
