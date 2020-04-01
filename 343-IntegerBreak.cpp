class Solution {
public:
	int integerBreak(int n) {
	    if(n==2) return 1;
	    if(n==3) return 2;
	    if(n==4) return 4;
	    auto exp = n/3;
	    auto rem = n%3;
	    if(rem==2) return (pow(3, exp))*rem;
	    if(rem==0) return (pow(3, exp));
	    return (pow(3, exp-1))*4;
	}
};
