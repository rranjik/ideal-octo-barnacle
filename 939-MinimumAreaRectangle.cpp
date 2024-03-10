class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> x2y;
        unordered_map<int, vector<int>> y2x;
        for(const auto& p : points){
            auto x = p[0]; auto y = p[1];
            x2y[x].push_back(y);
            y2x[y].push_back(x);
        }
        for(auto& [xcoor, ycoors]:x2y){
            sort(ycoors.begin(), ycoors.end());
        }
        for(auto& [ycoor, xcoors]:y2x){
            sort(xcoors.begin(), xcoors.end());
        }
        int res = 1e9;
        for(auto& [xcoor, ycoors]:x2y){
            sort(ycoors.begin(), ycoors.end());
            auto ny = ycoors.size();
            //cout<<"xcoor = "<<xcoor<<endl;
            for(int i = 0; i<ny; i++){
                for(int j = i+1; j<ny; j++){
                    auto y1 = ycoors[i];
                    auto y2 = ycoors[j];
                    //cout<<" y1 = "<<y1<<endl;
                    //cout<<" y2 = "<<y2<<endl;
                    auto y1xcoors = y2x[y1];
                    auto y2xcoors = y2x[y2];
                    /*
                    int k = y1xcoors.size()-1; 
                    int l = y2xcoors.size()-1;
                    while(k||l){
                        if(y1xcoors[k]>y2xcoors[l]) {k--; continue; }
                        if(y1xcoors[k]<y2xcoors[l]) {l--; continue; }
                        else{
                            res = max(res, abs(xcoor-y2xcoors[l])*abs(y1-y2));    
                            break;
                        }
                    } 
                    */
                    int k = 0; 
                    int l = 0;
                    while(k<y1xcoors.size()&&l<y2xcoors.size()){
                        if(y1xcoors[k]>y2xcoors[l]) {l++; continue; }
                        if(y1xcoors[k]<y2xcoors[l]) {k++; continue; }
                        if(y1xcoors[k]==xcoor){
                            l++; k++; continue;
                        }
                        else{
                            //cout<<" y11 = "<<y1xcoors[k]<<endl;
                            //cout<<" y22 = "<<y2xcoors[l]<<endl;
                            res = min(res, abs(xcoor-y2xcoors[l])*abs(y1-y2));    
                            //cout<<"res = "<<res<<endl;
                            k++; l++;
                        }
                    } 
                }
            }
        }
        return res==1e9?0:res;
    }
};
