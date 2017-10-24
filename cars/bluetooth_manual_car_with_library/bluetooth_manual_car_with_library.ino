#include <Motors.h>


int speedd=240; //speed at which motors run

//time since last command has been received, time since begining of code
long timerNewState=0,timerBegin;  //timer variables

char state; //Takes commands

Motors2 motors(5,6,10,11);


void setup()

{
  // put your setup code here, to run once:
  
  Serial.begin(57600);  //Fast bluetooth baud rate


}

void loop()
{
  // put your main code here, to run repeatedly:

  timerBegin=millis(); //time since begining of code

  if(Serial.available()>0)  //If command is comming in:
  {
    timerNewState =millis();    
    state=Serial.read();    //store command in state variable
    Serial.print("Received Command::");
    Serial.println(state);

    switch(state) //chooses action to run depending on command
    {
    case 'f':
      forward();
      //Serial.println("forward");

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
      //Serial.println("right");
      break;
    case 's':
      stopp();
      // Serial.println("stop");
      break;
    case 'u':
      speedUp();
        Serial.print("speed::");
        Serial.println(speedd);
      break;
    case 'd':
      speedDown();
       Serial.println("speed::");
       Serial.println(speedd);
      break;
    default : //stopp();
      break;
    }
    //break;
  }

  else {

      if(timerBegin-timerNewState>300)
      {
        stopp();
      }
  }



  //state='o'; //For resetting state
}

//Action-to-take functions
void forward()
{  //run motors forward at specified speed
              //left motor, right motor
  motors.runMtr(speedd,speedd);
}
void backward()
{
  //run motors backward at speed
  motors.runMtr(-speedd,-speedd);
}
void leftt()
{
  // run only left motor at speed
  motors.runMtrLeft(speedd);


}
void rightt()
{
  //run only right motor at speed
  motors.runMtrRight(speedd);
}
void stopp()
{
  //stop motors
 motors.runMtr(0,0);

}

//Speed changers
void speedUp()
{
  speedd+=10;
  
  //speed shouldnt be more than 255
  if (speedd>255)
      speedd=255;

}
void speedDown()
{
  speedd-=10;
  
  
  //speed shouldn't be below 100
  if(speedd<100)
    speedd=100;
}


