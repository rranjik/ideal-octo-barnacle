class Solution {
public:
    int numberOfMatches(int n) {
        cout<<"n = "<<n<<endl;
        int res{};
        if(n<=1) return 0;
        if(n%2){
            res+=(numberOfMatches((n-1)/2+1)+(n-1)/2);
        }else {
            res+=(numberOfMatches(n/2)+n/2);
        }
        return res;
    }
};
