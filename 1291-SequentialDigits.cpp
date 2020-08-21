class Solution {
public:
    int h;
    int l;
    void dfs(int i, int d, string curr, unordered_set<int>& res){
        cout<<"curr = "<<curr<<endl;
        if(curr.length()&&stoi(curr)>h) return;
        if(curr.length()&&(stoi(curr)>=l||stoi(curr)==h)) {
            res.insert(stoi(curr));
            return;
        }
        if(!curr.size()){
            for(int j = i; j<10; j++){
                auto c = curr+to_string(j);
                dfs(j+1, d-1, c, res);
            }
        }else if(i<10) {
            auto c = curr+to_string(i);
                while(i<10&&stoi(c)<=h){
                    dfs(i+1, d-1, c, res);
                    i++;
                    c = c+to_string(i);
            }
        }
        return;
    }
    vector<int> sequentialDigits(int low, int high) {
        h = high;
        l = low;
        unordered_set<int> res;
        string c;
        dfs(1, 0, c, res);
        vector<int> rres;
        for(const auto& n : res){
            rres.push_back(n);
        }
        sort(begin(rres), end(rres));
        return rres;
    }
};
