package sk.stuba.fiit.bombMaterials.Button;

public class ButtonWithCover extends Button {
	
	String correctButtons;
	boolean push = false;
	
	@Override
	public void list() {
		// TODO Auto-generated method stub
		
		System.out.println("\tDo you want to open cover of this button?");
		System.out.println("\t- [yes]");
		System.out.println("\t- [no]");
	}

	// is button pushed?
	@Override
	public void pushButton() {
		// TODO Auto-generated method stub
		
		if (push == false) {
			System.out.println("Nothing happened with button. Untouched.");
		}
		else {
			System.out.println("The button is pushed.");
		}
	}
	
	// is cover open or not?
	@Override
	public void checkButton(boolean check) {
		// TODO Auto-generated method stub
		
		if (check == false) {
			System.out.println("The cover of the button is closed.");
		}
		else {
			System.out.println("The cover of the button is opened.");
		}
	}

	@Override
	public boolean getPush() {
		// TODO Auto-generated method stub
		return push;
	}

	@Override
	public void setPush(boolean newPush) {
		// TODO Auto-generated method stub
		
		  push = newPush;
	}

}
