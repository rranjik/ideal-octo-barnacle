class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dd, int s, int d) {
        int cres = 0;
        int ccres = 0;
        if(s>d){
            swap(s, d);
        }
        for(int i = 0; i<dd.size(); i++){
            if(i>=s&&i<d){
                cres+=dd[i];
            }else {
                ccres+=dd[i];
            }
        }
        return min(cres, ccres);
    }
};
