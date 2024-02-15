class Solution {
public:
    string subStrHash(string S, int p, int m, int k, int H) {
        auto s = S;
        reverse(s.begin(), s.end());
        long long h = 0;    
        long long pp = 1;
        int j = 0;
        while(j<k-1){
            pp*=p;
            pp%=m;
            j++;
        }
        pp%=m;
        int i = 0;
        while(i<k){
            h*=p;
            h%=m;
            int c = s[i]-'a'+1;
            h+=c;
            h%=m;
            i++;
        }
        int start = 0;
        if(h==H){
            start = k-1;
        }
        for(i = k; i<s.size(); i++){
            long long v = s[i-k]-'a'+1;
            v*=pp;
            v%=m;
            h-=v;
            
            if(h<0){
                //cout<<"h was negative at i = "<<i<<" h = "<<h<<endl;
                h+=m;
                h%=m;
                //cout<<"after correction h = "<<h<<endl;
            }
            
            h*=p;
            h%=m;
            
            int c = s[i]-'a'+1;
            h+=c;
            h%=m;
            //cout<<"h = "<<h<<" i = "<<i<<endl;
            if(h==H){
                start = i;
            }
        }
        int n = S.size();
        cout<<"done start = "<<start<<" n = "<<n<<endl;
        start = n-start-1;
        cout<<"start = "<<start<<" start+k = "<<start+k<<endl;
        auto ss = string(S.begin()+start, S.begin()+start+k);
        return ss;
    }
};
