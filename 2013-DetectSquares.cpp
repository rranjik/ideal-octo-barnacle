class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> m;
    //using pii = pair<int, int>;
    vector<pair<int, int>> ps;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ps.push_back({point[0], point[1]});
        m[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        auto x1 = point[0];
        auto y1 = point[1];
        int res = 0;
        for(auto [x3, y3] : ps){
            //cout<<"(x1, y1) = "<<x1<<", "<<y1<<endl;
            //cout<<"(x3, y3) = "<<x3<<", "<<y3<<endl;
            if(y3==y1&&abs(x1-x3)!=0){
                //if(x1>x3){
                //    swap(x1, x3); swap(y1, y3);
                //}
                //cout<<"same"<<endl;
                auto d = abs(x1-x3);
                //cout<<"d =  "<<d<<endl;
                auto x2 = x1; auto y2 = y1+d;
                auto x4 = x3; auto y4 = y3+d;
                //cout<<"(x2, y2) = "<<x2<<", "<<y2<<endl;
                //cout<<"(x4, y4) = "<<x4<<", "<<y4<<endl;
                res+=(m[x2][y2]*m[x4][y4]);
                y2 = y1-d;
                y4 = y3-d;
                //cout<<"(x2, y2) = "<<x2<<", "<<y2<<endl;
                //cout<<"(x4, y4) = "<<x4<<", "<<y4<<endl;
                res+=(m[x2][y2]*m[x4][y4]);
            }
            //if(abs(x1-x3)!=0&&abs(x1-x3)==abs(y1-y3)){
            //    res+=(m[x1][y3]*m[x3][y1]);
            //}
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
