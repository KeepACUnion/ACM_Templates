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

 BigDecimal	abs() 
          返回 BigDecimal，其值为此 BigDecimal 的绝对值，其标度为 this.scale()。
 BigDecimal	abs(MathContext mc) 
          返回其值为此 BigDecimal 绝对值的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	add(BigDecimal augend) 
          返回一个 BigDecimal，其值为 (this + augend)，其标度为 max(this.scale(), augend.scale())。
 BigDecimal	add(BigDecimal augend, MathContext mc) 
          返回其值为 (this + augend) 的 BigDecimal（根据上下文设置进行舍入）。
 byte	byteValueExact() 
          将此 BigDecimal 转换为 byte，以检查丢失的信息。
 int	compareTo(BigDecimal val) 
          将此 BigDecimal 与指定的 BigDecimal 比较。
 BigDecimal	divide(BigDecimal divisor) 
          返回一个 BigDecimal，其值为 (this / divisor)，其首选标度为 (this.scale() - divisor.scale())；如果无法表示准确的商值（因为它有无穷的十进制扩展），则抛出 ArithmeticException。
 BigDecimal	divide(BigDecimal divisor, int roundingMode) 
          返回一个 BigDecimal，其值为 (this / divisor)，其标度为 this.scale()。
 BigDecimal	divide(BigDecimal divisor, int scale, int roundingMode)
          返回一个 BigDecimal，其值为 (this / divisor)，其标度为指定标度。
 BigDecimal	divide(BigDecimal divisor, int scale, RoundingMode roundingMode)
          返回一个 BigDecimal，其值为 (this / divisor)，其标度为指定标度。
 BigDecimal	divide(BigDecimal divisor, MathContext mc) 
          返回其值为 (this / divisor) 的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	divide(BigDecimal divisor, RoundingMode roundingMode) 
          返回一个 BigDecimal，其值为 (this / divisor)，其标度为 this.scale()。
 BigDecimal[]	divideAndRemainder(BigDecimal divisor) 
          返回由两个元素组成的 BigDecimal 数组，该数组包含 divideToIntegralValue 的结果，后跟对两个操作数计算所得到的 remainder。
 BigDecimal[]	divideAndRemainder(BigDecimal divisor, MathContext mc)
          返回由两个元素组成的 BigDecimal 数组，该数组包含 divideToIntegralValue 的结果，后跟根据上下文设置对两个操作数进行舍入计算所得到的 remainder 的结果。
 BigDecimal	divideToIntegralValue(BigDecimal divisor) 
          返回 BigDecimal，其值为向下舍入所得商值 (this / divisor) 的整数部分。
 BigDecimal	divideToIntegralValue(BigDecimal divisor, MathContext mc)
          返回 BigDecimal，其值为 (this / divisor) 的整数部分。
 double	doubleValue() 
          将此 BigDecimal 转换为 double。
 boolean	equals(Object x) 
          比较此 BigDecimal 与指定的 Object 的相等性。
 float	floatValue() 
          将此 BigDecimal 转换为 float。
 int	hashCode() 
          返回此 BigDecimal 的哈希码。
 int	intValue() 
          将此 BigDecimal 转换为 int。
 int	intValueExact() 
          将此 BigDecimal 转换为 int，以检查丢失的信息。
 long	longValue() 
          将此 BigDecimal 转换为 long。
 long	longValueExact() 
          将此 BigDecimal 转换为 long，以检查丢失的信息。
 BigDecimal	max(BigDecimal val) 
          返回此 BigDecimal 和 val 的最大值。
 BigDecimal	min(BigDecimal val) 
          返回此 BigDecimal 和 val 的最小值。
 BigDecimal	movePointLeft(int n) 
          返回一个 BigDecimal，它等效于将该值的小数点向左移动 n 位。
 BigDecimal	movePointRight(int n) 
          返回一个 BigDecimal，它等效于将该值的小数点向右移动 n 位。
 BigDecimal	multiply(BigDecimal multiplicand) 
          返回一个 BigDecimal，其值为 (this × multiplicand)，其标度为 (this.scale() + multiplicand.scale())。
 BigDecimal	multiply(BigDecimal multiplicand, MathContext mc) 
          返回其值为 (this × multiplicand) 的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	negate() 
          返回 BigDecimal，其值为 (-this)，其标度为 this.scale()。
 BigDecimal	negate(MathContext mc) 
          返回其值为 (-this) 的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	plus() 
          返回 BigDecimal，其值为 (+this)，其标度为 this.scale()。
 BigDecimal	plus(MathContext mc) 
          返回其值为 (+this) 的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	pow(int n) 
          返回其值为 (thisn) 的 BigDecimal，准确计算该幂，使其具有无限精度。
 BigDecimal	pow(int n, MathContext mc) 
          返回其值为 (thisn) 的 BigDecimal。
 int	precision() 
          返回此 BigDecimal 的精度。
 BigDecimal	remainder(BigDecimal divisor) 
          返回其值为 (this % divisor) 的 BigDecimal。
 BigDecimal	remainder(BigDecimal divisor, MathContext mc) 
          返回其值为 (this % divisor) 的 BigDecimal（根据上下文设置进行舍入）。
 BigDecimal	round(MathContext mc) 
          返回根据 MathContext 设置进行舍入后的 BigDecimal。
 int	scale() 
          返回此 BigDecimal 的标度。
 BigDecimal	scaleByPowerOfTen(int n) 
          返回其数值等于 (this * 10n) 的 BigDecimal。
 BigDecimal	setScale(int newScale) 
          返回一个 BigDecimal，其标度为指定值，其值在数值上等于此 BigDecimal 的值。
 BigDecimal	setScale(int newScale, int roundingMode) 
          返回一个 BigDecimal，其标度为指定值，其非标度值通过此 BigDecimal 的非标度值乘以或除以十的适当次幂来确定，以维护其总值。
 BigDecimal	setScale(int newScale, RoundingMode roundingMode) 
          返回 BigDecimal，其标度为指定值，其非标度值通过此 BigDecimal 的非标度值乘以或除以十的适当次幂来确定，以维护其总值。
 short	shortValueExact() 
          将此 BigDecimal 转换为 short，以检查丢失的信息。
 int	signum() 
          返回此 BigDecimal 的正负号函数。
 BigDecimal	stripTrailingZeros() 
          返回数值上等于此小数，但从该表示形式移除所有尾部零的 BigDecimal。
 BigDecimal	subtract(BigDecimal subtrahend) 
          返回一个 BigDecimal，其值为 (this - subtrahend)，其标度为 max(this.scale(), subtrahend.scale())。
 BigDecimal	subtract(BigDecimal subtrahend, MathContext mc) 
          返回其值为 (this - subtrahend) 的 BigDecimal（根据上下文设置进行舍入）。
 BigInteger	toBigInteger() 
          将此 BigDecimal 转换为 BigInteger。
 BigInteger	toBigIntegerExact() 
          将此 BigDecimal 转换为 BigInteger，以检查丢失的信息。
 String	toEngineeringString() 
          返回此 BigDecimal 的字符串表示形式，需要指数时，则使用工程计数法。
 String	toPlainString() 
          返回不带指数字段的此 BigDecimal 的字符串表示形式。
 String	toString() 
          返回此 BigDecimal 的字符串表示形式，如果需要指数，则使用科学记数法。
 BigDecimal	ulp() 
          返回此 BigDecimal 的 ulp（最后一位的单位）的大小。
 BigInteger	unscaledValue() 
          返回其值为此 BigDecimal 的非标度值 的 BigInteger。
static BigDecimal	valueOf(double val) 
          使用 Double.toString(double) 方法提供的 double 规范的字符串表示形式将 double 转换为 BigDecimal。
static BigDecimal	valueOf(long val) 
          将 long 值转换为具有零标度的 BigDecimal。
static BigDecimal	valueOf(long unscaledVal, int scale) 
          将 long 非标度值和 int 标度转换为 BigDecimal。
