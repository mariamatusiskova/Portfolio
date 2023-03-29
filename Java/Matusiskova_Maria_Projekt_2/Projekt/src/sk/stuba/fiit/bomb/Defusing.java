package sk.stuba.fiit.bomb;

import sk.stuba.fiit.levels.Levels;

public class Defusing {   
	
	Levels levels = new Levels();
	
	public void init() {}
	
	// method use for overriding (prekonavanie) - protected
	protected void list() {
		System.out.println("\t- [yes]");
		System.out.println("\t- [no]");
	}
	
	// method use to announce explosion
	protected void explosion() {
		System.out.println("\n\t### Boom! ###");
		System.out.println("\n"
				+ "     _.-^^---....,,--       \n"
				+ " _--                  --_  \n"
				+ "<                        >)\n"
				+ "|                         | \n"
				+ " \\._                   _./  \n"
				+ "    ```--. . , ; .--'''       \n"
				+ "          | |   |             \n"
				+ "       .-=||  | |=-.   \n"
				+ "       `-=#$%&%$#=-'   \n"
				+ "          | ;  :|     \n"
				+ " _____.,-#%&$@%#&#~,._____");
		System.exit(0);
	}
	
	// final
	// method use to announce defusing of the bomb 
	protected final void bombDefused() {
		System.out.println("Congrats! The bomb is defused.");
		levels.init();
	}
	
}
