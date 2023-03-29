package sk.stuba.fiit.levels;

import java.util.Random;

import sk.stuba.fiit.bomb.Defusing;
import sk.stuba.fiit.bomb.EVersionOne;
import sk.stuba.fiit.bomb.EVersionThree;
import sk.stuba.fiit.bomb.EVersionTwo;

public class Easy {
	
	int number;
	private static final int n1 = 1;
	private static final int n2 = 2;
	private static final int n3 = 3;
	
	// random from java.util
	int generateRandomELevel() {
		Random random = new Random();
		int answer = random.nextInt(3) + 1;
		
		return answer;
	}
	
	void init() {
		
		number = generateRandomELevel();
		
		EVersionOne v1 = new EVersionOne();
		EVersionTwo v2 = new EVersionTwo();
		EVersionThree v3 = new EVersionThree();
		
		// upcasting na Defusing
		Defusing def1 = v1; 
		Defusing def2 = v2;
		Defusing def3 = v3;
		
		EVersionOne v1_2 = null;
		EVersionTwo v2_2 = null;
		EVersionThree v3_2 = null;
		
		// downcasting
		switch(number) {

			case n1: 
				
				if (def1 instanceof EVersionOne) {
					v1_2 = (EVersionOne) def1;
					v1_2.init();
				}
				break;
				
			case n2:
			
				if (def2 instanceof EVersionTwo) {
					v2_2 = (EVersionTwo) def2;
					v2_2.init();
				}
				break;
				
			case n3:
				
				if (def3 instanceof EVersionThree) {
					v3_2 = (EVersionThree) def3;
					v3_2.init();
				}
				break;
				
			default:
		
		}
		
	}
	
}
