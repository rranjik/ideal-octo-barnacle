class Solution {
public:
    struct rep{
        vector<int> f;
        rep(){
            f = vector<int>(52, 0);
        }
        void inc(int i){
            f[i]++;
        }
        bool operator==(const rep& r) const{
            return f == r.f;
        }
        bool operator<(const rep& r) const{
            return f < r.f;
        }
    };
    int numSpecialEquivGroups(vector<string>& A) {
        map<rep, int> m;
        for(const auto& s : A){
            rep r;
            for(int i = 0; i<s.size(); i++){
                auto c = s[i];
                auto s{0};
                auto n = (c-'a');
                s = n*2;
                if(i%2){
                    r.inc(s);
                }else{
                    r.inc(s+1);
                }
            }
            //for(const auto& n : r.f){
            //    cout<<n<<"|";
            //}
            //cout<<endl;
            m[r]++;
        }
        //for(const auto& it : m){
        //    cout<<"{";
        //    for(const auto& s : it.second){
        //        cout<<s<<", ";
        //    }
        //    cout<<"}, ";
        //}
        //cout<<endl;
        return m.size();
    }
};
