#include <Servo.h>

Servo servo1;
Servo servo2;
//Servo servo3;
//Servo servo4;
Servo servo5;
Servo servo6;

int kolor = 0;         // parametr decydujący o ruchu ramienia
int pos = 0;           // pozycja
int krok=0;

int otwarty = 70;    // pozycja otwarcia chwytaka
int chwyt = 20;     // chwycenie
int zamkniety = 0;    // pozycja zamknięcia chwytaka

int x=20;
int y=70;
int i=60;


void setup() {
  Serial.begin(9600);
  servo1.attach(3);  // piny poszczegolnych serwomechanizmow
  servo2.attach(5);
  //servo3.attach(6);
  //servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);

  servo5.write(70);
  servo6.write(60);
  servo1.write(zamkniety);
  servo2.write(20);
  delay(1000);
  
}

void loop() {
if (Serial.available()>0) {
  kolor = Serial.read();
while(krok<1){
  if (kolor == 'z'){
    Serial.write("zielony");
    // sek2
    for (x = 25; x <= 65; x += 1) {
    servo2.write(x);              
    delay(15);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(2000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    //sek3
    servo1.write(chwyt);
    //sek4
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    for (i = 60; i <= 90; i += 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);  
    }
    delay(1000);
    for (i = 90; i >= 60; i -= 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    servo1.write(zamkniety);
    delay(1000);
    for (x = 65; x >= 25; x -= 1) {
    servo2.write(x);              
    delay(15);   
    }
    krok++;
  }
   else if (kolor == 'c'){
    Serial.write("czerwony");
        // sek2
    for (x = 25; x <= 65; x += 1) {
    servo2.write(x);              
    delay(15);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(1000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    //sek3
    servo1.write(chwyt);
    //sek4
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    for (i = 60; i >= 30; i -= 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);  
    }
    delay(1000);
    for (i = 30; i <= 60; i += 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    servo1.write(zamkniety);
    delay(1000);
    for (x = 65; x >= 25; x -= 1) {
    servo2.write(x);              
    delay(15);   
    }
    krok++;
   }
   else if (kolor == 'n'){
    Serial.write("niebieski");
    // sek2
    for (x = 25; x <= 65; x += 1) {
    servo2.write(x);              
    delay(15);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(1000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    //sek3
    servo1.write(chwyt);
    //sek4
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    for (i = 60; i <= 120; i += 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    for (y = 70; y >= 52; y -= 1) {
    servo5.write(y);              
    delay(40);   
    }
    delay(1000);
    servo1.write(otwarty);
    delay(1000);
    for (y = 52; y <= 70; y += 1) {
    servo5.write(y);              
    delay(40);  
    }
    delay(1000);
    for (i = 120; i >= 60; i -= 1) {
    servo6.write(i);              
    delay(40);  
    }
    delay(1000);
    servo1.write(zamkniety);
    delay(1000);
    for (x = 65; x >= 25; x -= 1) {
    servo2.write(x);              
    delay(15);   
    }
    krok++; 
   }
   else if (kolor == 'o') {
   Serial.write("brak obiektu lub zbyt wiele kolorow"); 
   }
   else{
   Serial.write("blad systemu");
   }
}
}
}
