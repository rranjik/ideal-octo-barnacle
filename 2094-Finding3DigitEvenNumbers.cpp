class Solution {
public:
    void dfs(int j, int c, vector<int>& res, vector<int>& f){
        cout<<"f.size()="<<f.size()<<endl;
        for(const auto& n : f){
            cout<<n<<" ";
        }
        cout<<endl;
        cout<<"j = "<<j<<" c = "<<c<<endl;
        if(j==3){
            if(c%2==0&&c>=100&&c<=999){
                res.push_back(c);
            }
            return;
        }
        for(int i = 0; i<f.size(); i++){
            if(f[i]>0){
                int temp = c;
                c*=10;
                c+=i;
                f[i]--;
                dfs(j+1, c, res, f);
                f[i]++;
                c = temp;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> f(10);
        for(const auto& d : digits){
            f[d]++;
        }
        vector<int> res;
        dfs(0, 0, res, f);
        return res;
    }
};
