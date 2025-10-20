public class Publisher {
    private String name;
    private String phone;

    // Standardkonstruktor
    public Publisher() {
        this.name = "Okänd utgivare";
        this.phone = "Inget nummer";
    }

    // Konstruktor med parametrar
    public Publisher(String name, String phone) {
        this.name = name;
        this.phone = phone;
    }

    // Getter och setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }
}
