import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        BigDecimal num1=new BigDecimal("123.45");
        BigDecimal num2=new BigDecimal("4.5");
        //加法
        System.out.println(num1.add(num2));
        //减法
        System.out.println(num1.subtract(num2));
        //乘法
        System.out.println(num1.multiply(num2));
        //除法（在divide的时候就设置好要精确的小数位数和舍入模式）
        System.out.println(num1.divide(num2,10,BigDecimal.ROUND_HALF_DOWN));
        //取绝对值
        System.out.println(num1.abs());
        //取反
        System.out.println(num1.negate());
        //取最大值
        System.out.println(num1.max(num2));
        //取最小值
        System.out.println(num1.min(num2));
        //是否相等
        System.out.println(num1.equals(num2));
        //判断大小( > 返回1, < 返回-1)
        System.out.println(num2.compareTo(num1));
    }
}
