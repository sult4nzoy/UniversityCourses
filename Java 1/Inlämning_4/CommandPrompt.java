import java.util.Scanner;

/**
 * Simulerar en enkel kommandotolk där användaren kan skriva in olika kommandon
 * som sedan utförs. Programmet fortsätter att köra tills användaren väljer att avsluta.
 * 
 * @author Omar Sultanzoy
 * @version 1.0
 * @Datum 2025-02-06
 */
public class CommandPrompt {
    private static final String PROMPT = "input> "; // Prompt-text
    private boolean running = true; // Kontrollvariabel för programmet
    private Scanner scanner; // Scanner för inmatning

    /**
     * Skapar en ny instans av CommandPrompt och initierar Scanner.
     */
    public CommandPrompt() 
    {
        scanner = new Scanner(System.in);
    }

    /**
     * Startar kommandotolken och hanterar inmatning av kommandon.
     */
    public void start() {
        while (running) {
            System.out.print(PROMPT);
            String command = scanner.nextLine().trim().toLowerCase();

            switch (command) {
                case "help":
                    displayHelp();
                    break;
                case "q":
                case "quit":
                    exitProgram();
                    break;
                case "hello":
                    printHello();
                    break;
                case "odd":
                    checkOddNumber();
                    break;
                case "repeat":
                    repeatText();
                    break;
                case "calc":
                case "calculate":
                    performCalculation();
                    break;
                default:
                    System.out.println("Ogiltigt kommando. Skriv 'help' för att se tillgängliga kommandon.");
            }
        }
        scanner.close();
    }

    /**
     * Skriver ut en hjälptext med alla tillgängliga kommandon.
     */
    private void displayHelp() {
        System.out.println("Tillgängliga kommandon:");
        System.out.println("help - Visar denna hjälptext.");
        System.out.println("q eller quit - Avslutar programmet.");
        System.out.println("hello - Skriver ut 'Hello, World!'");
        System.out.println("odd - Avgör om ett angivet heltal är udda eller jämnt.");
        System.out.println("repeat - Upprepar en given text ett angivet antal gånger.");
        System.out.println("calc eller calculate - Utför en enkel matematisk beräkning.");
    }

    /**
     * Avslutar programmet.
     */
    private void exitProgram() {
        System.out.println("Avslutar programmet...");
        running = false;
    }

    /**
     * Skriver ut "Hello, World!" till skärmen.
     */
    private void printHello() {
        System.out.println("Hello, World!");
    }

    /**
     * Frågar användaren om ett heltal och avgör om det är udda eller jämnt.
     */
    private void checkOddNumber() {
        System.out.print("Ange ett heltal: ");
        int number = scanner.nextInt();
        scanner.nextLine(); // Rensar inmatningsbufferten
        System.out.println(number % 2 == 0 ? "Talet är jämnt." : "Talet är udda.");
    }

    /**
     * Upprepar en given text ett angivet antal gånger.
     */
    private void repeatText() {
        System.out.print("Ange en text: ");
        String text = scanner.nextLine();
        System.out.print("Hur många gånger ska texten upprepas? ");
        int repetitions = scanner.nextInt();
        scanner.nextLine(); // Rensar bufferten
        for (int i = 0; i < repetitions; i++) {
            System.out.println(text);
        }
    }

    /**
     * Utför en enkel matematisk beräkning baserat på två tal och en operator.
     */
    private void performCalculation() {
        System.out.print("Ange första talet: ");
        double num1 = scanner.nextDouble();

        System.out.print("Ange operator (+, -, *, /): ");
        char operator = scanner.next().charAt(0);

        System.out.print("Ange andra talet: ");
        double num2 = scanner.nextDouble();
        scanner.nextLine(); // Rensar bufferten

        if (operator == '/' && num2 == 0) {
            System.out.println("Fel: Kan inte dividera med noll!");
            return;
        }

        double result = calculate(num1, num2, operator);
        System.out.println("Resultat: " + result);
    }

    /**
     * Utför den faktiska matematiska beräkningen.
     * 
     * @param num1 Första talet
     * @param num2 Andra talet
     * @param operator Räkneoperator (+, -, *, /)
     * @return Beräkningsresultatet
     */
    private double calculate(double num1, double num2, char operator) {
        switch (operator) {
            case '+': 
                return num1 + num2;

            case '-': 
                return num1 - num2;

            case '*':
                return num1 * num2;

            case '/':
                return num1 / num2;

            default: 
                System.out.println("Fel: Ogiltig operator!");
                return 0;
        }
    }

    /**
     * Huvudmetoden som skapar och startar CommandPrompt-programmet.
     */
    public static void main(String[] args) {
        CommandPrompt cmdPrompt = new CommandPrompt();
        cmdPrompt.start();
    }
}