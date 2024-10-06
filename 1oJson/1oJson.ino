//String myjson = "{\"ID\":\"HJ\", \"btn1\":1,\"btn2\":0, \"A0\":746, \"A1\": 146}";
const int btn1 = 7;
const int btn2 = 6;

int LedNumber = 0;
int LedStatus = -1;

int Led1= 8;
int Led2= 9;
int Led3= 10;
int Led4= 11;
int Led5= 12;
int Led6= 13;

 



const int LedS[] = { 8, 9, 10, 11 , 12, 13};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
// Serial.println(myjson);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
 
  Serial.setTimeout(20);

  for (int i = 0; i < 7; i++) {
    pinMode(LedS[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int btn1state = digitalRead(btn1);
  int btn2state = digitalRead(btn2);

  int  A0state = analogRead(A0);
  int  A1state = analogRead(A1);

  String myjson = "{\"ID\":\"HJ\", \"btn1\":" +
   String(btn1state) + ",\"btn2\":" +
   String(btn2state) + ", \"A0\":" +
   String(A0state) + ", \"A1\":" +
   String(A1state) + "}";

  Serial.println(myjson);
  delay(250);



  if ((LedNumber == 1 || LedNumber == 2 || LedNumber == 3 || LedNumber == 4 || LedNumber == 5 || LedNumber == 6) && (LedStatus == 0 || LedStatus == 1)) {
    digitalWrite(LedS[LedNumber - 1], LedStatus);
    Serial.print("LED: ");
    Serial.println(LedS[LedNumber - 1]);
    Serial.print("Status: ");
    Serial.println(LedStatus);
  }
  if ((LedNumber == 7 || LedNumber == 8 || LedNumber == 9 || LedNumber == 10) && (LedStatus == 0 || LedStatus == 1)){
    if(LedNumber==7 && LedStatus==0){
      for(int x=0; x<7; x++){
        digitalWrite(LedS[x-1],LOW);
      }

    }
    if(LedNumber==7 && LedStatus==1){
      for(int x=7; x>0; x--){
        digitalWrite(LedS[x-1],HIGH);
      }
    }
// derecha a izquierda
    if(LedNumber==8 && LedStatus==0){
      for(int x=0; x<7; x++){
        digitalWrite(LedS[x-1],HIGH);
        delay(100);
        digitalWrite(LedS[x-1],LOW);
        delay(100);
      }
    }
// izquierda -> derecha
    if(LedNumber==8 && LedStatus==1){
      for(int x=7; x>0; x--){
        digitalWrite(LedS[x-1],HIGH);
        delay(100);
        digitalWrite(LedS[x-1],LOW);
        delay(100);
      }
    }
// serial derecha a iz
    if(LedNumber==9 && LedStatus==0){
      digitalWrite(Led1, HIGH);
      delay(100);
      digitalWrite(Led2, HIGH);
          delay(100);
          digitalWrite(Led3, HIGH);
          delay(100);
          digitalWrite(Led4, HIGH);
          delay(100);
          digitalWrite(Led5, HIGH);
          delay(100);
          digitalWrite(Led6, HIGH);
          delay(100);
          digitalWrite(Led6, LOW);
          delay(100);
          digitalWrite(Led5, LOW);
          delay(100);
          digitalWrite(Led4, LOW);
          delay(100);
          digitalWrite(Led3, LOW);
          delay(100);
          digitalWrite(Led2, LOW);
          delay(100);
          digitalWrite(Led1, LOW);
          delay(100);

          digitalWrite(Led6, HIGH);
          delay(100);
          digitalWrite(Led5, HIGH);
          delay(100);
          digitalWrite(Led4, HIGH);
          delay(100);
          digitalWrite(Led3, HIGH);
          delay(100);
          digitalWrite(Led2, HIGH);
          delay(100);
          digitalWrite(Led1, HIGH);
          delay(100);
          digitalWrite(Led1, LOW);
          delay(100);
          digitalWrite(Led2, LOW);
          delay(100);
          digitalWrite(Led3, LOW);
          delay(100);
          digitalWrite(Led4, LOW);
          delay(100);
          digitalWrite(Led5, LOW);
          delay(100);
          digitalWrite(Led6, LOW);
          delay(100);
      
    }
// parpadean
    if(LedNumber==9 && LedStatus==1){
      for(int x=0; x<=5; x++){
        digitalWrite(LedS[0],HIGH);
        digitalWrite(LedS[1],HIGH);
        digitalWrite(LedS[2],HIGH);
        digitalWrite(LedS[3],HIGH);
        digitalWrite(LedS[4],HIGH);
        digitalWrite(LedS[5],HIGH);
        delay(100);
        digitalWrite(LedS[0],LOW);
        digitalWrite(LedS[1],LOW);
        digitalWrite(LedS[2],LOW);
        digitalWrite(LedS[3],LOW);
        digitalWrite(LedS[4],LOW);
        digitalWrite(LedS[5],LOW);
        delay(100);
      }
    }
// impar y par
    if(LedNumber==10 && LedStatus==0){
      for(int x=0; x<=5; x++){
        digitalWrite(LedS[0],HIGH);
        digitalWrite(LedS[2],HIGH);
        digitalWrite(LedS[4],HIGH);
        delay(600);
        digitalWrite(LedS[0],LOW);
        digitalWrite(LedS[2],LOW);
        digitalWrite(LedS[4],LOW);
        delay(600);
        digitalWrite(LedS[1],HIGH);
        digitalWrite(LedS[3],HIGH);
        digitalWrite(LedS[5],HIGH);
        delay(600);
        digitalWrite(LedS[1],LOW);
        digitalWrite(LedS[3],LOW);
        digitalWrite(LedS[5],LOW);
        delay(600);
      }
    }


    if(LedNumber==1 && LedStatus==1){
      digitalWrite(Led1,1);

    }
    if(LedNumber==1 && LedStatus==0){
      digitalWrite(Led1,0);

    }
    if(LedNumber==2 && LedStatus==1){
      digitalWrite(Led2,1);

    }
      if(LedNumber==2 && LedStatus==0){
      digitalWrite(Led2,0);

    }
        if(LedNumber==3 && LedStatus==1){
      digitalWrite(Led3,1);

    }
    if(LedNumber==3 && LedStatus==0){
      digitalWrite(Led3,0);
    }

    if(LedNumber==4 && LedStatus==1){
      digitalWrite(Led4,1);
    }
    if(LedNumber==4 && LedStatus==0){
      digitalWrite(Led4,0);
    }

    if(LedNumber==5 && LedStatus==1){
      digitalWrite(Led5,1);
    }
    if(LedNumber==5 && LedStatus==0){
      digitalWrite(Led5,0);
    }

    if(LedNumber==6 && LedStatus==1){
      digitalWrite(Led6,1);
    }
    if(LedNumber==6 && LedStatus==0){
      digitalWrite(Led6,0);
    }
  }

}

void serialEvent() {
  while (Serial.available()) {
    LedNumber = Serial.parseInt();
    LedStatus = Serial.parseInt();
    return;
  }
}