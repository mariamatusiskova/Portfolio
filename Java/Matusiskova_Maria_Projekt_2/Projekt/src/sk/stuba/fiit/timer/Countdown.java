package sk.stuba.fiit.timer;

import java.util.*;

import sk.stuba.fiit.bomb.Defusing;

// source: https://www.iitk.ac.in/esc101/05Aug/tutorial/essential/threads/timer.html 

public class Countdown extends Defusing {
	
	Timer timer;
	int seconds;

    public Countdown(int seconds) {
    	this.seconds = seconds;
    	System.out.println("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    	System.out.println("!!! 'You have " + this.seconds + " seconds to defuse the bomb' !!!");
    	System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        timer = new Timer();
        timer.schedule(new ExpirationTime(), 0, this.seconds*1000);
	}
    
    public void stop() {
    	timer.cancel();
    	timer.purge();
    }
    
    
    class ExpirationTime extends TimerTask {
    
        public void run() {

	        	if (seconds == 4) {
	        		System.out.println("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	        		System.out.println("!!! 'Hurry up! You're running out of time!' !!!");
	            	System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	            } else if ((seconds <= 3) && (seconds > 1)) {
	            	System.out.println("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	            	System.out.println("!!! 'You have only " + seconds + " seconds' !!!");
	            	System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	        	} else if ((seconds <= 1) && (seconds > 0)) {
	        		System.out.println("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	            	System.out.println("!!! 'You have only " + seconds + " second' !!!");
	            	System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	        	} else if (seconds == 0) {
	        		stop();
		        	explosion();
	            }
	        	seconds--;
//	        	} else {
//	        		System.out.println("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
//	            	System.out.println("!!! 'Time is stopped at " + seconds + " seconds' !!!");
//	            	System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
//	        	}
        }
    }
    
}
