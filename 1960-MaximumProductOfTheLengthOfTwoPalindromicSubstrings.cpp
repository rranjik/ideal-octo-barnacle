class Solution {
public:
    vector<int> manacher(const string& s){
        int n = s.size();
        vector<int> d1(n);
        vector<int> l2r(n,1);
        int l = 0; 
        int r = -1;
        for(int i = 0; i<n; i++){
            auto mirrorc = l+r-i;
            int k = (i>r)?1:min(d1[mirrorc], r-i+1);
            while(i-k>=0&&i+k<n&&s[i-k]==s[i+k]){
                //running smaller palidromes 
                //if computed here
                l2r[i + k] = 2 * k + 1;
                k++;
            }
            d1[i] = k;
            k--;
            if(i+k>r){
                l = i-k;
                r = i+k;
            }
        }
        //if we compute the length of each pali here
        //we will not get the running length
        //for(int i = 0; i<n; i++){
        //    cout<<d1[i]<<" ";
        //}
        cout<<endl;
        for(int i = 1; i < n; i++) 
            l2r[i] = max(l2r[i], l2r[i - 1]);
        return l2r;
    }
    void print(const vector<int>& v){
        //for(const auto& n : v) cout<<n<<" "; cout<<endl;
    }
    void print(const string& v){
        //for(const auto& c : v) cout<<c<<" "; cout<<endl;
    }
    long long maxProduct(string s) {
        auto l2r = manacher(s);
        print(s);
        int n = s.size(); 
        cout<<"n = "<<n<<endl;
        print(l2r);       
        reverse(s.begin(), s.end());
        auto r2l = manacher(s);
        auto pr2l = r2l;
        reverse(pr2l.begin(), pr2l.end());
        print(pr2l);       
        long long res = 0;
        //>>>>>>>---------------
        //------------------<<<<
//ggbswiymmlevedhkbdhntnhdbkhdevelmmyiwsbgg
        //  g  g  b  s  w  i  y  m  m  l  e  v  e  d  h  k  b  d  h  n  t  n  h  d  b  k   h   d   e   v   e   l   m   m   y   i   w   s   b   g   g 
        // 41  39 37 35 33 31 29 27 25 23 21 19 17 15 13 11 9  7  5  3  3  3  3  3  3  3   3   3   3   1   1   1   1   1   1   1   1   1   1   1   1 
        //  1  1  1  1  1  1  1  1  1  1  1  1  3  3  3  3  3  3  3  3  3  3  5  7  9  11  13  15  17  19  21  23  25  27  29  31  33  35  37  39  41 
        //  1  1  1  1  1  1  1  1  1  1  1  2  1  1  1  1  1  1  1  1  21 1  1  1  1  1   1   1   1   2   1   1   1   1   1   1   1   1   1   1   1 
        for (int i = 0, j = n - 2; i < n - 1; ++i, --j){
            if(res<(long long)l2r[i] * r2l[j]){
                //cout<<"update at i = "<<i<<" j = "<<j<<endl;
                res = (long long)l2r[i] * r2l[j];
            }
        }
        return res;
    }
};
