class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<int, vector<int>, greater<int>> rm;
        for(int i = 0; i<n; i++){
            auto m = ceil((double)dist[i]/speed[i]);
            //cout<<"m = "<<m<<endl;
            rm.push(m);
        }
        int m = 0;
        bool zm = true;
        int res = 0;
        while(!rm.empty()){
            auto fm = rm.top();
            //cout<<"fm = "<<fm<<endl;
            rm.pop();
            if(zm){
                m++;
                zm = false;
                res++;
                continue;
            }
            if(fm<=m) return res;
            else {
                res++;
                m++;
            }
        }
        return res;
    }
};
