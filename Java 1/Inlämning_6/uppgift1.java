
import java.util.Scanner;
import java.util.StringTokenizer;

public class uppgift1 
{
    public static void main(String[] args) 
    {
        Scanner userInput = new Scanner(System.in);

        System.out.print("Enter some text: ");
        String text = userInput.nextLine();


        StringTokenizer st = new StringTokenizer(text);
       
        int wordCount = st.countTokens();

        int charCount = text.length();

        // int sentenceCount = text.split("." + "!" + "?").length;
        int sentenceCount = text.split("\\?|!|\\.|\\n").length; 

        System.out.println("Meningar: " + sentenceCount);
        System.out.println("Ord: " + wordCount);
        System.out.println("Karaktärer: " + charCount);

        userInput.close();
    }
}