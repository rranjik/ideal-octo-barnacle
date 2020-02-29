class Solution {
public:
    int o;
    unordered_set<int> m;
    bool iH(int n){
        if(m.find(n)!=m.end())
            return false;
        cout<<"in iH "<<n<<endl;
        if(n==o)
            return false;
        if(n==1)
            return true;
        else if(n==2||n==3)
            return false;
        else {
            m.insert(n);
            int res=0;
            while(n){
                res +=((n%10)*(n%10));
                n=(n-n%10)/10;
            }
            return iH(res);
        }
    }
    bool isHappy(int n) {
        o = n;
        if(n==1)
            return true;
        else if(n==2||n==3)
            return false;
        else {
            int res=0;
            while(n){
                res +=((n%10)*(n%10));
                n=(n-n%10)/10;
            }
            return iH(res);
        }
    }
};
