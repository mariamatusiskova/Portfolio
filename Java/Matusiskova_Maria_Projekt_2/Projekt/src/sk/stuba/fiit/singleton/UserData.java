package sk.stuba.fiit.singleton;

// source: https://www.youtube.com/watch?v=s13rdEk5_xk

public class UserData {
	
	private static UserData instance = null;
	
	 public String name;
	
	private UserData() {
		name = "John";
	}
	
	public static UserData getInstance() {
		
		if (instance == null) {
			
			instance = new UserData();
		}
		
		return instance;
	}
}
