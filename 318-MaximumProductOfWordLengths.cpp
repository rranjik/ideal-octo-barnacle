class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int, int>> m(words.size(), {0, 0});
        for(const auto& w : words){
            int mk = 0;
            for(const auto& c : w){
                int n = 1; n<<=(c - 'a');
                mk |= n;
            }
            //cout<<w<<" "<<mk<<endl;
            m.push_back({w.length(), mk});
        }
        int res = 0;
        for(int i = 0; i<m.size(); i++){
            for(int j = i+1; j<m.size(); j++){
                if(!(m[i].second&m[j].second)){
                    res = max(m[i].first*m[j].first, res);
                }
            }
        }
        return res;
    }
};
