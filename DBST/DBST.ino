void setup() {
  pinMode(PB12,OUTPUT);
  pinMode(PB13,OUTPUT);
  pinMode(PB14,OUTPUT);
  pinMode(PB15,OUTPUT);

  pinMode(PA8,PWM);
  pinMode(PB8,PWM);
  pinMode(PB7,PWM);
  pinMode(PB6,PWM);
}

void loop() {
  motor(50,50,50,50);
}

void motor(int L1, int L2, int R2, int R1){
  L1 = L1*65535/255;
  L2 = L2*65535/255;
  R1 = R1*65535/255;
  R2 = R2*65535/255;
  if(L1 > 65535) L1 = 65535;
  if(L2 > 65535) L2 = 65535;
  if(R1 > 65535) R1 = 65535;
  if(R2 > 65535) R2 = 65535;
  if(L1 < -65535) L1 = -65535;
  if(L2 < -65535) L2 = -65535;
  if(R1 < -65535) R1 = -65535;
  if(R2 < -65535) R2 = -65535;
  
  if(L1 >= 0){
    digitalWrite(PB15,0);
    pwmWrite(PA8,L1);
  }
  else{
    digitalWrite(PB15,1);
    pwmWrite(PA8,L1+65535);
  }
  if(L2 >= 0){
    digitalWrite(PB14,0);
    pwmWrite(PB8,L2);
  }
  else{
    digitalWrite(PB14,1);
    pwmWrite(PB8,L2+65535);
  }
  if(R2 >= 0){
    digitalWrite(PB13,0);
    pwmWrite(PB7,R2);
  }
  else{
    digitalWrite(PB13,1);
    pwmWrite(PB7,R2+65535);
  }
  if(R1 >= 0){
    digitalWrite(PB12,0);
    pwmWrite(PB6,R1);
  }
  else{
    digitalWrite(PB12,1);
    pwmWrite(PB6,R1+65535);
  }
}