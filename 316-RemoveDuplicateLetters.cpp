class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        unordered_map<char, int> lastofchar;
        unordered_set<char> added;
        for(int i = 0; i<s.length(); i++){
            lastofchar[s[i]] = i;
        }
        for(int i = 0; i<s.length(); i++){
            auto c = s[i];
            if(added.find(c)==added.end()){
                while(!stk.empty()&&c<stk.top()&&lastofchar[stk.top()]>i){
                    auto rem = stk.top();
                    stk.pop();
                    added.erase(added.find(rem));
                }
                stk.push(c);
                added.insert(c);
            }
        }
        string res;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
