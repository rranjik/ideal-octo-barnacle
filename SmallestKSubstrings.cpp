// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION 
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <vector>
int countKDistinctSubstrings(string inputString, int num)
{
    auto res = 0;
    vector<int> bucket(26, 0);
    for(auto i = 0; i< inputString.length(); i++){
        int numberOfDistinctChars = 0;
        //maintain a bucket of distinct characters seen so far
        //cleared everytime we start over
        bucket = vector<int>(26, 0);
        //try all substrings from i through end
        for(int j = i; j<inputString.length(); j++){
            if(bucket[inputString[j]-'a'] == 0){
                numberOfDistinctChars++;
            }
            bucket[inputString[j]-'a']++;
            if(numberOfDistinctChars == num){
                res++;
            }
            else if(numberOfDistinctChars > num){
                break;
            }
        }
    }
    return res;
    // WRITE YOUR CODE HERE
}
// FUNCTION SIGNATURE ENDS