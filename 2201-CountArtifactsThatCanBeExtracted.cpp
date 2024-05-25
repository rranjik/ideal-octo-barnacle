class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_map<int, unordered_set<int>> d;
        for(const auto& l : dig){
            d[l[0]].insert(l[1]);
        }
        int res = 0;
        for(const auto& a : artifacts){
            vector<vector<int>> pts;
            if(a[0]==a[2]){
                int tly = a[1];
                int bry = a[3];
                while(tly<=bry){
                    pts.push_back({a[0], tly});
                    tly++;
                }
            }else if(a[1] == a[3]){
                int tlx = a[0];
                int brx = a[2];
                while(tlx<=brx){
                    pts.push_back({tlx, a[1]});
                    tlx++;
                }
            }else{
                int tlx = a[0];
                int tly = a[1];
                int brx = a[2];
                int bry = a[3];
                int trx = tlx;
                int tryy = bry;
                int blx = brx;
                int bly = tly;
                pts.push_back({tlx, tly});
                pts.push_back({trx, tryy});
                pts.push_back({blx, bly});
                pts.push_back({brx, bry});
            }
            auto found = true;
            for(const auto& p : pts){
                //cout<<"looking for "<<p[0]<<", "<<p[1]<<endl;
                if(d.find(p[0])==d.end()||d[p[0]].find(p[1])==d[p[0]].end()) {
                    found = false;
                    break;
                }
            }
            if(found)
                res++;
        }
        return res;
        //for(const auto& a : artifacts){
        //    if(d.find(tlx)==d.end()||d[tlx].find(tly)==d[tlx].end()) continue;
        //    if(d.find(brx)==d.end()||d[brx].find(bry)==d[brx].end()) continue;
        //    if(d.find(trx)==d.end()||d[trx].find(tryy)==d[trx].end()) continue;
        //    if(d.find(blx)==d.end()||d[blx].find(bly)==d[blx].end()) continue;
        //    res++;
        //}
    }
};
