// Complete the electionWinner function below.
string electionWinner(vector<string> votes) {
    map<string, int> tally;
    for(const auto& name : votes){
        if(tally.find(name)!=tally.end())
        {
            tally[name]++;
        }
        else{
            tally[name]=1;
        }
    }
    map<int, vector<string>> invert_tally;
    for(auto it = tally.begin(); it!=tally.end(); it++){
        if(invert_tally.find(it->second)!=invert_tally.end())
          invert_tally[it->second].push_back(it->first);
        else{
          vector<string> init;
          init.push_back(it->first);
          invert_tally[it->second] = init;
        }
    }
    int current_max =0;
    for(auto it=invert_tally.begin(); it!=invert_tally.end(); it++)
    {
      if (it->first>current_max)
      {
        current_max = it->first;
      }
        cout<<it->first<<" ";
        for(auto name: it->second)
        cout<<name<<" ";
        cout<<endl;
    }
    cout<<"current max is: "<<current_max;
    auto res = invert_tally[current_max];
    sort(res.begin(), res.end());
    return res[res.size()-1];
    //return "";
}
