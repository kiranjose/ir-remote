/*
The following program uses the IRremote library and displays the 
value of the button being pressed on serial module
For "JVC remote control unit"
Author  :  Kiran Jose
Date    :  23-12-2014
*/

#include <IRremote.h>

int RECV_PIN = 12;

IRrecv irrecv(RECV_PIN);

decode_results results;
int remote = 0;
int power_switch = 0;
int tv_vcr = 0;
int auto_1 = 0;
int tracking_minus = 0;
int tracking_plus = 0;
int ffd_left = 0;
int play = 0;
int ffd_right = 0;
int stop_1 = 0;
int pause = 0;
int tvch_minus = 0;
int tvch_plus = 0;
int tvch_power = 0;
int volume_minus = 0;
int volume_plus = 0;
int tvvcr_bottom = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  //initializing values of all pins to low
  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(22, LOW);
  digitalWrite(24, LOW);
  digitalWrite(26, LOW);
  digitalWrite(28, LOW);
  digitalWrite(30, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    remote = results.value;
    switch(remote)
    {
    case -15664 : 
                if (power_switch == 0) {//main tube
                  digitalWrite(8, HIGH); 
                  power_switch = 1;
                }
                else
                {
                  digitalWrite(8, LOW);
                  power_switch = 0;
                }       
                break;
    case -15672 : 
                if (tv_vcr == 0) {//fan
                  digitalWrite(9, HIGH); 
                  tv_vcr = 1;
                }
                else
                {
                  digitalWrite(9, LOW);
                  tv_vcr = 0;
                }     
                break;
    case -15870 :
                if (auto_1 == 0) {
                  digitalWrite(3, HIGH); 
                  auto_1 = 1;
                }
                else
                {
                  digitalWrite(3, LOW);
                  auto_1 = 0;
                }   
                break;
      case -15806 :
                if (tracking_minus == 0) {
                  digitalWrite(4, HIGH); 
                  tracking_minus = 1;
                }
                else
                {
                  digitalWrite(4, LOW);
                  tracking_minus = 0;
                }   
                break;
      case -15742 :
                if (tracking_plus == 0) {
                  digitalWrite(5, HIGH); 
                  tracking_plus = 1;
                }
                else
                {
                  digitalWrite(5, LOW);
                  tracking_plus = 0;
                }   
                break;
      case -15648 :
                if (ffd_left == 0) {
                  digitalWrite(6, HIGH); 
                  ffd_left = 1;
                }
                else
                {
                  digitalWrite(6, LOW);
                  ffd_left = 0;
                }   
                break;
      case -15776 :
                if (ffd_right == 0) {
                  digitalWrite(7, HIGH); 
                  ffd_right = 1;
                }
                else
                {
                  digitalWrite(7, LOW);
                  ffd_right = 0;
                }   
                break;
      case -15824 :
                if (play == 0) {
                  digitalWrite(13, HIGH); 
                  play = 1;
                }
                else
                {
                  digitalWrite(13, LOW);
                  play = 0;
                }   
                break;
      case -15680 :
                if (stop_1 == 0) {
                  digitalWrite(2, HIGH); 
                  stop_1 = 1;
                }
                else
                {
                  digitalWrite(2, LOW);
                  stop_1 = 0;
                }   
                break;
      case -15696 :
                if (pause == 0) {
                  digitalWrite(30, HIGH); 
                  pause = 1;
                }
                else
                {
                  digitalWrite(30, LOW);
                  pause = 0;
                }   
                break;
      case -16360 :
                if (tvch_minus == 0) {
                  digitalWrite(11, HIGH); 
                  tvch_minus = 1;
                }
                else
                {
                  digitalWrite(11, LOW);
                  tvch_minus = 0;
                }   
                break;
      case -16232 :
                if (tvch_plus == 0) {
                  digitalWrite(22, HIGH); 
                  tvch_plus = 1;
                }
                else
                {
                  digitalWrite(22, LOW);
                  tvch_plus = 0;
                }   
                break;
      case -16152 :
                if (tvch_power == 0) {
                  digitalWrite(24, HIGH); 
                  tvch_power = 1;
                }
                else
                {
                  digitalWrite(24, LOW);
                  tvch_power = 0;
                }   
                break;
      case -16136 :
                if (volume_minus == 0) {
                  digitalWrite(26, HIGH); 
                  volume_minus = 1;
                }
                else
                {
                  digitalWrite(26, LOW);
                  volume_minus = 0;
                }   
                break;
      case -16264 :
                if (volume_plus == 0) {
                  digitalWrite(28, HIGH); 
                  volume_plus = 1;
                }
                else
                {
                  digitalWrite(28, LOW);
                  volume_plus = 0;
                }   
                break;
      case -16184 :
                if (tvvcr_bottom == 0) {//washroom
                  digitalWrite(10, HIGH); 
                  tvvcr_bottom = 1;
                }
                else
                {
                  digitalWrite(10, LOW);
                  tvvcr_bottom = 0;
                }   
                break;
    }
    Serial.println(remote);
    irrecv.resume(); // Receive the next value
  }
}
