class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> b1(num1);
        bitset<32> b2(num2);
        int on = 0;
        for(int i = 0; i<32; i++){
            if(b2[i]){
                on++;
            }
            cout<<b2[i];
        }
        cout<<endl;
        cout<<"on = "<<on<<endl;
        int f = -1;
        for(int i = 31; i>=0; i--){
            if(b1[i]){
                f = i;
                break;
            }
        }
        cout<<"f = "<<f<<endl;
        if(f==-1){
            bitset<32> res;
            while(on){
                res[on] = 1;
                on--;
            }
            int rres = res.to_ulong();
            return rres;
        }
        if(!on){
            return num1;
        }
        auto res = bitset<32>();
        for(int i = 31; on&&i>=0; i--){
            if(on>i){
                on--;
                res[i] = 1;
            }else if(b1[i]){
                on--;
                res[i] = 1;
            }
            cout<<res[i];
        }
        cout<<endl;
        int rres = res.to_ulong();
        return rres;
    }
};
