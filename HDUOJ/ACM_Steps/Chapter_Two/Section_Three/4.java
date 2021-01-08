import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        BigInteger f[]=new BigInteger[10001];
        f[1]=new BigInteger("1");
        f[2]=new BigInteger("1");
        f[3]=new BigInteger("1");
        f[4]=new BigInteger("1");
        for(int i=5;i<=10000;i++)
        {
            f[i]=f[i-1].add(f[i-2]).add(f[i-3]).add(f[i-4]);
            //f[i]=f[i-1].add(f[i-2].add(f[i-3].add(f[i-4])));
        }
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext()){
            int m=sc.nextInt();
            System.out.println(f[m]);
        }   
    }
}