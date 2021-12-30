/********************************************************************************************************************/
/*    ANIL ÇETIN                                                                                                    */
/*    ESKISEHIR OSMANGAZI UNIVERSITY                                                                                */
/*    ELECTRICAL-ELECTRONICS ENGINEERING                                                                            */
/*    VOICE CONTROLLED HOME AUTOMATIONS                                                                             */
/********************************************************************************************************************/


#include <LiquidCrystal_I2C.h>                //added lcd screen with i2c modules library.
#include <dht11.h>                            //added DHT11 humidity and temperature sensor library.
#include <Wire.h>                             //added wire library to communicate with the i2c module.
#include <Servo.h>                            //added servo motor library.
#define fan 2                                 //connected fan to pin 2.
#define DHT11PIN 3                            //connected dht11 sensor to pin 3.
#define livingroomled 4                       //connected living rooms led to pin 4.
#define kitchenled 5                          //connected kitchens led to pin 5.
#define hallled 7                             //connected halls led to pin 7.
#define bedroomled 8                          //connected bedrooms led to pin 8.
#define bathroomled 12                        //connected bathroom led to pin 12.
LiquidCrystal_I2C lcd(0x3f,16,2);             //defined the screen model.
dht11 DHT11;                                  //defined the dht11 sensor.
Servo lroomwind;                              //defined living rooms window servo.
Servo kitchenwind;                            //defined kitchens window servo.
Servo door;                                   //defined the doors servo.                                
char state;                                   //defined a variable to collect the values taken by bluetooth.


void setup() {
pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);               //defined the pins modes.
pinMode(12,OUTPUT);
Serial.begin(9600);            //started the serial communication.
lcd.init();                    //initialized the lcd before use.
lcd.backlight();               //backlight
lroomwind.attach(6);      //
kitchenwind.attach(10);    //attached a servo variable to the pin where the servo is connected.
door.attach(9);          //
lcd.setCursor(3,0);             // specified the writings location.
lcd.print("WELLCOME!");         //printed a greeting message to lcd screen first.
delay(5000);                    //after five seconds
lcd.clear();                    //cleaned the screen.
}
void loop() {

 if(Serial.available()>0){    //checks if there is a command on the serial port.
    state=Serial.read();      //equalizes the command to the state variable.
  }
 if (state== '1'){                         //for the state=1.
  analogWrite(fan,150);                    //turns on the fan.
lcd.clear();
lcd.setCursor(2,0);                        //prints to screen the situation.
lcd.print("fan turned on");        
delay(100);
 }
 if (state== '2'){                         //for the state=2.
  analogWrite(fan,0);                      //turns off the fan.
lcd.clear();
lcd.setCursor(2,0);                        //prints to screen the situation.
lcd.print("fan turned off");
delay(100);
 }
 if (state== '3'){                         //for the state=3.
  digitalWrite(livingroomled,HIGH);        //turns on the living rooms light.
lcd.clear();
lcd.setCursor(2,0);
lcd.print("living rooms");                 //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("light on");
delay(100);
 }
 if (state== '4'){                         //for the state=4.
digitalWrite(livingroomled,LOW);         //turns off the living rooms light.
lcd.clear();
lcd.setCursor(2,0);
lcd.print("living rooms");               //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("light off");
delay(100);
 }
 if (state== '5'){                         //for the state=5.
  digitalWrite(kitchenled,HIGH);           //turns on the kitchens light.
lcd.clear();
lcd.setCursor(1,0);
lcd.print("kitchen light");               //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned on");
delay(100);
 }
 if (state== '6'){                         //for the state=6.
  digitalWrite(kitchenled,LOW);            //turns off the kitchens light.
lcd.clear();
lcd.setCursor(1,0);
lcd.print("kitchen light");            //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned off");
delay(100);
 }
 if (state== '7'){                         //for the state=7.
  digitalWrite(bedroomled,HIGH);           //turns on the bedrooms light.
lcd.clear();
lcd.setCursor(1,0);
lcd.print("bedroom light");             //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned on");
delay(100);
 } 
 if (state== '8'){                         //for the state=8.
 digitalWrite(bedroomled,LOW);             //turns off the bedrooms light.
lcd.clear();
lcd.setCursor(2,0);
lcd.print("bedroom light");            //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned off");
delay(100);
 }
 if (state== '9'){                         //for the state=9.
 digitalWrite(bathroomled,HIGH);           //turns on the bathrooms light.
lcd.clear();
lcd.setCursor(0,0);
lcd.print("bathroom light");             //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned on");
delay(100);
 }                
 if (state== 'a'){                         //for the state=a.
 digitalWrite(bathroomled,LOW);            //turns off the bathrooms light.
lcd.clear();
lcd.setCursor(0,0);
lcd.print("bathroom light");            //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned off");
delay(100);
 }
if (state== 'b'){                          //for the state=b.
  digitalWrite(hallled,HIGH);              //turns on the halls light.
lcd.clear();
lcd.setCursor(2,0);
lcd.print("hall light");            //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned on");
delay(100);
}
if (state== 'c'){                          //for the state=c.
  digitalWrite(hallled,LOW);               //turns off the halls light.
lcd.clear();
lcd.setCursor(2,0);
lcd.print("hall light");            //prints to screen the situation.
lcd.setCursor(2,1);
lcd.print("turned off");
delay(100);
}
if (state== 'd'){                          //for the state=d
  lroomwind.write(0);                     //opens the living rooms window.
lcd.clear();
lcd.setCursor(0,0);
lcd.print("living rooms");            //prints to screen the situation.
lcd.setCursor(0,1);
lcd.print("window open");
delay(100);
  }
if (state=='e'){                           //for the state=e
  lroomwind.write(180);                      //closes the living rooms window.
lcd.clear();
lcd.setCursor(0,0);
lcd.print("living rooms");            //prints to screen the situation.
lcd.setCursor(0,1);
lcd.print("window closed");
delay(100);
}       
if (state=='f'){                           //for the state=f
  kitchenwind.write(90);                   //opens kitchens window.
lcd.clear();
lcd.setCursor(4,0);
lcd.print("kitchens");            //prints to screen the situation.
lcd.setCursor(1,1);
lcd.print("window closed");
delay(100);
}
if (state=='g'){                           //for the state=g
   kitchenwind.write(0);                   //closes kitchens window.
lcd.clear();
lcd.setCursor(4,0);
lcd.print("kitchens");            //prints to screen the situation.
lcd.setCursor(1,1);
lcd.print("window open");
delay(100);
}                                      
if (state=='h'){                           //for the state=h
  door.write(0);                          //opens the entrance door.        
lcd.clear();
lcd.setCursor(3,0);
lcd.print("door closed");            //prints to screen the situation.  
delay(100);             
}   
if (state=='i'){                           //for the state=i
  door.write(90);                           //closes the entrance door.
lcd.clear();
lcd.setCursor(3,0);
lcd.print("door open");            //prints to screen the situation.    
delay(100);
}  
if (state=='j'){                           //for the state=l
  humtemp();                              //calls the function which calculates the temperature and humidity. 
}    
if (state=='k'){                           //for the state=m
 digitalWrite(livingroomled,HIGH);
 digitalWrite(kitchenled,HIGH);      
 digitalWrite(bedroomled,HIGH);             //turns on all lights.
 digitalWrite(bathroomled,HIGH);
 digitalWrite(hallled,HIGH);        
lcd.clear();
lcd.setCursor(1,0);
lcd.print("all lights on");               //prints to screen the situation.
delay(100);                         
}    
if (state=='n'){                           //for the state=n
 digitalWrite(livingroomled,LOW);
 digitalWrite(kitchenled,LOW);      
 digitalWrite(bedroomled,LOW);             //turns off all lights.
 digitalWrite(bathroomled,LOW);
 digitalWrite(hallled,LOW);        
lcd.clear();
lcd.setCursor(1,0);
lcd.print("all lights off");               //prints to screen the situation.
delay(100);                         
}    

}
void humtemp(){                            //a function to print temperature and humidity.
lcd.clear();
int chk = DHT11.read(DHT11PIN);            //reads the value from dht11 module and equalizes a variable.
//printing humidity,
lcd.setCursor(0,0);
lcd.print("Humidity:");
lcd.setCursor(10,0);
lcd.print((float)DHT11.humidity, 2);       //prints the float part of humidity in two characters.
//printing temperature.
lcd.setCursor(0,1);
lcd.print("Temp:");
lcd.setCursor(6,1);
lcd.print((float)DHT11.temperature, 2);   //prints the float part of temperature in two characters.
//waiting one second to refresh.
delay(1000);
}
