class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        while(n){
        if(n%3==0&&n%5==0){
            res.push_back("FizzBuzz");
        }
        else if(n%3==0){
            res.push_back("Fizz");
        }
        else if(n%5==0){
            res.push_back("Buzz");
        }
        else 
            res.push_back(to_string(n));
        n--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
