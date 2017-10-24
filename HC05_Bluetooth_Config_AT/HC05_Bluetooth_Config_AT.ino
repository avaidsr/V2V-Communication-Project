#include <SoftwareSerial.h>

SoftwareSerial btSerial(2,3); //serial port of bluetooth module in form (rx,tx)
char command[50]; //array to hold entered AT command
uint8_t i=0, count=0 , led=13;


void setup()
{
  // put your setup code here, to run once:
  
  Serial.begin(9600);    //baudrates of serial ports
  btSerial.begin (38400);
  
  while(!Serial){} //wait for serial port to open
  
  Serial.println("Initializing Serial Connections");

  Serial.println("Make Sure to set baud rate to 9600");
  Serial.println("Make Sure Line Ending is set to \"CR+LF\"");
  Serial.println("Ready to Accept AT Commands::");
}

void loop()
{
  // put your main code here, to run repeatedly:
  
  if(btSerial.available())   //when data is  available from bluetooth module
  {
    Serial.write(btSerial.read());
  }
  
  if(Serial.available()) //when data is available from serial monitor
  {
    
 /*  i=0;
    do{
        command[i]=Serial.read();
        i++;
      }  while(command[i-1]=='\n');
      
      count= i - 1;
     // Serial.print("COMMAND IS:: ");
      for( i=0;i<=count; i++);
      {
        Serial.print(command[i]);
        btSerial.write(command[i]);
      }
    Serial.println();*/

    char data = Serial.read();

    Serial.print(data);
    btSerial.write(data);
  }
  
 /* for (i=0; i<=count;i++) //reset command
  {
    command[i]=0;
  }*/
}

