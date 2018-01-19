//#define Receiver_Debug

#include "CMMC_Receiver.h"


#define LED 2
#define Motor_A_Pin 15
#define Motor_B_Pin 13
#define Motor_C_Pin 12
#define Motor_D_Pin 14

void setup() {
  receriver_init();

  pinMode(LED, OUTPUT);
  pinMode(Motor_A_Pin, OUTPUT);
  pinMode(Motor_B_Pin, OUTPUT);
  pinMode(Motor_C_Pin, OUTPUT);
  pinMode(Motor_D_Pin, OUTPUT);

}

uint32_t time_now, time_prev1;

void loop() {


  time_now = millis();

  if (time_now - time_prev1 >= 20) {
    time_prev1 += 20;

#ifdef Receiver_Debug
    Serial.print(Get_ChannelValue(1)); Serial.print("\t");
    Serial.print(Get_ChannelValue(2)); Serial.print("\t");
    Serial.print(Get_ChannelValue(3)); Serial.print("\t");
    Serial.print(Get_ChannelValue(4)); Serial.println("\t");
#endif

    float tmp;
    float tmp1 = (float)Get_ChannelValue(1) * 10.23f;
    float tmp2 = (float)Get_ChannelValue(2) * 10.23f;
    float tmp3 = (float)Get_ChannelValue(3) * 10.23f;
    float tmp4 = (float)Get_ChannelValue(4) * 10.23f;

    tmp = tmp2 + (tmp1 / 2);

    if (tmp > 1023)tmp2 = 1023;
    if (tmp < 0)tmp = 0;
    analogWrite(Motor_A_Pin, tmp);

    tmp = tmp2 - (tmp1 / 2);

    if (tmp > 1023)tmp = 1023;
    if (tmp < 0)tmp = 0;
    analogWrite(Motor_B_Pin, tmp);


    tmp = tmp3 * 10.23f;
    if (tmp > 1023)tmp = 1023;
    if (tmp < 0)tmp = 0;
    analogWrite(Motor_C_Pin, tmp);

    tmp = tmp4 * 10.23f;
    if (tmp > 1023)tmp = 1023;
    if (tmp < 0)tmp = 0;
    analogWrite(Motor_D_Pin, tmp);


  }

  receriver_loop();
}
