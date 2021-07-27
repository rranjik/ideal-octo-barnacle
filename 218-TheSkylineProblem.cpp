class Solution {
public:
    using pii = pair<int, int>;
    //critical point
    struct cpoint{
        bool isstart;
        int x;
        int y;
        cpoint(int _x, int _y, bool _a):x(_x), y(_y), isstart(_a){};
        bool operator<(const cpoint& p)const{
            //is the x coor collides
            if(x==p.x){
                //if one is a start and the other is an end
                //start comes first
                if(isstart^p.isstart){
                    return isstart>p.isstart;
                }else{
                    if(isstart){
                        //if both are starts
                        //taller building comes first
                        return y>p.y;
                    }else{
                        //if both are ends
                        //shorter building is first
                        return y<p.y;
                    }
                }
            }
            return x<p.x;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> prioq;
        prioq.insert({0, 1});
        vector<cpoint> cpoints;
        for(const auto& b : buildings){
            cpoints.push_back(cpoint(b[0], b[2], true));
            cpoints.push_back(cpoint(b[1], b[2], false));
        }
        sort(begin(cpoints), end(cpoints));
        int prevmax = 0;
        vector<vector<int>> res;
        for(const auto& c : cpoints){
            if(c.isstart){
                prioq[c.y]++;
                auto currmax = rbegin(prioq)->first;
                if(currmax>prevmax){
                    res.push_back({c.x, currmax});
                    prevmax = currmax;
                }
            }else{
                prioq[c.y]--;
                if(!prioq[c.y]){
                    prioq.erase(prioq.find(c.y));
                }
                auto currmax = rbegin(prioq)->first;
                if(currmax<prevmax){
                    res.push_back({c.x, currmax});
                    prevmax = currmax;
                }
            }
        }
        return res;
    }
};
