// Do not remove the include below
#include "lab3_2.h"



#define LEFT_MD_A 22
#define LEFT_MD_B 23
#define RIGHT_MD_A 24
#define RIGHT_MD_B 25

#define LEFT_MOTOR_EN 4
#define RIGHT_MOTOR_EN 5

int init_done = false;

void setup()
{
	pinMode(LEFT_MD_A,OUTPUT);
	pinMode(LEFT_MD_B,OUTPUT);
	pinMode(RIGHT_MD_A,OUTPUT);
	pinMode(RIGHT_MD_B,OUTPUT);
	pinMode(LEFT_MOTOR_EN,OUTPUT);
	pinMode(RIGHT_MOTOR_EN,OUTPUT);

	digitalWrite(LEFT_MD_A,LOW);
	digitalWrite(LEFT_MD_B,LOW);
	digitalWrite(RIGHT_MD_A,LOW);
	digitalWrite(RIGHT_MD_B,LOW);
	digitalWrite(LEFT_MOTOR_EN,LOW);
	digitalWrite(RIGHT_MOTOR_EN,LOW);
}

void move_forward(){
	digitalWrite(LEFT_MD_A, HIGH);
	digitalWrite(LEFT_MD_B,LOW);

	digitalWrite(RIGHT_MD_A,LOW);
	digitalWrite(RIGHT_MD_B,HIGH);

	analogWrite(LEFT_MOTOR_EN,100);
	analogWrite(RIGHT_MOTOR_EN,100);
}

void move_backward(){
	digitalWrite(LEFT_MD_A, LOW);
	digitalWrite(LEFT_MD_B,HIGH);

	digitalWrite(RIGHT_MD_A,HIGH);
	digitalWrite(RIGHT_MD_B,LOW);

	analogWrite(LEFT_MOTOR_EN,100);
	analogWrite(RIGHT_MOTOR_EN,100);
}

void move_stop(){
	analogWrite(LEFT_MOTOR_EN,0);
	analogWrite(RIGHT_MOTOR_EN,0);
}

void move_right(){
	digitalWrite(LEFT_MD_A, HIGH);	//left10=forward
	digitalWrite(LEFT_MD_B,LOW);

	digitalWrite(RIGHT_MD_A,LOW);
	digitalWrite(RIGHT_MD_B,LOW);
	analogWrite(LEFT_MOTOR_EN,150);
	analogWrite(RIGHT_MOTOR_EN,0);
}

void move_left(){
	digitalWrite(LEFT_MD_A, LOW);
	digitalWrite(LEFT_MD_B,LOW);

	digitalWrite(RIGHT_MD_A,LOW);//right01=forward
	digitalWrite(RIGHT_MD_B,HIGH);
	analogWrite(LEFT_MOTOR_EN,0);
	analogWrite(RIGHT_MOTOR_EN,150);
}
void loop()
{
	if(init_done==false){
		move_forward();
		delay(2000);

		move_stop();
		delay(500);

		move_right();
		delay(1500);

		move_stop();
		delay(500);

		move_left();
		delay(1500);

		move_stop();
		delay(500);

		move_backward();
		delay(2000);

		init_done = true;
	}
	else{
		move_stop();
	}
}
