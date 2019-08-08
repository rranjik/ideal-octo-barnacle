class Solution {
public:
    unordered_map<int, int> f;
    int count(vector<int> c){
        if(f.find(c.size())!=f.end()){
            return f[c.size()];
        }
        if(c.size()<=1)
            return 1;
        int res = 0;
        for(int i = 0; i<c.size(); i++){
            res += count(vector<int>(c.begin(), c.begin()+i))*count(vector<int>(c.begin()+i+1, c.end()));
        }
        f.insert({c.size(), res});
        return res;
    }
    int numTrees(int n) {
        vector<int> c;
        for(int i = 1; i<=n; i++)
            c.push_back(i);
        return count(c);
    }
};
