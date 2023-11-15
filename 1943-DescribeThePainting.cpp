class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<long long> mix(100001);
        vector<bool> term(100001);
        long long sum = 0;
        long long last = 0;
        vector<vector<long long>> res;
        for(const auto& s : segments){
            mix[s[0]]+=s[2];
            mix[s[1]]-=s[2];
            term[s[0]] = term[s[1]] = true;
        }
        for(int i = 1; i<100001; i++){
            //is something term here ?
            //we are gauranteed the mix is 
            //different the next time because 
            //the colors are distinct
            if(term[i]&&sum){
                res.push_back({last, i, sum});
            }
            last = term[i]? i: last;
            sum+=mix[i];
        }
        return res;
    }
};
