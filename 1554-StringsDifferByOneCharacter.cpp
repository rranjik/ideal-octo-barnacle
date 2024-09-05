class Solution {
public:
    bool differByOne(vector<string>& d) {
        int mod = 1e9+7;
        int n = d.size();
        int m = d[0].size();
        vector<int> hashes(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                hashes[i] = (26l * hashes[i]+(d[i][j]-'a'))%mod;
            }
        }
        //for(const auto& h : hashes) cout<<h<<" " <<endl;
        for(int j = m-1, mult = 1; j >=0 ; j--){
            unordered_map<int, vector<int>> m;
            for(int i = 0; i<n; i++){
                //hash without j
                int hnoj = (mod + hashes[i]-(long)mult*(d[i][j]-'a')%mod)%mod;
                auto it = m.find(hnoj);
                if(it!=end(m))
                    //other i
                    for(auto oi : it->second) {
                        cout<<d[oi]<<" might match "<<d[i]<<endl;
                        if(string(begin(d[i]), begin(d[i])+j) == string(begin(d[oi]), begin(d[oi])+j)
                          &&string(begin(d[i])+j+1, end(d[i])) == string(begin(d[oi])+j+1, end(d[oi]))) return true;
                    }
                m[hnoj].push_back(i);
            }
            mult = (26l*mult)%mod;
        }
        return false;
    }
};
