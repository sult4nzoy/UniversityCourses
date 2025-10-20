import java.util.Scanner;

/**
 * Testklass för att demonstrera funktionaliteten hos Publisher-klassen.
 * Denna klass låter användaren skapa ett Publisher-objekt genom att mata in namn och telefonnummer.
 * Därefter skrivs informationen ut och det totala antalet skapade förlag visas.
 * 
 * @Författare Omar Sultanzoy
 * @Version 1.0
 * @Datum 2025-02-06
 */
public class PublisherTest2 {

    /**
     * Huvudmetoden som kör programmet och låter användaren skapa ett Publisher-objekt.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Tar in förlagets information från användaren
        System.out.print("Namn på förlag: ");
        String name = scanner.nextLine();

        System.out.print("Förlagets telefonnummer: ");
        String phone = scanner.nextLine();

        // Skapar ett nytt förlagsobjekt med användardata
        Publisher userPublisher = new Publisher(name, phone);

        // Skriver ut informationen om det nya förlaget
        userPublisher.print();

        // Skriver ut totalt antal skapade förlag
        System.out.println("Totalt antal förlag som skapats: " + Publisher.getPublisherCount());

        scanner.close();
    }
}
