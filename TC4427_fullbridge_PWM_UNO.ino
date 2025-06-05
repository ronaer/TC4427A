/*
    ____       __________              _ __  
   / __ \_____/_  __/ __ \____  ____  (_) /__
  / / / / ___/ / / / /_/ / __ \/ __ \/ / //_/
 / /_/ / /  _ / / / _, _/ /_/ / / / / / ,<   
/_____/_/  (_)_/ /_/ |_|\____/_/ /_/_/_/|_| 
 
 Dr.TRonik / YouTube / Haziran 2025 / izmir / Türkiye                                        
 2xTC4427A Driver H-bridge;
 PWM direction control Demo;
 UNO & 2xTC4427 & 2xButtons;
 Q1;Q3 P kanal up
 Q2;Q4 N kanal down 
 https://youtu.be/7qh8iF5NuAE

*/

/********************************************************************
  GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___GLOBALS___
 ********************************************************************/
#define Q1 5  // analog / pwm control pin for Q1 High pMOSFET 1
#define Q3 6  // analog / pwm control pin for Q3 High pMOSFET 2
#define Q2 7  // Digital control pin for Q2 Low nMOSFET 1
#define Q4 8  // Digital control pin for Q4 Low nMOSFET 2

#define POT A0

#define SW1 2
#define SW2 3

/********************************************************************
  SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___SETUP___
 ********************************************************************/
void setup() {
  pinMode(Q1, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q2, OUTPUT);
  pinMode(Q4, OUTPUT);

  digitalWrite(Q1, HIGH);  // P kanal Q1 Mos1 Off
  digitalWrite(Q3, HIGH);  // P kanal Q3 Mos3 Off
  digitalWrite(Q2, LOW);   // N kanal Q2 Mos2 Off
  digitalWrite(Q4, LOW);   // N kanal Q4 Mos4 Off

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
}

/********************************************************************
  LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__LOOP__
 ********************************************************************/
void loop() {

  digitalWrite(Q1, HIGH);
  digitalWrite(Q3, HIGH);



  /* SW1 ON:
  Q1 PWM  
  Q4 HIGH / N ON
  Q3 HIGH / P OFF 
  Q2 LOW  / N OFF  
  */
  while (!digitalRead(SW1)) {

    digitalWrite(Q2, LOW);   //Q2 OFF n
    digitalWrite(Q3, HIGH);  //Q3 OFF p
    int potVal = analogRead(POT);
    potVal = map(potVal, 0, 1023, 0, 255);
    analogWrite(Q1, potVal);  //Q1 pwm
    digitalWrite(Q4, HIGH);   //Q4 ON n
  }

  /* SW2 ON:
  Q1 HIGH / P OFF  
  Q4 LOW / N OFF
  Q3 PWM  
  Q2 HIGH  / N ON  
  */
  while (!digitalRead(SW2)) {

    digitalWrite(Q4, LOW);   //Q4 OFF n
    digitalWrite(Q1, HIGH);  //Q1 OFF p
    int potVal = analogRead(POT);
    potVal = map(potVal, 0, 1023, 0, 255);
    //potVal = potVal / 4;
    analogWrite(Q3, potVal);  // Q3 PWM
    digitalWrite(Q2, HIGH);   //Q2 ON n
  }
}
/*
📌___:
📩 bilgi@ronaer.com
🟩 https://whatsapp.com/channel/0029VaxtFPiLSmbgUryuGs0E
📷 https://www.instagram.com/dr.tronik2023/   
📺 www.youtube.com/c/DrTRonik 
*/