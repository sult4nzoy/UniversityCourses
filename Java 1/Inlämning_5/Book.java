public class Book extends Media {
    private String author;

    // Standardkonstruktor
    public Book() {
        super();
        this.author = "Okänd författare";
    }

    // Konstruktor med parametrar
    public Book(String author, String title, int length, Publisher publisher) {
        super(title, length, publisher);
        this.author = author;
    }

    // Setter och getter för författare
    public void setAuthor(String author) {
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    // Omvandlar längden (antal sidor) till en string
    @Override
    public String getLengthAsString() {
        return length + (length == 1 ? " page" : " pages");
    }

    // Överskriven print-metod
    @Override
    public void print() {
        super.print();
        System.out.println("Författare: " + author);
    }

    // Överskriven toString-metod
    @Override
    public String toString() {
        return super.toString() + ", Författare: " + author;
    }
}
