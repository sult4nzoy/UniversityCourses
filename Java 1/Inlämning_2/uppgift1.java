import javax.swing.*; // Importera JOptionPane
import java.io.File;
import java.util.Scanner;

public class uppgift1
{
    public static void main(String[] args) throws Exception
    {
        File fil = new File("saga.txt");
        
        Scanner scanner = new Scanner(fil);
        Scanner userInput = new Scanner(System.in);

        System.out.println("Namnet på myran? ");
        String a = userInput.nextLine();

        System.out.println("Vem myran bor med? ");
        String b = userInput.nextLine();

        System.out.println("Hur många syskon som myran har? ");
        String c = userInput.nextLine();

        System.out.println("Var någonstans i skogen myrstacken finns? ");
        String d = userInput.nextLine();

        System.out.println("Vad myran och syskonen bär in till stacken? ");
        String e = userInput.nextLine();

        System.out.println("Vad myran och syskonen mer bär in till stacken? ");
        String f = userInput.nextLine();

        System.out.println("Vad det är för speciell dag som gör att myran är ledig? ");
        String g = userInput.nextLine();

        // Ersätt bokstäverna i filens innehåll med användarens inmatning
        StringBuilder filInnehall = new StringBuilder();
        while (scanner.hasNextLine()) 
        {
            String rad = scanner.nextLine(); // Läs rad för rad
            rad = rad.replace("1", a)
                     .replace("2", b)
                     .replace("3", c)
                     .replace("4", d)
                     .replace("5", e)
                     .replace("6", f)
                     .replace("7", g);
            filInnehall.append(rad).append("\n"); // Lägg till raden i StringBuilder
        }

        scanner.close();
        userInput.close();

        System.out.println("JOptionPane öppnas nu...");

        JOptionPane.showMessageDialog(null, filInnehall, "Sagan med dina val", JOptionPane.INFORMATION_MESSAGE);
    }
}