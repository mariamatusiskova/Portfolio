package sk.stuba.fiit.levels;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sk.stuba.fiit.generalPrints.Print;

public class Levels {
	
	// collection of strings -> levels
	List<String> listOfLevels = Arrays.asList("easy", "medium", "hard", "quit");
	
	Print print = new Print();
	
	void printLevels() {
		System.out.println("\n\tPick a level:");
		System.out.println("\t- [easy]");
		System.out.println("\t- [medium]");
		System.out.println("\t- [hard]");
		System.out.println("\t- [quit]");
	}
	             
	/* the most important method in this class 
	 		because there we are calling other methods and objects */
	public void init() {
		
		Scanner input = new Scanner(System.in);
		
		// calling the method to print options -> levels
		printLevels();
		
		//input
		String pickLevel = input.nextLine(); 
		
		while(pickLevel != null) {
			
			// if 'easy'
			if (pickLevel.equals(listOfLevels.get(0))) {
				// composition (kompozicia)
				// call constructor Easy
				Easy easy = new Easy();
				easy.init();
				input.close();
				return;
			// if 'medium'
			} else if (pickLevel.equals(listOfLevels.get(1))) {
				// composition (kompozicia)
				Medium medium = new Medium();
				medium.init();
				input.close();
				return;
			// if 'hard'
			} else if (pickLevel.equals(listOfLevels.get(2))) {
				// composition (kompozicia)
				Hard hard = new Hard();
				hard.init();
				input.close();
				return;
			// wrong input
			} else if (pickLevel.equals(listOfLevels.get(3))) {
				System.out.println("Quit");
				System.exit(0);
			} else {
				print.incorrectInput();
				printLevels();
					
				//input
				pickLevel = input.nextLine(); 
			}
			
		}
		
		input.close();
	}
}
