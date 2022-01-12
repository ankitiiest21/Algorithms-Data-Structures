import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        int i=0;
        Scanner sc=new Scanner(System.in);
        while(i++<2){
            
            BigInteger total=sc.nextBigInteger();
            BigInteger more=sc.nextBigInteger();
            // System.out.println(total);
            // System.out.println(more);
            BigInteger divisor=new BigInteger("2");
            BigInteger k=total.add(more);
            // System.out.println(k);
            // System.out.println(na);
            k=k.divide(divisor);
            BigInteger na=total.subtract(more);
            na=na.divide(divisor);
            System.out.println(k);
            System.out.println(na);
        }
       

    }
}