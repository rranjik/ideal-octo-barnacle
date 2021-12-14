class Solution {
public:
    int gcd(int a, int b){
        if(a<b) return gcd(b, a);
        if(b==0) return a;
        return gcd(a%b, b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        unordered_map<int, unordered_set<int>> seen;
        for(int d = 1; d<=n; d++){
            for(int n = 1; n<d; n++){
                auto nn = n;
                auto dd = d;
                double v = static_cast<double>(nn)/static_cast<double>(dd);
                if(0<v&&v<1){
                    int gcdd = gcd(nn, dd);
                    nn/=gcdd;
                    dd/=gcdd;
                    if(seen.find(nn)==seen.end()
                       ||seen[nn].find(dd)==seen[nn].end()){
                       seen[nn].insert(dd); 
                       string r = to_string(nn)+"/"+to_string(dd);
                       res.push_back(r);
                    }
                }
            }
        }
        return res;
    }
};
