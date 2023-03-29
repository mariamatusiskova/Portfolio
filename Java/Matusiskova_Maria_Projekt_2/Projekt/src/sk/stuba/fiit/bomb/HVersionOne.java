package sk.stuba.fiit.bomb;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.bombMaterials.Batteries;
import sk.stuba.fiit.bombMaterials.Switch;
import sk.stuba.fiit.bombMaterials.Button.ButtonWithCover;
import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.health.Health;
import sk.stuba.fiit.timer.Countdown;

// Polymorphism
public class HVersionOne extends Defusing implements Bomb {
	
	// constants -> final
	final int numberOfSwitches = 4; 
	final int timeToDefuse = 30;
	final int numberOfCoverButtons = 3;
	
	public static String remember;
	
	// aggregation
	Health attempts = new Health();
	Print print = new Print();
	ButtonWithCover buttonWithCover = new ButtonWithCover();
	Batteries batteries = new Batteries();
	
	static List<String> switches = 
						Arrays.asList(
							"switch 1", 
							"switch 2", 
							"switch 3", 
							"switch 4"
						);
	
	private List<String> colorsOfCoverButtons = 
			Arrays.asList(
				"blue", 
				"green", 
				"yellow"
			);
		
	
	// overriding (prekonavanie)
	protected void list() {
		System.out.println("\tWhich switch are you going to turn on/off?");
		
		for(int  i = 0; i < numberOfSwitches; i++) {
			System.out.println("\t- [" + switches.get(i)+ "]");
	    }
	}
	
	void listYesNo() {
		System.out.println("\t- [yes]");
		System.out.println("\t- [no]");
	}
	
	// overloading (pretazovanie)
	void list(String chars) {
		
		System.out.println("\tWhich button are you going to push " + chars + "?");
		for(int  i = 0; i < numberOfCoverButtons; i++) {
			System.out.println("\t- [" + colorsOfCoverButtons.get(i)+ "]");
	    }
	}
	
	/* 
	 * the most important method in this class 
	 * because there we are calling other methods and objects 
	 */

	@Override
	public void init() {
		// TODO Auto-generated method stub
		
		List<String> tasks = Arrays.asList(
				//switch
				"\n< If you turn on a " + switches.get(3) + ", you can turn off a " + switches.get(0) + ".",
				"\n< If you turn off a " + switches.get(0) + ", you can't turn on a " + switches.get(1) + ". >",
				"\n< If you turn on a " + switches.get(2) + ", you can't turn on a " + switches.get(0) + ". >",
				
				// button with cover
				"\n< If you push a " + colorsOfCoverButtons.get(0) + " button you can't push a " + colorsOfCoverButtons.get(1) + " button. "
						+ "\nBut firstly you need to open the cover of the button to push. >",
						
				// batteries
				"\n< To completely deactivate the bomb, it's necessary to remove the batteries. >"
		);
		
		// set the time to detonate the bomb
		Countdown countdown = new Countdown(timeToDefuse);
		
		try (Scanner input = new Scanner(System.in)) {
			System.out.println("Here's the task:");
			System.out.println("We have on the bomb " + numberOfSwitches + " switches: " + switches.get(0) + ", " 
			+ switches.get(1) + ", " + switches.get(2) + ", " + switches.get(3) + ".");
			System.out.println("Furthermore it contains buttons with the cover on it and batteries.");
			
			System.out.println(tasks.get(0));
			list();
			
			// ************* Switch *************
			//input
			String pickSwitch = input.nextLine(); 
			
			while(pickSwitch != null) {
				
				// if right answer
				if (pickSwitch.contains(switches.get(3))) {
					// turn off switch
					Switch.turnOffSwitch();
					// It is a right answer
					Switch.checkSwitch(true);
					break;
				// if wrong answer
				} else if (switches.contains(pickSwitch) && !pickSwitch.equals(switches.get(3))) {
					// turn off switch
					Switch.turnOffSwitch();
					// It is a wrong answer
					Switch.checkSwitch(false);
					// take live
					attempts.setHealth();
					// check how many lives user has
					attempts.lifeLoss(countdown);
					System.out.println(tasks.get(0));
					list();
					
					//input
					pickSwitch = input.nextLine(); 
				}
				
				// if wrong input
				if (!switches.contains(pickSwitch)) {
					print.incorrectInput();
					list();
						
					//input
					pickSwitch = input.nextLine(); 
				}
			}
			
			pickSwitch = null;
			
			System.out.println(tasks.get(1));
			list();
			
			pickSwitch = input.nextLine(); 
			
			while(pickSwitch != null) {
				
				// if right answer
				if (pickSwitch.contains(switches.get(0))) {
					Switch.turnOffSwitch();
					Switch.checkSwitch(true);
					break;
				// else if wrong answer
				} else if (switches.contains(pickSwitch) && !pickSwitch.equals(switches.get(0))) {			
						Switch.turnOffSwitch();
						Switch.checkSwitch(false);
						attempts.setHealth();
						attempts.lifeLoss(countdown);
						System.out.println(tasks.get(1));
						list();
						
						//input
						pickSwitch = input.nextLine(); 
			    }
				
				// if wrong input
				if (!switches.contains(pickSwitch)) {
					print.incorrectInput();
					list();
						
					//input
					pickSwitch = input.nextLine(); 
				}
			}
			
			pickSwitch = null;
			
			System.out.println(tasks.get(2));
			list();
			
			//input
			pickSwitch = input.nextLine(); 
			
			while(pickSwitch != null) {
				
				// if right answer
				if (pickSwitch.contains(switches.get(2))) {
					Switch.turnOnSwitch();
					Switch.checkSwitch(true);
					
					break;
				// else if wrong answer
				} else if (switches.contains(pickSwitch) && !pickSwitch.equals(switches.get(2))) {
					Switch.turnOnSwitch();
					Switch.checkSwitch(false);
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					System.out.println(tasks.get(2));
					list();
					
					//input
					pickSwitch = input.nextLine(); 
				}
				
				// if wrong input
				if (!switches.contains(pickSwitch)) {
					print.incorrectInput();
					list();
						
					//input
					pickSwitch = input.nextLine(); 
				}
			}
			
			pickSwitch = null;
			
			// ************* Button with Cover *************
			
			System.out.println(tasks.get(3));
			list("🕹️");
			
			//input
			String chooseButton = input.nextLine(); 
			String yesOrNot;
			
			while(chooseButton != null) {
				
				// if right answer
				if (chooseButton.contains(colorsOfCoverButtons.get(2))) {
					
					buttonWithCover.list();
					
					yesOrNot = input.nextLine(); 
					
					while(yesOrNot != null) {
						
						if (yesOrNot.equals("no")) {
							
							buttonWithCover.checkButton(false);
							buttonWithCover.setPush(false);
							buttonWithCover.pushButton();
							
							// take life
							attempts.setHealth();
							attempts.lifeLoss(countdown);
							
							remember = yesOrNot;
							break;
						
						} else if (yesOrNot.equals("yes")) {
							
							buttonWithCover.checkButton(true);
							buttonWithCover.setPush(true);
							buttonWithCover.pushButton();
							remember = yesOrNot;
							break;
							
						} else {
							
							print.incorrectInput();
							System.out.println(tasks.get(3));
							listYesNo();
							remember = "";
							//input
							yesOrNot = input.nextLine(); 
						}
						
					}
					
					if (remember.equals("no")) {
						yesOrNot = null;
						list("🕹️");
						//input
						chooseButton = input.nextLine(); 
					} else {
						yesOrNot = null;
						break;
					}
					
				// else if wrong answer
				} else if (colorsOfCoverButtons.contains(chooseButton) && !chooseButton.equals(colorsOfCoverButtons.get(2))) {
					
					buttonWithCover.list();
					
					yesOrNot = input.nextLine(); 
					
					while(yesOrNot != null) {
						
						if (yesOrNot.equals("no")) {
							
							buttonWithCover.checkButton(false);
							buttonWithCover.setPush(false);
							buttonWithCover.pushButton();
							
							// take life
							attempts.setHealth();
							attempts.lifeLoss(countdown);
							
							break;
						} else if (yesOrNot.equals("yes")) {
							
							buttonWithCover.checkButton(true);
							buttonWithCover.setPush(true);
							buttonWithCover.pushButton();
							
							// take life
							attempts.setHealth();
							attempts.lifeLoss(countdown);
							break;
						} else {
							
							print.incorrectInput();
							System.out.println(tasks.get(3));
							listYesNo();
							
							//input
							yesOrNot = input.nextLine(); 
						}
					}
					
					yesOrNot = null;
					list("🕹️");
					//input
					chooseButton = input.nextLine(); 
				}
				
				// if wrong input
				if (!colorsOfCoverButtons.contains(chooseButton)) {
					print.incorrectInput();
					list("🕹️");
						
					//input
					chooseButton = input.nextLine(); 
				}
			}
			
			chooseButton = null;
			
			// ************* Batteries *************
			System.out.println(tasks.get(4));
			batteries.list("🔋🔋🔋️");
			
			yesOrNot = input.nextLine(); 
			
			while(yesOrNot != null) {
				
				if (yesOrNot.equals("no")) {
					
					batteries.removeBatteries(false);
					
					// take life
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					
					System.out.println(tasks.get(4));
					batteries.list("🔋🔋🔋️");
					
					//input
					yesOrNot = input.nextLine(); 
					break;
				} else if (yesOrNot.equals("yes")) {
					
					batteries.removeBatteries(true);
					countdown.stop();
					bombDefused();
					
					break;
				} else {
					
					print.incorrectInput();
					System.out.println(tasks.get(4));
					batteries.list("🔋🔋🔋️");
					
					//input
					yesOrNot = input.nextLine(); 
				}
			}
			
			yesOrNot = null;
			countdown.stop();
			input.close();
		}
	}		
}
