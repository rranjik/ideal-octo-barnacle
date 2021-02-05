class Solution {
public:
    void print(vector<int> v){
        for(const auto& n : v) cout<<n<<" ";
        cout<<endl;
    }
    auto buildMaxK(vector<int> v, int k){
        cout<<"buildMaxK@ k = "<<k<<" : ";
        print(v);
        vector<int> res;
        stack<int> stk;
        int len = v.size();
        for(int i = 0; i<len; i++){
            while(stk.size()+len-i>k&&!stk.empty()&&stk.top()<v[i]) stk.pop();
            if(stk.size()<k) stk.push(v[i]);
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
    auto chooseNextElementFromV1(const vector<int>& v1, int i,
                          const vector<int>& v2, int j){
        while(i<v1.size()&&j<v2.size()&&v1[i]==v2[j]){i++; j++;}
        return j>=v2.size()||(i<v1.size()&&v1[i]>v2[j]);
    }
    auto mergeToBuildK(const vector<int>& v1, const vector<int>& v2, int K){
        cout<<"mergeToBuildK@ k = "<<K<<endl<<"v1: ";
        print(v1);
        cout<<"v2: ";
        print(v2);
        vector<int> res;
        for(int i = 0, j = 0, k = 0; k<K; k++){
            res.push_back(chooseNextElementFromV1(v1, i, v2, j)?v1[i++]:v2[j++]);
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //vector<int> v1{6, 7};
        //vector<int> v2{6, 0, 7};
        //cout<<"is v1 greater than v2 ? "<<(v1>v2?"yes":"no")<<endl;
        //auto v1m = buildMaxK(v2, 2);
        //print(v1m);
        //cout<<"should I choose from v1 "
        //    <<(chooseNextElementFromV1(v1, 0, v2, 0)?"yes":"no")<<endl;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k);
        for (int i = max(0, k - m); i <= k && i <= n; ++i) {
            auto r = mergeToBuildK
                (buildMaxK(nums1, i), buildMaxK(nums2, k - i), k);
            if (chooseNextElementFromV1(r, 0, res, 0)) res = r;
        }
        return res;
    }
};
