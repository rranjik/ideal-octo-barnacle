class Solution {
public:
    bool winnerOfGame(string c) {
        int a = 0;
        int b = 0;
        int bob = 0;
        int alice = 0;
        char h;
        for(int i = 0; i<c.size(); i++){
            //cout<<"alice = "<<alice<<" a = "<<a<<" bob = "<<bob<<" b = "<<b<<endl;
            h = c[i];
            if(h=='A'){
                if(b>=3){
                    bob += b-2;
                    b = 0;
                }else{
                    b = 0;
                }
                a++;
            }else{
                if(a>=3){
                    alice += a-2;
                    a = 0;
                }else{
                    a = 0;
                }
                b++;
            }
        }
        if(b>=3){
            bob += b-2;
        }
        if(a>=3){
            alice += a-2;
        }
        //cout<<"alice = "<<alice<<" a = "<<a<<" bob = "<<bob<<" b = "<<b<<endl;
        return alice>bob;
    }
};
