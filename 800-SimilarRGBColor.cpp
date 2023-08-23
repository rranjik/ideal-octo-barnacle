class Solution {
public:
    /*
    (x1) 
    (y1)
    (z1)
    
    x2, y2, z2
    x2 belongs to {0,1,2...f}
    y2 belongs to {0,1,2...f}
    z2 belongs to {0,1,2...f}
    2233aa
    O(1) = 16^3
    O(1) = 16
    
    ABCDEF
    AB belongs to {00, 01, 02, ...., FF}
    0 1 2 ... FF
    00     11     22     x    33        FF
    x%11 = 5
    33%10 = 3
    
    quant = -(x1-x2)^2-(y1-y2)^2-(z1-z2)^2
          = -[ (x1-x2)^2+(y1-y2)^2+(z1-z2)^2 ]
          
           [(x1-x2)^2+(y1-y2)^2+(z1-z2)^2] = 5
           quant = -5
           [(x1-x2)^2+(y1-y2)^2+(z1-z2)^2] = 100
           quant = -100
    */
    string similarRGB(string color) {
        auto ab = string(color.begin()+1, color.begin()+3);
        auto cd = string(color.begin()+3, color.begin()+5);
        auto ef = string(color.begin()+5, color.begin()+7);
        cout<<"ab = "<<ab<<" cd = "<<cd<<" ef = "<<ef<<endl;
        auto abn = stoi(ab, 0, 16);
        auto cdn = stoi(cd, 0, 16);
        auto efn = stoi(ef, 0, 16);
        cout<<"abn = "<<abn<<" cdn = "<<cdn<<" efn = "<<efn<<endl;
        //if(abn%17>=17/2)
        vector<string> allowed = {
            "00", "11", "22", "33", "44", "55", "66", "77", "88",
            "99", "aa", "bb", "cc", "dd", "ee", "ff"
        };
        int mab = 1e9;
        int mcd = 1e9;
        int mef = 1e9;
        int res = 1e9;
        string rres;
        int pab = -1;
        int pcd = -1;
        int pef = -1;
        for(int i = 0; i<allowed.size(); i++){
            auto picked = stoi(allowed[i], 0, 16);
            if(mab>(picked-abn)*(picked-abn)){
                mab = (picked-abn)*(picked-abn);
                pab = i;
            }
            if(mcd>(picked-cdn)*(picked-cdn)){
                mcd = (picked-cdn)*(picked-cdn);
                pcd = i;
            }
            if(mef>(picked-efn)*(picked-efn)){
                mef = (picked-efn)*(picked-efn);
                pef = i;
            }
        }
        return "#"+allowed[pab]+allowed[pcd]+allowed[pef];
        //for(int i = 0; i<allowed.size(); i++){
        //}
        //return 
        //*/
        //return {};
        //auto ab = stoi(string())
    }
};
