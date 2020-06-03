class Solution {
public:
    int subtractProductAndSum(int n) {
        int nc = n;
        int s = 0;
        int p = 1;
        while(nc){
            int d = nc%10;
            cout<<"d = "<<d<<endl;
            nc /= 10;
            p *= d;
            s += d;
        }
        return p-s;
    }
};
