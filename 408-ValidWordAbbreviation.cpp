class Solution {
public:
    bool validWordAbbreviation(string w, string a) {
        int n = a.size();
        int m = w.size();
        int i = 0; 
        int j = 0;
        int x = 0;
        while(i<n&&j<m){
            cout<<" i = "<<i<<" j = "<<j<<endl;
            if(a[i]>='0'&&a[i]<='9'){
                int start = i;
                while(a[i]>='0'&&a[i]<='9'){
                    x = x*10+(a[i]-'0');
                    i++;
                }
                if(!x) return false;
                if(
                    (to_string(
                        stoi(a.substr(start, i-start))).size()!=
                       a.substr(start, i-start).size()
                       )
                ) 
                       {
                        return false;
                       }
                j+=x;
                x = 0;
            }
            else{
                if(a[i]!=w[j]){
                    return false;
                }
                i++; j++;
            }
        }
        return i==n&&j==m;
    }
};
