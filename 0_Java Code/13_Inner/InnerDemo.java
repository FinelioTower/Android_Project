class Outer{
	private static int a = 10;
	
	static class Inner{
		public void prinlnfo(){
			System.out.println("a = "+a);
		}
	}
}

public class InnerDemo{
	public static void main(String args[]){
		/*Outer o = new Outer();
		Outer.Inner i = o.new Inner();
		i.prinlnfo();*/
		
		Outer.Inner i = new Outer.Inner();
		i.prinlnfo();
	}
}