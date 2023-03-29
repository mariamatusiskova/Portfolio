package sk.stuba.fiit.bomb;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.bombMaterials.Switch;
import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.health.Health;
import sk.stuba.fiit.timer.Countdown;

//Polymorphism
public class EVersionThree extends Defusing implements Bomb {
	
	// constants -> final
	final int numberOfSwitches = 4; 
	final int timeToDefuse = 10;
	
	// aggregation
	Health attempts = new Health();
	Print print = new Print();
	
	static List<String> switches = 
						Arrays.asList(
							"switch 1", 
							"switch 2", 
							"switch 3", 
							"switch 4"
						);
		
	
	// overriding (prekonavanie)
	protected void list() {
		System.out.println("\tWhich switch are you going to turn on/off?");
		
		for(int  i = 0; i < numberOfSwitches; i++) {
			System.out.println("\t- [" + switches.get(i)+ "]");
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
				"\n< If you turn off a " + switches.get(3) + ", you can turn on a " + switches.get(0) + ".",
				"\n< If you turn on a " + switches.get(0) + ", you can't turn on a " + switches.get(1) + ". >",
				"\n< If you turn off a " + switches.get(2) + ", you can't turn off a " + switches.get(0) + ". >"
		);
		
		// set the time to detonate the bomb
		Countdown countdown = new Countdown(timeToDefuse);
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Here's the task:");
		System.out.println("We have on the bomb " + numberOfSwitches + " switches: " + switches.get(0) + ", " 
		+ switches.get(1) + ", " + switches.get(2) + ", " + switches.get(3) + ".");
		System.out.println(tasks.get(0));
		list();
		
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
				Switch.turnOnSwitch();
				Switch.checkSwitch(true);
				break;
			// else if wrong answer
			} else if (switches.contains(pickSwitch) && !pickSwitch.equals(switches.get(0))) {			
					Switch.turnOnSwitch();
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
			if (pickSwitch.contains(switches.get(1))) {
				Switch.turnOffSwitch();
				Switch.checkSwitch(true);
				countdown.stop();
				bombDefused();
				
				break;
			// else if wrong answer
			} else if (switches.contains(pickSwitch) && !pickSwitch.equals(switches.get(1))) {
				Switch.turnOffSwitch();
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
		input.close();
		countdown.stop();
		
	}

}
