class Solution {
public:
    int upper;
    int lower;
    vector<int> colsum;
    vector<vector<int>> reconstructMatrix(int _upper, int _lower, vector<int>& _colsum) {
        upper = _upper;
        lower = _lower;
        colsum = _colsum;
        int cu = 0;
        int cl = 0;
        vector<bool> tc = vector<bool>(colsum.size(), false);
        vector<vector<int>> m(colsum.size(), vector<int>());
        for(int i = 0; i<colsum.size(); i++){
            //cout<<"here i = "<<i<<endl;
            if(colsum[i] == 2){
                //cout<<"adding a 1 each; i = "<<i<<endl;
                cu++; cl++;
                tc[i] = true;
                m[i].push_back(1);
                m[i].push_back(1);
            } else if(colsum[i] == 0){
                //cout<<"adding a 0 each; i = "<<i<<endl;
                tc[i] = true;
                m[i].push_back(0);
                m[i].push_back(0);
            }
        }
        //cout<<"out of 2 and 0 cu = "<< cu <<"; cl = "<<cl<<endl;
        if(cu>upper||cl>lower) return vector<vector<int>>();
        vector<bool> aott = vector<bool>(colsum.size(), false);
        for(int i = 0; i<colsum.size(); i++){
            if(colsum[i]==1&&cu<upper){
                cu++;
                tc[i] = true;
                //cout<<"adding 1 on top; i = "<<i<<"; cu = "<<cu<<endl;
                aott[i] = true;
                m[i].push_back(1);
                m[i].push_back(0);
            }
        }
        for(int i = 0; i<colsum.size(); i++){
            if(colsum[i]==1&&cl<lower&&!aott[i]){
                cl++;
                tc[i] = true;
                //cout<<"adding 1 on bottom; i = "<<i<<"; cl = "<<cl<<endl;
                m[i].push_back(0);
                m[i].push_back(1);
            }
        }
        bool done = true;
        for(int i = 0; i < colsum.size(); i++){
            if(!tc[i]) {done = false; break;}
        }
        if(done&&cu==upper&&cl==lower) {
            vector<int> u;
            vector<int> l;
            for(const auto& v: m){
                if(v[0]) u.push_back(1); else u.push_back(0);
                if(v[1]) l.push_back(1); else l.push_back(0);
            }
            vector<vector<int>> res;
            res.push_back(u);
            res.push_back(l);
            return res;
        }
        else {
            cout<<"failed "<<endl;
            return vector<vector<int>>();
        }
    }
};
