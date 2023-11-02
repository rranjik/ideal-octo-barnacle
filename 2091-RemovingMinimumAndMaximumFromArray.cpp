class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto s = min_element(nums.begin(), nums.end())-nums.begin();
        auto b = max_element(nums.begin(), nums.end())-nums.begin();
        cout<<"s = "<<s<<" b = "<<b<<endl;
        int n = nums.size();
        cout<<"n = "<<n<<endl;
        auto rs = ((n-s)>s+1)?s+1:(n-s);
        cout<<"rs = "<<rs<<endl;
        auto bs = ((n-s)>s+1)?true:false;
        cout<<"bs = "<<bs<<endl;
        auto rb = ((n-b)>b+1)?b+1:(n-b);
        cout<<"rb = "<<rb<<endl;
        auto bb = ((n-b)>b+1)?true:false;
        cout<<"bb = "<<bb<<endl;
        //if(bs==bb) return max(rs, rb);
        //return rs+rb;
        cout<<"***"<<endl;
        return min({max(n-s, n-b),max(s, b)+1, rs+rb});
    }
};
