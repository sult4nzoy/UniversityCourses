import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class uppgift2 
{
    public static void main (String[] args) throws FileNotFoundException
    {
       String filename = "wordlist1.txt";

        if (args.length > 0)
        {
            filename = args[0];
        }
    
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the word to search for: ");
        String searchWord = input.nextLine().toLowerCase();

        File file = new File(filename);
        Scanner fileScanner = new Scanner(file);

        int wordCount = 0;
        boolean wordFound = false;
        long startTime = System.currentTimeMillis();

        while (fileScanner.hasNext()) 
        {
            String word = fileScanner.next().toLowerCase();
            wordCount++;
            
            if (word.equals(searchWord))
            {
                wordFound = true;
            }
        }

        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;

        System.out.println("The file" + " " + filename + " " + "contains " + wordCount + " words.");
        
        if (wordFound)
        {
            System.out.println("The word '" + searchWord + "' exists in this file.");
        } 
        
        else 
        {
            System.out.println("The word '" + searchWord + "' does not exist in this file.");
        }
        System.out.println("The search took " + elapsedTime + " ms");

        fileScanner.close();
        input.close();
    }
}
