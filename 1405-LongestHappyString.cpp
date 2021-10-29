class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int A{}, B{}, C{};
        int size = a+b+c;
        string res;
        for(int i = 0; i<size; i++){
            if((a==max({a,b,c})&&A<2)||(C==2&&a>0)||(B==2&&a>0)){
                a--;
                res+="a";
                A++; B=0;C=0;
            }
            else if((b==max({a,b,c})&&B<2)||(A==2&&b>0)||(C==2&&b>0)){
                b--;
                res+="b";
                B++; A=0;C=0;
            }
            else if((c==max({a,b,c})&&C<2)||(A==2&&c>0)||(B==2&&c>0)){
                c--;
                res+="c";
                C++; A=0;B=0;
            }
        }
        return res;
    }
};
