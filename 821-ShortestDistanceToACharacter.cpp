class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<bool> v(s.size(), false);
        vector<int> res(s.size());
        queue<int> q;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==c){
                v[i] = true;
                res[i] = 0;
                q.push(i);
            }
        }
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            auto prev = n-1;
            auto next = n+1;
            if(prev>=0){
                if(!v[prev]){
                    v[prev] = true;
                    res[prev] = res[n]+1;
                    q.push(prev);
                }
            }
            if(next<s.size()){
                if(!v[next]){
                    v[next] = true;
                    res[next] = res[n]+1;
                    q.push(next);
                }
            }
        }
        return res;
    }
};
