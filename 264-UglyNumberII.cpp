class Solution {
public:
    using ull = unsigned long long;
    int nthUglyNumber(int n) {
        priority_queue<ull, vector<ull>, greater<ull>> q;
        vector<ull> uns;
        q.push(1);
        unordered_set<ull> seen;
        while(uns.size()<n){
            auto mini = q.top();
            cout<<mini<<" ";
            q.pop();
            uns.push_back(mini);
            ull u5 = (mini<=numeric_limits<ull>::max()/5)?(mini*5):1; 
            ull u2 = (mini<=numeric_limits<ull>::max()/2)?(mini*2):1; 
            ull u3 = (mini<=numeric_limits<ull>::max()/3)?(mini*3):1; 
            if(seen.find(u2)==seen.end()){
                seen.insert(u2);
                q.push(u2);
            }
            if(seen.find(u3)==seen.end()){
                seen.insert(u3);
                q.push(u3);
            }
            if(seen.find(u5)==seen.end()){
                seen.insert(u5);
                q.push(u5);
            }
        }
        return uns.back();
    }
};
