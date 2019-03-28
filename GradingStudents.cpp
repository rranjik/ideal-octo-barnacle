
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the gradingStudents function below.
 */
vector<int> gradingStudents(vector<int> grades) {
    /*
     * Write your code here.
     */
    vector<int> ans;
    for (auto it = grades.rbegin(); it != grades.rend(); it++) {
      if (*it < 38)
        ans.push_back(*it);
      else {
          auto d = (*it)/5;
          if(*it%5==0){
              ans.push_back(*it);
          }
          else if((((d+1)*5)-*it)<3){
            ans.push_back((d+1)*5);
          }
          else{
              ans.push_back(*it);
          }
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> grades(n);

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
