class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        List<Integer> indices = new ArrayList<>();
        for(int i = 0; i< secret.length(); i++){
            if(secret.charAt(i)==guess.charAt(i)){
                bulls++;
            }
            else
                indices.add(i);
        }
        //indices.forEach(i->System.out.print(i+" "));
        //System.out.println("");
        StringBuilder ssecret = new StringBuilder();
        StringBuilder sguess = new StringBuilder();
        for(int i = 0; i<indices.size(); i++){
            ssecret.append(secret.charAt(indices.get(i)));
            sguess.append(guess.charAt(indices.get(i)));
        }
        System.out.println(ssecret);
        System.out.println(sguess);
        int[] occs = new int[10];
        int[] occg = new int[10];
        int cows = 0;
        for(int i = 0; i<ssecret.length(); i++){
            occs[ssecret.toString().charAt(i)-'0']++;
            occg[sguess.toString().charAt(i)-'0']++;
        }
        //for(int i = 0; i<occs.length; i++){
        //    System.out.print(occs[i]+" ");
        //}
        //    System.out.println("");
        //for(int i = 0; i<occs.length; i++){
        //    System.out.print(occg[i]+" ");
        //}
        //    System.out.println("");
        for(int i =0; i<10; i++){
            cows += Math.min(occs[i], occg[i]);
        }
        StringBuilder res = new StringBuilder();
        res.append(bulls);
        res.append("A");
        res.append(cows);
        res.append("B");
        return res.toString();
    }
}
