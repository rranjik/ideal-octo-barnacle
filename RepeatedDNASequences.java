class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        if(s.length()<10){
            return res;
        }  
        StringBuilder sb = new StringBuilder();
        sb.append(s.substring(0,10));
        
        String c = sb.toString();
        System.out.println("finding "+ c);
        Integer freq = m.getOrDefault(c, 0);
        m.put(c, ++freq);
        
        for(int i = 10; i<s.length(); i++){
            sb.delete(0, 1);
            sb.append(s.charAt(i));
            c = sb.toString();
            System.out.println("finding "+ c);
            freq = m.getOrDefault(c, 0);
            m.put(c, ++freq);
        }
        for(Map.Entry<String, Integer> e : m.entrySet()){
            if(e.getValue()>1){
                res.add(e.getKey());
            }
        }
        return res; 
    }
}
