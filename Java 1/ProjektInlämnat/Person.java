import java.util.Scanner;
public class Person {

    private String firstName;
    private String lastName;
    private String signature;
    private int height;
    private Adress address;
    Scanner scanner = new Scanner(System.in);

    // Konstruktor som skapar ett Person-objekt och sätter alla fält
    public Person(String firstName, String lastName, int height, Adress address) 
    {
        this.firstName = firstName;  // Sätter förnamnet
        this.lastName = lastName;    // Sätter efternamnet
        this.signature = createSignature(firstName, lastName); // Skapar signatur baserat på namn
        this.height = height;        // Sätter höjden
        this.address = address;      // Sätter adressen
    }

    // Setter-metod för att sätta signaturen
    public void setSignature(String signature) 
    {
        this.signature = signature;
    }
    
    // Setter-metod för att sätta förnamnet
    public void setFirstName(String firstName) 
    {
        this.firstName = firstName;
    }
    
    // Setter-metod för att sätta efternamnet
    public void setSecondName(String lastName) 
    {
        this.lastName = lastName;
    }
    
    // Setter-metod för att sätta höjden i meter, omvandlar till cm
    public void setHeightInMeters(double heightInMeters) 
    {
        this.height = (int) (heightInMeters * 100); // Omvandlar från meter till cm
    }
    
    // Setter-metod för att sätta höjden i cm
    public void setHeight(int height) 
    {
        this.height = height;
    }
    
    // Setter-metod för att sätta adressen
    public void setAddress(Adress address) 
    {
        this.address = address;
    }
    
    // Setter-metod för att sätta höjden i cm
    public void setHeightInCm(int height) 
    {
        this.height = height;
    }    

    // Getter-metod för att hämta signaturen
    public String getSignature() 
    {
        return signature;
    }

    // Getter-metod för att hämta förnamnet
    public String getFirstName() 
    {
        return firstName;
    }

    // Getter-metod för att hämta efternamnet
    public String getSecondName()
    {
        return lastName;
    }

    // Getter-metod för att hämta höjden i meter (omvandlat från cm)
    public double getHeightInMeters() 
    {
        return height / 100.0; // Omvandlar från cm till meter
    }

    // Getter-metod för att hämta höjden i cm
    public int getHeight() 
    {
        return height;
    }

    // Getter-metod för att hämta adressen
    public Adress getAddress() 
    {
        return address;
    }

    // Getter-metod för att hämta höjden i cm (samma som getHeight)
    public int getHeightInCm() 
    {
        return height;
    }

    // Skapar signatur genom att använda de tre första bokstäverna av för- och efternamn
    private String createSignature(String firstName, String lastName) 
    {
        String firstThree = extractFirstThreeLetters(firstName);  // Hämta de tre första bokstäverna av förnamnet
        String lastThree = extractFirstThreeLetters(lastName);    // Hämta de tre första bokstäverna av efternamnet
        
        return (firstThree + lastThree).toLowerCase(); // Kombinera och gör hela signaturen till små bokstäver
    }

    // Hjälpmetod som hämtar de tre första bokstäverna i ett namn, eller hela namnet om det är kortare än tre bokstäver
    private String extractFirstThreeLetters(String name) 
    {
        String result = "";
        if (name.length() >= 3) 
        {
            result = name.substring(0, 3);  // Hämta de tre första bokstäverna
        } 
        else 
        {
            result = name;  // Om namnet är kortare än tre bokstäver, använd hela namnet
        }
        return result;
    }
}
