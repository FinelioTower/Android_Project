
import a.b.c.d1.*;
import a.b.c.d2.*;

public class Pack{
	public static void main(String args[]){
		/*add method*/
		System.out.println(a.b.c.d1.Math.add(1,2));
		System.out.println(a.b.c.d2.Math.add(1,2));
		/*sub method*/
		System.out.println(a.b.c.d2.Math.sub(3,2));
		
		a.b.c.d2.Print.printlnf();
		Print.printlnf();
	}
}