//Variables for pin numbers

int ringSma = 11;

int ringMed = 10;

int ringBig = 9;



void setup() {

  // put your setup code here, to run once:

  pinMode(0, INPUT);

  pinMode(ringSma, OUTPUT);

  pinMode(ringMed, OUTPUT);

  pinMode(ringBig, OUTPUT);

  Serial.begin(9600);



}



void loop() {

  // put your main code here, to run repeatedly

  Serial.println(analogRead(0)); //read values of analogue input



  //conditional statement that checks whether pressure pad senses anything

  if (analogRead(0) <= 100) {

    // Inner Ring

    for (int fadeVal = 0 ; fadeVal <= 80; fadeVal += 10)

    {

      analogWrite(ringSma, fadeVal);

      delay(20);

    }

    for (int fadeVal = 80 ; fadeVal >= 0; fadeVal -= 10) {

      analogWrite(ringSma, fadeVal);

      delay(20);

      //Mid Ring

    }

    for (int fadeVal = 0 ; fadeVal <= 20; fadeVal += 5)

    {

      analogWrite(ringMed, fadeVal);

      delay(20);

    }

    for (int fadeVal = 20 ; fadeVal >= 0; fadeVal -= 5) {

      analogWrite(ringMed, fadeVal);

      delay(20);

    }

    //Outer ring

    for (int fadeVal = 0 ; fadeVal <= 10; fadeVal += 2)

    {

      analogWrite(ringBig, fadeVal);

      delay(20);

    }

    for (int fadeVal = 10 ; fadeVal >= 5; fadeVal -= 2) { //brightness of lights decrease as it moves to the outer ring

     analogWrite(ringBig, fadeVal);
     delay(70);

      

    }

  } else {

    analogWrite(11, 5);// when  sensors detcct nothing, light stays at brightness 5

    analogWrite(10, 5);

    analogWrite(9, 5);



  }

}
