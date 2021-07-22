class Solution {
public:
    double dist(vector<int> p1, vector<int> p2){
        auto dist = sqrt(pow(p1[0]-p2[0], 2)+pow(p1[1]-p2[1], 2));
        cout<<dist<<endl;
        return dist;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> ps({p1, p2, p3, p4});
        sort(begin(ps), end(ps));
        for(const auto& p :ps){
            for(const auto& c : p){
                cout<<c<<" ";
            }
            cout<<endl;
        }
        auto d1 = dist(ps[0], ps[1]);
        auto d2 = dist(ps[0], ps[2]);
        auto d3 = dist(ps[3], ps[2]);
        auto d4 = dist(ps[3], ps[1]);
        
        auto di1 = dist(ps[0], ps[3]);
        auto di2 = dist(ps[2], ps[1]);
        
        return (dist(ps[0], ps[1])!=0.0
                &&(d1==d2&&d2==d3&&d3==d4)
                &&(di1 == di2));
    }
};
