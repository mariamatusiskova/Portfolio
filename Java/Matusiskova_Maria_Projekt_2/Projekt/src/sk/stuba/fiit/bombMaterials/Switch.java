package sk.stuba.fiit.bombMaterials;

public class Switch {
	
	public static void turnOnSwitch() {
		System.out.println("\nThe Switch is turned on.");
	}
	
	public static void turnOffSwitch() {
		System.out.println("The Switch is turned off.");
	}
	
	// is answer right?
	public static void checkSwitch(boolean rightSwitch) {
		if (rightSwitch == false) {
			System.out.println("You chose the wrong switch.");
		}
		else {
			System.out.println("You chose the right switch.");
		}
	}
}
