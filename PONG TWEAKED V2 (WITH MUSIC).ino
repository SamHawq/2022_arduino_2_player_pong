// VERSION: MENU CAUSE OVERWRITE AFTER DISPLAYED BUT OTHERWISE FULLY FUNCTIONAL, WORKING MUSIC LIBRARY | MUSIC DOES NOT LOOP
#include <TFT_eSPI.h>
#include <Automaton.h>

TFT_eSPI tft = TFT_eSPI();

//musical notes defs
#define NOTE_B0 31  
 #define NOTE_C1 33  
 #define NOTE_CS1 35  
 #define NOTE_D1 37  
 #define NOTE_DS1 39  
 #define NOTE_E1 41  
 #define NOTE_F1 44  
 #define NOTE_FS1 46  
 #define NOTE_G1 49  
 #define NOTE_GS1 52  
 #define NOTE_A1 55  
 #define NOTE_AS1 58  
 #define NOTE_B1 62  
 #define NOTE_C2 65  
 #define NOTE_CS2 69  
 #define NOTE_D2 73  
 #define NOTE_DS2 78  
 #define NOTE_E2 82  
 #define NOTE_F2 87  
 #define NOTE_FS2 93  
 #define NOTE_G2 98  
 #define NOTE_GS2 104  
 #define NOTE_A2 110  
 #define NOTE_AS2 117  
 #define NOTE_B2 123  
 #define NOTE_C3 131  
 #define NOTE_CS3 139  
 #define NOTE_D3 147  
 #define NOTE_DS3 156  
 #define NOTE_E3 165  
 #define NOTE_F3 175  
 #define NOTE_FS3 185  
 #define NOTE_G3 196  
 #define NOTE_GS3 208  
 #define NOTE_A3 220  
 #define NOTE_AS3 233  
 #define NOTE_B3 247  
 #define NOTE_C4 262  
 #define NOTE_CS4 277  
 #define NOTE_D4 294  
 #define NOTE_DS4 311  
 #define NOTE_E4 330  
 #define NOTE_F4 349  
 #define NOTE_FS4 370  
 #define NOTE_G4 392  
 #define NOTE_GS4 415  
 #define NOTE_A4 440  
 #define NOTE_AS4 466  
 #define NOTE_B4 494  
 #define NOTE_C5 523  
 #define NOTE_CS5 554  
 #define NOTE_D5 587  
 #define NOTE_DS5 622  
 #define NOTE_E5 659  
 #define NOTE_F5 698  
 #define NOTE_FS5 740  
 #define NOTE_G5 784  
 #define NOTE_GS5 831  
 #define NOTE_A5 880  
 #define NOTE_AS5 932  
 #define NOTE_B5 988  
 #define NOTE_C6 1047  
 #define NOTE_CS6 1109  
 #define NOTE_D6 1175  
 #define NOTE_DS6 1245  
 #define NOTE_E6 1319  
 #define NOTE_F6 1397  
 #define NOTE_FS6 1480  
 #define NOTE_G6 1568  
 #define NOTE_GS6 1661  
 #define NOTE_A6 1760  
 #define NOTE_AS6 1865  
 #define NOTE_B6 1976  
 #define NOTE_C7 2093  
 #define NOTE_CS7 2217  
 #define NOTE_D7 2349  
 #define NOTE_DS7 2489  
 #define NOTE_E7 2637  
 #define NOTE_F7 2794  
 #define NOTE_FS7 2960  
 #define NOTE_G7 3136  
 #define NOTE_GS7 3322  
 #define NOTE_A7 3520  
 #define NOTE_AS7 3729  
 #define NOTE_B7 3951  
 #define NOTE_C8 4186  
 #define NOTE_CS8 4435  
 #define NOTE_D8 4699  
 #define NOTE_DS8 4978  
 #define REST 0  

#define PIN_RESET 49
#define PIN_DC 48
#define PIN_CS 53
// #define DC_JUMPER 0 // OTHER PINS: MISO-50, MOSI-51, SCK-52

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

// Lucid Dreams -Juice WRLD, values
int melodyLucidDreams[] = { 
0, 587, 554, 554, 440, 440, 659, 587, 554, 554, 494, 0, 440, 554, 554, 554, 440, 440, 659, 587, 554, 554, 494, 494, 554, 554, 587, 554, 494, 494, 554, 554, 587, 554, 494, 440, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 440, 440, 494, 440, 440, 440, 440, 494, 494, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 440, 440, 494, 440, 0, 494, 440, 440, 440, 440, 440, 440, 440, 494, 440, 440, 440, 440, 494, 494, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 440, 494, 494, 440, 440, 440, 440, 440, 440, 440, 494, 440, 0, 554, 440, 440, 554, 494, 440, 440, 440, 659, 587, 587, 554, 440, 494, 494, 494, 440, 554, 587, 587, 554, 494, 554, 554, 554, 440, 370, 0, 0, 554, 440, 440, 554, 494, 440, 440, 440, 440, 440, 440, 440, 440, 494, 494, 494, 440, 0 
};
int noteDurationsLucidDreams[] = { 
240, 120, 120, 240, 240, 240, 240, 240, 240, 240, 480, 120, 120, 120, 120, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 480, 480, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 480, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 480, 120, 120, 240, 120, 120, 120, 120, 120, 240, 120, 120, 120, 120, 120, 480, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 480, 360, 120, 120, 360, 360, 120, 120, 360, 360, 120, 120, 360, 360, 120, 120, 120, 240, 360, 120, 120, 360, 360, 120, 120, 360, 120, 360, 480, 960, 360, 120, 120, 360, 360, 120, 120, 360, 360, 120, 120, 360, 360, 120, 120, 120, 240, 0 
};

// Megalovania values
int melodyMegalovania[] = { 
294, 587, 440, 415, 0, 392, 349, 349, 294, 349, 392, 0, 0, 262, 262, 587, 415, 415, 0, 392, 349, 349, 294, 349, 392, 0, 0, 233, 233, 587, 415, 0, 415, 0, 392, 349, 349, 294, 349, 392, 233, 233, 587, 415, 0, 415, 0, 392, 349, 349, 294, 349, 392, 294, 294, 587, 440, 0, 415, 0, 392, 349, 349, 294, 349, 392, 262, 262, 587, 415, 0, 415, 0, 392, 349, 349, 294, 349, 392, 0, 233, 233, 587, 415, 0, 415, 0, 392, 349, 349, 294, 349, 392, 233, 233, 587, 415, 415, 0, 392, 349, 349, 294, 349, 392, 0, 0, 587, 587, 1175, 880, 831, 0, 784, 698, 698, 587, 698, 784, 0, 0, 523, 523, 1175, 831, 831, 0, 784, 698, 698, 587, 698, 784, 0, 0, 466, 466, 1175, 831, 0, 831, 0, 784, 698, 698, 587, 698, 784, 466, 466, 1175, 831, 0, 831, 0, 784, 698, 698, 587, 698, 784, 466, 466, 1175, 831, 0, 831, 0, 784, 698, 698, 587, 523, 698, 698, 698, 698, 698, 698, 698, 587, 587, 587, 587, 587, 698, 698, 698, 0, 784, 831, 831, 784, 831, 784, 587, 698, 784, 698, 698, 698, 698, 784, 831, 831, 831, 1047, 1047, 831, 0 
};
int noteDurationsMegalovania[] = { 
120, 240, 240, 120, 120, 240, 180, 120, 120, 120, 120, 180, 120, 120, 120, 240, 240, 240, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 60, 60, 120, 120, 120, 120, 120, 240, 240, 120, 120, 240, 180, 240, 240, 240, 240, 120, 120, 120, 120, 240, 240, 240, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 240, 120, 240, 120, 120, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 120, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 120, 240, 240, 240, 240, 240, 240, 120, 120, 240, 120, 120, 120, 240, 240, 120, 120, 120, 240, 120, 120, 60, 60, 120, 120, 120, 360, 240, 120, 180, 120, 240, 120, 120, 240, 120, 120, 360, 0 
};

//Stay LAROI values
int StayMelody[] = { 
0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 262, 208, 233, 554, 554, 554, 831, 831, 523, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 523, 523, 554, 554, 831, 831, 554, 622, 622, 1047, 831, 933, 0, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 262, 208, 233, 554, 554, 554, 831, 831, 523, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 523, 523, 554, 554, 831, 831, 554, 622, 622, 1047, 831, 933, 0, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 0, 208, 0, 262, 277, 415, 0, 277, 0, 262, 277, 262, 208, 233, 554, 554, 554, 831, 831, 523, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 554, 523, 554, 554, 831, 831, 554, 523, 523, 523, 523, 523, 523, 554, 554, 523, 523, 554, 554, 831, 831, 554, 622, 622, 1047, 831, 933, 0 
};
int StayNoteDurations[] = { 
168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 504, 504, 168, 0, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 504, 504, 168, 0, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 336, 336, 168, 168, 168, 168, 336, 336, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 336, 168, 168, 168, 504, 504, 168, 0
};


int a = 0;
int b = 0;
int but = 0;
int song_select = 0;

int state = 0; // 0 = main menu, 1 = music library

  unsigned long noteStartTime = 0;
  int currentNote = 0;
  int LDcurrentNote = 0;
  int StaycurrentNote = 0;

  int melodyLength = sizeof(melodyMegalovania) / sizeof(int);
  int melodyLengthLD = sizeof(melodyLucidDreams) / sizeof(int);
  int melodyLengthStay = sizeof(StayMelody) / sizeof(int);

  int noteDuration = 0;
  int LDnoteDuration = 0;
  int StaynoteDuration = 0;

void initialize(){
  unsigned long noteStartTime = 0;
  int currentNote = 0;
  int LDcurrentNote = 0;
  int StaycurrentNote = 0;

  int melodyLength = sizeof(melodyMegalovania) / sizeof(int);
  int melodyLengthLD = sizeof(melodyLucidDreams) / sizeof(int);
  int melodyLengthStay = sizeof(StayMelody) / sizeof(int);

  int noteDuration = 0;
  int LDnoteDuration = 0;
  int StaynoteDuration = 0;
}


void setup() {
  initialize();
  a = 0;
  b = 0;
  // put your setup code here, to run once:
  Serial.println("STARTED");
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  tft.setTextSize(4);
  tft.setCursor(tft.width() + 100,tft.height()/2 - 40);
  tft.println("A1 GAMES PRESENTS:");
  tft.setCursor(tft.width() + 100,tft.height()/2);
  tft.setTextSize(5);
  tft.println("THE ALMANAC");
  delay(2500);
  tft.fillScreen(BLACK);

  pinMode(A4, INPUT); //joystick 1 y control
  pinMode(A3, INPUT); // joystick 2 y control
  pinMode(41, INPUT); // joystick 1 click control
  pinMode(39, INPUT); // joystick 2 click control
  pinMode(A0, OUTPUT);
  digitalWrite(41, HIGH);
  digitalWrite(39, HIGH);

  pinMode(11, INPUT);
  pinMode(9, INPUT);
  pinMode(7, INPUT);
  pinMode(5, INPUT);

  mainMenu();


  }


void paddle1win(){
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setCursor(30,tft.height()/2);
  tft.print("Red Paddle Wins");
}

void paddle2win(){
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setCursor(30,tft.height()/2);
  tft.print("Blue Paddle Wins");
}

void loop() {
  // put your main code here, to run repeatedly: 11 9 7

  if(song_select == 0 || song_select == 4){
    noTone(A0);
  }
  if(song_select == 1){
    LucidDreams();
    unsigned long noteStartTime = 0;
    int LDcurrentNote = 0;

    int LDnoteDuration = 0;
  }
  if(song_select == 2){
    Megalovania();
    unsigned long noteStartTime = 0;
    int currentNote = 0;

    int noteDuration = 0;
  }
  if(song_select == 3){
    Stay();
    unsigned long noteStartTime = 0;
    int StaycurrentNote = 0;

    int StaynoteDuration = 0;
  }

  if (state == 0){
    if(digitalRead(11) == HIGH){
      gameplayIntro();
      gameplay();
    }
    if(digitalRead(9) == HIGH){
      MusicLibrary();
    }
    if(digitalRead(7) == HIGH){
      controlMenu();
    }
  }
  if (state == 1){
    if(digitalRead(11) == HIGH){ //lucid dreams
      tft.fillScreen(BLACK);
      tft.setTextSize(4);
      tft.setCursor(0,tft.height()/2);
      mainMenu();
      initialize();      
      song_select = 1;
    }

    if(digitalRead(9) == HIGH){ //megalovania
      tft.fillScreen(BLACK);
      tft.setTextSize(4);
      tft.setCursor(0,tft.height()/2);
      mainMenu();
      initialize();
      song_select = 2;
    }  

    if(digitalRead(7) == HIGH){ //stay
      tft.fillScreen(BLACK);
      tft.setTextSize(4);
      tft.setCursor(0,tft.height()/2);
      mainMenu();
      initialize();
      song_select = 3;
    } 

    if(digitalRead(5) == HIGH){ // no song
      tft.fillScreen(BLACK);
      tft.setTextSize(4);
      tft.setCursor(0,tft.height()/2);
      song_select = 4;
      initialize();
      mainMenu();
    }  
  }

  if(state == 2 || state == 3 || state ==4){
    if(digitalRead(5) == HIGH){
      mainMenu();
    }  
  }
  
}

void MusicLibrary(){
//  if(but == 2){
  state = 1;
//  }

  tft.fillScreen(MAGENTA);
  tft.setCursor(0,0);
  tft.setTextSize(3);
  tft.println("MUSIC LIBRARY");

  tft.setCursor(10,40);
  tft.setTextSize(2);
  tft.println("Button 1: Lucid Dreams - Juice WRLD");

  tft.setTextSize(2);
  tft.setCursor(10, 80);
  tft.println("Button 2: Megalovania - Undertale");
  
  tft.setCursor(10,120);
  tft.setTextSize(2);
  tft.println("Button 3: Stay - The Kid LAROI and Justin Bieber");

  tft.setCursor(10,160);
  tft.setTextSize(2);
  tft.println("Button 4: No Music");

  }



void gameplayIntro(){
    state = 3;
    tft.fillScreen(BLACK);
    tft.setTextSize(5);
    tft.setCursor(24,tft.height()/2);
    tft.println("LETS PLAY PONG!");

    delay(1000);

    tft.fillScreen(BLACK);
    tft.setTextSize(50);
    tft.setCursor(tft.width()/2,tft.height()/2);
    tft.println("3");

    delay(1000);

    tft.setTextSize(50);
    tft.setCursor(tft.width()/2,tft.height()/2);
    tft.println("2");

    delay(1000);

    tft.setTextSize(50);
    tft.setCursor(tft.width()/2,tft.height()/2);
    tft.println("1");

    delay(1000);
    tft.fillScreen(BLACK);
}

void gameplay(){
    state = 4;
    int ballStart = random(1,3);
    int paddleW = 5; 
    int paddleH = 60;

    int paddle0_Y = (tft.height()/2) - (paddleH / 2);
    int paddle0_X = 2;

    int paddle1_Y = (tft.height()/2) - (paddleH/2);
    int paddle1_X = tft.width() - 3 - paddleW;
    int ball_rad = 10; // ball radius

    int ball_X = tft.width()/2;

    int ball_Y = random(1 + ball_rad, tft.height() - ball_rad);
    int ballVelocityX = 3;
    int ballVelocityY = 3;

    int paddle0Velocity = -3;
    int paddle1Velocity = 3;

    tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLUE);
    tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, RED);

    tft.setCursor(tft.width()/2 - 60,0);
    tft.print(b);
    tft.print("-");
    tft.print(a);
    // Actually   draw everything on the screen:
    delay(25);  // Delay   for visibility

    while(((ball_X - ball_rad) > 1 && ((ball_X + ball_rad) < tft.width() - 2))){
      int aa = analogRead(A4);
      int bb = analogRead(A3);

      tft.fillCircle(ball_X, ball_Y, ball_rad, BLACK);

      if(ballStart == 1){
        ball_X += ballVelocityX;
      }

      if(ballStart == 2){
        ball_X -= ballVelocityX;
      }
      
      
      ball_Y += ballVelocityY;

      tft.fillCircle(ball_X, ball_Y, ball_rad, YELLOW);

      if(aa > 550){
        tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLACK);
        paddle0_Y--;

        paddle0_Y--;
        tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLUE);
      }
    
      if(aa < 475){
        tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLACK);
        paddle0_Y++;

        paddle0_Y++;
        tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLUE);
      }

      if(bb > 550){
        tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, BLACK);
        paddle1_Y++;

        paddle1_Y++;
        tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, RED);
      }

      if(bb < 475){
        tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, BLACK);
        paddle1_Y--;

        paddle1_Y--;
        tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, RED);
      }

      if(ball_X - ball_rad < paddle0_X + paddleW){
        // Check if ball is   within paddle's height
        if((ball_Y > paddle0_Y) && (ball_Y < paddle0_Y   + paddleH)){
          tone(A0, 587, 200);
          tft.fillCircle(ball_X, ball_Y, ball_rad, BLACK);
          ball_X++;  // Move ball over one to the right
          tft.fillCircle(ball_X, ball_Y, ball_rad, YELLOW);
          ballVelocityX = -ballVelocityX; // Change velocity
        }
      }
      // Check if the ball hit the right paddle
      if(ball_X + ball_rad > paddle1_X){
        // Check if ball is within paddle's height
        if ((ball_Y >   paddle1_Y) && (ball_Y < paddle1_Y + paddleH)){
          tone(A0, 587, 200);
          tft.fillCircle(ball_X, ball_Y, ball_rad, BLACK);
          ball_X--;  //   Move ball over one to the left
          tft.fillCircle(ball_X, ball_Y, ball_rad, YELLOW);
          ballVelocityX = -ballVelocityX; // change   velocity
        }
      }
      // Check if the ball hit the top or bottom   
      if((ball_Y <= ball_rad) || (ball_Y >= (tft.height() - ball_rad - 1))){
        // Change up/down velocity direction
        ballVelocityY = -ballVelocityY;
      }
      // Move the paddles up and down
      // Change paddle 0's direction   if it hit top/bottom
      if((paddle0_Y <= 1) || (paddle0_Y > tft.height()   - 2 - paddleH)){
        paddle0Velocity = -paddle0Velocity;
      }
      // Change paddle 1's direction if it hit top/bottom
      if ((paddle1_Y <=   1) || (paddle1_Y > tft.height() - 2 - paddleH)){
        paddle1Velocity   = -paddle1Velocity;
      }
    
    
    // Draw the center line
    tft.fillRect(tft.width()/2 - 1, 0, 2, tft.height(), WHITE);
    
    // Draw the ball:
    } 

    if(ball_X + ball_rad < tft.width() - 2){
      a+=1;
      tft.fillCircle(ball_X, ball_Y, ball_rad, BLACK);
      tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLACK);
      tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, BLACK);
      if(a == 7){
        paddle1win();
        delay(1500);        
        tft.fillScreen(BLACK);
        tft.setTextSize(4);
        tft.setCursor(0,tft.height()/2);
        mainMenu();
      }
      else{
        gameplay();
      }
      
    }else{
      b+=1;
      tft.fillCircle(ball_X, ball_Y, ball_rad, BLACK);
      tft.fillRect(paddle0_X, paddle0_Y, paddleW, paddleH, BLACK);
      tft.fillRect(paddle1_X, paddle1_Y, paddleW, paddleH, BLACK);
      if(b == 7){
        paddle2win();
        delay(1500);
        tft.fillScreen(BLACK);
        tft.setTextSize(4);
        tft.setCursor(0,tft.height()/2);
        mainMenu();
      }
      else{
        gameplay();
      }
    }
  
}

void controlMenu(){
  state = 2;
  tft.fillScreen(BLACK);
  tft.setCursor(0,0);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("CONTROL MENU");

  tft.setTextSize(3);
  tft.setTextColor(MAGENTA);
  tft.println("IN GAME");
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.println("Left Joystick");
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("Flick Up/Down: Blue paddle move up/down");
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.println("Right Joystick");
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("Flick Up/Down: Red paddle move up/down");

  tft.setTextSize(3);
  tft.println("");
  tft.setTextColor(MAGENTA);
  tft.println("From Home Menu");
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print("Button 1:");
  tft.setTextColor(WHITE);
  tft.println("Start New Game");

  tft.setTextColor(YELLOW);
  tft.print("Button 2:");
  tft.setTextColor(WHITE);
  tft.println("Music Library");

  tft.setTextColor(YELLOW);
  tft.print("Button 3:");
  tft.setTextColor(WHITE);
  tft.println("Control Menu");

  tft.setTextSize(3);
  tft.println("");
  tft.setTextColor(MAGENTA);
  tft.println("From Any MENU");
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print("Button 4:");
  tft.setTextColor(WHITE);
  tft.println("Home Menu");

}

void mainMenu(){
  tft.fillScreen(BLACK);
  tft.setTextSize(5);
  tft.setCursor(30,tft.height()/2);
  state = 0;
  a = 0;
  b = 0;
  tft.println("1:PLAY GAME");
  tft.println(" 2:MUSIC LIBRARY");
  tft.println(" 3:CONTROL MENU");
  //loop();
}

void LucidDreams(){
  if(LDcurrentNote < melodyLengthLD){
    LDnoteDuration = noteDurationsLucidDreams[LDcurrentNote];
    if(millis() - noteStartTime >= LDnoteDuration){
      noTone(A0);
      LDcurrentNote++;
      noteStartTime = millis();
    }else{
      tone(A0, melodyLucidDreams[LDcurrentNote], LDnoteDuration * 0.7);
    }
  }
}

void Megalovania(){
  if(currentNote < melodyLength){
    noteDuration = noteDurationsMegalovania[currentNote];
    if(millis() - noteStartTime >= noteDuration){
      noTone(A0);
      currentNote++;
      noteStartTime = millis();
    }else{
      tone(A0, melodyMegalovania[currentNote], noteDuration * 0.7);
    }
  }
}

void Stay(){
  if(StaycurrentNote < melodyLengthStay){
    StaynoteDuration = StayNoteDurations[StaycurrentNote];
    if(millis() - noteStartTime >= StaynoteDuration){
      noTone(A0);
      StaycurrentNote++;
      noteStartTime = millis();
    }else{
      tone(A0, StayMelody[StaycurrentNote], StaynoteDuration * 0.7);
    }
  }
}

void MusicOff(){
  noTone(A0);
}


