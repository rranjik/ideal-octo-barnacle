class Vector2D {
public:
    int r = 0;
    int c = 0;
    int R = 0;
    int C = 0;
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
        R = v.size();
        if(R){
        C = v[R-1].size();
        }
        cout<<"R = "<<R<<endl;
        cout<<"C = "<<C<<endl;
    }
    
    int next() {
        int ret = 0;
        cout<<"r = "<<r<<"; c = "<<c<<endl;
        while(c==v[r].size()){
            r++;
            c = 0;
        }
        cout<<"final r = "<<r<<"; c = "<<c<<endl;
        ret = v[r][c];
        c++;
        cout<<"returning "<<ret<<endl;
        return ret;
    }
    
    bool hasNext() {
        if(!R) return false;
        int rr = r;
        int cc = c;
        while(rr<R&&cc==v[rr].size()){
            rr++;
            cc = 0;
        }
        if(rr<R) return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
