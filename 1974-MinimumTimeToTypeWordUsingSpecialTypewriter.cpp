class Solution {
public:
    int ctn(char c){
        return c-'a'+1;
    }
    int minTimeToType(string word) {
        char p = 'a';
        int res = 0;
        for(const auto& c : word){
            auto n = ctn(p);
            auto r = ctn(c);
            cout<<"p = "<<p<<" n = "<<n<<" c = "<<c<<" r = "<<r<<endl;
            cout<<abs(n-r)<<" "<<26-(abs(n-r))<<endl;
            res+=(min(abs(n-r), 26-(abs(n-r))));
            p = c;
            res++;
        }
        return res;
    }
};
