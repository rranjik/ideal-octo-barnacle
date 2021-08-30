class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> rres;
        for(int i = 1; i<=n; i++){
            string s = to_string(i);
            //rres.insert(upper_bound(begin(rres), end(rres), s), s);
            rres.push_back(s);
        }
        sort(begin(rres), end(rres));
        vector<int> res;
        for(const auto& s : rres){
            res.push_back(stoi(s));
        }
        return res;
    }
};
