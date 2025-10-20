public class DVD extends Media {
    private int ageLimit;

    // Standardkonstruktor
    public DVD() {
        super();
        this.ageLimit = 0;
    }

    // Konstruktor med parametrar
    public DVD(String title, int length, int ageLimit, Publisher publisher) {
        super(title, length, publisher);
        setAgeLimit(ageLimit);
    }

    // Setter och getter för åldersgräns
    public void setAgeLimit(int ageLimit) {
        this.ageLimit = Math.max(ageLimit, 0); // Säkerställer att åldersgränsen inte blir negativ
    }

    public int getAgeLimit() {
        return ageLimit;
    }

    // Överskriven print-metod
    @Override
    public void print() {
        super.print();
        System.out.println("Åldersgräns: " + ageLimit + " år");
    }

    // Omvandlar längden till HH:MM:SS-format
    @Override
    public String getLengthAsString() {
        int hours = length / 3600;
        int minutes = (length % 3600) / 60;
        int seconds = length % 60;
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    // Överskriven toString-metod
    @Override
    public String toString() {
        return super.toString() + ", Åldersgräns: " + ageLimit + " år";
    }
}
