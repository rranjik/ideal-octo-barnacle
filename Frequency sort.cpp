/*
 * Complete the 'customSort' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void customSort(vector<int> arr) {
    map<int, int> tally;
    for(const auto& elem : arr){
        if(tally.find(elem)!=tally.end())
            tally[elem]++;
        else{
            tally[elem]=1;
        }
    }
    map<int, vector<int>> invert_tally;
    for(auto it=tally.begin(); it!=tally.end(); it++)
    {
      if (invert_tally.find(it->second) != invert_tally.end()){
        //vector<int> init;
        for (int j = 0; j < it->second; j++)
          invert_tally[it->second].push_back(it->first);
        //invert_tally[it->second].push_back(init);
      }
        //invert_tally[it->second].push_back(it->first);
      else {
          vector<int> init;
          for(int j=0; j<it->second; j++)
            init.push_back(it->first);
        invert_tally[it->second] = init;
      }
    }
    for(auto it=invert_tally.begin(); it!=invert_tally.end(); it++){
        for(auto elem :it->second){
            cout<<elem<<endl;
        }
    }
}
