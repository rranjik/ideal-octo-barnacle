class Solution {
public:
    int score(int i, int j){
        cout<<"i = "<<i<<" j = "<<j<<endl;
        if(i>=j) return 1;
        auto m = match[i];
        cout<<"match["<<i<<"] = "<<m<<endl;
        if(m==j){
            auto inner = i+1<m-1?score(i+1, m-1):0;
            return inner?2*inner:1;
        }
        auto inner = i+1<m-1?score(i+1, m-1):0;
        auto neigbhors = score(m+1, j);
        return (inner?2*inner:1)+neigbhors;
    }
    unordered_map<int, int> match;
    int scoreOfParentheses(string s) {
        stack<int> stk;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='('){
                stk.push(i);
            }else{
                match[stk.top()] = i;
                stk.pop();
            }
        }
        return score(0, s.length()-1);
    }
};
