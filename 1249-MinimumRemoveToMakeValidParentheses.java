class Solution {
    public String minRemoveToMakeValid(String s) {
        char[] arr;
        // allocating memory for 5 integers.
        int n = s.length();
        arr = new char[n];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
 
            // Check if the character has paranthesis
            if((s.charAt(i) == '(') || (s.charAt(i) == ')'))
            {
                if(s.charAt(i)=='(')
                {
                    stack.push(i);
                }
                if(s.charAt(i)==')')
                {
                    if(!stack.empty())
                    {
                        int g = stack.pop();
                        arr[g] = '(';
                        arr[i] = ')';
                    }
                }
            } 
            else
            {
                arr[i]= s.charAt(i);
                
            }   
        }
    StringBuilder str = new StringBuilder();

    for(int i=0;i< arr.length;i++)
    {
        if(arr[i]== '\0')
        {}
        else
        {
            str.append(arr[i]);
        }
    }
    return str.toString();
    }
}
