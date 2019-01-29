/*
 * Complete the 'smallestString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER weight as parameter.
 */


string smallestString(long weight) {
    vector<unsigned long long int> weights(22,0); //according to given constraints we don't need more than 10^16 but this is 
    //as high as we can get
    //compute initial weights
    weights[0]=1;
    for(int i=1;i<weights.size();i++){
        weights[i]=(i+1)*weights[i-1] + (i+1);
    }
    // for (int i = 0; i < weights.size(); i++) {
    //     cout<<weights[i]<<endl;
    // }
    string res;
    //be greedy go from the back 
    //subtract till wieght is greater than the current char weight
    for(int i=21; i>=0; i--){
        if(weight==0){
            //in case you hit zero return
            reverse(res.begin(),res.end());
            return res;
        }
        while(weight>=weights[i])
        {
            res.push_back((char)((int)('A')+i));
            weight -= weights[i];
        }
    }
    //a special case where strings using A will bail out of for loop because of i and not due to weight being 0;
    reverse(res.begin(), res.end());
    return res;
}
