class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k) return false;
        int i{0};
        auto limit = 1<<k;
        bitset<32> b;
        unordered_set<string> c;
        for(int i = 0; i<=s.size()-k; i++){
            auto ss = s.substr(i, k);
            //cout<<"looking for "<<ss<<endl;
            c.insert(ss);
            //b = bitset<32>(i);
            //auto bs = (b).to_string();
            //bs = bs.substr(32-k);
            ////cout<<"looking for "<<bs<<endl;
            //if(s.find(bs)==string::npos) return false;
        }
        if(c.size()<limit) return false;
        return true;
    }
};
