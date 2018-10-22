#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    printf("Waiting for event\n");
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    while(digitalRead(0) == 0);
    digitalWrite(2 , HIGH);
    digitalWrite(1 , LOW);
	

    printf("Trying to connect to server\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/NourAlzoibi", "NZ" , "Motion sensor" , "LED GLOW");
  }
  /*NOTREACHED*/
  return 0 ;
}
