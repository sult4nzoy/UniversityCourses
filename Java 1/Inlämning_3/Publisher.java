/**
 * Representerar ett förlag (Publisher) med namn och telefonnummer.
 * Inkluderar en statisk räknare för att hålla koll på antalet skapade förlag.
 */
public class Publisher {
    // Privata instansvariabler
    private String name;
    private String phone;
    
    // Statisk variabel för att räkna antalet förlag
    private static int publisherCount = 0;

    /**
     * Standardkonstruktor som skapar ett förlag med standardvärden.
     * Ökar antalet förlag vid varje nytt objekt.
     */
    public Publisher() {
        this.name = "Unknown";
        this.phone = "No phone number";
        publisherCount++; // Öka räknaren vid skapandet av ett nytt objekt
    }

    /**
     * Konstruktor som skapar ett förlag med angivet namn och telefonnummer.
     * Ökar antalet förlag vid varje nytt objekt.
     *
     * @param name Förlagets namn.
     * @param phone Förlagets telefonnummer.
     */
    public Publisher(String name, String phone) {
        this.name = name;
        this.phone = phone;
        publisherCount++; // Öka räknaren vid skapandet av ett nytt objekt
    }

    /**
     * Hämtar förlagets namn.
     *
     * @return Förlagets namn.
     */
    public String getName() {
        return name;
    }

    /**
     * Hämtar förlagets telefonnummer.
     *
     * @return Förlagets telefonnummer.
     */
    public String getPhone() {
        return phone;
    }

    /**
     * Ändrar förlagets namn.
     *
     * @param name Det nya namnet för förlaget.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Ändrar förlagets telefonnummer.
     *
     * @param phone Det nya telefonnumret för förlaget.
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     * Skriver ut förlagets information till konsolen.
     */
    public void print() {
        System.out.println("------------------------------");
        System.out.println("Förlag Information");
        System.out.println("------------------------------");
        System.out.println("Namn: " + name);
        System.out.println("TelefonNr: " + phone);
        System.out.println("------------------------------");
    }

    /**
     * Hämtar antalet skapade förlag.
     *
     * @return Antalet instanser av Publisher.
     */
    public static int getPublisherCount() {
        return publisherCount;
    }
}
