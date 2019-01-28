#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};
unordered_map<pair<int, int>, bool, pair_hash> lookup;

bool abbreviate(string a, string b){
  //cout << "strings are: " << a << " and " << b << endl;
  auto coordinate = pair<int, int>(a.length(), b.length());
  if (lookup.find(coordinate) != lookup.end())
    return lookup[coordinate];
  if (a == b) {
    //cout << "in case: 1" << endl;
    lookup[coordinate] = true;
    return true;
      }
    else if(a.length()<b.length()){
        //cout<<"in case: 2"<<endl;
        lookup[coordinate] = false;
        return lookup[coordinate];
    }
    else if(a.length()>0 && b.length()==0){
        //cout<<"in case: 3"<<endl;
        lookup[coordinate] = true;
        return lookup[coordinate];
    }
    // // 'a' is empty but 'b' is not
    // else if(a.length()==0||b.length()!=0) 
    //     return false;
    // last character of'a' and 'b' are upper case and are equal
    else if (isupper(a.back()) && (a.back() == b.back())){
        //cout<<"in case: 4"<<endl;
        lookup[coordinate] = abbreviate(string(a.begin(), a.end() - 1),
                                             string(b.begin(), b.end() - 1));
        return lookup[coordinate];
    }
    // last charater of 'a' is upper case and does not equal 'b'
    // we cannot afford to drop a capital letter in 'a'
    else if (isupper(a.back()) && (a.back() != b.back())){
      lookup[coordinate] = false;
      //cout << "in case: 5" << endl;
      return lookup[coordinate];
    }
    //last character of 'a' is lower case and is not as same as 'b'
    else if(islower(a.back()) && (toupper(a[a.length()-1])!=b.back())){
      lookup[coordinate] = abbreviate(string(a.begin(), a.end() - 1),
                                      string(b.begin(), b.end()));
      //cout<<"in case: 6"<<endl;
      return lookup[coordinate];
    }
    //last character of 'a' is lower case and equals 'b'
    else //if(islower(a.back()) && toupper(a[a.length()-1]==b.back()))
    {
      lookup[coordinate] = (abbreviate(string(a.begin(), a.end() - 1),
                                       string(b.begin(), b.end() - 1)) ||
                            abbreviate(string(a.begin(), a.end() - 1),
                                       string(b.begin(), b.end())));
      //cout<<"in case: 7"<<endl;
      return lookup[coordinate];
    }
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    lookup.clear();
    if(abbreviate(a,b))
        return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
