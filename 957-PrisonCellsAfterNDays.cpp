class Solution {
public:
    int day(bitset<8> p){
        bitset<8> res;
        res[0] = 0;
        for(int i = 1; i<7; i++){
            if(p[i-1]==p[i+1]) res[i]=1;
            else res[i] = 0;
        }
        res[7] = 0;
        int ps = static_cast<int>(res.to_ulong());
        return ps;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<int, int> m;
        bitset<8> p;
        for(int i = 0; i<cells.size(); i++){
            p[i] = cells[i]?1:0;
        }
        int ps = static_cast<int>(p.to_ulong());
        while(N>0){
            if(m.find(ps)!=m.end()){
                cout<<"N = "<<N<<" m[ps] = "<<m[ps]<<" ";
                cout<<"cycle ";
                cout<<"m[ps]-N = "<<m[ps]-N<<endl;
                if((m[ps]-N)<0) cout<<"negative "<<endl;
                N%=abs(m[ps]-N);
            }
            m.insert({ps, N});
            if(N>=1) {
                N--;
                ps = day(ps);
            }
        }
        vector<int> res(8);
        bitset<8> r = ps;
        for(int i = 0; i<8; i++){
            res[i] = r[i];
        }
        return res;
    }
};
