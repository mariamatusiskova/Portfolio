package sk.stuba.fiit.bombMaterials;

public class Batteries {
	
	public void list(String chars) {
		
		System.out.println("\tAre you going to take out batteries " + chars + "?");
		System.out.println("\t- [yes]");
		System.out.println("\t- [no]");
	}
	
	public void removeBatteries(boolean batteriesRemoved) {
		 if (batteriesRemoved == false) {
			 System.out.println("Keep batteries.");
		 }
		 else {
			 System.out.println("Batteries are removed.");
		 }
	}

}
