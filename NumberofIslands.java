class Solution {
    List<List<Node>> grph = new ArrayList<>();
    class Node{
        public Integer g;
        public Boolean v;
        public Node(Integer g, Boolean v){
            this.g=g;
            this.v=v;
        }
    }
    
    public void dfs(int r, int c){
        //System.out.println("r = "+r+" c = "+c);
        if(grph.get(r).get(c).v)
            return;
        else{
            grph.get(r).get(c).v = true;
            if(r-1>=0 && !grph.get(r-1).get(c).v && grph.get(r-1).get(c).g == 1)
                dfs(r-1, c);
            if(c-1>=0 && !grph.get(r).get(c-1).v && grph.get(r).get(c-1).g == 1)
                dfs(r, c-1);
            if(r+1<grph.size() && !grph.get(r+1).get(c).v && grph.get(r+1).get(c).g == 1)
                dfs(r+1, c);
            if(c+1<grph.get(r).size() && !grph.get(r).get(c+1).v && grph.get(r).get(c+1).g == 1)
                dfs(r, c+1);
        }
        return;
    }
    public int numIslands(char[][] grid) {
        if(grid.length==0)
            return 0;
        List<List<Node>> graph = new ArrayList<>();
        for(int i = 0; i<grid.length; i++){
            List<Node> level = new ArrayList<>();
            for(int j = 0; j<grid[i].length; j++){
                level.add(new Node((grid[i][j]=='1'?1:0), false));
            }
            graph.add(level);
        }
        grph = graph;
        int cc = 0;
        for(int i = 0; i<grph.size(); i++){
            for(int j = 0; j<grph.get(i).size(); j++){
                if(!grph.get(i).get(j).v && grph.get(i).get(j).g == 1){
                    cc++;
                    dfs(i, j);
                    //System.out.println("finished a component");
                }
            }
        }
        return cc;
    }
}
