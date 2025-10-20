public class Media {
    String title;
    int length;
    Publisher publisher;

    // Standardkonstruktor med defaultvärden
    public Media() {
        this.title = "Unknown";
        this.length = 0;
        this.publisher = new Publisher();
    }

    // Konstruktor med parametrar
    public Media(String title, int length, Publisher publisher) {
        setTitle(title);
        setLength(length);
        setPublisher(publisher);
    }

    // Setter och getter för titel
    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    // Setter och getter för längd
    public void setLength(int length) {
        this.length = Math.max(length, 0); // Säkerställer att längden inte blir negativ
    }

    public int getLength() {
        return length;
    }

    // Setter och getter för Publisher
    public void setPublisher(Publisher publisher) {
        this.publisher = publisher;
    }

    public Publisher getPublisher() {
        return publisher;
    }

    // Print-metod
    public void print() {
        System.out.println("Titel: " + title);
        System.out.println("Längd: " + getLengthAsString());
        System.out.println("Utgivare: " + publisher.getName());
    }

    // Metod som omvandlar längden till en formatsträng (kan överskrivas)
    public String getLengthAsString() {
        return length + " sekunder";
    }

    // toString-metod
    @Override
    public String toString() {
        return "Titel: " + title + ", Längd: " + getLengthAsString() + ", Utgivare: " + publisher.getName();
    }
}
