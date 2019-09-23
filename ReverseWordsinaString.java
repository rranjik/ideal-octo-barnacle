class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] words = s.split("\\s+");
        for(String word: words){
            System.out.println(word);
        }
        StringBuilder builder = new StringBuilder();
        for(int i = words.length-1; i>=0; i--){
            builder.append(words[i]);
            builder.append(" ");
        }
        String res = builder.toString().trim();
        return res;
    }
}
