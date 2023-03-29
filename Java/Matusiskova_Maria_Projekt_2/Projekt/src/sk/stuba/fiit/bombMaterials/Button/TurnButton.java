package sk.stuba.fiit.bombMaterials.Button;

public class TurnButton extends Button {
	
	boolean push = false;

	@Override
	public void list() {
		// TODO Auto-generated method stub
		
		System.out.println("\tDo you want to turn button?");
	}

	@Override
	public void pushButton() {
		// TODO Auto-generated method stub
		
		if (push == false) {
			System.out.println("Nothing happened with button. Untouched.");
		}
		else {
			System.out.println("The button is turned.");
		}
	}

	@Override
	public void checkButton(boolean check) {
		// TODO Auto-generated method stub
		
		if (check == false) {
			System.out.println("You turned the wrong button.");
		}
		else {
			System.out.println("You turned the right button.");
		}
	}

	@Override
	public boolean getPush() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void setPush(boolean newPush) {
		// TODO Auto-generated method stub
		
		  push = newPush;
	}

}
