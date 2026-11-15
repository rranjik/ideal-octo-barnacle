class Solution {
public:
    int minLights(vector<int>& l) {
        int n = l.size();
        vector<int> a(n+1);
        for(int i = 0; i<l.size(); i++){
            if(l[i]==0) continue;
            int v = l[i];
            auto s = max(0, i-v);
            auto e = min(n-1, i+v);
            a[s]+=1;
            a[e+1]-=1;
        }
        int sum = 0;
        int res = 0;
        for(int i = 0; i<n; i++){
            sum+=a[i];
            //cout<<"i = "<<i<<" sum = "<<sum<<endl;
            if(sum==0){
                if(i+3<a.size())a[i+3]-=1;
                sum++;
                if(i+1<n) sum+=a[i+1];
                if(i+2<n) sum+=a[i+2];
                i+=2;
                res++;
            }
        }
        return res;
    }
};
