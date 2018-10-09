/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

 
 #define outputA 2
 #define outputB 3
 int counter = 0; 
 int angle = 0;
 int aState;
 int aLastState;  
 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
   attachInterrupt(digitalPinToInterrupt(outputA), angle, CHANGE);
   attachInterrupt(digitalPinToInterrupt(outputB), angle, CHANGE);
 } 
 
 void loop() { 
 }

 void angle(){ aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     counter = counter%40
     Serial.print("Position: ");
     Serial.println(counter*9);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
   angle =  counter*9;
 }

