public class CD extends Media {
    private String artist;

    // Standardkonstruktor
    public CD() {
        super();
        this.artist = "Okänd artist";
    }

    // Konstruktor med parametrar
    public CD(String artist, String title, int length, Publisher publisher) {
        super(title, length, publisher);
        this.artist = artist;
    }

    // Setter och getter för artist
    public void setArtist(String artist) {
        this.artist = artist;
    }

    public String getArtist() {
        return artist;
    }

    // Omvandlar längden till HH:MM:SS-format
    @Override
    public String getLengthAsString() {
        int hours = length / 3600;
        int minutes = (length % 3600) / 60;
        int seconds = length % 60;
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    // Överskriven print-metod
    @Override
    public void print() {
        super.print();
        System.out.println("Artist: " + artist);
    }

    // Överskriven toString-metod
    @Override
    public String toString() {
        return super.toString() + ", Artist: " + artist;
    }
}
