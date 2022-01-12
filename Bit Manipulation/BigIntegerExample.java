import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    static void playWithBigInt(){
        //Declaring BigInteger
        BigInteger a=new BigInteger("12");
        BigInteger b=new BigInteger("1234567891011121314151617181920");
        // a=a.add(b);
        // System.out.println(a);
        // a=a.multiply(b);
        // System.out.println(a);
        // b=b.divide(a);
        // System.out.println(b);
        // b=b.subtract(a);
        // System.out.println(b);

        //Bit Counts-Total set bits
        System.out.println(a.bitCount());

        //Total number of bits
        System.out.println(a.bitLength());

        //Taking input from Scanner
        Scanner sc=new Scanner(System.in);
        int c=sc.nextInt();
        int d=sc.nextInt();
        System.out.println(c+d);

        BigInteger e=BigInteger.valueOf(c);
        BigInteger f=BigInteger.valueOf(d);

        //print the gcd
        System.out.println(e.gcd(f));

        //Base Conversion
        //interpret the given number in the given base
        BigInteger g=new BigInteger("1001",2);
        System.out.println(g);

        //power of number
        System.out.println(e.pow(500000));

    }
    public static void main(String args[]) {
       playWithBigInt();
    }
}