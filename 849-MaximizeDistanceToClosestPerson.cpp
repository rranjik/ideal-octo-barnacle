class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int f{-1};
        int l{-1};
        for(int i = 0; i<seats.size(); i++){
            if(seats[i]){
                f = i;
                break;
            }
        }
        for(int i = seats.size()-1; i>=0; i--){
            if(seats[i]){
                l = i;
                break;
            }
        }
        int ll = -1;
        int far = -1;
        for(int i = 0; i<seats.size(); i++){
            if(seats[i]){
                if(ll==-1){
                    ll = i;
                }else{
                    far = max(far, i-ll+1);
                    ll = i;
                }
            }
        }
        cout<<"f = "<<f<<" l = "<<l<<endl;
        cout<<"far = "<<far<<endl;
        int m = -1;
        if(far%2){
            m = far/2;
        }else{
            m = far/2-1;
        }
        return max({m, f, (int)seats.size()-1-l});
    }
};
