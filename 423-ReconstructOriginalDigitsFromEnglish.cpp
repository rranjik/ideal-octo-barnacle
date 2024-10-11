class Solution {
public:
/*
zero  - z
one
two   - w
three 
four  - u
five  
six   - x
seven
eight - g
nine  


one   - o
three - r
five  - f
seven 
nine  

seven - v
nine  - i
*/
    void dec(unordered_map<char, int>& m, int t, string s){
        cout<<t<<" "<<s<<endl;
        for(const auto& c : s) m[c]-=t;
    }
    vector<string> l = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    vector<int> ln = {
        0, 2, 4, 6, 8, 1, 3, 5, 7, 9
    };
    string originalDigits(string s) {
        unordered_map<char, int> m;
        for(const auto& c : s) m[c]++;
        //for(const auto& [k, v]: m) cout<<"{"<<k<<", "<<v<<"} "; cout<<endl;
        vector<char> v = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        int res = 0;
        string rres;
        int  num = 0;
        for(const auto& c : v){
            auto here =  m[c]; 
            //cout<<c<<" "<<here<<endl;
            for(int i = 0; i<here; i++) rres += to_string(ln[num]);
            res+=here;
            dec(m, here, l[ln[num]]);
            num++;
        }
        sort(rres.begin(), rres.end());
        return rres;
    }
};
