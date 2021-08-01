class Solution {
public:
    //1971 Jan 1 is a Friday
    //2100 Dec 31 is a Friday
    map<int, int> monthtodays = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31},
        {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };
    bool isleapyear(int year){
        return ((year%4==0&&year%100!=0)||(year%400==0))?true:false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int prevyear = year-1;
        int numberofdays = 0;
        for(int i = 1971; i<=prevyear; i++){
            if(isleapyear(i)){
                numberofdays+=366;
            }else{
                numberofdays+=365;
            }
        }
        int prevmon = month-1;
        for(int i = 1; i<=prevmon; i++){
            if(i!=2){
                numberofdays+=monthtodays[i];
            }else{
                if(isleapyear(year)) numberofdays+=29;
                else numberofdays+=28;
            }
        }
        numberofdays+=day;
        int dayofweek = numberofdays%7;
        switch(dayofweek){
            case 1:
                return "Friday";
                break;
            case 2:
                return "Saturday";
                break;
            case 3:
                return "Sunday";
                break;
            case 4:
                return "Monday";
                break;
            case 5:
                return "Tuesday";
                break;
            case 6:
                return "Wednesday";
                break;
            case 0:
                return "Thursday";
                break;
        }
        return "";
    }
};
