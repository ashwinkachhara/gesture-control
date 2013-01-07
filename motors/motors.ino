//Code for motor control based on state recd through the Accelerometer
//Authors: Sanchar Sharma*, Ashwin Kachhara*, Sumeet Fefar*
//*IIT Bombay
#define rmotp 3
#define rmotn 5
#define lmotp 6
#define lmotn 11

void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void aw(int pin, int value){
  analogWrite(pin, value);
}

void loop(){
  if (Serial.available()>0){
    int state=Serial.read();
    switch (state-48){
      case 0:
        aw(rmotp, 0);
        aw(rmotn, 0);
        aw(lmotp, 0);
        aw(lmotn, 0);
        digitalWrite(13, HIGH);
        break;
      case 1:
        aw(rmotp, 255);
        aw(rmotn, 0);
        aw(lmotp, 255);
        aw(lmotn, 0);
        digitalWrite(13, LOW);
        break;
      case 2:
        aw(rmotp, 0);
        aw(rmotn, 255);
        aw(lmotp, 0);
        aw(lmotn, 255);
        digitalWrite(13, HIGH);
        break;
      case 3:
        aw(rmotp, 0);
        aw(rmotn, 255);
        aw(lmotp, 255);
        aw(lmotn, 0);
        digitalWrite(13, LOW);
        break;
      case 4:
        aw(rmotp, 255);
        aw(rmotn, 0);
        aw(lmotp, 0);
        aw(lmotn, 255);
        digitalWrite(13, HIGH);
        break;
      case 5:
        aw(rmotp, 0);
        aw(rmotn, 0);
        aw(lmotp, 255);
        aw(lmotn, 0);
        digitalWrite(13, LOW);
        break;
      case 6:
        aw(rmotp, 255);
        aw(rmotn, 0);
        aw(lmotp, 0);
        aw(lmotn, 0);
        digitalWrite(13, HIGH);
        break;
    }
    case 7:
        aw(rmotp, 0);
        aw(rmotn, 255);
        aw(lmotp, 0);
        aw(lmotn, 0);
        digitalWrite(13, HIGH);
        break;
    }
    case 6:
        aw(rmotp, 0);
        aw(rmotn, 0);
        aw(lmotp, 0);
        aw(lmotn, 255);
        digitalWrite(13, HIGH);
        break;
    }
  }
}


