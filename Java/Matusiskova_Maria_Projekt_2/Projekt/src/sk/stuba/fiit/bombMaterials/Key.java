package sk.stuba.fiit.bombMaterials;

public class Key {
	
	void turnKey(boolean keyIsTurned) {
		if (keyIsTurned == false) {
			System.out.println("Nothing happened with key. Untouched.");
		}
		else {
			System.out.println("The key was turned.");
		}
	}

}
