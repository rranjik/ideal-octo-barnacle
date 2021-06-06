class Solution {
public:
    vector<double> compute(int i, int j){
        if(j<i) {
            //cout<<"something's wrong"<<endl;
            return {};
        }
        if(i==j) return {nums[i]};
        vector<double> inter;
        for(int k = i; k<j; k++){
            auto l = compute(i, k);
            auto r = compute(k+1, j);
            for(int left = 0; left<l.size(); left++){
                for(int right = 0; right<r.size(); right++){
                    if(r[right]!=0.0) inter.push_back(l[left]/r[right]);
                    inter.push_back(l[left]-r[right]);
                    inter.push_back(l[left]+r[right]);
                    inter.push_back(l[left]*r[right]);
                }
            }
        }
        //cout<<"i = "<<i<<"; j = "<<j<<" : ";
        //for(const auto& intermediate : inter){
        //    cout<<intermediate<<" ";
        //}
        //cout<<endl;
        return inter;
    }
    vector<double> nums;
    bool judgePoint24(vector<int>& ns) {
        for(const auto& n : ns) nums.push_back((double)(n));
        sort(begin(nums), end(nums));
        do{
            for(const auto& n : nums) cout<<n<<" "; cout<<endl;
            auto res = compute(0, 3);
            for(const auto& r : res){
                if(abs(r-24)<1e-6) {
                    cout<<"r = "<<r<<"close to 24"<<endl;
                    return true;
                }
            }
        }while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
};
