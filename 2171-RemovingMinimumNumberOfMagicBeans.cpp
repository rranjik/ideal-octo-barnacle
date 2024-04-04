class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        vector<long long> s(n);
        s[0] = beans[0];
        //total mass
        long long tm = beans[0];
        for(int i =1; i<n; i++){
            s[i] += s[i-1]+beans[i];
            tm += beans[i];
        }
        //cout<<"tm = "<<tm<<endl;
        //for(const auto& v : s) cout<<v<<" ";cout<<endl;
        long long res = numeric_limits<long long>::max();
        for(int i = 0; i<n; i++){
            //cout<<" i = "<<i<<" ";
            //number of numbers to the right 
            //w/o including i. (i, n-1]
            long long nr = n-i-1;
            //cout<<"nr = "<<nr<<" ";
            //mass to the right
            long long mr = tm-s[i];
            //cout<<"mr = "<<mr<<" ";
            //loss to the right
            long long lr = mr-(nr*beans[i]);
            //cout<<"lr = "<<lr<<" ";
            //loss on left
            long long ll = i>0?s[i-1]:0;
            //cout<<"ll = "<<ll<<" ";
            //cout<<endl;
            res = min(res, ll+lr);
        }
        return res;
    }
};
