abstract class Father{
	
}

interface A{
	public static int i = 10;
	public abstract int getNum();
}

interface B{
	public static String name = "Interface B";
	public abstract String getName();
}

class Son extends Father implements A,B{
	public int getNum(){
		return i;
	}
	public String getName()
	{
		return name;
	}
}

public class Ext{
	public static void main(String args[]){
		Son son = new Son();
		System.out.println(son.getName());
		System.out.println(son.getNum());
	}
}