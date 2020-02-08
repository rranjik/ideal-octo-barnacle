class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0, w = 0;
        for(const auto& b : bills){
            cout<<b<<endl;
            switch(b){
                case 5:
                    f++;
                    break;
                case 10:{
                    if(f>=1){
                        f--;
                        t++;
                    }
                    else return false;
                }
                    break;
                case 20:{
                    if(f>=1&&t>=1){
                        f--;t--;
                        w++;
                    }
                    else if(f>=3){
                        f-=3;
                        w++;
                    }
                    else return false;
                }
                    break;
            }
        }
        return true;
    }
};
