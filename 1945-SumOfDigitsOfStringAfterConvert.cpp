class Solution {
public:
    int getLucky(string s, int k) {
        string ss;
        for(int i = 0; i<s.size(); i++){
            ss += to_string(((int)(s[i]-'a'))+1);
        }
        string rres;
        int nres = 0;
        cout<<ss<<endl;
        while(k){
            nres = 0;
            for(int i = 0; i<ss.size(); i++){
                nres+=(ss[i]-'0');
            }
            rres = to_string(nres);
            ss = rres;
            k--;
            cout<<"k = "<<k<<" ss = "<<ss<<endl;
        }
        return stoi(rres);
    }
};
