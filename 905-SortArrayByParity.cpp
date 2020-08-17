class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int j = a.size()-1;
        int i = 0;
        vector<int> A = a;
        while(i<a.size()&&j>=0&&i<j){
            while(i<j&&j>=0&&A[i]%2){
                swap(A[i], A[j]);
                j--;
            }
            i++;
        }
        return A;
    }
};
