package sk.stuba.fiit.bomb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.bombMaterials.Wire;
import sk.stuba.fiit.bombMaterials.Button.ButtonWithCover;
import sk.stuba.fiit.bombMaterials.Button.SimpleButton;
import sk.stuba.fiit.bombMaterials.Button.TurnButton;
import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.health.Health;
import sk.stuba.fiit.timer.Countdown;

// Polymorphism
public class MVersionOne extends Defusing implements Bomb {
	
	// constants -> final
	final int numberOfWires = 3;
	final int numberOfCoverButtons = 3;
	final int timeToDefuse = 20;
	
	Wire wire = new Wire();	
	// default button
	SimpleButton simpleButton = new SimpleButton();
	TurnButton turnButton = new TurnButton();
	ButtonWithCover buttonWithCover = new ButtonWithCover();
	Health attempts = new Health();
	Print print = new Print();
	
	public static List<String> colorsOfWires = new ArrayList<String>();
	
	private List<String> colorsOfCoverButtons = 
			Arrays.asList(
				"blue", 
				"green", 
				"yellow"
			);
	
	// overriding (prekonavanie)
	protected void list() {
		
		System.out.println("\tWhich wire are you going to cut?");
		for(int  i = 0; i < numberOfWires; i++) {
			System.out.println("\t- [" + colorsOfWires.get(i)+ "]");
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
		
	@Override
	public void init() {
		// TODO Auto-generated method stub
		
		wire.setNumberOfWires(numberOfWires);
		wire.generateRandomColors(colorsOfWires);
		
		// ############################
		List<String> tasks = Arrays.asList(
			// simple button (default button)
			"\n< The red button is turned on, do you want to turn it off? >",
			// turn button
			"\n< Now we have a different type of button, which is not pushable. You need to turn it to the side to power up. >",
			
			// wires
			"\n< You have to cut one of the three wires, we have: " + colorsOfWires.get(0) + ", " + colorsOfWires.get(1) 
				+ " and " + colorsOfWires.get(2) + ". You can't cut the first one and third one." + " >",
				
			// button with cover
			"\n< If you push a " + colorsOfCoverButtons.get(1) + " button you can't push a " + colorsOfCoverButtons.get(0) + " button. "
					+ "\nBut firstly you need to open the cover of the button to push. >"
		);
		
		Countdown countdown = new Countdown(timeToDefuse);
		
		try (Scanner input = new Scanner(System.in)) {
			System.out.println("\nHere's the task:");
			System.out.println("We have on the bomb one default button and " + numberOfWires + " wires: " + colorsOfWires.get(0) + ", " 
			+ colorsOfWires.get(1) + " and " + colorsOfWires.get(2) + ".");
			System.out.println("Furthermore it contains one turn button and buttons with the cover on it.");
			
			System.out.println(tasks.get(0));
			listYesNo();
			
			// ************* Simple Button *************
			
			//input
			String yesOrNot = input.nextLine(); 
			
			while(yesOrNot != null) {
				
				if (yesOrNot.equals("no")) {
					
					simpleButton.setPush(false);
					simpleButton.pushButton();
					simpleButton.setPush(true);
					simpleButton.turnOnButton();
					simpleButton.checkButton(false);
					
					// take life
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					
					System.out.println(tasks.get(0));
					listYesNo();
					
					//input
					yesOrNot = input.nextLine(); 
					break;
				} else if (yesOrNot.equals("yes")) {
					
					simpleButton.setPush(true);	
					simpleButton.pushButton();
					simpleButton.setPush(false);
					simpleButton.turnOnButton();
					simpleButton.checkButton(true);
					
					break;
				} else {
					
					print.incorrectInput();
					System.out.println(tasks.get(0));
					listYesNo();
					
					//input
					yesOrNot = input.nextLine(); 
				}
			}
			
			yesOrNot = null;
			
			// ************* Turn Button *************
			
			System.out.println(tasks.get(1));
			turnButton.list();
			listYesNo();
			
			yesOrNot = input.nextLine(); 
			
			while(yesOrNot != null) {
				
				if (yesOrNot.equals("no")) {
					
					turnButton.setPush(false);
					turnButton.pushButton();
					turnButton.checkButton(false);
					
					// take life
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					
					System.out.println(tasks.get(1));
					listYesNo();
					
					//input
					yesOrNot = input.nextLine(); 
					
				} else if (yesOrNot.equals("yes")) {
					
					turnButton.setPush(true);
					turnButton.pushButton();
					turnButton.checkButton(true);
					
					break;
				} else {
					
					print.incorrectInput();
					System.out.println(tasks.get(1));
					listYesNo();
					
					//input
					yesOrNot = input.nextLine(); 
				}
			}
			
			yesOrNot = null;
			
			// ************* Wires *************
			
			System.out.println(tasks.get(2));
			list();
			
			//input
			String pickWire = input.nextLine(); 
			
			while(pickWire != null) {
				
				// if right answer
				if (pickWire.contains(colorsOfWires.get(1))) {
					// cut wire
					wire.cutWire(pickWire);
					// It is a right answer
					wire.checkWire(true);
					break;
				// if wrong answer
				} else if (colorsOfCoverButtons.contains(pickWire) && !pickWire.equals(colorsOfWires.get(1))) {
					// cut wire
					wire.cutWire(pickWire);
					// It is a wrong answer
					wire.checkWire(false);
					// take live
					attempts.setHealth();
					// check how many lives user has
					attempts.lifeLoss(countdown);
					System.out.println(tasks.get(2));
					list();
					
					//input
					pickWire = input.nextLine(); 
				}
				
				// if wrong input
				if (!colorsOfCoverButtons.contains(pickWire)) {
					print.incorrectInput();
					list();
						
					//input
					pickWire = input.nextLine(); 
				}
			}
			
			pickWire = null;
			
			// ************* Button with Cover *************
			
			System.out.println(tasks.get(3));
			list("🕹️");
			
			//input
			String chooseButton = input.nextLine(); 
			
			while(chooseButton != null) {
				
				// if right answer
				if (chooseButton.contains(colorsOfCoverButtons.get(1))) {
					
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
							
							countdown.stop();
							bombDefused();
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
					print.incorrectInput();
					list("🕹️");
						
					//input
					chooseButton = input.nextLine(); 
					
				// else if wrong answer
				} else if (colorsOfCoverButtons.contains(chooseButton) && !chooseButton.equals(colorsOfCoverButtons.get(1))) {
					
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
			countdown.stop();
			input.close();
		}
	}
}
