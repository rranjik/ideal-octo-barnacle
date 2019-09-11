class Solution {
    public class LevelAndWord{
        int level;
        String word;
        LevelAndWord(int level, String word){
            this.level = level;
            this.word = word;
        }
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int l = beginWord.length();
        
        HashMap<String, ArrayList<String>> adjWords = new HashMap<>();
        
        wordList.forEach(word->{
            for(int i = 0; i< l; i++){
                String inter = word.substring(0, i) + "*" + word.substring(i+1, l);
                ArrayList<String> adjs = adjWords.getOrDefault(inter, new ArrayList<String>());
                adjs.add(word);
                adjWords.put(inter, adjs);
            }
        });
        
        Queue<LevelAndWord> q = new LinkedList<>();
        Map<String, Boolean> v = new HashMap<>();
        q.add(new LevelAndWord(1, beginWord));
        
        while(q.peek()!=null){
            LevelAndWord law =  q.remove();
            String word = law.word;
            int level = law.level;
            //System.out.println(word);
            
            for(int i = 0; i<l; i++){
                String inter = word.substring(0, i) + "*" + word.substring(i+1, l);
                
                for(String adj : adjWords.getOrDefault(inter, new ArrayList<String>())){
                    if(adj.equals(endWord)){
                        return level+1;
                    }
                    if(!v.containsKey(adj)){
                        v.put(adj, true);
                        q.add(new LevelAndWord(level+1, adj));
                    }
                }
            }
        }
        return 0;
    }
}
