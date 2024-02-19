class Solution {
public:
    struct cpoint{
        int x;
        int h;
        bool start;
        //cpoint(const cpoint& c){this->x = c.x; this->h = c.h; this->start =c.start;}
        cpoint(int _x, int _h, bool _start):x(_x), h(_h), start(_start){}
        bool operator<(const cpoint& other){
            if(x==other.x){
                if(start^other.start){//only one is start
                    //start precedes end
                    /*

                     |--------|--------|
                     |        |        |
                     |   a    |   b    |
                     |        |        |
                    _______________________
                    b before a 
                    so that we can maintain continuity
                    */
                    return start>other.start;
                }
                if(start){
                    //this is start and so other is also start
                    //you come before the other if you're taller
                    /*
                    both a and b are start
                     __________
                    |          |
                    |----\  a  |
                    |    |     |
                    |  b |     |
                    |    |     |
                    _______________
                    a before b

                    so that a can overshadow
                    */
                    return h>other.h;
                }
                    //this is end and so other is also end
                    //you come before the other if you're shorter
                    /*
                    both a and b are end
                     __________
                    |          |
                    | a  /-----|
                    |    |     |
                    |    |  b  |
                    |    |     |
                    _______________
                    b before a
                    
                    so that a can overshadow
                    */
                return h<other.h;
            }
            return x<other.x;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<cpoint> cpoints;
        for(int i = 0; i<buildings.size(); i++){
            cpoints.push_back({buildings[i][0], buildings[i][2], true});
            cpoints.push_back({buildings[i][1], buildings[i][2], false});
        }
        sort(cpoints.begin(), cpoints.end());
        map<int, int> m; //heights -> num of cpoints with that height
        m.insert({0, 1}); //there's a degenerate building of height 0 always
        //you can also think of it as the ground
        auto prevmax = 0;
        vector<vector<int>> res;
        for(const auto& cp : cpoints){
            //cout<<"x = "<<cp.x
            //<<" h = "<<cp.h
            //<<" start = "<<(cp.start?"true":"false")<<endl;
            if(cp.start){
                m[cp.h]++;
                auto curmax = m.rbegin()->first;
                if(prevmax<curmax){
                    res.push_back({cp.x, curmax});
                    prevmax = curmax;
                }
            }else{
                m[cp.h]--;
                if(!m[cp.h]) m.erase(m.find(cp.h));
                auto curmax = m.rbegin()->first;
                if(prevmax>curmax){
                    res.push_back({cp.x, curmax});
                    prevmax = curmax;
                }
            }
        }
        return res;
    }
};
