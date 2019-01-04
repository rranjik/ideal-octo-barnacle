#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//unordered_map<string, int> lookup;
int LookUp[5001][5001];
/*
int commonChildWL(string s1, string s2, int** lookUp)
{
    if(lookUp[s1.length()][s2.length()] != -1)
        return lookUp[s1.length()][s2.length()];
    else if(s1.length() == 0 || s2.length() ==0)
        {
            return lookUp[s1.length()][s2.length()] = 0;
            //return lookup[make_pair<int, int>(s1.length(), s2.length())];
        }
    else if (s1.back() == s2.back()){
        return lookUp[s1.length()][s2.length()] = 1+commonChildWL(
            std::string(s1.begin(), s1.end()-1), std::string(s2.begin(), s2.end()-1), lookUp);
        //return lookup[make_pair<int, int>(s1.length(), s2.length())];
    }
    else
    {
        return lookUp[s1.length()][s2.length()] = max(
            commonChildWL(std::string(s1.begin(), s1.end()), std::string(s2.begin(), s2.end()-1), lookUp),
            commonChildWL(std::string(s1.begin(), s1.end()-1), std::string(s2.begin(), s2.end()), lookUp));
         //return lookup[make_pair<int, int>(s1.length(), s2.length())];
    }
}

int commonChildWLV(string s1, string s2) {
  if (s1.length() == 0 || s2.length() == 0) 
    return 0;
  else if (LookUp[s1.length()-1][s2.length()-1] != -1)
    return LookUp[s1.length()-1][s2.length()-1];
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  else if (s1.back() == s2.back()) {
    LookUp[s1.length()-1][s2.length()-1] =
               1 + commonChildWLV(std::string(s1.begin(), s1.end() - 1),
                                 std::string(s2.begin(), s2.end() - 1));
    return LookUp[s1.length()-1][s2.length()-1];
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  } else {
    LookUp[s1.length()-1][s2.length()-1] =
               max(commonChildWLV(std::string(s1.begin(), s1.end()),
                                 std::string(s2.begin(), s2.end() - 1)),
                   commonChildWLV(std::string(s1.begin(), s1.end() - 1),
                                 std::string(s2.begin(), s2.end())));
    return LookUp[s1.length()-1][s2.length()-1];
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  }
}
*/
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    //cout<<"lengths are: "<<s1.length()<<"," <<s2.length()<<endl;
  if (LookUp[s1.length()][s2.length()] != -1)
    return LookUp[s1.length()][s2.length()];
  else if (s1.length() == 0 || s2.length() == 0) {
    LookUp[s1.length()][s2.length()] = 0;
    return LookUp[s1.length()][s2.length()];
  }
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  else if (s1.back() == s2.back()) {
    LookUp[s1.length()][s2.length()] =
               1 + commonChild(std::string(s1.begin(), s1.end() - 1),
                                 std::string(s2.begin(), s2.end() - 1));
    return LookUp[s1.length()][s2.length()];
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  } else {
    LookUp[s1.length()][s2.length()] =
               max(commonChild(std::string(s1.begin(), s1.end()),
                                 std::string(s2.begin(), s2.end() - 1)),
                   commonChild(std::string(s1.begin(), s1.end() - 1),
                                 std::string(s2.begin(), s2.end())));
    return LookUp[s1.length()][s2.length()];
    // return lookup[make_pair<int, int>(s1.length(), s2.length())];
  }

    //return 0;
    //vector<vector<int>> LookUp(s1.length(), vector<int>(s2.length(), -1));
    /*int lookUp[s1.length()][s2.length()];
    for(auto i = 0; i< s1.length(); i++)
        for(auto j=0; j<s2.length(); j++)
            lookUp[i][j] = -1;*/
    //return commonChildWLV(s1, s2);
    /*
    if(lookup.find(std::string(std::to_string(s1.length())) + "," + std::to_string(s2.length()))!= lookup.end())
      return lookup[std::string(std::to_string(s1.length())) + "," +
                    std::to_string(s2.length())];
    else if(s1.length() == 0 || s2.length() ==0)
        {
      lookup.insert(make_pair(std::string(std::to_string(s1.length())) + "," +
                        std::to_string(s2.length()),
                    0));
      return lookup[std::string(std::to_string(s1.length())) + "," +
                    std::to_string(s2.length())];
        }
    else if (s1.back() == s2.back()){
        lookup.insert(make_pair((std::string(std::to_string(s1.length())) + "," +
                        std::to_string(s2.length())), 1+commonChild(
            std::string(s1.begin(), s1.end()-1), std::string(s2.begin(), s2.end()-1))
        ));
        return lookup[(std::string(std::to_string(s1.length())) + "," +
                       std::to_string(s2.length()))];
    }
    else
    {
      lookup.insert(
          make_pair((std::string(std::to_string(s1.length())) + "," +
                     std::to_string(s2.length())),
                    max(commonChild(std::string(s1.begin(), s1.end()),
                                    std::string(s2.begin(), s2.end() - 1)),
                        commonChild(std::string(s1.begin(), s1.end() - 1),
                                    std::string(s2.begin(), s2.end())))));
      return lookup[(std::string(std::to_string(s1.length())) + "," +
                        std::to_string(s2.length()))];
    }
    */
}

int main()
{
    for(auto i = 0; i< 5001; i++)
        for(auto j=0; j<5001; j++)
            LookUp[i][j] = -1;
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
