vector<bool> condense(const vector<string>& data){
    vector<bool> res;
    for(const auto& day : data){
        if(day.find('N')!=string::npos)
            res.push_back(false);
        else
            res.push_back(true);
    }
    return res;
}

int maxStreak(int m, vector<string> data) {
    auto c = condense(data);
    int streak=0;
    int max_so_far = 0;
    for(const auto day:c){
      if(day){
          streak++;
          if(streak>max_so_far)
            max_so_far = streak;
      }
      else{
          streak = 0;
      }
    }
    return max_so_far;
}