class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<bitset<32>> stu;
        vector<bitset<32>> men;
        
        for(int i = 0; i<m; i++){
            int stub = 0;
            int menb = 0;
            int sh = 0;
            for(int j = 0; j<n; j++){
                stub |= (students[i][j]<<sh);
                menb |= (mentors[i][j]<<sh);
                sh++;
            }
            stu.push_back(stub);
            men.push_back(menb);
            //cout<<stu.back()<<" "<<men.back()<<endl;
        }
        vector<int> perm;
        for(int i = 0; i<m; i++){
            perm.push_back(i);
        }
        int res = 0;
        do{
            int comp = 0;
            //for(int i = 0; i<m; i++){
            //    cout<<"s  = "<<i<<" m = "<<perm[i]<<endl;
            //}
            for(int i = 0; i<m; i++){
                comp += n-((stu[i]^men[perm[i]]).count());
            }
            //cout<<"comp = "<<comp<<endl;
            res = max(res, comp);
            //cout<<endl;
        }while(next_permutation(perm.begin(), perm.end()));
        return res;
    }
};
