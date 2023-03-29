package sk.stuba.fiit.bomb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.bombMaterials.Button.SimpleButton;
import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.health.Health;
import sk.stuba.fiit.timer.Countdown;

//Polymorphism
public class EVersionTwo extends Defusing implements Bomb {
	
	// constants -> final
	final int numberOfButtons = 5; 
	final int timeToDefuse = 10;
	
	// aggregation
	SimpleButton simpleButton = new SimpleButton(numberOfButtons);	
	Health attempts = new Health();
	Print print = new Print();
	
	// static variable due to variable tasks
	static List<String> colors = new ArrayList<String>();
	
	// overriding (prekonavanie)
	protected void list() {
		System.out.println("\tWhich button are you going to push?");
		
		for(int  i = 0; i < numberOfButtons; i++) {
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
		
		// generate random colors of wires and add them to the String list colors
		simpleButton.generateRandomColors(colors);
		
		List<String> tasks = Arrays.asList(
				"\n< If you push a " + colors.get(1) + " button you can't push a " + colors.get(0) + " button.",
				"\n< If you don't push a " + colors.get(0) + " button, you have to push a " + colors.get(2) + " one. >",
				"\n< If you push a " + colors.get(0) + " button you can't push a " + colors.get(1) + ", " 
				+ colors.get(3) + " or " + colors.get(2) + " wire. >"
		);
		
		// set the time to detonate the bomb
		Countdown countdown = new Countdown(timeToDefuse);
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Here's the task:");
		System.out.println("We have on the bomb " + numberOfButtons + " buttons: " + colors.get(0) + ", " 
		+ colors.get(1) + ", " + colors.get(2) + ", " + colors.get(3) + " and " + colors.get(4) + ".");
		System.out.println(tasks.get(0));
		list();
		
		//input
		String pickButton = input.nextLine(); 
		
		while(pickButton != null) {
			
			// if right answer
			if (pickButton.contains(colors.get(1))) {
				// push button
				simpleButton.setPush(true);
				// It is a right answer
				simpleButton.checkButton(true);
				break;
			// if wrong answer
			} else if (colors.contains(pickButton) && !pickButton.equals(colors.get(1))) {
				// push button
				simpleButton.setPush(false);
				// It is a wrong answer
				simpleButton.checkButton(false);
				// take live
				attempts.setHealth();
				// check how many lives user has
				attempts.lifeLoss(countdown);
				System.out.println(tasks.get(0));
				list();
				
				//input
				pickButton = input.nextLine(); 
			}
			
			// if wrong input
			if (!colors.contains(pickButton)) {
				print.incorrectInput();
				list();
					
				//input
				pickButton = input.nextLine(); 
			}
		}
		
		pickButton = null;
		
		System.out.println(tasks.get(1));
		list();
		
		pickButton = input.nextLine(); 
		
		while(pickButton != null) {
			
			// if right answer
			if (pickButton.contains(colors.get(2))) {
				simpleButton.setPush(true);
				simpleButton.checkButton(true);
				break;
			// else if wrong answer
			} else if (colors.contains(pickButton) && !pickButton.equals(colors.get(2))) {			
					simpleButton.setPush(false);
					simpleButton.checkButton(false);
					attempts.setHealth();
					attempts.lifeLoss(countdown);
					System.out.println(tasks.get(1));
					list();
					
					//input
					pickButton = input.nextLine(); 
		    }
			
			// if wrong input
			if (!colors.contains(pickButton)) {
				print.incorrectInput();
				list();
					
				//input
				pickButton = input.nextLine(); 
			}
		}
		
		pickButton = null;
		
		System.out.println(tasks.get(2));
		list();
		
		//input
		pickButton = input.nextLine(); 
		
		while(pickButton != null) {
			
			// if right answer
			if (pickButton.contains(colors.get(4))) {
				simpleButton.setPush(true);
				simpleButton.checkButton(true);
				countdown.stop();
				bombDefused();
				
				break;
			// else if wrong answer
			} else if (colors.contains(pickButton) && !pickButton.equals(colors.get(4))) {
				simpleButton.setPush(false);
				simpleButton.checkButton(false);
				attempts.setHealth();
				attempts.lifeLoss(countdown);
				System.out.println(tasks.get(2));
				list();
				
				//input
				pickButton = input.nextLine(); 
			}
			
			// if wrong input
			if (!colors.contains(pickButton)) {
				print.incorrectInput();
				list();
					
				//input
				pickButton = input.nextLine(); 
			}
		}
		
		pickButton = null;
		input.close();
		countdown.stop();
		
	}

}
