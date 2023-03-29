package sk.stuba.fiit.bomb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.bombMaterials.Wire;
import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.health.Health;
import sk.stuba.fiit.timer.Countdown;

// this level will be always different because of changed colors of wires, which are always randomly generated

// Polymorphism
public class EVersionOne extends Defusing implements Bomb {
	

	// constants -> final
	final int numberOfWires = 6; 
	final int timeToDefuse = 10;
	
	// aggregation
	Wire wire = new Wire();	
	Health attempts = new Health();
	Print print = new Print();
	
	// static variable due to a variable tasks
	static List<String> colors = new ArrayList<String>();
	
	// overriding (prekonavanie)
	protected void list() {
		System.out.println("\tWhich wire are you going to cut?");
		
		for(int  i = 0; i < numberOfWires; i++) {
			System.out.println("\t- [" + colors.get(i)+ "]");
	    }
	}

	/* 
	 * the most important method in this class 
	 * because there we are calling other methods and objects 
	 */
	
	@Override
	public void init() {
		// TODO Auto-generated method stub
		
		/* encapsulation (zapuzdrenie) -> set number 
 		of wires in the class wires to use its functions */
		wire.setNumberOfWires(numberOfWires);
		// generate random colors of wires and add them to the String list colors
		wire.generateRandomColors(colors);
		
		List<String> tasks = Arrays.asList(
			"\n< If you cut a " + colors.get(0) + " wire you can't cut a " + colors.get(4) + " wire. >",
			"\n< If you cut a " + colors.get(2) + " wire you have to cut a " + colors.get(3) + " one. >",
			"\n< If you cut a " + colors.get(4) + " wire you can't cut a " + colors.get(0) + ", " 
			+ colors.get(3) + ", " + colors.get(5) + " or " + colors.get(2) + " wire. >"
		);
		
		// set the time to detonate the bomb
		Countdown countdown = new Countdown(timeToDefuse);
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Here's the task:");
		System.out.println("We have on the bomb " + numberOfWires + " wires: " + colors.get(0) + ", " + colors.get(1) + ", " 
		+ colors.get(2) + ", " + colors.get(3) + ", " + colors.get(4) + " and " + colors.get(5) + ".");
		System.out.println(tasks.get(0));
		list();
		
		//input
		String pickWire = input.nextLine(); 
		
		while(pickWire != null) {
			
			// if right answer
			if (pickWire.contains(colors.get(0))) {
				// cut wire
				wire.cutWire(pickWire);
				// It is a right answer
				wire.checkWire(true);
				break;
			// if wrong answer
			} else if (colors.contains(pickWire) && !pickWire.equals(colors.get(0))) {
				// cut wire
				wire.cutWire(pickWire);
				// It is a wrong answer
				wire.checkWire(false);
				// take live
				attempts.setHealth();
				// check how many lives user has
				attempts.lifeLoss(countdown);
				System.out.println(tasks.get(0));
				list();
				
				//input
				pickWire = input.nextLine(); 
			}
			
			// if wrong input
			if (!colors.contains(pickWire)) {
				print.incorrectInput();
				list();
					
				//input
				pickWire = input.nextLine(); 
			}
		}
		
		pickWire = null;
		
		System.out.println(tasks.get(1));
		list();
		
		pickWire = input.nextLine(); 
		
		while(pickWire != null) {
			
			// if right answer
			if (pickWire.contains(colors.get(2))) {
				wire.cutWire(pickWire);
				wire.checkWire(true);
				break;
			// else if wrong answer
			} else if (colors.contains(pickWire) && !pickWire.equals(colors.get(2))) {			
					wire.cutWire(pickWire);
					wire.checkWire(false);
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					System.out.println(tasks.get(1));
					list();
					
					//input
					pickWire = input.nextLine(); 
		    }
			
			// if wrong input
			if (!colors.contains(pickWire)) {
				print.incorrectInput();
				list();
					
				//input
				pickWire = input.nextLine(); 
			}
		}
		
		pickWire = null;
		
		System.out.println("Are you going to cut another wire? [yes/no]");
		
		//input
		String yesOrNot = input.nextLine(); 
		
		while(yesOrNot != null) {
			
			// if no
			if (yesOrNot.equals("no")) {
				attempts.setHealth();
				attempts.lifeLoss(countdown);
				System.out.println("Are you going to cut another wire? [yes/no]");
				
				//input
				yesOrNot = input.nextLine(); 
			// else if yes
			} else if (yesOrNot.equals("yes")) {
				list();
				break;
			// else wrong input
			} else {
				print.incorrectInput();
				System.out.println("'Are you going to cut another wire? [yes/no]'");
				
				//input
				yesOrNot = input.nextLine(); 
			}
			
		}
		
		yesOrNot = null;
		
		
		//input
		pickWire = input.nextLine(); 
		
		while(pickWire != null) {
			
			// if right answer
			if (pickWire.contains(colors.get(3))) {
				wire.cutWire(pickWire);
				wire.checkWire(true);
				break;
			// else if wrong answer
			} else if (colors.contains(pickWire) && !pickWire.equals(colors.get(3))) {
				wire.cutWire(pickWire);
				wire.checkWire(false);
				attempts.setHealth();
				attempts.lifeLoss(countdown);
				System.out.println(tasks.get(1));
				list();
				
				//input
				pickWire = input.nextLine(); 
			}
			
			// if wrong input
			if (!colors.contains(pickWire)) {
				print.incorrectInput();
				list();
					
				//input
				pickWire = input.nextLine(); 
			}
		}
		
		pickWire = null;
		
		System.out.println(tasks.get(2));
		list();
		
		//input
		pickWire = input.nextLine(); 
		
		while(pickWire != null) {
			
			// if right answer
			if (pickWire.contains(colors.get(1))) {
				wire.cutWire(pickWire);
				wire.checkWire(true);
				countdown.stop();
				bombDefused();
				
				break;
			// else if wrong answer
			} else if (colors.contains(pickWire) && !pickWire.equals(colors.get(1))) {
				wire.cutWire(pickWire);
				wire.checkWire(false);
				attempts.setHealth();
				attempts.lifeLoss(countdown);
				System.out.println(tasks.get(2));
				list();
				
				//input
				pickWire = input.nextLine(); 
			}
			
			// if wrong input
			if (!colors.contains(pickWire)) {
				print.incorrectInput();
				list();
					
				//input
				pickWire = input.nextLine(); 
			}
		}
		
		pickWire = null;
		input.close();
		countdown.stop();
		
	}

}
