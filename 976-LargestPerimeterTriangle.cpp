class Solution {
public:
    bool isTriangle(int a, int b, int c){
        return (a+b>c)&&(b+c>a)&&(c+a>b);
    }
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));
        for(int i = A.size()-3; i>=0; i--){
            if(A[i]+A[i+1]>A[i+2])
                return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }
};
