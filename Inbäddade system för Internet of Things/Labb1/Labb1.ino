/*
DEL 1
Författare: Omar Sultanzoy & Siye Abera
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Senast ändrat: 2026-02-02
*/


/*
Initialiera alla variabler
Variabelnamnet = själva biten, men värdet som blir tilldelat till variabeln = pin på arduinon
*/
const int bitOne = 11;
const int bitTwo = 10;
const int bitFour = 9;
const int bitEight = 8;
const int buttonPin = 7;
/*
Initialisera alla pins
*/
void setup() {
  pinMode(bitOne, OUTPUT);
  pinMode(bitTwo, OUTPUT);
  pinMode(bitFour, OUTPUT);
  pinMode(bitEight, OUTPUT);
  pinMode(buttonPin, INPUT);
}
/*
Min infinite loop som körs tills jag antingen kopplar ut arduino:n eller kompilerar ny kod.
*/
void loop() { 
  if (digitalRead(buttonPin) == HIGH) { // När jag klickar på knappen, gör det som står nedan.
    for (int count = 0; count <= 15; count++) { // For loop som itererar 16 gånger, 0-15.
      int temp = count;

      if (temp >= 8) { // Bit 4 (längst till vänster, värde 8)
        digitalWrite(bitEight, HIGH); // Om sant, lys den lampan
        temp -= 8; // Subtrahera värdet från temp
      } 
      else {
        digitalWrite(bitEight, LOW); // Annars håll den avstängd
      }

      if (temp >= 4) { // Bit 3 (värde 4)
        digitalWrite(bitFour, HIGH);
        temp -= 4;
      } 
      else {
        digitalWrite(bitFour, LOW);
      }

      if (temp >= 2) { // Bit 3 (värde 2)
        digitalWrite(bitTwo, HIGH);
        temp -= 2;
      } 
      else {
        digitalWrite(bitTwo, LOW);
      }

      if (temp >= 1) { // Bit 1 (längst till höger, värde 1)
        digitalWrite(bitOne, HIGH);
      } 
      else {
        digitalWrite(bitOne, LOW);
      }

      delay(1000);
    }
    /*
    Släcker alla lampor
    */
    digitalWrite(bitEight, LOW);
    digitalWrite(bitFour, LOW);
    digitalWrite(bitTwo, LOW);
    digitalWrite(bitOne, LOW);
  }
}