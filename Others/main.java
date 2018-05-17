1. 输入输出
格式为：Scanner cin = new Scanner (new
BufferedInputStream(System.in));
或者、Scanner cin = new Scanner (System.in);
函数：System.out.print(); System.out.println();
System.out.printf();
System.out.print(); // cout << …;
System.out.println(); // cout << … << endl;
System.out.printf(); // 与C 中的printf 用法类似.
例程：
import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
public class Main{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner (new
		BufferedInputStream(System.in));
		int a; double b; BigInteger c; String st;
		a = cin.nextInt(); b = cin.nextDouble(); c =cin.nextBigInteger(); d = cin.nextLine();
		// 每种类型都有相应的输入函数.
		a = 12345; b = 1.234567;
		System.out.println(a + " " + b);
		System.out.printf("%d %10.5f\n", a, b);
		// 输入b 为字宽为10，右对齐，保留小数点后5 位，四舍五入.
	}
}

2. 字符串处理
java 中字符串String 是不可以修改的，要修改只能转换为字符数组.
例程：
{
	int i;
	Scanner cin = new Scanner (new
	BufferedInputStream(System.in));
	String st = "abcdefg";
	System.out.println(st.charAt(0)); // st.charAt(i)就相当于st[i].
	char [] ch = st.toCharArray(); // 字符串转换为字符数组.
	for (i = 0; i < ch.length; i++) ch[i] += 1;
	System.out.println(ch); // 输入为“bcdefgh”.
	if (st.startsWith("a")) // 如果字符串以'0'开头.
	{
		st = st.substring(1); // 则从第1 位开始copy(开头为第0 位).
	}
}

3. 排序
函数：Arrays.sort();
例程：
Scanner cin = new Scanner (new BufferedInputStream(System.in));
int n = cin.nextInt();
int a[] = new int [n];
for (int i = 0; i < n; i++) a[i] = cin.nextInt();
Arrays.sort(a);
for (int i = 0; i < n; i++) System.out.print(a[i] + " ");

4. 结构体排序
例子：一个结构体有两个元素String x，int y，排序，如果x 相等y 升序，否者x 升序。
Comparator
强行对某个对象collection 进行整体排序的比较函数，可以将
Comparator 传递给Collections.sort 或Arrays.sort。
接口方法：这里也给出了两种方法。
import java.util.*;
class structSort{
	String x;
	int y;
}
class cmp implements Comparator<structSort>{
	public int compare(structSort o1, structSort o2) {
		if(o1.x.compareTo(o2.x) == 0){//这个相当于c/c++中strcmp（o1.x , o2,x）
			return o1.y - o2.y;
		}
		return o1.x.compareTo(o2.x);
	}
}
public class Main {
	public static void main(String[] args) {
		Comparator<structSort> comparator = new Comparator<structSort>(){
			public int compare(structSort o1, structSort o2) {
				if(o1.x.compareTo(o2.x) == 0){
					return o1.y - o2.y;
				}
				return o1.x.compareTo(o2.x);
			}
		};
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		structSort a[] = new structSort[10];
		for (int i = 0; i < n; i++) {
			a[i] = new structSort();
			a[i].x = cin.next();
			a[i].y = cin.nextInt();
		}
		Arrays.sort(a,0,n,comparator);//这个直接使用Comparator
		Arrays.sort(a,0,n,new cmp());//这个实现Comparator，就就跟c++中的sort 函数调用就差不多了
		for (int i = 0; i < n; i++) {
			System.out.println(a[i].x+" "+a[i].y);
		}
	}
}
Comparable强行对实现它的每个类的对象进行整体排序，实现此接口的对象列表（和数组）可以通过Collections.sort 或Arrays.sort 进行自动排序。就是输入完了直接就默认排序了，
接口方法：
import java.util.*;
class structSort implements Comparable<structSort>{
	String x;
	int y;
	public int compareTo(structSort o1) {
		if(this.x.compareTo(o1.x) == 0){
			return this.y - o1.y;
		}
		return this.x.compareTo(o1.x);
	}
}
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		structSort a[] = new structSort[10];
		for (int i = 0; i < n; i++) {
			a[i] = new structSort();
			a[i].x = cin.next();
			a[i].y = cin.nextInt();
		}
		Arrays.sort(a,0,n);
		for (int i = 0; i < n; i++) {
			System.out.println(a[i].x+" "+a[i].y);
		}
	}
}
