class Solution {
public:
    void print(const vector<int>& v){
        for(const auto& n : v) cout<<n<<" ";
        cout<<endl;
    }
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> ol(n);
        vector<int> orr(n);
        vector<int> zl(n);
        vector<int> zr(n);
        ol[0] = 0;
        orr[n-1] = 0;
        for(int i = 1; i<n; i++){
            ol[i] = (ol[i-1] + ((s[i-1]=='1')?1:0));
            zl[i] = (zl[i-1] + ((s[i-1]=='0')?1:0));
        }
        for(int i = n-2; i>=0; i--){
            orr[i] = (orr[i+1] + ((s[i+1]=='1')?1:0));
            zr[i] = (zr[i+1] + ((s[i+1]=='0')?1:0));
        }
        long long res = 0;
        //cout<<"ol = "; print(ol); 
        //cout<<"orr = "; print(orr); 
        //cout<<"zl = "; print(zl); 
        //cout<<"zr = "; print(zr); 
        for(int i = 1; i<n-1; i++){
            if(s[i]=='1'){
                res += (zl[i]*zr[i]);
            }else{
                res += (ol[i]*orr[i]);
            }
        }
        return res;
    }
};
