class Solution {
public:
    int equalSubstring(string s, string t, const int maxCost) {
        vector<int> d;
        for(int i = 0; i<s.length(); i++){
            d.push_back(abs(s[i]-t[i]));
        }
        // for(const auto& n : d){
        //     //cout<<n<<"\t";
        // }
        int res = 0;
        for(int i = 0; i<d.size(); i++){
            int mx = maxCost;
            for(int j = i; j<d.size()&&mx>=0; j++){
                mx-=d[j];
                if(mx>=0){
                    res = max(res, j-i+1);
                }
                else 
                    break;
            }
        }
        for(int i = 0; i<d.size(); i++){
            int c = 0;
            for(int j = i; j<d.size(); j++){
                c+=d[j];
                if(c<=maxCost){
                    
                }
            }
        }
        return res;
    }
};
