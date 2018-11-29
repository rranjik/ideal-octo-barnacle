#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  string pattern = "abcdefghijklmnopqrstuvwxyz";
  bool isP=true;
  for(const auto& p:pattern)
  {
      if(string::npos==s.find(p))
      {
        isP=false;
        break;
      }
  }
  return (isP) ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
