package sk.stuba.fiit.bombMaterials.Button;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SimpleButton extends Button {
	
	boolean push;
	public int numberOfButtons;
	
	List<String> randomColors = new ArrayList<String>();
	
	public List<String> colors = 
			Arrays.asList(
				"purple",
				"blue", 
				"red", 
				"green", 
				"yellow", 
				"orange", 
				"black", 
				"white", 
				"pink", 
				"grey", 
				"brown"
			);
	
	// overloading of constructors (pretazovanie konstruktorov)
	// default button
	public SimpleButton() {
		this.push = true;
		this.numberOfButtons = 1;
		this.colors = Arrays.asList("red");
	}
	
	// due to default button
	public SimpleButton(boolean push) {
		this.push = push;
	}
	
	// if we need more buttons than one
	public SimpleButton(int numberOfButtons) {
		this.numberOfButtons = numberOfButtons;
	}
	
	// if we need more buttons than one with specific colors
	public SimpleButton(int numberOfButtons, List<String> colors) {
		this.numberOfButtons = numberOfButtons;
		this.colors = colors;
	}

	// listOfButtons
	@Override
	public void list() {
		// TODO Auto-generated method stub
		
		System.out.println("\tWhich button are you going to push?");
		for(int  i = 0; i < numberOfButtons; i++) {
			System.out.println("\t- [" + colors.get(i)+ "]");
	    }
		
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

	// right color?
	@Override
	public void checkButton(boolean rightColor) {
		// TODO Auto-generated method stub
		
		if (rightColor == false) {
			System.out.println("You pushed the wrong button.");
		}
		else {
			System.out.println("You pushed the right button.");
		}
	}

	//  is button turned?
	public void turnOnButton() {
		if (push == true) {
		System.out.println("\nThe Button is turned on.");
		} else {
			System.out.println("The Button is turned off.");
		}
	}
	
	// announce how many buttons the bomb has
	public void infoButton() {
		// if only 1 button 
		if ((numberOfButtons > 0) && (numberOfButtons <= 1)) {
			System.out.println("We have " + numberOfButtons + " " + colors.get(0) + " button.");
		// else more
		} else {
			System.out.println("We have " + numberOfButtons + "buttons:"); 
			
			for(int  i = 0; i < numberOfButtons; i++) {
				System.out.println("\t- [" + colors.get(i)+ "]");
		    }
		// end of else
		}
	// end of function
	}
	
	// from the list of colors will be generated another list of colors but with a concrete number
	public List<String> generateRandomColors(List<String> colorsOfButtons) {
		
		Collections.shuffle(colors);
		  
		for(int i = 0; i < numberOfButtons; i++) {
			randomColors.add(colors.get(i));
	    }
		
		for(int i = 0; i < numberOfButtons; i++) {
			colorsOfButtons.add(getRandomColorsList(i));
	    }
		
		return colorsOfButtons;
	}
	
	// Encapsulation (zapuzdrenie)
	// get list of colors
	public String getRandomColorsList(int i) {
		return randomColors.get(i);
	}

	// Encapsulation (zapuzdrenie)
	// get variable push
	@Override
	public boolean getPush() {
		// TODO Auto-generated method stub
		
		return push;
	}

	// set variable push
	@Override
	public void setPush(boolean newPush) {
		// TODO Auto-generated method stub
		
		 push = newPush;
	}

}
