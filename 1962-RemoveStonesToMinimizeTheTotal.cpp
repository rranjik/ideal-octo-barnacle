class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //priority_queue<int, vector<int>, greater<int>> q;
        priority_queue<int> q;
        for(const auto& p : piles){
            q.push(p);
        }
        while(k){
            auto t = q.top();
            //cout<<t<<endl;
            q.pop();
            t = t-floor(((double)t)/2);
            //cout<<"pushing t = "<<t<<endl;
            q.push(t);
            k--;
        }
        int res = 0;
        while(q.size()){
            auto t = q.top();
            q.pop();
            res+=t;
        }
        return res;
    }
};
