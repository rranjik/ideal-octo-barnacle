// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left<=right){
            int m = left+(right-left)/2;
            cout<<"left = "<<left<<"; right = "<<right<<"; m = "<<m<<endl;
            if(m==n) return n;
            auto thisv = isBadVersion(m);
            auto nextv = isBadVersion(m+1);
            cout<<"isBadVersion("<<m<<") = "<<thisv
                <<"; isBadVersion("<<m+1<<") = "<<nextv<<endl;
            if(!thisv&&nextv) return m+1;
            if(!thisv){
                left = m+1;
            }else{
                right = m-1;
            }
        }
        return 1;
    }
};
