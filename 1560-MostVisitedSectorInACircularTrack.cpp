class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> v(n+1, 0);
        v[rounds[0]] = 1;
        for(int i = 1; i<rounds.size(); i++){
            cout<<"i = "<<i<<endl;
            int s = rounds[i-1];
            int e = rounds[i];
            int c = s;
            while(c!=e){
                cout<<"@ "<<c<<" ";
                c++;
                if(c==n+1) c = 1;
                v[c]++;
            }
            cout<<"@ "<<c<<" ";
            cout<<endl;
        }
        vector<int> res;
        int rres{};
        for(int i = 1; i<v.size(); i++) {
            cout<<"v["<<i<<"] = "<<v[i]<<endl;
            auto vv = v[i];
            if(vv>rres){
                rres = vv;
                res.clear();
                res.push_back(i);
            }else if(vv==rres){
                res.push_back(i);
            }
        }
        return res;
    }
};
