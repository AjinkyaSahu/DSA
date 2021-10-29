import java.util.*;
class Result
{
  static String swapFirstLastChar(String str)
  {
 char[] ch = str.toCharArray(); 
        for (int i = 0; i < ch.length; i++) { 
  
            // k stores index of first character 
            // and i is going to store index of last  
            // character.  
            int k = i; 
            while (i < ch.length && ch[i] != ' ')  
                i++; 
              
            // Swapping 
            char temp = ch[k]; 
            ch[k] = ch[i - 1]; 
            ch[i - 1] = temp; 
  
            // We assume that there is only one space 
            // between two words. 
        } 
        return new String(ch); 
  }
}
class Main
{
  public static void main(String[] args)
  {
    int t,i,j=0;
    String a, b;
    Scanner s=new Scanner(System.in);
    t=Integer.parseInt(s.nextLine());
    while(t != 0)
    {
      a = s.nextLine();
      b=Result.swapFirstLastChar(a);
      System.out.println(b);
      t--;
    }
  }
}
