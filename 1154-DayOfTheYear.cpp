class Solution {
public:
    unordered_map<int, int> md = {
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };
    bool isLeap(int y){
        if((y%4==0&&y%100!=0)||(y%400==0)) return true; return false;
    }
    int dayOfYear(string date) {
        string y;
        string m;
        string d;
        for(int i = 0; i<4; i++){
            y+=string(1, date[i]);
        }
        for(int i = 5; i<7; i++){
            m+=string(1, date[i]);
        }
        for(int i = 8; i<10; i++){
            d+=string(1, date[i]);
        }
        auto ny = stoi(y);
        auto nm = stoi(m);
        auto nd = stoi(d);
        cout<<"ny = "<<ny<<" nm = "<<nm<<" nd = "<<nd<<endl;
        int res{};
        bool isleapyear = isLeap(ny);
        for(int i = 1; i<nm; i++){
            res+=md[i];
        }
        res+=nd;
        if(isleapyear&&nm>2) res++;
        return res;
    }
};
