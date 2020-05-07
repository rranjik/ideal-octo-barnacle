class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wV, vector<vector<int>>& Fs, int id, int L) {
        queue<int> Q;
        Q.push(id);
        vector<vector<int>> FbL(100);
        int lvl = 0;
        vector<int> friendsInLevelL;
        vector<bool> visited(Fs.size(), false);
        vector<bool> inq(Fs.size(), false);
        while(lvl<=L&&!Q.empty()){
            vector<int> FiL;
            while(!Q.empty()){
                FiL.push_back(Q.front());
                Q.pop();
            }
            if(lvl == L){
                friendsInLevelL = FiL;
            }
            for(const auto&f: FiL){
                visited[f] = true;
            }
            for(const auto&f: FiL){
                for(const auto& ff:Fs[f]){
                    if(!visited[ff]&&!inq[ff]){
                        inq[ff] = true;
                        Q.push(ff);
                    }
                }
            }
            lvl++;
        }
        for(const auto& f : friendsInLevelL){
            cout<<f<<" ";
        }
        cout<<endl;
        map<string, int> freq;
        for(const auto f :friendsInLevelL){
            for(const auto& m : wV[f]){
                if(freq.find(m)==freq.end()){
                    freq[m] = 1;
                }else freq[m]++;
            }
        }
        map<int, vector<string>> ifreq;
        for(auto it = freq.begin(); it!=freq.end(); it++){
            if(ifreq.find(it->second)==ifreq.end()){
                ifreq[it->second] = vector<string>();
            }
            ifreq[it->second].push_back(it->first);
        }
        vector<string> res;
        for(auto it = ifreq.begin(); it!=ifreq.end(); it++){
            res.insert(res.end(), it->second.begin(), it->second.end());;
        }
        cout<<endl;
        return res;
        
    }
};
