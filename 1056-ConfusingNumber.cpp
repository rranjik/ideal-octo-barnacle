class Solution {
public:
    bool confusingNumber(int N) {
        map<int, int> m{{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        //rotated number
        int rotn = 0;
        int n = N;
        while(n){
            int d = n%10;
            if(m.find(d)==m.end()) return false;
            if(rotn>numeric_limits<int>::max()/10) return false;
            rotn = rotn*10+m[d];
            n/=10;
        }
        return (rotn==N)?false:true;
    }
};
