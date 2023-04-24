#include <pcmConfig.h>
#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>
#include <pcmRF.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;

int buttonPin = 5;
int buttonNew;
int old = 0;
int soundCheck = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  //digitalWrite(dir1,HIGH);
  //digitalWrite(dir2,LOW);
  tmrpcm.speakerPin = 9;
  tmrpcm.setVolume(5);
  //tmrcpm.quality(1);
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD fails");
    return;
  }
  tmrpcm.disable();
  Serial.println("Done");
}


void loop() {
  // put your main code here, to run repeatedly:
  bob();
  }
  
  
void bob(){
  buttonNew = digitalRead(buttonPin);
  if(buttonNew == 1 && old == 0){
    //Serial.println("Check");
    if(soundCheck == 0){
      Serial.println("Playing"); 
      tmrpcm.play("six.wav");   
      soundCheck = 1;
      
    } 
    else if(soundCheck == 1){
      Serial.println("Stopping"); 
      tmrpcm.disable();
      soundCheck = 0; 
    }  
  }
  old = buttonNew;
  delay(100);
}
