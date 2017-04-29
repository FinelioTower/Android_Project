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
	
	public void drink(){
		System.out.println("This is Father drink");
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
	public void dance(){
		System.out.println("This is Daughter dance");
	}
}

public class Cnv1{
	public static void main(String args[]){
		Father f = new Father();
		Son s = new Son();
		Daughter d = new Daughter();
		
		printAction(f);
		printAction(s);
		printAction(d);
	}
	
	public static void printAction(Father f){
		if(f instanceof Son){
			Son s = (Son)f;
			s.playGame();
		}
		else if(f instanceof Daughter){
			Daughter d = (Daughter)f;
			d.dance();
		}
		else if(f instanceof Father){
			f.drink();
		}
	}
	}
}