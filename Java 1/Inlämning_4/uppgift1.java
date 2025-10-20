import java.util.Scanner;

public class uppgift1
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        // Användaren anger min- och maxvärde
        System.out.print("Ange min tal: ");
        int minTal = input.nextInt();

        System.out.print("Ange max tal: ");
        int maxTal = input.nextInt();

        // Generera slumpmässigt nummer inom intervallet
        int generatedNumber = (int) (Math.random() * (maxTal - minTal + 1)) + minTal; 

        System.out.println("Gissa vilket nummer jag tänker på...");

        int antalGissningar = 0; // Startvärde
        String userInput; // Sträng för att kunna hantera "exit"
        int userGuess;

        // Loopa tills användaren gissar rätt
        do 
        {
            System.out.print("Din gissning: ");
            userInput = input.next(); // Läs in som sträng

            if (userInput.equals("exit")) 
            {
                System.out.println("Programmet avslutas...");
                break;
            }

            userGuess = Integer.parseInt(userInput); // Konvertera till int
            antalGissningar++;

            if (userGuess > generatedNumber) 
            {
                System.out.println("För högt! Försök igen.");
            } 
            
            else if (userGuess < generatedNumber) 
            {
                System.out.println("För lågt! Försök igen.");
            } 
            
            else 
            {
                System.out.println("Rätt! Du gissade rätt på " + antalGissningar + " försök.");
            }

        } while (userGuess != generatedNumber);

        input.close();
    }
}