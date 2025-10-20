import java.util.Arrays;
import java.util.Random;

public class Yatzy {
    int[] dices;
    Random random;

    // Constructor: Rolls all five dice when the object is created
    public Yatzy() {
        dices = new int[5];
        random = new Random();
        rollDices();
    }

    // Rolls all five dice
    public void rollDices() {
      //  System.out.println("Rolling all the dices...");
        for (int i = 0; i < dices.length; i++) {
            dices[i] = random.nextInt(6) + 1; // Random number between 1 and 6
        }
        // printDices();
    }

    // Rolls selected dice based on boolean array
    public void rollDices(boolean... roll) {
        for (int i = 0; i < dices.length; i++) {
            if (roll[i]) {
                dices[i] = random.nextInt(6) + 1;
            }
        }
        // printDices();
    }

    // Checks if all dice values are the same (Yatzy)
    public boolean isYatzy() {
        for (int i = 1; i < dices.length; i++) {
            if (dices[i] != dices[0]) {
                return false;
            }
        }
        return true;
    }

    // Sorts the dice values in descending order
    public void sort() {
        Arrays.sort(dices);
        for (int i = 0, j = dices.length - 1; i < j; i++, j--) {
            int temp = dices[i];
            dices[i] = dices[j];
            dices[j] = temp;
        }
        System.out.println("Sorting the dices...");
    }

    // Returns dice values as a string
    @Override
    public String toString() {
        return Arrays.toString(dices).replaceAll("[\\[\\],]", "");
    }

    // Main method (Test program and Yatzy probability simulation)
    public static void main(String[] args) {
        System.out.println("=== Yatzy Game ===");
        Yatzy game = new Yatzy();  // Initial roll
        
        System.out.println("Initial roll: " + game);

        // game.rollDices(true, false, false, false, true); // Re-roll dice 1 and 5
        game.rollDices(new boolean[] {true, false, false, false, true}); // Re-roll dice 1 and 5

        System.out.println("After re-roll: " + game);

        game.sort();
        System.out.println("Sorted: " + game);

        System.out.println("Checking for Yatzy...");
        if (game.isYatzy()) {
            System.out.println("YATZY!");
        } else {
            System.out.println("Sorry, " + game + " is not a Yatzy!");
        }

        // Yatzy probability simulation
        System.out.println("\n=== Yatzy Probability Simulation ===");
        int rolls = 10000000; // Change this number to test different roll counts
        int yatzyCount = 0;
        long startTime = System.currentTimeMillis();

        for (int i = 0; i < rolls; i++) {
            Yatzy simulation = new Yatzy();
            if (simulation.isYatzy()) {
                yatzyCount++;
            }
        }

        long endTime = System.currentTimeMillis();
        double percentage = (double) yatzyCount / rolls * 100;

        System.out.println("Rolling the dices " + rolls + " times... " + (endTime - startTime) + " ms");
        System.out.println("Number of Yatzy: " + yatzyCount + " (" + String.format("%.4f", percentage) + "%)");
    }
}
