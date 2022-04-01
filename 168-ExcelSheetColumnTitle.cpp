class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            auto nn = n%26;
            if(!nn) nn = 26;
            char c = 'A';
            c--;
            cout<<"nn = "<<nn<<" c = "<<c<<endl;
            c+=nn;
            cout<<"nn = "<<nn<<" c = "<<c<<endl;
            c = (char)c;
            cout<<"nn = "<<nn<<" c = "<<c<<endl;
            res+=string(1, c);
            n--;
            n/=26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
