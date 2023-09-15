class Solution {
public:
    int confuse(const string& a, const char c, const int k){
        int res = 0;
        int i = 0;
        const int n = a.size();
        int need = 0;
        int other = 0;
        for(int j = 0; j<n; j++){
            //cout<<"i = "<<i<<" j = "<<j<<" other = "<<other<<endl;
            if(a[j]!=c) other++;
            while(other>k&&i<n){
                if(a[i]!=c) other--;
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string a, int k) {
        return max(confuse(a, 'T', k), confuse(a, 'F', k));
    }
};
