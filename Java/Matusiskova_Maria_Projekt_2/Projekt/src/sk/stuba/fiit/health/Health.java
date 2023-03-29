package sk.stuba.fiit.health;

import sk.stuba.fiit.bomb.Defusing;
import sk.stuba.fiit.timer.Countdown;

public class Health extends Defusing {
	
	int healthAttempts = 3;
	
	// super
	// overriding (prekonavanie)
	protected void explosion() {
		System.out.println("\n<<< You've lost all of your attempts. :( >>>");
		super.explosion();
	}
	
	// association (asociacia)
	// check how many attempts the user has
	public void lifeLoss(Countdown countdown) {
		// if more than one live
		if (healthAttempts > 1) {
			System.out.println("<<< You have only " + healthAttempts + " attempts from 3. >>>");
		// else if only one live
		} else if ((healthAttempts <= 1) && (healthAttempts > 0)) {
			System.out.println("<<< You have only " + healthAttempts + " attempt from 3. >>>");
		// else boom
		} else {
			countdown.stop();
			explosion();
		}
	}
	
	// get how many attempts the user has
	public int getHealth() {
		return healthAttempts;
	}
	
	// take live
	public int setHealth() {
		return healthAttempts--;
	}
}
