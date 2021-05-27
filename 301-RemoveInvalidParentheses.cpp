class Solution {
public:
    bool isValid(string s){
        int count = 0;
        for(int i = 0; i<s.length(); i++) {
            if(s[i]=='(') count++;
            if(s[i]==')') {
                count--;
                if(count<0) return false;
            }
        }
        if(!count) return true;
        return false;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> seen;
        queue<string> q;
        q.push(s);
        seen.insert(s);
        bool reached = false;
        while(!q.empty()){
            auto len = q.size();
            for(int i = 0; i<len; i++){
                //candidate
                auto c = q.front(); q.pop();
                if(isValid(c)){
                    res.push_back(c);
                    reached = true;
                }else if(!reached){
                    for(int j = 0; j<c.length(); j++){
                        if(c[j]=='('||c[j]==')'){
                            //new candidate
                            auto nc = c.substr(0, j) + c.substr(j+1, -1);
                            if(seen.find(nc)==seen.end()){
                                q.push(nc);
                                seen.insert(nc);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
