class Solution {
public:
    int minMoves(int t, int m) {
        int res = 0;
        //we are yet to reach one
        //and we can still double.
        //if you cannot double, just 
        //exit you have to increment
        while(t>1&&m){
            //if t is even, divide by 2
            //is valid and only 1 coin
            //is spent; else substract 1
            //and divide by 2 (2 coins)
            if(t%2){
                res+=2;
                t--;
            }else{
                res+=1;
            }
            t/=2;
            m-=1;
        }
        return res + (t-1);
    }
    /*
    int minMoves(int t, int m) {
        if(t==1) return 0;
        if(!m) return t-1;
        int nearl = log2(t);
        int near = 1<<nearl;
        cout<<"nearest power of two = "<<near<<endl;
        auto tc = t;
        auto mc = m;
        while(m){
            tc/=2;
            m--;
        }
        cout<<"tc = "<<tc<<endl;
        int res = 0;
        res = tc-1 + mc + (t-near-1);
        return res;
    }
    */
};
