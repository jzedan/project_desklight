
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;  // the number of the pushbutton pin
const int ledPin = 2;    // the number of the LED pin
const int Reset=12;
int incomingByte =0; // definition of incoming byte for midnight time
int pinstate=0;

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int ResetButton=0;
int shiftbutton=0;
int counter=0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
pinMode(Reset, INPUT);

Serial.begin(9600);
  //int  buttonpress=0;
  
}

void loop() {
  // read the state of the pushbutton v0alue:

buttonState = digitalRead(buttonPin);
pinstate =digitalRead(ledPin);
  
  if (buttonState ==HIGH && pinstate ==LOW ) 
  {
    // turn LED on:

     digitalWrite(ledPin, HIGH);
     Serial.println ( "Taken1");
     
     //counter= counter + 1;      
 }

if (buttonState ==HIGH && pinstate ==HIGH ) 
  {

    digitalWrite(ledPin, LOW);
     Serial.println ( "Empty");
      //counter=counter-1;
  }


    
// turn off button after the timer has gone by
    
  if (pinstate==HIGH)
  {
    Serial.println ( "Taken2");
    }

   if ( pinstate==LOW)
   {
    Serial.println ( "Empty2");
    }




delay (100);// delay to make sure the communication goes through to the raspberry pi

if (Serial.available() > 0) {
             
        Serial.println("midnight reset");
        digitalWrite(ledPin, LOW); // this will reset the pin 
       // shiftbutton=0;
       // ResetButton=1;
}  

 }
