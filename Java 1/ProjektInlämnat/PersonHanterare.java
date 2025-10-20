import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Collections;
import java.util.Comparator;

public class PersonHanterare 
{
    private List<Person> personList;  // En lista som lagrar alla personer

    // Konstruktor som initialiserar personList som en tom ArrayList
    public PersonHanterare() 
    {
        personList = new ArrayList<>();
    }

    // Lägg till en person i personList
    public void addPerson(Person person) 
    {
        personList.add(person);
    }

    // Skriv ut alla personer i listan
    public void printPeople() {
        for (int i = 0; i < personList.size(); i++)
        {
            Person person = personList.get(i);

        // %d → Plats för ett heltal (nummer).
        // . → Punkt och mellanslag för att separera värden.
        // %s → Plats för en sträng (förnamn).
        // %s → Plats för en sträng (efternamn).
        // %s → Plats för en sträng (plats).
        // %.2f → Plats för ett flyttal med två decimaler (längd).
        // m → Lägger till "m" efter längden för att ange enhet (meter).
        // \n → Ny rad efter utskriften.
        System.out.printf("%d. %s %s %s %.2f m\n", i + 1, person.getSignature(), person.getFirstName(), person.getSecondName(), person.getHeightInMeters());
        }
    }

    // Hitta en person genom att använda signaturen
    public Person findPerson(String signature) 
    {
        for (Person person : personList) {
            if (person.getSignature().equals(signature)) 
            {
                return person;  // Returnerar personen om signaturen matchar
            }
        }
        return null;  // Returnerar null om personen inte hittades
    }

    // Ta bort en person baserat på signatur
    public void removePerson(String signature) 
    {
        Person person = findPerson(signature);  // Hitta personen
        if (person != null) 
        {
            personList.remove(person);  // Ta bort personen från listan
            System.out.println("Personen har tagits bort.");
        } 
        else 
        {
            System.out.println("Personen kunde inte hittas.");
        }
    }

    // Spara listan till en fil
    public void saveListToFile(String filename) 
    {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) 
        {
            // Skriv alla personer i listan till filen
            for (Person person : personList) 
            {
                // Skapa en sträng som representerar personens data
                String personData = person.getSignature() + " "
                                   + person.getFirstName() + " "
                                   + person.getSecondName() + " "
                                   + person.getHeight() + " "
                                   + person.getAddress().getStreet() + " "
                                   + person.getAddress().getPostalCode() + " "
                                   + person.getAddress().getCity();
                writer.write(personData);  // Skriv strängen till filen
                writer.newLine();  // Ny rad efter varje person
            }
            System.out.println("Listan har sparats till filen: " + filename);
        } 
        catch (IOException e) 
        {
            System.out.println("Kunde inte spara listan till filen: " + e.getMessage());
        }
    }

    // Läs in listan från en fil
    public void loadListFromFile(String filename) 
    {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) 
        {
            List<String> lines = reader.lines().toList();  // Läs in alla rader från filen

            // Bearbeta varje rad i filen
            for (String line : lines) 
            {
                // Dela upp raden i delar: signatur, namn, längd och adress
                String[] parts = line.split(" ");
                if (parts.length >= 7) {
                    String signature = parts[0];
                    String firstName = parts[1];
                    String lastName = parts[2];
                    double height = Double.parseDouble(parts[3]);
                    String street = parts[4];
                    String postalCode = parts[5];
                    String city = parts[6];

                    // Skapa ett Address-objekt
                    Adress address = new Adress(street, postalCode, city);

                    // Skapa ett Person-objekt
                    Person person = new Person(firstName, lastName, (int) height, address);
                    personList.add(person);  // Lägg till personen i listan
                }
            }
            System.out.println("Listan har lästs från filen: " + filename);
        } 
        catch (IOException e) 
        {
            System.out.println("Kunde inte läsa filen: " + e.getMessage());
        }
    }

    // Sortera listan baserat på höjd (längsta först)
    public void sortPeopleByHeightDescending() 
    {
        // Använder Comparator för att sortera efter höjd i fallande ordning
        Collections.sort(personList, new Comparator<Person>() 
        { 
            @Override
            public int compare(Person p1, Person p2) {
                return Integer.compare(p2.getHeightInCm(), p1.getHeightInCm());  // Jämför höjder i cm
            }
        });
        System.out.println("Listan har sorterats baserat på längd (längsta först).");
    }

// Blandar listan med personer slumpmässigt
public void peopleShuffler() 
{
    // Blandar personList för att slumpa ordningen på personerna
    Collections.shuffle(personList);
    System.out.println("Listan har blandats.");
}
}