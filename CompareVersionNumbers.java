class Solution {
    public void print(String s){
        System.out.println(s);
    }
    public int compareVersion(String version1, String version2) {
        String[] split1 = version1.split("\\.", 0);
        String[] split2 = version2.split("\\.", 0);
        Integer[] spl1n = new Integer[split1.length];
        Integer[] spl2n = new Integer[split2.length];
        print(""+split1.length);
        print(""+split2.length);
        for(int i = 0; i<split1.length; i++){
            spl1n[i] = Integer.parseInt(split1[i]); 
            print(""+spl1n[i]);
        }   
        for(int i = 0; i<split2.length; i++){
            spl2n[i] = Integer.parseInt(split2[i]); 
            print(""+spl2n[i]);
        }   
        
        int i = 0;
        int j = 0;
        while(i<spl1n.length && j<spl2n.length){
            if(spl1n[i]>spl2n[j]){
                return 1;
            }else if(spl1n[i]<spl2n[j]){
                return -1;
            }
            i++;
            j++;
        }
        System.out.println("out of initial loop"+"; i = "+i+"; j = "+j);
        if(i==spl1n.length&& j==spl2n.length)
            return 0;
        System.out.println("out both equal "+"; i = "+i+"; j = "+j);
        if(i==spl1n.length){
            while(j<spl2n.length){
                if(spl2n[j]>0){
                    return -1;
                }
                j++;
            }
            return 0;
        }
        System.out.println("out second is greater "+"; i = "+i+"; j = "+j);
        while(i<spl1n.length){
            if(spl1n[i]>0){
                return 1;
            }
            i++;
        }
        return 0;
    }
}
