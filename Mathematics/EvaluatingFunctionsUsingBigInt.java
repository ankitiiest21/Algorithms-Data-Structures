import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        BigInteger x=sc.nextBigInteger();
        BigInteger x3=x.multiply(x);
        x3=x3.multiply(x);
        BigInteger coeff_x3=new BigInteger("4");
        x3=x3.multiply(coeff_x3);
        BigInteger x2=x.multiply(x);
        BigInteger coeff_x2=new BigInteger("5");
        x2=x2.multiply(coeff_x2);
        BigInteger coeff_x=new BigInteger("6");
        x=x.multiply(coeff_x);
        BigInteger constant=new BigInteger("14");
        BigInteger ans=x3;
        ans=ans.add(x2);
        ans=ans.subtract(x);
        ans=ans.add(constant);
        System.out.println(ans);
    }
}