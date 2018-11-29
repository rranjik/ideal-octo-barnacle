#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    string cipher;
    k = k%26;
    for(const auto& c:s)
    {
        //cout<<"char is: "<<c<<endl;
        auto cc = c;
        if(isupper(cc))
        {
          cout << "an upper case char was found: " << cc << " " <<(int)cc << endl;
          int o = ((((int)cc) + k));
          
          if(o>90)
            o = o%90;
          if (o < 65)
            o = o + 65 -1;
          std::cout << "o is " << o << endl;
          cc = (char)(o);
          cout << "op is: " << cc << endl;
          cipher.push_back(cc);
        }
        else if(ispunct(cc)||isdigit(cc)||isspace(cc))
        {
          //cout << "a punct char was found: " << cc << " " << (int)cc << endl;
          //cout << "op is: " << cc << endl;
          cipher.push_back(cc);
        }
        else
        {
          //cout << "a lower case char was found: " << cc << " " << (int)cc << endl;
          int o = ((((int)cc) + k));
          if(o>122)
          o = o%122;
          if(o<97)
            o=o-1+97;
          //std::cout << "o is " << o << endl;
          cc = (char)(o);
          //cout << "op is: " << cc << endl;
          cipher.push_back(cc);
        }
    }
    return cipher;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
