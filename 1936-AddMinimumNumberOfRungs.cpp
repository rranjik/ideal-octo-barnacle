class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int at = 0;
        int res = 0;
        int n = rungs.size();
        const int req = rungs[n-1];
        //cout<<"req = "<<req<<endl;
        int i = 0;
        while(at<req){
            cout<<"i = "<<i<<endl;
            int reach = at+dist;
            int nat = at;
            cout<<"reach = "<<reach<<" at = "<<at<<endl;
            bool moved = false;
            while(i<n&&reach>=rungs[i]){
                //cout<<"jumping to "<<rungs[i]<<endl;
                moved = true;
                nat = rungs[i];
                i++;
            }
            at = nat;
            //cout<<"nat = "<<nat<<endl;
            int nextAvail = -1;
            if(i<n) nextAvail = rungs[i];
            if(!moved){
                //res++;
                //at = at+dist;
                auto steps = (nextAvail-at-1)/dist;
                res += steps;               
                at = at+steps*dist;
            }
        }
        return res;
    }
};
