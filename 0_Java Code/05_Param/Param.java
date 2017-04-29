public class Param{
	public static void main(String args[]){
		int x  = 1;
		func(x);
		
		int p[] = new int[1];
		p[0] = 123;
		
		System.out.println("Before fun2:" + p[0]);
		func2(p);
		System.out.println("after fun2 :" + p[0]);
		
		System.out.println(x);
	}
	
	public static void func(int x){
		x = 100;
	}
	
	public static void func2(int[] p){
		p[0] = 200;
	}
}