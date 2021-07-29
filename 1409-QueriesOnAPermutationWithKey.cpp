class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int> l;
        map<int, list<int>::iterator> miter;
        for(int i = 1; i<=m; i++){
            l.push_back(i);
            miter[i] = prev(l.end());
        }
        vector<int> res;
        for(const auto& q : queries){
            int i = 0;
            for(auto it = l.begin(); it!=l.end(); it++, i++){
                if(*it==q){
                    res.push_back(i);
                    l.splice(l.begin(), l, miter[q]);
                    break;
                }
            }
        }
        return res;
    }
};
