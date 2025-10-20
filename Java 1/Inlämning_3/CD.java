/**
 * Representerar en CD med titel, artist, speltid och en utgivare (Publisher).
 */
public class CD 
{
    private String titel;
    private String artist;
    private int seconds;
    private Publisher publisher;

    /**
     * Skapar en ny CD med specificerad titel, artist, speltid och utgivare.
     *
     * @param titel CD:ns titel.
     * @param artist Namnet på artisten.
     * @param seconds Speltiden i sekunder.
     * @param publisher Utgivaren av CD:n.
     */
    public CD(String titel, String artist, int seconds, Publisher publisher)
    {
        this.titel = titel;
        this.artist = artist;
        this.seconds = seconds;
        this.publisher = publisher;
    }

    public CD()
    {}
    
    /**
     * Sätter CD:ns titel.
     *
     * @param titel Den nya titeln.
     */
    public void setTitle(String titel)
    {
        this.titel = titel;
    }

    /**
     * Sätter artistens namn.
     *
     * @param artist Det nya artistnamnet.
     */
    public void setArtist(String artist)
    {
        this.artist = artist;
    }

    /**
     * Sätter CD:ns längd i sekunder.
     *
     * @param seconds Den nya speltiden i sekunder.
     */
    public void setSeconds(int seconds)
    {
        this.seconds = seconds;
    }

    /**
     * Sätter utgivaren av CD:n.
     *
     * @param publisher Den nya utgivaren.
     */
    public void setPublisher(Publisher publisher)
    {
        this.publisher = publisher;
    }

    /**
     * Skapar och sätter en ny utgivare med namn och telefonnummer.
     *
     * @param name Utgivarens namn.
     * @param phoneNumber Utgivarens telefonnummer.
     */
    public void setPublisher(String name, String phoneNumber)
    {
        this.publisher = new Publisher(name, phoneNumber);
    }

    /**
     * Hämtar CD:ns titel.
     *
     * @return CD:ns titel.
     */
    public String getTitle()
    {
        return titel;
    }

    /**
     * Hämtar artistens namn.
     *
     * @return Namnet på artisten.
     */
    public String getArtist()
    {
        return artist;
    }

    /**
     * Hämtar CD:ns längd i sekunder.
     *
     * @return Speltiden i sekunder.
     */
    public int getSeconds()
    {
        return seconds;
    }

    /**
     * Hämtar utgivaren av CD:n.
     *
     * @return Utgivaren av CD:n.
     */
    public Publisher getPublisher()
    {
        return publisher;
    }

    /**
     * Returnerar en strängrepresentation av CD-objektet.
     *
     * @return En sträng som innehåller titel, artist, längd och utgivare.
     */
    @Override
    public String toString()
    {
        return "Titel: " + titel + ", Artist: " + artist + ", Längd (Sekunder): " + seconds + ", Publisher: " + publisher.getName();
    }

    /**
     * Skriver ut CD-informationen till konsolen.
     */
    public void print()
    {
        System.out.println(toString());
    }
}
