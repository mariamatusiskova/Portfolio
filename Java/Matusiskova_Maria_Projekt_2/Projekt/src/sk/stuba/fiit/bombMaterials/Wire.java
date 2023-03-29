package sk.stuba.fiit.bombMaterials;

import java.util.*;

public class Wire {
	
	String colorOfWire;
	int numberOfWires;
	
	List<String> colors = 
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
	
	List<String> randomColors = new ArrayList<String>();
	
	// from the list of colors will be generated another list of colors but with a concrete number
	public List<String> generateRandomColors(List<String> colorsOfWires) {
		
		Collections.shuffle(colors);
		  
		for(int  i = 0; i < numberOfWires; i++) {
			randomColors.add(colors.get(i));
	    }
		
		for(int i = 0; i < numberOfWires; i++) {
			colorsOfWires.add(getRandomColorsList(i));
	    }
		
		return colorsOfWires;
	}
	
	// cut certain wire (color)
	public void cutWire(String colorOfWire) {
		this.colorOfWire = colorOfWire;
		System.out.println("Cutting " + colorOfWire);
	}
	
	
	// check if the user cut wrong or right wire
	public void checkWire(boolean rightColor) {
		if (rightColor == false) {
			System.out.println("You've cut a wrong wire.");
		}
		else {
			System.out.println("You've cut a right wire.");
		}
	}
	
	// Encapsulation (zapuzdrenie)
	// get list of colors
	public String getRandomColorsList(int i) {
		return randomColors.get(i);
	}
	
	// get variable of numberW
	public int getNumberOfWires() {
		return numberOfWires;
	}
	
	// set variable of numberW
	public void setNumberOfWires(int newNumberOfWires) {
	    numberOfWires = newNumberOfWires;
	}
	
}
