import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;

public class uppgift2 {
    public static void main(String[] args) throws IOException { // IOException to handle File operations
        String filename = "befolkning2050.txt";
        File file = new File(filename);

        OutputStream os = new FileOutputStream("output.txt", true); // Append mode
        Scanner scanner = new Scanner(file);

        int totalPopulation = 0;
        int age = 0;
        int totalAgePopulation;



        while (scanner.hasNextLine()) {
            scanner.nextLine();
            String men = scanner.nextLine();
            String women = scanner.nextLine();

            String[] menParts = men.split("\\s+");
            String[] womenParts = women.split("\\s+");

            totalAgePopulation = Integer.parseInt(menParts[2]) + Integer.parseInt(womenParts[2]);
            totalPopulation += totalAgePopulation;



            String text = "Ålder:" + " " + age + "\n" + "Totalt antal:" + " " + totalAgePopulation + "\n" + "--------------------" + "\n";
            os.write(text.getBytes());

            age++;
        }

        String totalText = "Totalt antal: " + totalPopulation + "\n";
        os.write(totalText.getBytes());

        // Close resources
        scanner.close();
        os.close();
    }
}
