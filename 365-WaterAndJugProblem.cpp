class Solution {
public:
    int gcd(int x, int y){
        if(y==0)
            return x;
        else if (y==1)
            return 1;
        else return gcd(y, x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(!z) return true;
        if(!x&&y){
            if(z!=y)
                return false;
            else return true;
        }
        else if(!y&&x){
            if(z!=x)
                return false;
            else return true;
        }
        else if(!x&&!y)
            return false;
        if(z>x+y)
            return false;
        if(y>x){
            auto t = y;
            y = x;
            x = t;
        }
        cout<<"x = "<<x<<"; y = "<<y<<endl;
        if(gcd(x,y)!=1 && (z!=(x+y)) && !(z%x==0||z%y==0))
            return false;
        else return true;
    }
};
