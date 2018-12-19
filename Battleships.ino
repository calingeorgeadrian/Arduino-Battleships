#include <LedControl.h>
#include <LiquidCrystal.h>

#define X_PIN1 A8
#define Y_PIN1 A9
#define X_PIN2 A0
#define Y_PIN2 A1
#define PLACING_PIN1 23
#define ROTATE_PIN1 25
#define PLACING_PIN2 22
#define ROTATE_PIN2 24
#define V0_PIN1 8
#define V0_PIN2 13
#define buzzer 9

LedControl lc1stPlayer = LedControl(16, 17, 18, 1);
LedControl lc2ndPlayer = LedControl(12, 11, 10, 1);
LiquidCrystal lcd1stPlayer(43, 45, 47, 49, 51, 53);
LiquidCrystal lcd2ndPlayer(2, 3, 4, 5, 6, 7);

byte shipsMap1stPlayer[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte hitMap1stPlayer[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte shipsMap2ndPlayer[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte hitMap2ndPlayer[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte youWon[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

byte youLost[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const byte IMAGES[][8] = {
  {
    B11111100,
    B01100110,
    B01100110,
    B01111100,
    B01100110,
    B01100110,
    B11111100,
    B00000000
  }, {
    B11111000,
    B11001100,
    B11001100,
    B11111000,
    B11001100,
    B11001101,
    B11111000,
    B00000000
  }, {
    B11110000,
    B10011000,
    B10011001,
    B11110000,
    B10011001,
    B10011011,
    B11110001,
    B00000000
  }, {
    B11100000,
    B00110000,
    B00110011,
    B11100000,
    B00110011,
    B00110110,
    B11100011,
    B00000000
  }, {
    B11000000,
    B01100000,
    B01100111,
    B11000000,
    B01100111,
    B01101100,
    B11000111,
    B00000000
  }, {
    B10000000,
    B11000000,
    B11001111,
    B10000001,
    B11001111,
    B11011001,
    B10001110,
    B00000000
  }, {
    B00000000,
    B10000000,
    B10011110,
    B00000011,
    B10011111,
    B10110011,
    B00011101,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00111100,
    B00000110,
    B00111110,
    B01100110,
    B00111011,
    B00000000
  }, {
    B00000000,
    B00000000,
    B01111000,
    B00001100,
    B01111100,
    B11001100,
    B01110110,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11110001,
    B00011000,
    B11111000,
    B10011000,
    B11101100,
    B00000000
  }, {
    B00000000,
    B00000001,
    B11100011,
    B00110001,
    B11110001,
    B00110001,
    B11011000,
    B00000000
  }, {
    B00000001,
    B00000011,
    B11000111,
    B01100011,
    B11100011,
    B01100011,
    B10110001,
    B00000000
  }, {
    B00000010,
    B00000110,
    B10001111,
    B11000110,
    B11000110,
    B11000110,
    B01100011,
    B00000000
  }, {
    B00000100,
    B00001100,
    B00011110,
    B10001100,
    B10001100,
    B10001101,
    B11000110,
    B00000000
  }, {
    B00001000,
    B00011000,
    B00111100,
    B00011000,
    B00011000,
    B00011010,
    B10001100,
    B00000000
  }, {
    B00010000,
    B00110000,
    B01111101,
    B00110000,
    B00110000,
    B00110100,
    B00011000,
    B00000000
  }, {
    B00100000,
    B01100001,
    B11111011,
    B01100001,
    B01100001,
    B01101001,
    B00110000,
    B00000000
  }, {
    B01000001,
    B11000011,
    B11110111,
    B11000011,
    B11000011,
    B11010011,
    B01100001,
    B00000000
  }, {
    B10000010,
    B10000110,
    B11101111,
    B10000110,
    B10000110,
    B10100110,
    B11000011,
    B00000000
  }, {
    B00000100,
    B00001100,
    B11011111,
    B00001100,
    B00001100,
    B01001101,
    B10000110,
    B00000000
  }, {
    B00001000,
    B00011000,
    B10111110,
    B00011000,
    B00011000,
    B10011010,
    B00001100,
    B00000000
  }, {
    B00010001,
    B00110000,
    B01111100,
    B00110000,
    B00110000,
    B00110100,
    B00011001,
    B00000000
  }, {
    B00100011,
    B01100001,
    B11111001,
    B01100001,
    B01100001,
    B01101001,
    B00110011,
    B00000000
  }, {
    B01000111,
    B11000011,
    B11110011,
    B11000011,
    B11000011,
    B11010011,
    B01100111,
    B00000000
  }, {
    B10001110,
    B10000110,
    B11100110,
    B10000110,
    B10000110,
    B10100110,
    B11001111,
    B00000000
  }, {
    B00011100,
    B00001100,
    B11001100,
    B00001100,
    B00001100,
    B01001100,
    B10011110,
    B00000000
  }, {
    B00111000,
    B00011000,
    B10011000,
    B00011001,
    B00011001,
    B10011001,
    B00111100,
    B00000000
  }, {
    B01110000,
    B00110000,
    B00110001,
    B00110011,
    B00110011,
    B00110011,
    B01111001,
    B00000000
  }, {
    B11100000,
    B01100000,
    B01100011,
    B01100110,
    B01100111,
    B01100110,
    B11110011,
    B00000000
  }, {
    B11000000,
    B11000000,
    B11000111,
    B11001100,
    B11001111,
    B11001100,
    B11100111,
    B00000000
  }, {
    B10000000,
    B10000000,
    B10001111,
    B10011001,
    B10011111,
    B10011000,
    B11001111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00011110,
    B00110011,
    B00111111,
    B00110000,
    B10011110,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00111100,
    B01100110,
    B01111110,
    B01100000,
    B00111100,
    B00000000
  }, {
    B00000000,
    B00000000,
    B01111000,
    B11001101,
    B11111100,
    B11000000,
    B01111001,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11110001,
    B10011011,
    B11111001,
    B10000000,
    B11110011,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11100011,
    B00110110,
    B11110011,
    B00000000,
    B11100111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11000111,
    B01101100,
    B11100111,
    B00000000,
    B11001111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B10001111,
    B11011000,
    B11001111,
    B00000001,
    B10011111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00011111,
    B10110000,
    B10011110,
    B00000011,
    B00111110,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00111110,
    B01100000,
    B00111100,
    B00000110,
    B01111100,
    B00000000
  }, {
    B00000001,
    B00000000,
    B01111100,
    B11000000,
    B01111000,
    B00001100,
    B11111001,
    B00000000
  }, {
    B00000011,
    B00000001,
    B11111001,
    B10000001,
    B11110001,
    B00011001,
    B11110011,
    B00000000
  }, {
    B00000111,
    B00000011,
    B11110011,
    B00000011,
    B11100011,
    B00110011,
    B11100111,
    B00000000
  }, {
    B00001110,
    B00000110,
    B11100110,
    B00000111,
    B11000110,
    B01100110,
    B11001110,
    B00000000
  }, {
    B00011100,
    B00001100,
    B11001101,
    B00001110,
    B10001100,
    B11001100,
    B10011100,
    B00000000
  }, {
    B00111000,
    B00011000,
    B10011011,
    B00011101,
    B00011001,
    B10011001,
    B00111001,
    B00000000
  }, {
    B01110000,
    B00110000,
    B00110110,
    B00111011,
    B00110011,
    B00110011,
    B01110011,
    B00000000
  }, {
    B11100000,
    B01100000,
    B01101100,
    B01110110,
    B01100110,
    B01100110,
    B11100110,
    B00000000
  }, {
    B11000000,
    B11000000,
    B11011001,
    B11101100,
    B11001100,
    B11001100,
    B11001101,
    B00000000
  }, {
    B10000001,
    B10000000,
    B10110011,
    B11011001,
    B10011001,
    B10011001,
    B10011011,
    B00000000
  }, {
    B00000011,
    B00000000,
    B01100111,
    B10110011,
    B00110011,
    B00110011,
    B00110111,
    B00000000
  }, {
    B00000110,
    B00000000,
    B11001110,
    B01100110,
    B01100110,
    B01100110,
    B01101111,
    B00000000
  }, {
    B00001100,
    B00000000,
    B10011100,
    B11001100,
    B11001100,
    B11001100,
    B11011110,
    B00000000
  }, {
    B00011000,
    B00000000,
    B00111001,
    B10011000,
    B10011000,
    B10011000,
    B10111100,
    B00000001
  }, {
    B00110000,
    B00000000,
    B01110011,
    B00110001,
    B00110001,
    B00110001,
    B01111001,
    B00000011
  }, {
    B01100000,
    B00000000,
    B11100110,
    B01100011,
    B01100011,
    B01100011,
    B11110011,
    B00000111
  }, {
    B11000000,
    B00000000,
    B11001101,
    B11000110,
    B11000110,
    B11000111,
    B11100110,
    B00001111
  }, {
    B10000000,
    B00000000,
    B10011011,
    B10001100,
    B10001100,
    B10001111,
    B11001100,
    B00011110
  }, {
    B00000000,
    B00000000,
    B00110111,
    B00011001,
    B00011001,
    B00011111,
    B10011000,
    B00111100
  }, {
    B00000000,
    B00000000,
    B01101110,
    B00110011,
    B00110011,
    B00111110,
    B00110000,
    B01111000
  }, {
    B00000000,
    B00000000,
    B11011100,
    B01100110,
    B01100110,
    B01111100,
    B01100000,
    B11110000
  }, {
    B00000000,
    B00000000,
    B10111000,
    B11001101,
    B11001100,
    B11111000,
    B11000001,
    B11100000
  }, {
    B00000000,
    B00000000,
    B01110001,
    B10011011,
    B10011001,
    B11110000,
    B10000011,
    B11000000
  }, {
    B00000000,
    B00000000,
    B11100011,
    B00110110,
    B00110011,
    B11100000,
    B00000111,
    B10000000
  }, {
    B00000000,
    B00000000,
    B11000111,
    B01101100,
    B01100111,
    B11000000,
    B00001111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B10001111,
    B11011000,
    B11001111,
    B10000001,
    B00011111,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00011111,
    B10110000,
    B10011110,
    B00000011,
    B00111110,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00111110,
    B01100000,
    B00111100,
    B00000110,
    B01111100,
    B00000000
  }, {
    B00000000,
    B00000000,
    B01111100,
    B11000000,
    B01111000,
    B00001100,
    B11111000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11111000,
    B10000000,
    B11110000,
    B00011000,
    B11110000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11110000,
    B00000000,
    B11100000,
    B00110000,
    B11100000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11100000,
    B00000000,
    B11000000,
    B01100000,
    B11000000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B11000000,
    B00000000,
    B10000000,
    B11000000,
    B10000000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B10000000,
    B00000000,
    B00000000,
    B10000000,
    B00000000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  }, {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  }, {
    B00000001,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000001,
    B00000000
  }, {
    B00000011,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000011,
    B00000000
  }, {
    B00000111,
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000011,
    B00000111,
    B00000000
  }, {
    B00001111,
    B00000110,
    B00000110,
    B00000111,
    B00000110,
    B00000110,
    B00001111,
    B00000000
  }, {
    B00011111,
    B00001100,
    B00001100,
    B00001111,
    B00001100,
    B00001100,
    B00011111,
    B00000000
  }, {
    B00111111,
    B00011001,
    B00011001,
    B00011111,
    B00011001,
    B00011001,
    B00111111,
    B00000000
  }, {
    B01111110,
    B00110011,
    B00110011,
    B00111110,
    B00110011,
    B00110011,
    B01111110,
    B00000000
  }
};

const int IMAGES_LEN = sizeof(IMAGES) / 8;

struct point {
  int x, y;
};

struct ship {
  int length;
  point* coords;
};

struct player {
  int shipsNumber;
  int shipsLeftToPlace;
  ship shipToBePlaced;
  int targetsLeft;
  ship* ships;
  bool isReady;
  bool pressedStart;
  bool wantsToRestart;
  int X_PIN;
  int Y_PIN;
  int PLACE_PIN;
  int ROTATE_PIN;
  int x_value;
  int y_value;
  int oldX;
  int oldY;
  int newX;
  int newY;
  int placeBtnState;
  int lastPlaceBtnState;
  int rotateBtnState;
  int lastRotateBtnState;
};

int imageLine1stPlayer;
int imageLine2ndPlayer;
int turn;
bool playersPressedStart;
bool gameStarted;
int period = 250;
unsigned long delay1stPlayer = 0;
unsigned long delay2ndPlayer = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

player player1, player2;
ship nava;

void initiateGame() {
  imageLine1stPlayer = 0;
  imageLine2ndPlayer = 0;
  turn = 1;
  playersPressedStart = false;
  gameStarted = false;

  // creez jucatorul
  player1.shipsNumber = 4;
  player1.shipsLeftToPlace = 4;
  player1.isReady = false;
  player1.pressedStart = false;
  player1.wantsToRestart = false;
  player1.X_PIN = X_PIN1;
  player1.Y_PIN = Y_PIN1;
  player1.PLACE_PIN = PLACING_PIN1;
  player1.ROTATE_PIN = ROTATE_PIN1;
  player1.oldX = 0;
  player1.oldY = 0;
  player1.newX = 0;
  player1.newY = 0;
  player1.placeBtnState = LOW;
  player1.lastPlaceBtnState = LOW;
  player1.rotateBtnState = LOW;
  player1.lastRotateBtnState = LOW;
  player1.targetsLeft = 4 + 3 + 2 + 2; // suma lungimilor navelor
  player1.ships = new ship[4];

  player2.shipsNumber = 4;
  player2.shipsLeftToPlace = 4;
  player2.isReady = false;
  player2.pressedStart = false;
  player2.wantsToRestart = false;
  player2.X_PIN = X_PIN2;
  player2.Y_PIN = Y_PIN2;
  player2.PLACE_PIN = PLACING_PIN2;
  player2.ROTATE_PIN = ROTATE_PIN2;
  player2.oldX = 0;
  player2.oldY = 0;
  player2.newX = 0;
  player2.newY = 0;
  player2.placeBtnState = LOW;
  player2.lastPlaceBtnState = LOW;
  player2.rotateBtnState = LOW;
  player2.lastRotateBtnState = LOW;
  player2.targetsLeft = 4 + 3 + 2 + 2; // suma lungimilor navelor
  player2.ships = new ship[4];

  // creez prima nava, cu lengtha de 4 patratele
  nava.length = 4;
  nava.coords = new point[4];
  setCoords(&nava, player1.newX, player1.newY);
  player1.ships[0] = nava;
  player2.ships[0] = nava;

  // creez a doua nava, cu lengtha de 3 patratele
  nava.length = 3;
  nava.coords = new point[3];
  setCoords(&nava, player1.newX, player1.newY);
  player1.ships[1] = nava;
  player2.ships[1] = nava;

  // creez a treia si a patra nava, ambele avand lengtha de 2 patratele
  nava.length = 2;
  nava.coords = new point[2];
  setCoords(&nava, player1.newX, player1.newY);
  player1.ships[2] = nava;
  player1.ships[3] = nava;
  player2.ships[2] = nava;
  player2.ships[3] = nava;

  // retinem prima nava ce trebuie plasata
  player1.shipToBePlaced = player1.ships[0];
  player2.shipToBePlaced = player2.ships[0];

  lcd1stPlayer.clear();
  lcd1stPlayer.setCursor(1, 0);
  lcd1stPlayer.print("Press the left");
  lcd1stPlayer.setCursor(0, 1);
  lcd1stPlayer.print("button to begin");
  lcd2ndPlayer.clear();
  lcd2ndPlayer.setCursor(1, 0);
  lcd2ndPlayer.print("Press the left");
  lcd2ndPlayer.setCursor(0, 1);
  lcd2ndPlayer.print("button to begin");
  setMatrixTo0(shipsMap1stPlayer);
  setMatrixTo0(shipsMap2ndPlayer);
  setMatrixTo0(hitMap1stPlayer);
  setMatrixTo0(hitMap2ndPlayer);
}

void setMatrixTo0(byte matrix[][8]) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      matrix[i][j] = 0;
}

// functie pentru stingerea completa a unei matrici
void clearMatrix(LedControl lc) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      lc.setLed(0, i, j, false);
}

// functie pentru aprinderea unei matrici dupa un anumit model
void printMatrix(LedControl lc, byte model[][8]) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      lc.setLed(0, i, j, model[i][j]);
}

void startGame() {
  lcd1stPlayer.clear();
  lcd1stPlayer.setCursor(0, 0);
  lcd1stPlayer.print("Place your ships");
  lcd2ndPlayer.clear();
  lcd2ndPlayer.setCursor(0, 0);
  lcd2ndPlayer.print("Place your ships");
  playersPressedStart = true;
}

void beginAttacking() {
  clearMatrix(lc1stPlayer);
  clearMatrix(lc2ndPlayer);
  player1.newX = 0;
  player1.newY = 0;
  player2.newX = 0;
  player2.newY = 0;
  lcd1stPlayer.clear();
  lcd1stPlayer.setCursor(1, 0);
  lcd1stPlayer.print("Player ");
  lcd1stPlayer.print(turn);
  lcd1stPlayer.print(" turn");
  lcd2ndPlayer.clear();
  lcd2ndPlayer.setCursor(1, 0);
  lcd2ndPlayer.print("Player ");
  lcd2ndPlayer.print(turn);
  lcd2ndPlayer.print(" turn");
  gameStarted = true;
  player1.isReady = false;
  player2.isReady = false;
}

void waitForOtherPlayer(LiquidCrystal lcd, int playerNr) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Waiting for");
  lcd.setCursor(4, 1);
  lcd.print("Player ");
  lcd.print(playerNr);
}

void gameFinished() {
  lcd1stPlayer.clear();
  lcd1stPlayer.setCursor(1, 0);
  lcd1stPlayer.print("Press the left");
  lcd1stPlayer.setCursor(0, 1);
  lcd1stPlayer.print("button to restart");
  lcd2ndPlayer.clear();
  lcd2ndPlayer.setCursor(1, 0);
  lcd2ndPlayer.print("Press the left");
  lcd2ndPlayer.setCursor(0, 1);
  lcd2ndPlayer.print("button to restart");
}

// functie pentru afisarea textului de start
void displayImage(const byte* image, LedControl lc) {
  for (int k = 0; k < 8; k++) {
    for (int j = 0; j < 8; j++) {
      lc.setLed(0, k, j, bitRead(image[k], 7 - j));
    }
  }
}

void targetHit() {
  tone(buzzer, 600);
  noTone(buzzer);
  tone(buzzer, 600);
  delay(100);
  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);
}

void victorySound() {
  tone(buzzer, 1000);
  delay(250);
  noTone(buzzer);
  delay(50);
  tone(buzzer, 600);
  delay(250);
  noTone(buzzer);
  delay(50);
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
}
/* functie ce seteaza coordonatele navei primite ca parametru,
   unde x si y sunt coordonatele capului navei */
void setCoords(ship *nav, int x, int y) {
  nav->coords[0].x = x;
  nav->coords[0].y = y;

  for (int i = 1; i < nav->length; i++) {
    nav->coords[i].x = nav->coords[i - 1].x + 1;
    nav->coords[i].y = nav->coords[i - 1].y;
  }
}

// functie pentru aprinderea navei pe matrice
void turnOnShip(ship nav, LedControl lc) {
  for (int i = 0; i < nav.length; i++)
    lc.setLed(0, nav.coords[i].x, nav.coords[i].y, true);
}

// functie pentru stingerea navei pe matrice
void turnOffShip(ship nav, byte shipsMap[][8], LedControl lc) {
  for (int i = 0; i < nav.length; i++)
    if (shipsMap[nav.coords[i].x][nav.coords[i].y] != 1)
      lc.setLed(0, nav.coords[i].x, nav.coords[i].y, false);
}

// functie pentru afisarea hartii
void printShipsMap(byte shipsMap[][8], LedControl lc) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
      if (shipsMap[i][j] == 1)
      {
        lc.setLed(0, i, j, true);
      }
    }
}

// functie pentru afisarea hartii pe care tintim
void printHitMap(byte hitMap[][8], LedControl lc) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
      if (hitMap[i][j] == 1)
      {
        lc.setLed(0, i, j, true);
      }
      if (hitMap[i][j] == 2) {
        lc.setLed(0, i, j, true);
        delay(1);
        lc.setLed(0, i, j, false);
      }
    }
}

// functie pentru citirea coordonatelor navei in functie de miscarea joystick-ului
void readJoystickCoords(player *plr) {
  plr->oldX = plr->newX;
  plr->oldY = plr->newY;
  plr->x_value = analogRead(plr->X_PIN);
  plr->y_value = analogRead(plr->Y_PIN);

  if (plr->x_value < 400)
    plr->newX--;
  else if (plr->x_value > 600)
    plr->newX++;

  if (plr->y_value < 400)
    plr->newY--;
  else if (plr->y_value > 600)
    plr->newY++;

  if (plr->newX < 0)
    plr->newX = 8 - plr->shipToBePlaced.length;
  else if (plr->newX > 8 - plr->shipToBePlaced.length)
    plr->newX = 0;

  if (plr->newY < 0)
    plr->newY = 7;
  else if (plr->newY > 7)
    plr->newY = 0;
}

// functie pentru citirea coordonatelor tintei in functie de miscarea joystick-ului
void readTargetCoords(player *plr) {
  plr->oldX = plr->newX;
  plr->oldY = plr->newY;
  plr->x_value = analogRead(plr->X_PIN);
  plr->y_value = analogRead(plr->Y_PIN);

  if (plr->x_value < 400)
    plr->newX--;
  else if (plr->x_value > 600)
    plr->newX++;

  if (plr->y_value < 400)
    plr->newY--;
  else if (plr->y_value > 600)
    plr->newY++;

  if (plr->newX < 0)
    plr->newX = 7;
  else if (plr->newX > 7)
    plr->newX = 0;

  if (plr->newY < 0)
    plr->newY = 7;
  else if (plr->newY > 7)
    plr->newY = 0;
}

// functie ce verifica daca jucatorul vrea sa inceapa jocul
void checkIfPlayerWantsToStart(player *plr) {
  int startOrNot = digitalRead(plr->PLACE_PIN);

  if (startOrNot != plr->lastPlaceBtnState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (startOrNot != plr->placeBtnState) {
      plr->placeBtnState = startOrNot;
      if (plr->placeBtnState == HIGH) {
        plr->pressedStart = true;
        clearMatrix(lc1stPlayer);
        clearMatrix(lc2ndPlayer);
      }
    }
  }
  plr->lastPlaceBtnState = startOrNot;
}

// functie ce verifica daca jucatorul vrea sa joace din nou
void checkIfPlayerWantsToRestart(player *plr) {
  int restartOrNot = digitalRead(plr->PLACE_PIN);

  if (restartOrNot != plr->lastPlaceBtnState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (restartOrNot != plr->placeBtnState) {
      plr->placeBtnState = restartOrNot;
      if (plr->placeBtnState == HIGH) {
        plr->wantsToRestart = true;
        Serial.println("Player wants to restart.");
      }
    }
  }
  plr->lastPlaceBtnState = restartOrNot;
}

/* functie ce verifica daca jucatorul doreste sa roteasca nava curenta
   si apeleaza functia de rotire in cazul apasarii butonului */
void checkPlacingButton(player *plr, byte shipsMap[][8], LiquidCrystal lcd) {
  int placeOrNot = digitalRead(plr->PLACE_PIN);

  if (placeOrNot != plr->lastPlaceBtnState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (placeOrNot != plr->placeBtnState) {
      plr->placeBtnState = placeOrNot;
      if (plr->placeBtnState == HIGH) {
        placeShip(plr, shipsMap, lcd);
      }
    }
  }

  plr->lastPlaceBtnState = placeOrNot;
}

// functie pentru plasarea navei pe harta corespunzatoare cu navele jucatorului
void placeShip(player *plr, byte shipsMap[][8], LiquidCrystal lcd) {
  int shipCanBePlaced = 0;
  ship nav = plr->shipToBePlaced;
  // verific daca nu cumva nava se intersecteaza cu alta deja plasata
  for (int i = 0; i < nav.length; i++)
    if (shipsMap[nav.coords[i].x][nav.coords[i].y] != 1) {
      shipCanBePlaced = 1;
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Place your ships");
      lcd.setCursor(0, 1);
      lcd.print("Can't place ship");
      Serial.println("Conflict.");
      shipCanBePlaced = 0;
      break;
    }

  if (shipCanBePlaced) {
    for (int i = 0; i < nav.length; i++)
      shipsMap[nav.coords[i].x][nav.coords[i].y] = 1;
    plr->shipsLeftToPlace--;
    plr->shipToBePlaced = plr->ships[4 - plr->shipsLeftToPlace];
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Place your ships");
    lcd.setCursor(2, 1);
    lcd.print("Ship placed");
    Serial.println("Ship placed.");
    Serial.print("Player ships left to place: ");
    Serial.print(plr->shipsLeftToPlace);
  }
}

/* functie ce verifica daca jucatorul doreste sa plaseze nava curenta
   si apeleaza functia de plasare in cazul apasarii butonului */
void checkRotatingButton(player *plr, LiquidCrystal lcd) {
  int rotateOrNot = digitalRead(plr->ROTATE_PIN);

  if (rotateOrNot != plr->lastRotateBtnState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (rotateOrNot != plr->rotateBtnState) {
      plr->rotateBtnState = rotateOrNot;
      if (plr->rotateBtnState == HIGH) {
        rotateShip(plr->shipToBePlaced, lcd);
      }
    }
  }
  plr->lastRotateBtnState = rotateOrNot;
}

// functie pentru rotirea navei
void rotateShip(ship &nav, LiquidCrystal lcd) {
  for (int i = 1; i < nav.length; i++) {
    int aux = nav.coords[i].y;
    nav.coords[i].y = nav.coords[i].x;
    nav.coords[i].x = aux;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Place your ships");
  lcd.setCursor(1, 1);
  lcd.print("Ship rotated");
  Serial.println("Ship rotated.");
}

// functie pentru miscarea navei pe matrice
void moveShip(player *plr, byte shipsMap[][8], LedControl lc) {
  turnOffShip(plr->shipToBePlaced, shipsMap, lc);
  setCoords(&plr->shipToBePlaced, plr->newX, plr->newY);
  turnOnShip(plr->shipToBePlaced, lc);
}

// functie pentru miscarea tintei
void moveTarget(player plr, LedControl lc) {
  lc.setLed(0, plr.oldY, plr.oldX, false);
  lc.setLed(0, plr.newY, plr.newX, true);
}

/* functie ce verifica daca jucatorul doreste sa atace oponentul
   si apeleaza functia de atac in cazul apasarii butonului */
void checkTargetButton(player *plr, byte shipsMap[][8], byte hitMap[][8], LiquidCrystal lcd, int turnNr) {
  int targetOrNot = digitalRead(plr->PLACE_PIN);

  if (targetOrNot != plr->lastPlaceBtnState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (targetOrNot != plr->placeBtnState) {
      plr->placeBtnState = targetOrNot;
      if (plr->placeBtnState == HIGH) {
        targetPosition(plr, shipsMap, hitMap, lcd);
        turn = 2 - turnNr;
        plr->newX = 0;
        plr->newY = 0;
        clearMatrix(lc1stPlayer);
        clearMatrix(lc2ndPlayer);
      }
    }
  }
  plr->lastPlaceBtnState = targetOrNot;
}

// functie pentru a ataca oponentul
void targetPosition(player *plr, byte shipsMap[][8], byte hitMap[][8], LiquidCrystal lcd) {
  int x = plr->newX;
  int y = plr->newY;
  if (shipsMap[y][x] == 1) {
    hitMap[y][x] = 1;
    shipsMap[y][x] = 0;
    plr->targetsLeft--;
    lcd.clear();
    lcd1stPlayer.setCursor(1, 0);
    lcd1stPlayer.print("Player ");
    lcd1stPlayer.print(3 - turn);
    lcd1stPlayer.print(" turn");
    lcd2ndPlayer.clear();
    lcd2ndPlayer.setCursor(1, 0);
    lcd2ndPlayer.print("Player ");
    lcd2ndPlayer.print(3 - turn);
    lcd2ndPlayer.print(" turn");
    lcd.setCursor(0, 1);
    lcd.print("Ship hit at ");
    lcd.print(y);
    lcd.print(" ");
    lcd.print(x);
    Serial.println("Ship hit!");
    targetHit();
  }
  else {
    hitMap[y][x] = 2;
    lcd.clear();
    lcd1stPlayer.setCursor(1, 0);
    lcd1stPlayer.print("Player ");
    lcd1stPlayer.print(3 - turn);
    lcd1stPlayer.print(" turn");
    lcd2ndPlayer.clear();
    lcd2ndPlayer.setCursor(1, 0);
    lcd2ndPlayer.print("Player ");
    lcd2ndPlayer.print(3 - turn);
    lcd2ndPlayer.print(" turn");
    lcd.setCursor(1, 1);
    lcd.print("Missed at ");
    lcd.print(x);
    lcd.print(" ");
    lcd.print(y);
    Serial.println("Missed!");
  }
}

void setup() {
  // initializare matrici
  lc1stPlayer.shutdown(0, false);
  lc1stPlayer.setIntensity(0, 5);
  lc1stPlayer.clearDisplay(0);
  lc2ndPlayer.shutdown(0, false);
  lc2ndPlayer.setIntensity(0, 5);
  lc2ndPlayer.clearDisplay(0);

  //initializare lcd
  lcd1stPlayer.begin(16, 2);
  lcd2ndPlayer.begin(16, 2);
  analogWrite(V0_PIN1, 100);
  analogWrite(V0_PIN2, 120);

  //initializez pinii
  pinMode(X_PIN1, INPUT);
  pinMode(Y_PIN1, INPUT);
  pinMode(X_PIN2, INPUT);
  pinMode(Y_PIN2, INPUT);
  pinMode(PLACING_PIN1, INPUT);
  pinMode(ROTATE_PIN1, INPUT);
  pinMode(PLACING_PIN2, INPUT);
  pinMode(ROTATE_PIN2, INPUT);
  pinMode(V0_PIN1, OUTPUT);
  pinMode(V0_PIN2, OUTPUT);
  Serial.begin(9600);

  initiateGame();
  Serial.print("Player 1 ships left to place:");
  Serial.print(player1.shipsLeftToPlace);
  Serial.println();
  Serial.print("Player 1 ready: ");
  Serial.print(player1.isReady);
  Serial.println();
  Serial.print("Player 2 ships left to place:");
  Serial.print(player2.shipsLeftToPlace);
  Serial.println();
  Serial.print("Player 2 ready: ");
  Serial.print(player2.isReady);
  Serial.println();
}

void loop() {
  if (millis() > delay1stPlayer + 100 && !player1.pressedStart) {
    displayImage(IMAGES[imageLine1stPlayer], lc1stPlayer);
    if (++imageLine1stPlayer >= IMAGES_LEN)
      imageLine1stPlayer = 0;
  }

  if (millis() > delay2ndPlayer + 100 && !player2.pressedStart) {
    displayImage(IMAGES[imageLine2ndPlayer], lc2ndPlayer);
    if (++imageLine2ndPlayer >= IMAGES_LEN)
      imageLine2ndPlayer = 0;
  }

  if (millis() > delay1stPlayer + period && (!player1.pressedStart || !player2.pressedStart)) {
    delay1stPlayer = millis();
    checkIfPlayerWantsToStart(&player1);
  }
  else if (player1.pressedStart && !player2.pressedStart) {
    delay1stPlayer = millis();
    waitForOtherPlayer(lcd1stPlayer, 2);
  }

  if (millis() > delay2ndPlayer + period && (!player1.pressedStart || !player2.pressedStart)) {
    delay2ndPlayer = millis();
    checkIfPlayerWantsToStart(&player2);
  }
  else if (player2.pressedStart && !player1.pressedStart) {
    delay2ndPlayer = millis();
    waitForOtherPlayer(lcd2ndPlayer, 1);
  }

  if (!playersPressedStart && player1.pressedStart && player2.pressedStart) {
    startGame();
  }

  if (millis() > delay1stPlayer + period && player1.shipsLeftToPlace > 0 && !player1.isReady && playersPressedStart) {
    delay1stPlayer = millis();
    printShipsMap(shipsMap1stPlayer, lc1stPlayer);
    checkRotatingButton(&player1, lcd1stPlayer);
    readJoystickCoords(&player1);
    moveShip(&player1, shipsMap1stPlayer, lc1stPlayer);
    checkPlacingButton(&player1, shipsMap1stPlayer, lcd1stPlayer);

    if (player1.shipsLeftToPlace == 0 && !player1.isReady) {
      waitForOtherPlayer(lcd1stPlayer, 2);
      player1.isReady = true;
    }
  }

  if (millis() > delay2ndPlayer + period && player2.shipsLeftToPlace > 0 && !player2.isReady && playersPressedStart) {
    delay2ndPlayer = millis();
    printShipsMap(shipsMap2ndPlayer, lc2ndPlayer);
    checkRotatingButton(&player2, lcd2ndPlayer);
    readJoystickCoords(&player2);
    moveShip(&player2, shipsMap2ndPlayer, lc2ndPlayer);
    checkPlacingButton(&player2, shipsMap2ndPlayer, lcd2ndPlayer);

    if (player2.shipsLeftToPlace == 0 && !player2.isReady) {
      waitForOtherPlayer(lcd2ndPlayer, 1);
      player2.isReady = true;
    }
  }

  if (!gameStarted && player1.isReady && player2.isReady) {
    beginAttacking();
  }

  if (millis() > delay1stPlayer + period && gameStarted && player1.targetsLeft > 0 && turn == 1) {
    delay1stPlayer = millis();
    printHitMap(hitMap1stPlayer, lc1stPlayer);
    printShipsMap(shipsMap2ndPlayer, lc2ndPlayer);
    readTargetCoords(&player1);
    moveTarget(player1, lc1stPlayer);
    checkTargetButton(&player1, shipsMap2ndPlayer, hitMap1stPlayer, lcd1stPlayer, 0);
  }

  if (millis() > delay2ndPlayer + period && gameStarted && player2.targetsLeft > 0 && turn == 2) {
    delay2ndPlayer = millis();
    printHitMap(hitMap2ndPlayer, lc2ndPlayer);
    printShipsMap(shipsMap1stPlayer, lc1stPlayer);
    readTargetCoords(&player2);
    moveTarget(player2, lc2ndPlayer);
    checkTargetButton(&player2, shipsMap1stPlayer, hitMap2ndPlayer, lcd2ndPlayer, 1);
  }

  if (player1.targetsLeft == 0 && player2.targetsLeft > 0 && gameStarted) {
    gameFinished();
    Serial.println("Game finished. Player 1 wins.");
    printMatrix(lc1stPlayer, youWon);
    printMatrix(lc2ndPlayer, youLost);
    victorySound();
    gameStarted = 0;
  }
  else if (player2.targetsLeft == 0 && player1.targetsLeft > 0 && gameStarted) {
    gameFinished();
    Serial.println("Game finished. Player 2 wins.");
    printMatrix(lc2ndPlayer, youWon);
    printMatrix(lc1stPlayer, youLost);
    victorySound();
    gameStarted = 0;
  }

  if (millis() > delay1stPlayer + period && (player1.targetsLeft == 0 || player2.targetsLeft == 0)) {
    delay1stPlayer = millis();
    checkIfPlayerWantsToRestart(&player1);
  }
  else if (player1.wantsToRestart && !player2.wantsToRestart) {
    delay1stPlayer = millis();
    waitForOtherPlayer(lcd1stPlayer, 2);
  }

  if (millis() > delay2ndPlayer + period && (player1.targetsLeft == 0 || player2.targetsLeft == 0)) {
    delay2ndPlayer = millis();
    checkIfPlayerWantsToRestart(&player2);
  }
  else if (player2.wantsToRestart && !player1.wantsToRestart) {
    delay2ndPlayer = millis();
    waitForOtherPlayer(lcd2ndPlayer, 1);
  }

  if (player1.wantsToRestart && player2.wantsToRestart) {
    initiateGame();
  }

}
