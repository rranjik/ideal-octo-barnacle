class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int, int>> line;
        for(const auto& l : lights){
            line.push_back({l[0]-l[1], 1});
            line.push_back({l[0]+l[1]+1, -1});
        }
        sort(line.begin(), line.end());
        int res = 0;
        int bright = 0;
        int mbright = -1e9;
        for(const auto& [pos, light] : line){
            //cout<<"pos = "<<pos<<" light = "<<light<<endl;
            //cout<<"bright = "<<bright<<" mbright = "<<mbright<<endl;
            bright+=light;
            if(mbright<bright){
                mbright = bright;
                res = pos;
            }
        }
        return res;
    }
};
