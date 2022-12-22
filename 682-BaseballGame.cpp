class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(const auto& c : ops){
                if(c=="+"){
                    auto f = s.top();
                    s.pop();
                    auto t = s.top();
                    s.pop();
                    auto n = f+t;
                    s.push(t);
                    s.push(f);
                    s.push(n);
                }
                else if(c=="D"){
                    auto p = s.top();
                    auto n = 2*p;
                    s.push(n);
                }
                else if(c=="C"){
                    s.pop();                   
                }
                else {
                    int n = stoi(c);
                    s.push(n);
                }
        }
        int res{};
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};
