class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        map<int, vector<int>> m;
        for(int i =0; i<colors.size(); i++){
            m[colors[i]].push_back(i);
        }
        vector<int> rres;
        for(const auto& q : queries){
            auto lbit = lower_bound(begin(m[q[1]]), end(m[q[1]]), q[0]);
            auto ubit = upper_bound(begin(m[q[1]]), end(m[q[1]]), q[0]);
            auto res = numeric_limits<int>::max();
            if(ubit!=end(m[q[1]])){
                //cout<<"ub of "<<q[0]<<" is "<<*ubit<<endl;
                res = min(res, abs(*ubit-q[0]));
            }
            if(lbit!=end(m[q[1]])){
                //cout<<"lb of "<<q[0]<<" is "<<*lbit<<endl;
                res = min(res, abs(*lbit-q[0]));
            }
            if(lbit!=begin(m[q[1]])){
                lbit--;
                //cout<<"lb of "<<q[0]<<" is "<<*lbit<<endl;
                res = min(res, abs(*lbit-q[0]));
            }
            rres.push_back((res==numeric_limits<int>::max())?-1:res);
        }
        return rres;
    }
};
