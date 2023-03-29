package sk.stuba.fiit.bombMaterials;

import java.util.Scanner;

import sk.stuba.fiit.generalPrints.Print;
import sk.stuba.fiit.levels.Levels;
import sk.stuba.fiit.singleton.UserData;

public class User {
	
	// initialization of the object levels
	// aggregation
	Levels levels = new Levels();
	Print print = new Print();
	
	// singleton method
	public static void nameUserData() {
		
		UserData userData = UserData.getInstance();
		UserData userData2 = UserData.getInstance();
		
		if (userData.equals(userData2)) {
			System.out.println("names equals");
		} else {
			System.out.println("names don't equals");
		}
	}
		
	void init() {
		
		//class which is part of Java util used to receive user input
		Scanner input = new Scanner(System.in);
		
		System.out.println("Welcome to the game Defuse a bomb!");
		System.out.println("\n"
				+ " . . .                         \n"
				+ "              \\|/                          \n"
				+ "            `--+--'                        \n"
				+ "              /|\\                          \n"
				+ "             ' | '                         \n"
				+ "               |                           \n"
				+ "               |                           \n"
				+ "           ,--'#`--.                       \n"
				+ "           |#######|                       \n"
				+ "        _.-'#######`-._                    \n"
				+ "     ,-'###############`-.                 \n"
				+ "   ,'#####################`,               \n"
				+ "  /#########################\\              \n"
				+ " |###########################|             \n"
				+ "|#############################|            \n"
				+ "|#############################|            \n"
				+ "|#############################|            \n"
				+ "|#############################|            \n"
				+ " |###########################|             \n"
				+ "  \\#########################/              \n"
				+ "   `.#####################,'               \n"
				+ "     `._###############_,'                 \n"
				+ "        `--..#####..--'\n"
				+ "");
		
		
		System.out.println("Wanna be named? [yes/no]");
		//input
		String nameUser = input.nextLine(); 
		
		while(nameUser != null) {
	
			if (nameUser.equals("no")) {
				System.out.println("Okay, let's continue");
				break;
			} else if (nameUser.equals("yes")) {
				System.out.println("Named as John");
				nameUserData();
				break;
			} else {
				// call method to announce user wrong input
				print.incorrectInput();
				System.out.println("\n'Can we start? [yes/no]'");
				
				//input
				nameUser = input.nextLine(); 
			}
					
		}
		nameUser = null;
		
		// start game
		System.out.println("Can we start? [yes/no]");
		
		//input
		String startGame = input.nextLine(); 
		
		
		while(startGame != null) {
	
			if (startGame.equals("no")) {
				System.out.println("Quit");
				System.exit(0);
			} else if (startGame.equals("yes")) {
				System.out.println("Let's start!");
				// call method in class Levels to start game
				levels.init();
				break;
			} else {
				// call method to announce user wrong input
				print.incorrectInput();
				System.out.println("'Can we start? [yes/no]'");
				
				//input
				startGame = input.nextLine(); 
			}
			
		}
		// close input
		input.close();
		
	}
}
