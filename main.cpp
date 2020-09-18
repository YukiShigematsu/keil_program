#include "mbed.h"
#include "adrobo.h"
#include "Motor.h"

BusOut led(LED1,LED2,LED3,LED4,LED5,LED);
Motor motor1(MOTOR11, MOTOR12);
AnalogIn ad[] = {AD1, AD3};
BusIn sw(SW1, SW2);

int main() {
  float value1, value2, value3, value4;
	sw.mode(PullUp);
	
	led = 0x1;
	
	while(1) {
    while(1) {
      value1 = ad[0].read();
	  	wait(0.1);
	  	printf("1:%f\r\n", value1);
      wait(0.1);
  	  if (value1 >= 0.73) {
			  break;
		  }
	  }
		
	  while (1) {
		  motor1 = 1;
    	value2 = ad[1].read();
  	  printf("2:%f\r\n", value2);
			printf("3:%f\r\n", value3);
			value4 = value2 - value3;
			printf("4:%f\r\n", value4);
	    if (value2 >= 0.005 || (value2 >= 0.003 && value3 == value2) || (value2 >= 0.003 && value4 <= 0.0002)) {
			  break;
		  }
			wait (0.3);
			led = 0x1;
			wait (0.3);
			led = 0x2;
			wait (0.3);
			led = 0x4;
			wait (0.3);
			led = 0x8;
			wait (0.3);
			led = 0x10;
			value3 = value2;
	  }
		
	//	led = 0x7f;
		
  	while (1) {
	  	motor1 = 0;
		  if (sw  == 1) {
			  break;
		  }
	  }
		
  	while (1) {
		  motor1 = -1;
	  	value2 = ad[1].read();
  		printf("2:%f\r\n", value2);
	  	if (value2 <= 0.0015) {
  			wait (5.0);
			  break;
		  }
			wait (0.3);
			led = 0x10;
			wait (0.3);
			led = 0x8;
			wait (0.3);
			led = 0x4;
			wait (0.3);
			led = 0x2;
			wait (0.3);
			led = 0x1;
	  }
  	motor1 = 0;
  }
}