import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    static BigInteger big_factorial(int n){
        BigInteger ans=new BigInteger("1");
        for(int i=2;i<=n;i++)
         ans=ans.multiply(BigInteger.valueOf(i));
        return ans;
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        System.out.println(big_factorial(a));
    }
}