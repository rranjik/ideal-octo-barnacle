class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for(const auto& f : folder)cout<<f<<endl;
        sort(folder.begin(), folder.end());
        vector<bool> stay(folder.size());
        int n = folder.size();
        for(int i = 0; i<n;){
            auto p = folder[i];
            stay[i] = true;
            i++;
            while(i<n&&
                  p.end()==std::mismatch(p.begin(), p.end(), 
                                         folder[i].begin(), folder[i].end()).first
                 &&folder[i][p.size()]=='/'){
                stay[i] = false;
                i++;
            }
        }
        vector<string> res;
        for(int i = 0; i<n; i++){
            if(stay[i]) res.push_back(folder[i]);
        }
        return res;
    }
};
