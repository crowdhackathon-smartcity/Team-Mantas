// Adafruit IO Publish Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// this int will hold the current count for our sketch
int count = 2;
int forceSensor = 0;
int force;
int force1;
int force2;
int force3;
int force4;
int forceSensorA1 = 16;
int forceSensorA2 = 5;
int forceSensorD1 = 4;
int forceSensorD2 = 2;
int flag = 0;

// set up the 'counter' feed
AdafruitIO_Feed *parkingSlot1 = io.feed("parkingSlot1");
AdafruitIO_Feed *parkingSlot2 = io.feed("parkingSlot2");
AdafruitIO_Feed *noParking1 = io.feed("noParking1");
AdafruitIO_Feed *kados1 = io.feed("kados1");
AdafruitIO_Feed *kados2 = io.feed("kados2");
AdafruitIO_Feed *diavasi1 = io.feed("diavasi1");
AdafruitIO_Feed *diavasi2 = io.feed("diavasi2");
AdafruitIO_Feed *AMEA1 = io.feed("AMEA1");
AdafruitIO_Feed *AMEA2 = io.feed("AMEA2");
AdafruitIO_Feed *AMEA3 = io.feed("AMEA3");

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();
  

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  pinMode(forceSensorA1 , OUTPUT);
  pinMode(forceSensorA2 , OUTPUT);
  pinMode(forceSensorD1 , OUTPUT);
  pinMode(forceSensorD2 , OUTPUT);

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
  
    digitalWrite(forceSensorA1,HIGH);
    digitalWrite(forceSensorA2,LOW);
    digitalWrite(forceSensorD1,LOW);
    digitalWrite(forceSensorD2,LOW);
    force1 = analogRead(forceSensor);
    Serial.println("sensor1");
    Serial.println(force);
   if (force1 > 13){
    parkingSlot1->save("Taken");
    kados1->save("Full");
    diavasi1->save("Switch");
    AMEA1->save("Block");
    count = count -1 ;
   }
   else{
    parkingSlot1->save("Free");
    kados1->save("Empty");
    diavasi1->save("Regular");
    AMEA1->save("Not Blocked");
   }

    digitalWrite(forceSensorA1,LOW);
    digitalWrite(forceSensorA2,HIGH);
    digitalWrite(forceSensorD1,LOW);
    digitalWrite(forceSensorD2,LOW);
    force = analogRead(forceSensor);
    Serial.println("sensor2");
    Serial.println(force);
    if (force > 100){
      parkingSlot2->save("Taken");
      kados2->save("Full");
      diavasi2->save("Switch");
      AMEA2->save("Block");
      count = count -1;
    }
    else {
    parkingSlot1->save("Free");
    kados1->save("Empty");
    diavasi1->save("Regular");
    AMEA1->save("Not Blocked");
    }

    digitalWrite(forceSensorA1,LOW);
    digitalWrite(forceSensorA2,LOW);
    digitalWrite(forceSensorD1,HIGH);
    digitalWrite(forceSensorD2,LOW);
    force = analogRead(forceSensor);
    Serial.println("sensor3");
    Serial.println(force);
    if (force > 250){
      noParking1->save("MoveYourCar");      
      AMEA3->save("Block");
    }
    else{
    noParking1->save("Normal");    
    AMEA3->save("Not Blocked");
    }

   // digitalWrite(forceSensorA1,LOW);
  //  digitalWrite(forceSensorA2,LOW);
  //  digitalWrite(forceSensorD1,LOW);
  //  digitalWrite(forceSensorD2,HIGH);
  //  force = analogRead(forceSensor);
  //  Serial.println("sensor4");
  //  Serial.println(force);
 //   if (force > 100){
 //     parkingSlot4->save("Taken");
 //     kados4->save("Full");
 //     diavasi4->save("Switch");
 //     AMEA4->save("Block");
 //   }
 //   else{
 //   parkingSlot4->save("Free");
 //   kados4->save("Empty");
 //   diavasi4->save("Regular");
 //   AMEA4->save("Not Blocked");
 //   } 
    


   
    //counter->save(count);
    

  // save count to the 'counter' feed on Adafruit IO
 // Serial.print("sending -> ");
 // Serial.println(count);
//  parkingSlot1->save("free");
 // parkingSlot2->save("free");
//  noParking1->save("dont");
//  noParking2->save("dont");

  // increment the count by 1
  //count++;

  // wait one second (1000 milliseconds == 1 second)
  Serial.print(flag);
  delay(1000);
}


