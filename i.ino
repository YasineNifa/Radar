const int pingPin = 2;

    // Includes the Servo library
    #include <Servo.h>. 
    // Defines Tirg and Echo pins of the Ultrasonic Sensor
    const int sigPIN = 3;
    // Variables for the duration and the distance
    long duration;
    int distance;
    Servo myServo; // Creates a servo object for controlling the servo motor
    void setup() {
      pinMode(sigPIN, OUTPUT); // Sets the trigPin as an Output
      //pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      Serial.begin(9600);
      myServo.attach(9); // Defines on which pin is the servo motor attached
    }
    void loop() {
      // rotates the servo motor from 15 to 165 degrees
      long duration, cm;
      for(int i=15;i<=165;i+=1){  
      myServo.write(i);
      delay(30);
      pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm = microsecondsToCentimeters(duration);

  Serial.print(i);
  Serial.print(",");
  Serial.print(cm);
  Serial.print(".");
      }
      // Repeats the previous lines from 165 to 15 degrees
      for(int i=165;i>15;i-=1){  
      myServo.write(i);
      delay(30);
      pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // on utilise pulseIn pour recevoir une durée de type long
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // On converti la durée en distance grâce à une fonction que vous trouverez plus bas
  cm = microsecondsToCentimeters(duration);

  Serial.print(i);
  Serial.print(",");
  Serial.print(cm);
  Serial.print(".");
      }
    }
    // Function for calculating the distance measured by the Ultrasonic sensor
    int calculateDistance(){ 
      
      digitalWrite(sigPIN, LOW); 
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(sigPIN, HIGH); 
      delayMicroseconds(10);
      digitalWrite(sigPIN, LOW);
      duration = pulseIn(sigPIN, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
      distance= duration*0.034/2;
      return distance;
    }
    
    long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
