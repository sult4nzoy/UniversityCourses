public class MediaTest {
    public static void main(String[] args) {
        Publisher publisher = new Publisher("Bonnier", "123-456-789");

        DVD dvd = new DVD("Inception", 5280, 12, publisher);
        Book book = new Book("J.K. Rowling", "Harry Potter", 320, publisher);
        CD cd = new CD("The Beatles", "Abbey Road", 2700, publisher);

        System.out.println("=== DVD ===");
        dvd.print();
        System.out.println("\n=== Book ===");
        book.print();
        System.out.println("\n=== CD ===");
        cd.print();
    }
}
