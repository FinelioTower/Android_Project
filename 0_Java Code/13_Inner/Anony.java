abstract class A{
	public abstract void printlnfo();
}

public class Anony{
	public static void main(String args[]){
		//B b = new B();
		//testFunc(new B());
		testFunc(new A(){
			public void printlnfo(){
				System.out.println("Hello , world!2");
			}
		});
	}
	
	public static void testFunc(A a){
		a.printlnfo();
	}
}