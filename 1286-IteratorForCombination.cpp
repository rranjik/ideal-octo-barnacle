class CombinationIterator {
public:
    int combination{};
    bitset<32> b;
    string s;
    int limit = 0;
    int k = 0;
    int n = 0;
    CombinationIterator(string characters, int combinationLength) {
        k = combinationLength;
        s = characters;
        n = characters.length();
        limit = (1<<characters.length())-1;
        cout<<"limit = "<<limit<<endl;
        gen();
        limit = rres.size();
    }
    
    string next() {
        auto res = rres[i];
        i++;
        return res;
    }
    vector<string> rres;
    int i{};
    bool hasNext() {
        return i<limit;
    }
    void gen() {
        auto m = b;
        while(m.to_ulong()<limit){
            auto v = m.to_ulong();
            v++;
            m = bitset<32>(v);
            if(m.count() == k) {
                cout<<"m = "<<m<<endl;
                string ires{};
                for(int i = 0; i<n; i++){
                    if(m[i])
                    ires.push_back(s[i]);
                }
                rres.push_back(ires);
            }
        }
        sort(rres.begin(), rres.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
