class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int th) {
        unordered_map<int, unordered_map<int, int>> c;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                c[i][j] = c[i-1][j]+c[i][j-1]-c[i-1][j-1]+mat[i][j];
                //cout<<"i = "<<i<<" j = "<<j<<" sum = "<<c[i][j]<<endl;
            }
        }
        
        int sz = min(m, n);
        int l = 0; int r = sz;
        int res = 0;
        int resh = 0;
        while(l<=r){
            int d = (l+r)/2;
            int h = 0;
            //cout<<"* l = "<<l<<" r = "<<r<<" d = "<<d<<endl;
            bool isq = false;
            for(int i = 0; i<=m-d; i++){
                for(int j = 0; j<=n-d; j++){
                    int hh = c[i+d-1][j+d-1]-c[i-1][j+d-1]-c[i+d-1][j-1]+c[i-1][j-1];
                    if(hh<=th){
                        isq = true;
                        break;
                    }
                    //cout<<"A["<<i<<","<<j<<"] = "<<"A["<<i+d-1<<","<<
                    //    j+d-1<<"]-A["<<i-1<<","<<j+d-1<<"]-A["<<i+d-1
                    //    <<","<<j-1<<"]+A["<<i-1<<","<<j-1<<"]"<<endl;
                    //cout<<" i = "<<i<<" j = "<<j<<" hh = "<<hh<<endl;
                }
            }
            //cout<<"l ="<<l<<" r = "<<r<<" h = "<<h<<" d = "<<d<<endl;
            if(isq){
                l = d+1;
            }else{
                r = d-1;
            }
        }
        return r;
    }
};
