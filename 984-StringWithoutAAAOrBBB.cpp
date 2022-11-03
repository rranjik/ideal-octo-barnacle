class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s;
        int n = A+B;
        int na{};
        int nb{};
        for(int i = 0; i<n; i++){
            if(A>B){
                if(na<2){
                    s.push_back('a');
                    na++;
                    A--;
                    nb = 0;
                }else{
                    s.push_back('b');
                    nb++;
                    B--;
                    na = 0;
                }
            }else{
                if(nb<2){
                    s.push_back('b');
                    nb++;
                    B--;
                    na = 0;
                }else{
                    s.push_back('a');
                    na++;
                    A--;
                    nb = 0;
                }
            }
        }
        return s;
    }
};
