class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = sqrt(area);
        vector<int> res;
        auto done = false;
        while(!done){
            if(area%s==0){
                res.push_back(area/s);
                res.push_back(s);
                done = true;
            }
            s--;
        }
        return res;
    }
};
