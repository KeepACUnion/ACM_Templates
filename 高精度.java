import java.io.*;  
import java.math.BigInteger;  
import java.util.*;  
public class Main {  
  
    public static void main(String[] args) {  
//声明和赋值  
        Scanner cin=new Scanner(System.in);//在import java.util.*;包中，  
        //实现了大整数输入的方法   cin.nextBigInteger()  
          
        BigInteger big1=BigInteger.ZERO;//0 声明一个大整数并常数值赋值0  
        BigInteger big2=BigInteger.ONE;//1  
        BigInteger big3=BigInteger.TEN;//10  
          
        BigInteger big4 =new BigInteger("1000");//赋除了0，1，10之外的常数值的方法一  
        BigInteger big5= BigInteger.valueOf(1000);//没有new赋除了之外的常数值的方法二  
        //BigInteger bi1 =  new BigInteger(55,new Random());  生成一个个随机的大整数  
          
        BigInteger [] a=new BigInteger [1005];//声明大整数数组，并赋值  
        a[1]=BigInteger.ZERO;  
        a[2]=BigInteger.ONE;  
        a[3]=a[2];  
        a[4]= BigInteger.valueOf(3);//a[4]=a[2].add(a[2].add(a[2]));  
        int n = cin.nextInt();  
        System.out.println(a[n]);  
          
//手动输入  
        int n1=cin.nextInt();//输入一个int型的n1  
        long n2=cin.nextLong();//输入一个long的n2  
          
        BigInteger n3 = cin.nextBigInteger();//声明一个大数，并手动输入这个值  
        BigInteger n4 = cin.nextBigInteger();  
          
//case处理  
        while(cin.hasNext())  
        {  
            //cin.hasNext()输入结束同c++里的while(scanf("%d",&n)!=EOF)  
        }  
        while(cin.hasNextLong())  
        {  
            //同上，这个输入的是long类型时  
        }  
        int test = cin.nextInt();  
        while(test-- >0)  
        {  
            //同c++里的while(scanf(test--))  
        }  
        for(int tt=4;tt<=test;tt++)  
        {  
            //需要记录case++时候  
            System.out.println("Case "+tt+":");//这里不断开，用\n会报错？？  
            System.out.println(big1+" + "+big2+" = "+big1.add(big2));  
        }  
//四则运算及其他  
        System.out.println(n3.add(n4));//n3+n4  
        System.out.println(n3.subtract(n4));//n3-n4  
        System.out.println(n3.multiply(n4));//n3*n4  
        System.out.println(n3.divide(n4));//n3/n4（两个大整数，整除的商  
        System.out.println(n3.remainder(n4));//n3%n4（两个大整数，取余数  
        System.out.println(n3.mod(n4));//同上  
        System.out.println(n3.gcd(n4));//n3和n4的最大公约数  
        System.out.println(n3.abs());//n3取绝对值  
        System.out.println(n3.negate());//n3取相反数  
        System.out.println(n3.min(n4));//n3  
        System.out.println(n3.max(n4));//n3  
        System.out.println(n3.abs());//n3取绝对值  
        System.out.println(n3.pow(2));//n3的2次方（指数  
        System.out.println(n3.toString(2)); // 转化为 x 的 n进制;  
        System.out.println(n3.compareTo(n4)==0); //x和y进行比较  
          if(big1.compareTo(big2) > 0)    
                
              System.out.println("bd1 is greater than bd2");    
   
          else if(big1.compareTo(big2) == 0)    
   
              System.out.println("bd1 is equal to bd2");    
   
          else if(big1.compareTo(big2) < 0)    
   
              System.out.println("bd1 is lower than bd2");    
          
    }  
}  
