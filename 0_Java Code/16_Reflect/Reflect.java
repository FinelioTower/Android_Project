//import a.b.c.d.Person;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Field;

public class Reflect{
	public static void main (String args[]) throws Exception{	
		Class<?> c = Class.forName("a.b.c.d.Person");
		
		Object p = c.newInstance();
		
		Constructor<?> con = c.getConstructor(String.class);
		Object p2 = con.newInstance("asdasd");
		
		Method set = c.getMethod("setName", String.class);
		set.invoke(p2, "123");
		set.invoke(p, "abc");
		
	
		Method get = c.getMethod("getName");
		System.out.println(get.invoke(p));
		System.out.println(get.invoke(p2));
		
		Field name = c.getDeclaredField("name");
		name.setAccessible(true);
		
		name.set(p,"www");
		name.set(p2,"110ask");
		
		System.out.println(name.get(p));
		System.out.println(name.get(p2));
	}
}