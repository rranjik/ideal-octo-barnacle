class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        struct comp{
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
                auto [anum, aden] = a;
                auto [bnum, bden] = b;
                return anum*bden>bnum*aden;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int n = arr.size();
        unordered_map<int, int> m;
        for(int i = n-1; i>0; i--){
            m[arr[i]] = arr[i-1];
        }
        for(int i = 0; i<n; i++){
            pq.push({arr[i], arr[n-1]});
        }
        vector<int> res;
        while(k){
            auto [num, den] = pq.top(); pq.pop();
            //cout<<num<<"/"<<den<<endl;
            res = {num, den};
            if(m.find(den)!=m.end()){
                pq.push({num, m[den]});
            }
            k--;
        }
        return res;
    }
};
