class Solution {
public:
    int countOperations(int num1, int num2) {
        int s = 0;
        while(num1&&num2){
            //cout<<"n1 = "<<num1<<" n2 = "<<num2<<endl;
            if(num1>=num2){
                num1 = max(0, num1-num2);
            }else{
                num2 = max(0, num2-num1);
            }
            s++;
        }
        return s;
    }
};
