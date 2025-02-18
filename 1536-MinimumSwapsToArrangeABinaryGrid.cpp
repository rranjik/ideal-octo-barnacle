class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        list<int> rows;
        for(int i = 0; i<n; i++){
            int numz = 0;
            cout<<i<<endl;
            for(int j = n-1; j>=0&&grid[i][j]==0; j--){
                cout<<j<<endl;
                cout<<"conting "<<endl;
                numz++;
            }
            rows.push_back(numz);
        }
        int res = 0;
        for(const auto& r : rows) cout<<r<<" "; cout<<endl;
        for(int i = 0, minneed = n-1; i<n; minneed--, i++){
            auto thisrow = rows.begin();
            int satrowi = i;
            int k = i;
            while(k){
                thisrow = next(thisrow);
                k--;
            }
            auto satrowc = thisrow;
            while(thisrow!=rows.end()&&*thisrow<minneed){
                thisrow = next(thisrow);
                satrowi++;
            }
            if(thisrow==rows.end()) return -1;
            rows.splice(satrowc, rows, thisrow);
            //auto temp = rows[i];
            //rows[i] = rows[satrow];
            //rows[satrow] = temp;
            res+=(satrowi-i);
            //for(const auto& r : rows) cout<<r<<" "; cout<<endl;
            for(const auto& r : rows) cout<<r<<" "; cout<<endl;
        }
        return res;
    }
};
