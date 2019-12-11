class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] map = new String[26];
        String[] words = str.split(" ");
        Map<String, Character> rev =  new HashMap<>();
        if(pattern.length()!=words.length)
            return false;
        for(int i = 0; i<pattern.length(); i++){
            //System.out.println("checking "+words[i]+"; "+pattern.charAt(i));
            if(rev.get(words[i])==null){
                if(map[pattern.charAt(i)-'a'] == null){
                    map[pattern.charAt(i)-'a'] = words[i];
                }
                else{
                    if(!map[pattern.charAt(i)-'a'].equals(words[i]))       
                        return false;
                }
                rev.put(words[i], pattern.charAt(i));
            }
            else{
                if(!(pattern.charAt(i)==rev.get(words[i])))
                    return false;
            }
        }
        return true;
    }
}
