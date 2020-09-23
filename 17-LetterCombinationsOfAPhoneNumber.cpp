class Solution {
    map<char, vector<char>> m = {
        {'2' , {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
    };
public:
    string d;
    void dfs(int i, string curr, vector<string>& res){
        cout<<"i = "<<i<<"; curr = "<<curr<<endl;
        if(i>d.length()) return;
        if(i==d.length()){
            res.push_back(curr);
            return;
        }
        string c = curr;
        for(int j = 0; j<m[d[i]].size(); j++){
            c+=m[d[i]][j];
            dfs(i+1, c, res);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        d = digits;
        vector<string> ans = vector<string>();
        if(!d.size())
            return ans;
        string c;
        dfs(0, c, ans);                           
        return ans;
    }
};
