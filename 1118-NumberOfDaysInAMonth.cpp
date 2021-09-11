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
        if((y%4==0&&y%100!=0)||(y%400)==0) return true;
        return false;
    }
    int numberOfDays(int year, int month) {
        if(month!=2) return md[month];
        if(isLeap(year)) return 29;
        return 28;
    }
};
