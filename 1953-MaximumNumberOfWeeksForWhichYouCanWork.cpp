class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        auto sum = 0ll;
        //max milestone
        auto mm = -1ll;
        for(const auto& m : milestones){
            sum+=m;
            mm = max(mm, (long long)m);
        }
        cout<<"sum = "<<sum<<" mm = "<<mm<<endl;
        if(sum-mm<mm){
            return 2*(sum-mm)+1;
        }
        return sum;
    }
};
