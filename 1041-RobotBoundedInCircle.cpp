class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> dirs({{0, 1}, {-1, 0}, {0, -1}, {1, 0}});
        int d = 0;
        int xx = 0;
        int yy = 0;
        set<pair<int, int>> v;
        v.insert({0, 0});
        for(int j = 0; j<4; j++){
            pair<int, int> s({xx, yy});
            v.insert(s);
            for(const auto& i : instructions){
                switch(i){
                    case 'G':{
                        xx+=dirs[d].first;
                        yy+=dirs[d].second;
                        //if(v.find({xx, yy})!=v.end()) return true;
                        //v.insert({xx, yy});
                        cout<<"at x = "<<xx<<"; y = "<<yy<<endl;
                    }break;
                    case 'L':{
                        d = (d+1)%4;
                    }break;
                    case 'R':{
                        if(d==0) d=3;
                        else d = d-1;
                    }break;
                }
            }
            if(v.find({xx, yy})!=v.end()) return true;
        }
        return false;
    }
};
