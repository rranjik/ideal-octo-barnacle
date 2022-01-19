class Solution {
public:
    int lastRemaining(int n) {
        auto remaining = n;
        auto left = true;
        auto step = 1;
        auto head = 1;
        while(remaining>1){
            if(left){
                head = head+step;
                remaining/=2;
                left = false;
                step*=2;
            }else{
                if(remaining%2){
                    head = head+step;
                }
                remaining/=2;
                left = true;
                step*=2;
            }
        }
        return head;
    }
};
