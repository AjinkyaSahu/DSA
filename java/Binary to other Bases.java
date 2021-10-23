import java.util.*;
class decoder
{  
    public static void main(String args[])
  {  
    Scanner I= new Scanner (System.in);
     String h[]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    String O[]={"0","1","2","3","4","5","6","7"};
    long n,i,j,r=0;
    int x=0;
    String s="",w="";
    System.out.println("Enter a Binary");
    n=I.nextLong();
    for(i=n;i>0;i/=10) 
       if(i%10>1)
       {
         System.out.println("Invalid Input");
         break;
       }
    if( i== 0)
    {     
        if(n != 0)
        {
          for(j=n;j>0;j=j/10000,x=0)
          {  
            for(i=0;i<((int)Long.toString(j%10000).length());i++)
                x=x+(int)(((j%10000)/Math.pow(10,i))%10* Math.pow(2,i));
            s=h[x]+s; 
          }
          for(j=n;j>0;j=j/1000,x=0)
          {  
            for(i=0;i<((int)Long.toString(j%1000).length());i++)
                x=x+(int)(((j%1000)/Math.pow(10,i))%10* Math.pow(2,i));
             w=h[x]+w; 
          }
          for(j=n;j>0;j=j/10,x++) 
           r=(int)(r+j%10*Math.pow(2,x));
          System.out.println("Hexa Equivalent: "+s+"\nOctal Equivalent: "+w+"\nDecimal Equivalent: " +r);    	
       }
       else
       {
             System.out.println("Hexa Equivalent: 0\nOctal Equivalent: 0\nDecimal Equivalent: 0");
       }
    }
   }
}
