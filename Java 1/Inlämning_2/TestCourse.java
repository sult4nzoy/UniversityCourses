import javax.swing.*;

class Course
{  // Ingen "public" här eftersom filen måste matcha den publica klassen
    private String courseCode;
    private String name;
    private String credits;
    private String description;

    public void setCourseCode(String courseCode) {
        this.courseCode = courseCode;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCredits(String credits) {
        this.credits = credits;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void printCourseInfo() 
    {
        System.out.println("Kurskod: " + courseCode);
        System.out.println("Namn: " + name);
        System.out.println("Poäng: " + credits);
        System.out.println("Beskrivning: " + description);
        System.out.println("---------------------");
    }

    public String getcourseCode()
    {
        return courseCode;
    }
        
        public String getName()
    {
        return name;
    }
        
        public String getCredits()
    {
        return credits;
    }
        
        public String getDescriptions()
    {
        return description;
    }

}

// Ingen "public" här så vi kan ha allt i samma fil
class TestCourse
{
    public static void main(String[] args) 
    {
        Course java = new Course();
        java.setCourseCode("DT196G");
        java.setName("Java I");
        java.setCredits("7.5 hp");
        java.setDescription("Introduktion till Java programming.");
        java.printCourseInfo();

        Course userCourse = new Course();
        String courseCode = JOptionPane.showInputDialog("Skriv kurskoden:");
        String name = JOptionPane.showInputDialog("Skriv Kursnamn:");
        String credits = JOptionPane.showInputDialog("Skriv kurspoäng:");
        String description = JOptionPane.showInputDialog("Skriv beskrivning:");

        userCourse.setCourseCode(courseCode);
        userCourse.setName(name);
        userCourse.setCredits(credits);
        userCourse.setDescription(description);
        userCourse.printCourseInfo();
    }
}
