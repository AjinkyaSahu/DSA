/*
Java program to print first
non-repeating character in a string
 */

import java.util.Scanner;

public class firstUniqueCharacter {

    /*returns index of first non-repeating
    character else it returns -1*/
    public static int firstNonRepeating(String str) {
        int[] fi = new int [256];


        for(int i = 0; i<256; i++)
            fi[i] = -1;

        // sets all repeating characters to -2 and non-repeating characters
        // contain the index where they occur
        for(int i = 0; i<str.length(); i++) {
            if(fi[str.charAt(i)] == -1) {
                fi[str.charAt(i)] = i;
            }else {
                fi[str.charAt(i)] = -2;
            }
        }

        int res =  Integer.MAX_VALUE;

        for(int i = 0; i<256; i++) {

            // If this character is not -1 or -2 then it
            // means that this character occurred only once
            // so find the min index of all characters that
            // occur only once, that's our first index
            if(fi[i] >= 0)
                res = Math.min(res, fi[i]);
        }

        // if res remains  Integer.MAX_VALUE, it means there are no
        // characters that repeat only once or the string is empty
        if(res ==  Integer.MAX_VALUE) return -1;
        else return res;
    }

    public static void main(String[] args){
        String str;
        System.out.println("Enter your string");
        Scanner myObj = new Scanner(System.in);
        str = myObj.nextLine();  // Read user input
        int firstIndex = firstNonRepeating(str);
        if (firstIndex == -1)
            System.out.println("Either all characters are repeating or string is empty");
        else
            System.out.println("First non-repeating character is "+ str.charAt(firstIndex));
    }
}