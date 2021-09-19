class Solution {
public:
    int twoSumLessThanK(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int res = -1;
        for(int i = 0; i<a.size()-1; i++){
            int ai = a[i];
            int x = k-ai-1;
            cout<<"a["<<i<<"] = "<<a[i]<<"; x = "<<x<<endl;
            auto j = std::lower_bound(a.begin()+i+1, a.end(), x)-a.begin();
            if(j==a.size())j--;
            //cout<<"j = "<<j<<endl;
            if(j<a.size())cout<<"a[j] = "<<a[j]<<endl;
            if(j<a.size()){
                auto aj = a[j];
                if(aj>x){
                    if(j-1>i) {
                        aj = a[j-1];
                        cout<<"a["<<i<<"] = "<<ai<<"; a["<<j<<"] = "<<aj<<endl;
                        res = max(res, aj+ai);
                        cout<<res<<endl;
                    }else {
                        //cout<<"not found"<<endl;
                    }
                }else {
                        cout<<"a["<<i<<"] = "<<ai<<"; a["<<j<<"] = "<<aj<<endl;
                        res = max(res, aj+ai);
                        cout<<res<<endl;
                }
            }else {
                //cout<<"a["<<i<<"] not found "<<endl;
            }
        }
        return res;
    }
};
