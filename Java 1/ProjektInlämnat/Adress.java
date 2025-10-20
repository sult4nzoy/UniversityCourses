public class Adress {
    private String street;
    private String postalCode;
    private String city;

    // Konstruktor som sätter värdena för gata, postnummer och stad
    public Adress(String street, String postalCode, String city) 
    {
        this.street = street;
        this.postalCode = postalCode;
        this.city = city;
    }

    // Setter för gatuadress
    public void setStreet(String street) 
    {
        this.street = street;
    }

    // Setter för postnummer
    public void setPostalCode(String postalCode)
    {
        this.postalCode = postalCode;
    }

    // Setter för stad
    public void setCity(String city)
    {
        this.city = city;
    }

    // Getter för gatuadress
    public String getStreet() 
    {
        return street;
    }

    // Getter för postnummer
    public String getPostalCode() 
    {
        return postalCode;
    }

    // Getter för stad
    public String getCity() 
    {
        return city;
    }
}
