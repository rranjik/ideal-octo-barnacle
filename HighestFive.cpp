// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// ProductReviewScore CLASS IS ALREADY DEFINED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <algorithm>
//a brute force custom class to hold items
class Holder{
        public:
    //everthing made public for ease
    vector<double> vals;

    //construct an empty container
    Holder(){
        vals = vector<double>(5, 0.0);
    }
    void insert(double val){
        bool toBeConsidered = false;
        for(int i = 0; i< 5; i++){
            //if your item is greater or equal 
            //than any of the elemetns
            //>=, the = here signfies the multiset condition
            if(val >= vals[i]){
                toBeConsidered = true;
            }
        }
        //then it can be considered and inserted at the end 
        //can be inserted at end as we know the last element should be 
        //smaller or equal to it and does no harm 
        if(toBeConsidered){
            vals[4] = val;
            //sort it everytime
            //could be optimized here by getting into details of where to 
            //insert in the sorted list
            sort(vals.begin(), vals.end(), greater<double>());
        }
        
    }
};


map<int, double> calculateHighestFive(int scoreCount, 
                             vector<ProductReviewScore> reviewScoresOfProduct)
{
    // WRITE YOUR CODE HERE
    map<int, double> res;
    //segregate items 
    map<int, Holder> segregated;
    for(const auto& item : reviewScoresOfProduct){
        if(segregated.find(item.productId)!=segregated.end()){
            segregated[item.productId].insert(item.reviewScore);
        }
        else{
            Holder init;
            init.insert(item.reviewScore);
            segregated[item.productId] = init;
        }
    }
    //for every distinct element
    for(auto segit = segregated.begin(); segit!= segregated.end(); segit++){
        double r = 0;
        auto valss = segit->second.vals;
        //add up all values
        for(const auto& v : valss){
                r+=v;
            }
        //average and return
        r/=5.0;
        res[segit->first] = r;
    }
    return res;
}
// FUNCTION SIGNATURE ENDS
