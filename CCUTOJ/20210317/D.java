import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int Case;
        Case = sc.nextInt();
        while(Case > 0) {
            Case--;
            BigInteger a =  new BigInteger("0");	
            BigInteger b = sc.nextBigInteger();
            BigInteger zero = new BigInteger("0");
            while(b.intValue() != 0) {
                a = a.add(b);
                b = sc.nextBigInteger();
            }
            System.out.println(a);
            System.out.println("");
        }
        
    }
}