class Solution {
public:
    vector<int>s;
    unordered_map<int,int>m;
    int numSquares(int n) {
        for(int i=1;i<=100;i++)
        {
            s.push_back(i*i);
           // cout<<i*i << " ";

        }
        
        return dfs(n);
    }
    int dfs(int n)
    {
        //cout<< n << endl;
        if(n==1)
        {
            return m[n]=1;

        }
        if(n==0)
        {
            return m[n]=0;
        } 
        if(m.find(n)!=m.end())
        {
            return m[n];
        }       
        
        int cost=1e9;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<=n)
            {
                int v = n-s[i];
                
                cost = min(cost, 1+dfs(v));
              //  cout<< " cost is" << cost << endl;
                
                
            }
            else
            {
                break;
            }
            
        }
        return m[n]=cost;
    }
};
