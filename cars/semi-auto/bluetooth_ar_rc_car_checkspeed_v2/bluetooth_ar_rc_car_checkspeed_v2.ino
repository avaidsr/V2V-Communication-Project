#include<Motors.h>

Motors2  myMotors(5,6,10,11);
int speedd = 240;
long timerNewState = 0, timerBegin;

char state; //Takes commands
void setup()

{
  Serial.begin(57600);  //Fast bluetooth baud rate

}

void loop()
{
  // put your main code here, to run repeatedly:

  timerBegin = millis();

  if (Serial.available() > 0) //If command is comming in:
  { 
    timerNewState = millis();
    //delayMicroseconds(2);     //store command in state variable
    checkspeed();
    state = Serial.read();
    Serial.print("Received Command::");
    Serial.print(state);
    // Serial.print(" And the direction:");
    Serial.println();
    // delayMicroseconds(1);
  }
  switch (state) //chooses action to run depending on command
  {
    case 'f':
      forward();
//      Serial.println("forward");

      // Serial.print(state);
      //delay(1000);
      break;
    case 'b':
      backward();
      //   Serial.println("backward");
      break;
    case 'l':
      leftt();
      //Serial.println("left");
      break;
    case'r':
      rightt();
      // Serial.println("right");
      break;
    case 's':
      stopp();
      // Serial.println("stop");
      break;
    /* case 'u':
       checkspeed();

       break;
      case 'd':
       checkspeed();

       break;
*/    default : //stopp();
      break;
  }
  //break;



  if (timerBegin - timerNewState > 15000) //No command for 300ms then stop
  {
    stopp();
  }




  //state='o'; //For resetting state
}                           //end of main function


//functions
//check speed
void checkspeed()
{
  if (Serial.peek() == 'u' || Serial.peek() == 'd')

  {

    char speedType =  Serial.read();

    if (speedType == 'u')
    {
      speedUp();
      //Serial.print(speedd);
    }
    else if (speedType == 'd')
    {
      speedDown();
      //Serial.print(speedd);
    }
    return;
  }

}


//Action-to-take functions
void forward()
{
myMotors.runMtr(speedd,speedd);
//Serial.print(speedd);
}
void backward()
{
    myMotors.runMtr(-speedd,-speedd);
  //  Serial.print(speedd);
}
void leftt()
{

  myMotors.runMtrLeft(speedd);
//
//Serial.print(speedd);

}
void rightt()
{
  myMotors.runMtrRight(speedd);
  //Serial.print(speedd);
}
void stopp()
{
myMotors.runMtr(0,0);
//Serial.print(speedd);
}
void speedUp()
{
  speedd += 10;

  if (speedd > 255)
  {
    speedd = 255;
  }

}
void speedDown()
{
  speedd -= 10;
  if (speedd < 120)
  {
    speedd = 120;
  }

}


