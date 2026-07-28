class Solution {
public:
    vector<pair<int, int>> counts;
    int n;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> c;
    int maxFrom(int i, int ones, int zeros){
        //cout<<"maxFrom("<<i<<", "<<ones<<", "<<zeros<<")"<<endl;
        if(i==n || ((ones==0)&&(zeros==0))) return 0;

        if(c.find(i)!=c.end()&&
        c[i].find(ones)!=c[i].end()&&
        c[i][ones].find(zeros)!=c[i][ones].end()) return c[i][ones][zeros];
        
        auto [onesh, zerosh] = counts[i];
        if((ones-onesh<0)||(zeros-zerosh<0)){
            return c[i][ones][zeros] = maxFrom(i+1, ones, zeros);
        }
        
        int take = 1+maxFrom(i+1, ones-onesh, zeros-zerosh);
        int ntake = maxFrom(i+1, ones, zeros);

        return c[i][ones][zeros] = max(take, ntake);
    }
    int findMaxForm(vector<string>& strs, int m, int k) {
        n = strs.size();
        counts = vector<pair<int, int>>(n, {0, 0});
        for(int i = 0; i<n; i++){
            auto x = strs[i];
            for(const auto& c : x){
                if(c=='0') counts[i].first++;
                else counts[i].second++;
            }
        }
        return maxFrom(0, m, k);
    }
};

