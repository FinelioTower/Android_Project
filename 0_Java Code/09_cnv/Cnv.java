class Father{
	private int money;
	public int getMoney(){
		return money;
	}
	public void setMoney(int money){
		this.money=money;
	}
	public void printInfo(){
		System.out.println("This is Father class");
	}
}

class Son extends Father{
	public void printInfo(){
		System.out.println("This is Son Class");
	}
	public void playGame(){
		System.out.println("This is Son playGame");
	}
}

class Daughter extends Father{
	public void printInfo(){
		System.out.println("This is Daughter Class");
	}
}

public class Cnv{
	public static void main(String args[]){
		Father f = new Father();
		Son s = new Son();
		Daughter d = new Daughter();
		
		print(f);
		print(s);
		print(d);
	}
	
	public static void print(Father f){
		f.printInfo();
	}
	
}