/**
 * Testklass för att demonstrera funktionaliteten hos Publisher-klassen.
 * Skapar flera Publisher-objekt, skriver ut deras information, ändrar värden och 
 * visar det totala antalet skapade förlag.
 * 
 * @Författare Omar Sultanzoy
 * @Version 1.0
 * @Datum 2025-02-06
 */
public class PublisherTest1 {

    /**
     * Huvudmetoden som kör programmet och testar Publisher-klassen.
     */
    public static void main(String[] args) {
        // Skapar tre olika förlag med hårdkodade värden
        Publisher publisher1 = new Publisher("Natur & Kultur", "123567654");
        Publisher publisher2 = new Publisher("Rabén & Sjögren", "7657654567");
        Publisher publisher3 = new Publisher("Bonnierförlagen", "34567876543");

        // Skriver ut information om alla förlag
        System.out.println("\n");
        publisher1.print();
        System.out.println("\n");
        publisher2.print();
        System.out.println("\n");
        publisher3.print();
        System.out.println("\n");

        // Ändrar värden på publisher3 och visar uppdaterad information
        publisher3.setName("Joe & Co");
        publisher3.setPhone("9876543234567");
        publisher3.print();
        System.out.println("\n");

        // Skriver ut det totala antalet skapade förlag
        System.out.println("Totala antalet förlag som skapats: " + Publisher.getPublisherCount() + " och 1 som ändrats.");
    }
}
