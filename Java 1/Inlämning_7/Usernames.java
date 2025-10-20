import java.util.ArrayList;

public class Usernames {
    
    public static ArrayList<String> create(String[] names) {
        ArrayList<String> usernames = new ArrayList<>();
        for (String name : names) {
            String[] parts = name.toLowerCase().split(" ");
            String username = getFirstThree(parts[0]) + (parts.length > 1 ? getFirstThree(parts[1]) : "");
            usernames.add(username);
        }
        return usernames;
    }

    public static void list(String[] names, ArrayList<String> usernames) {
        for (int i = 0; i < names.length; i++) {
            System.out.println(names[i] + " (" + usernames.get(i) + ")");
        }
    }

    private static String getFirstThree(String s) {
        return s.length() > 3 ? s.substring(0, 3) : s;
    }

    public static void main(String[] args) {
        String[] names = {
            "Bo Ek", "Erik Edström", "Jörgen Svensson", "Anna Karlsson", "Olof Berg",
            "Maria Lind", "Jonas Dahl", "Lena Persson", "Ulf Olsson", "Karin Blomqvist"
        };

        ArrayList<String> usernames = create(names);
        list(names, usernames);
    }
}