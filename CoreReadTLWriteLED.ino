// Updated June 19, 2015 for GitHub repository

int led0 = D0;  // You'll need to wire an LED to this one to see it blink.
int led7 = D7; // This one is the built-in tiny one to the right of the USB jack
int ain0 = A0; // the light sensor
int ain1 = A1; // The temperature sensor
int A0val = 0;
int A1val = 0;
int tempF = 0;
int statusCode = 0;
String arguments;



void setup() {
   Spark.variable("Light", &A0val, INT);
   Spark.variable("Temp", &A1val, INT);
   Spark.function("lightLed0", lightLed0);
   pinMode(led0, OUTPUT);
   pinMode(led7, OUTPUT);
   pinMode(ain0, INPUT);
   pinMode(ain1, INPUT);

}

// Spark variables are constantly updated by the firmware in the backgound
// and the current value is available to the SDK getVAriable method.
void loop() {
   A0val = analogRead(ain0);
   A1val = analogRead(ain1);


   digitalWrite(led7, LOW);  // This blinking LED code is just proof of life
   delay(500);               // if the Core is on the desk in front of you,
   digitalWrite(led7, HIGH); // as mine is.
   delay(500);               // Wait for 1/2 second in on, then off mode
}

 //  This is the function that is run when the SDK callFunction method is run.
 int lightLed0(String args) {
     if (args == "0") digitalWrite(led0, LOW);
     if (args == "1") digitalWrite(led0, HIGH);
     int statusCode = 1;
     return statusCode;
 }
