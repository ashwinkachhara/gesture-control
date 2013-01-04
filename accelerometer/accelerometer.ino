// Arduino code for using the MMA7361 Accelerometer Module
// Please feel free to copy, edit, distribute, sell, plagiarise ... Whatever you want  
// A mention of Babelduck Cybernetics would be nice but is not necessary
// Written January 2012 
char str[512];                  // We will use this to construct a string to send with the readings
int state=0;
void setup()
{
 
  Serial.begin(9600);           // Start the serial link so we can see the output in the Arduino IDE
}
void loop()
{
  int x, y, z;                  // Variables to store the 3 readings
 
  x = analogRead(A0)-340;           // Read the X axis reading
  y = analogRead(A1)-370;           // Read the Y axis reading
  z = analogRead(A2)-350;           // Read the Z axis reading
  /*
  sprintf(str, "%d \t %d \t %d", x, y, z);   // Construct a string out of all three readings
  Serial.println(str);                       // Print it to the serial link
  delay(500);
  */
  if(z<135){
    if(x>65){
      if(y>65) state=5;
      else if(y<-65) state=6;
      else state=1;
    }
    else if(x<-60){
      if(y>65) state=7;
      else if(y<-65) state=8;
      else state=2;
    }
    else if(y>65) state=3;
    else if(y<-65) state=4;
  }
  else state=0;
  /*
  Serial.print("\nState: ");Serial.print(state);
  Serial.print("\tx: ");
  Serial.print(x);
  Serial.print("\ty: ");
  Serial.print(y);
  Serial.print("\tz: ");
  Serial.print(z);*/
  Serial.write(state+48);
  delay(50);     
}
/*
States:  
516
304
728
stable: 340 370 490
front: 505 370 325
back: 170 370 325
left: 360 530 315
right: 330 200 340
*/
