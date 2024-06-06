class Solution {
public:
    vector<int> numa;
    vector<int> numb;
    vector<bool> de;
    unordered_map<int, unordered_map<int, bool>> w;
    unordered_map<int, unordered_map<int, int>> c;
    int dp(int i, int ba){
        //cout<<"at "<<i<<" ba = "<<ba<<endl;
        if(i<=0||ba==0) return 0;
        if(c.find(i)!=c.end()&&c[i].find(ba)!=c[i].end()) return c[i][ba];
        if(ba>numa[i-1]){
            auto shoot = dp(i-1, ba-(numa[i-1]+1))+i-1;
            auto dshoot = dp(i-1, ba);
            if(shoot>dshoot){
                w[i-1][ba] = true;
                return c[i][ba] = shoot;
            }else{
                return c[i][ba] = dshoot;
            }
        }
        return c[i][ba] = dp(i-1, ba);
    }
    vector<int> maximumBobPoints(int na, vector<int>& aliceArrows) {
        numa = aliceArrows;
        numb = vector<int>(12);
        de = vector<bool>(12);
        auto s = dp(12, na);
        cout<<"s = "<<s<<endl;
        int ba = na;
        for(int i = 11; i>=0; i--){
            if(w.find(i)!=w.end()&&w[i].find(ba)!=w[i].end()){
                numb[i] = numa[i]+1;
                ba -=numa[i]+1;
            }
        }
        if(ba) numb[0] = ba;
        return numb;
    }
};
