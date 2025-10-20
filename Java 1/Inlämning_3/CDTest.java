import java.util.Scanner;

public class CDTest 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        Publisher publisher1 = new Publisher("Omar & Co", "87654323456");
        CD CD1 = new CD("Joes Album", "Joe", 100, publisher1);

        System.out.println("Skriv in titel: ");
        String titel = input.nextLine();
        System.out.println("Skriv in artistens namn: ");
        String artist = input.nextLine();
        System.out.println("Skriv in längden (sekunder): ");
        int seconds = input.nextInt();
        input.nextLine();

        System.out.println("Skriv in publisher namn: ");
        String publisherName = input.nextLine();
        System.out.println("Telefonnummer till publisher: ");
        String publisherNumber = input.nextLine();

        Publisher publisher2 = new Publisher(publisherName, publisherNumber);
        CD CD2 = new CD(titel, artist, seconds, publisher2);

        CD1.print();
        CD2.print();

        input.close();
    }
}
