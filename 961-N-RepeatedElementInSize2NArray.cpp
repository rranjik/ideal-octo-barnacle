class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i = 0; i<A.size(); i++){
            cout<<"i = "<<i<<endl;
            //if(i+3<A.size()){
            //    if(A[i+3]==A[i]) return A[i];
            //}
            if(i+2<A.size()){
                if(A[i+2]==A[i]) return A[i];
            }
            if(i+1<A.size()){
                if(A[i+1]==A[i]) return A[i];
            }
        }
        return 0;
    }
};
