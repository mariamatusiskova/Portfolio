package sk.stuba.fiit.bombMaterials;

public class Password {
	
	void typePassword(boolean passwordIsTyped) {
		if (passwordIsTyped == false) {
			System.out.println("No password.");
		}
		else {
			System.out.println("Password was Typed.");
		}
	}
	
	void checkPassword(boolean correctPassword) {
		if (correctPassword == false) {
			System.out.println("The password is incorrect.");
		}
		else {
			System.out.println("The password is correct.");
		}
	}

}
