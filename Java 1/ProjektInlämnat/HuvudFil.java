// Importerar Scanner-klassen för att kunna ta emot inmatning från användaren
import java.util.Scanner;

public class HuvudFil 
{
    // Skapar ett Scanner-objekt för att läsa input från användaren
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) 
    {
        // Skapar en PersonHanterare som kommer hålla koll på alla personer
        PersonHanterare manager = new PersonHanterare();

        // Här börjar en evig loop som visar en meny tills användaren väljer att avsluta
        while (true) 
        {
            // Skriver ut menyn med olika alternativ för användaren att välja
            System.out.println("---MENY---");
            System.out.println("|1| Lägg till person");
            System.out.println("|2| Skriv ut lista");
            System.out.println("|3| Sök person");
            System.out.println("|4| Ta bort person");
            System.out.println("|5| Spara till fil");
            System.out.println("|6| Läs från fil");
            System.out.println("|7| Sortera listan efter längd (längsta först)");
            System.out.println("|8| Slumpmässigt blanda listan");
            System.out.println("|9| Avsluta");
            System.out.print("Val: ");

            // Läser användarens val (som en textsträng)
            String choice = scanner.nextLine();

            // Kollar om valet är mellan 1 och 8, om inte fortsätter vi till nästa iteration
            if (!choice.matches("[1-9]")) 
            {
                System.out.println("Ogiltigt val. Ange ett nummer mellan 1 och 9");
                continue; // Om valet inte är giltigt så hoppar vi tillbaka till början av loopen
            }

            // Omvandla det som användaren skrev till ett heltal
            int choiceInt = Integer.parseInt(choice);

            // Här väljer vi vilket alternativ som användaren valt genom en switch-sats
            switch (choiceInt) 
            {
                case 1:
                    try 
                    {
                        // Be om förnamn
                        System.out.print("Ange förnamn: ");
                        String firstName = scanner.nextLine().trim();
                        // Här kollar vi att förnamnet bara innehåller bokstäver, annars får användaren rätta sig
                        while (!isText(firstName)) 
                        {
                            System.out.print("Ogiltigt förnamn. Endast bokstäver tillåtna: ");
                            firstName = scanner.nextLine().trim();
                        }

                        // Be om efternamn
                        System.out.print("Ange efternamn: ");
                        String lastName = scanner.nextLine().trim();
                        // Här gör vi samma sak för efternamnet
                        while (!isText(lastName)) 
                        {
                            System.out.print("Ogiltigt efternamn. Endast bokstäver tillåtna: ");
                            lastName = scanner.nextLine().trim();
                        }

                        // Här kollar vi att användaren anger en giltig längd (positivt tal)
                        int height = -1;
                        while (height < 0) 
                        {
                            System.out.print("Ange längd (i cm): ");
                            String heightStr = scanner.nextLine().trim();
                            try 
                            {
                                height = Integer.parseInt(heightStr);
                                if (height < 0) 
                                {
                                    System.out.println("Längden måste vara ett positivt tal.");
                                }
                            } 
                            catch (NumberFormatException e) 
                            {
                                System.out.println("Ogiltig längd. Ange en siffra.");
                            }
                        }

                        // Be om adress
                        System.out.print("Ange adress: ");
                        String street = scanner.nextLine().trim();

                        // Be om postnummer och kolla så att det är exakt 5 siffror
                        System.out.print("Ange postnummer (5 siffror): ");
                        String postalCode = scanner.nextLine().trim();
                        while (!postalCode.matches("\\d{5}")) 
                        {
                            System.out.print("Ogiltigt postnummer. Ange exakt 5 siffror: ");
                            postalCode = scanner.nextLine().trim();
                        }

                        // Be om stad och kolla så att den bara innehåller bokstäver
                        System.out.print("Ange stad: ");
                        String city = scanner.nextLine().trim();
                        while (!isText(city)) 
                        {
                            System.out.print("Ogiltig stad. Endast bokstäver tillåtna: ");
                            city = scanner.nextLine().trim();
                        }

                        // Skriv ut att personen har lagts till
                        System.out.println("Kontakt tillagd!");

                        // Skapa ett Adress-objekt och ett Person-objekt som vi lägger till i manager
                        Adress address = new Adress(street, postalCode, city);
                        Person person = new Person(firstName, lastName, height, address);
                        manager.addPerson(person);
                        continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn

                    } 
                    catch (Exception e) 
                    {
                        // Om något går fel (t.ex. användaren skriver något konstigt), skriv ut ett felmeddelande
                        System.out.println("Ett fel uppstod vid inmatningen: " + e.getMessage());
                    }
                    break;

                case 2:
                    // Skriv ut listan på alla personer som har lagts till
                    manager.printPeople();
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 3:
                    // Be om en signatur för att söka efter en person
                    System.out.print("Ange signatur att söka efter: ");
                    String signatureSearch = scanner.nextLine();
                    Person foundPerson = manager.findPerson(signatureSearch);
                    if (foundPerson != null) 
                    {
                        // Om personen finns, skriv ut deras information
                        System.out.printf("%s %s %s %.2f m\n", 
                            foundPerson.getSignature(), 
                            foundPerson.getFirstName(), 
                            foundPerson.getSecondName(), 
                            foundPerson.getHeightInMeters());
                    } 
                    else 
                    {
                        // Om personen inte finns, skriv ut ett felmeddelande
                        System.out.println("Personen hittades inte.");
                    }
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 4:
                    // Be om en signatur för att ta bort en person
                    System.out.print("Ange signatur att ta bort: ");
                    String signatureDelete = scanner.nextLine();
                    // Ta bort personen från listan
                    manager.removePerson(signatureDelete);
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 5:
                    // Be om ett filnamn för att spara listan
                    System.out.print("Ange filnamn för att spara: ");
                    String saveFilename = scanner.nextLine();
                    manager.saveListToFile(saveFilename);
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 6:
                    // Be om ett filnamn för att läsa in en lista från fil
                    System.out.print("Ange filnamn för att läsa: ");
                    String loadFilename = scanner.nextLine();
                    manager.loadListFromFile(loadFilename);
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 7:
                    // Sortera listan efter längd (längsta först) och skriv ut den
                    manager.sortPeopleByHeightDescending();
                    manager.printPeople();
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 8:
                    // Blandar listan med personer innan programmet avslutas
                    System.out.println("Blandar listan med personer...");
                    manager.peopleShuffler();  // Anropar funktionen för att blanda personerna i manager
                    continueFunction(); // Vänta på att användaren ska trycka på en tangent innan vi går tillbaka till menyn
                    break;

                case 9:
                    // Avsluta programmet
                    System.out.println("Avslutar programmet...");
                    scanner.close(); // Stänger Scanner-objektet
                    return; // Stänger programmet

                default:
                    // Om något går fel (t.ex. användaren anger ett nummer som inte finns), skriv ut ett felmeddelande
                    System.out.println("Ogiltigt val. Försök igen.");
                    break;
            }
        }
    }

    // Den här metoden kollar om en sträng bara innehåller bokstäver
    public static boolean isText(String text)
    {
        if (text.matches("\\d+"))
        {
            return false; // Om texten bara innehåller siffror, returnera false
        }
        return true; // Om texten innehåller bokstäver, returnera true
    }

    // Den här metoden gör så att programmet pausar och väntar på att användaren ska trycka på en tangent
    public static void continueFunction() 
    {
        System.out.print("Tryck valfri tangent för att fortsätta till meny...");
        scanner.nextLine(); // Väntar på att användaren trycker på en tangent
    }

}
