//Projet - 2025/03/21
//William-Anthony Legault
//Projet_jour1
//V1.0 - Projet-Legault_WilliamAnthony
//#include <elapsedMillis.h>
#include <MOMO_RGB_Matrix.h>
#include <EEPROM.h>

#define LARGEUR 64
#define HAUTEUR 32

void dessinerPlanetes();
void initialiserPlanetes();
void dessinerPlanetes();
void deplacerPlanetes();
void ajouterPlanete();
void checkCollision();
void ajusterVitesse();


MOMO_RGB_Matrix matrix;

void initialisationDEL_BTN() {
  //registre_DEL1
  DDRG |= (1 << 2);  // DEL1 Rouge : Sortie (DDR @ 1)
  DDRG |= (1 << 1);  // DEL1 Vert : Sortie (DDR @ 1)
  DDRG |= (1 << 0);  // DEL1 Bleu : Sortie (DDR @ 1)
  //registre_DEL2
  DDRL |= (1 << 7);  // DEL2 Rouge : Sortie (DDR @ 1)
  DDRL |= (1 << 6);  // DEL2 Vert : Sortie (DDR @ 1)
  DDRL |= (1 << 5);  // DEL2 Bleu : Sortie (DDR @ 1)
  //registre_DEL3
  DDRL |= (1 << 4);  // DEL3 Rouge : Sortie (DDR @ 1)
  DDRL |= (1 << 3);  // DEL3 Vert : Sortie (DDR @ 1)
  DDRL |= (1 << 2);  // DEL3 Bleu : Sortie (DDR @ 1)

  //Bouton
  DDRC &= ~(1 << 2);  // Bouton 1 : Entree (DDR @ 0) ↑
  DDRC &= ~(1 << 7);  // Bouton 2 : Entree (DDR @ 0) ↓
  DDRC &= ~(1 << 1);  // Bouton 3 : Entree (DDR @ 0) ←
  DDRC &= ~(1 << 3);  // Bouton 4 : Entree (DDR @ 0) →
  DDRC &= ~(1 << 6);  // Bouton 5 : Entree (DDR @ 0) A
  DDRC &= ~(1 << 4);  // Bouton 6 : Entree (DDR @ 0) B
  DDRC &= ~(1 << 5);  // Bouton 7 : Entree (DDR @ 0) C

  // PullUp_Bouton
  PORTC |= (1 << 2);  // Bouton 1 : PullUp (PORT @ 1)
  PORTC |= (1 << 7);  // Bouton 2 : Entree (PORT @ 1)
  PORTC |= (1 << 1);  // Bouton 3 : Entree (PORT @ 1)
  PORTC |= (1 << 3);  // Bouton 4 : Entree (PORT @ 1)
  PORTC |= (1 << 6);  // Bouton 5 : Entree (PORT @ 1)
  PORTC |= (1 << 4);  // Bouton 6 : Entree (PORT @ 1)
  PORTC |= (1 << 5);  // Bouton 7 : Entree (PORT @ 1)
}
/*void DEL_1(unsigned char etat) {
  if (lireBTNA()) {     // Si parametre etat est a '1'
    PORTG |= (1 << 0);  // DEL1 @ '1' : Sortie (PORT @ 1)
  } else if (lireBTNB()) {
    PORTG |= (1 << 1);  // DEL1 @ '0' : Sortie (PORT @ 0)
  } else if (lireBTNC()) {
    PORTG |= (1 << 2);  // DEL1 @ '0' : Sortie (PORT @ 0)
  } else {
    PORTG &= ~(1 << 0);
    PORTG &= ~(1 << 1);
    PORTG &= ~(1 << 2);  // DEL1 @ '0' : Sortie (PORT @ 0)
  }*/
void DEL_1() {
  if (lireBTNA()) {
    DelR1_ON();
  } else {
    DelR1_OFF();
  }
  if (lireBTNB()) {
    DelV1_ON();
  } else {
    DelV1_OFF();
  }
  if (lireBTNC()) {
    DelB1_ON();
  } else {
    DelB1_OFF();
  }
}
// Controle de la DEL1
void DEL_2() {
  if (lireBTNA()) {
    DelR2_ON();
  } else {
    DelR2_OFF();
  }
  if (lireBTNB()) {
    DelV2_ON();
  } else {
    DelV2_OFF();
  }
  if (lireBTNC()) {
    DelB2_ON();
  } else {
    DelB2_OFF();
  }
}
// Controle de la DEL2
void DEL_3() {
  if (lireBTNA()) {
    DelR3_ON();
  } else {
    DelR3_OFF();
  }
  if (lireBTNB()) {
    DelV3_ON();
  } else {
    DelV3_OFF();
  }
  if (lireBTNC()) {
    DelB3_ON();
  } else {
    DelB3_OFF();
  }
}
// Controle de la DEL3

unsigned char lireBTNHaut() {
  return ((PINC & (1 << 2)) == 0);  //Verifie si la bouton H est appuyer
}
unsigned char lireBTNBas() {
  return ((PINC & (1 << 7)) == 0);  //Verifie si la bouton B est appuyer
}
unsigned char lireBTNGauche() {
  return ((PINC & (1 << 1)) == 0);  //Verifie si la bouton G est appuyer
}

unsigned char lireBTNADroite() {
  return ((PINC & (1 << 3)) == 0);  //Verifie si la bouton D est appuyer
}

unsigned char lireBTNA() {
  return ((PINC & (1 << 6)) == 0);  //Verifie si la bouton A est appuyer
}

unsigned char lireBTNB() {
  return ((PINC & (1 << 4)) == 0);  //Verifie si la bouton B est appuyer
}

unsigned char lireBTNC() {
  return ((PINC & (1 << 5)) == 0);  //Verifie si la bouton C est appuyer
}




//DEL ROUGE
unsigned char DelR1_ON() {
  PORTG |= (1 << 2);
}
unsigned char DelR1_OFF() {
  PORTG &= ~(1 << 2);
}

unsigned char DelR2_ON() {
  PORTL |= (1 << 7);
}
unsigned char DelR2_OFF() {
  PORTL &= ~(1 << 7);
}

unsigned char DelR3_ON() {
  PORTL |= (1 << 4);
}
unsigned char DelR3_OFF() {
  PORTL &= ~(1 << 4);
}
//DEL VERT
unsigned char DelV1_ON() {
  PORTG |= (1 << 1);
}
unsigned char DelV1_OFF() {
  PORTG &= ~(1 << 1);
}
unsigned char DelV2_ON() {
  PORTL |= (1 << 6);
}
unsigned char DelV2_OFF() {
  PORTL &= ~(1 << 6);
}
unsigned char DelV3_ON() {
  PORTL |= (1 << 3);
}
unsigned char DelV3_OFF() {
  PORTL &= ~(1 << 3);
}
//DEL BLEU
unsigned char DelB1_ON() {
  PORTG |= (1 << 0);
}
unsigned char DelB1_OFF() {
  PORTG &= ~(1 << 0);
}
unsigned char DelB2_ON() {
  PORTL |= (1 << 5);
}
unsigned char DelB2_OFF() {
  PORTL &= ~(1 << 5);
}
unsigned char DelB3_ON() {
  PORTL |= (1 << 2);
}
unsigned char DelB3_OFF() {
  PORTL &= ~(1 << 2);
}


volatile int InterruptEtat;
void LireChannelB() {
  DDRE &= ~(1 << 5);  // Interruption 3 : Entree (DDR @ 0)
  DDRE &= ~(1 << 3);  // Interruption 5 : Entree (DDR @ 0)


  if (PINE & (1 << 3)) {
    InterruptEtat++;
  } else {
    InterruptEtat--;
  }
}

struct Planete {
  int x, y;
  bool active;
};
Planete planetes[10];
int nbPlanetes = 10;

int xVaisseau = 5;
int yVaisseau = 15;

volatile bool gameOver = false;

int volatile meilleurScore = 0;
int volatile score = 0;

enum eEcran_possible { Frontpage,
                       Jeu,
                       Score,
                       Pause };

static eEcran_possible etat = Frontpage;
void machine_etat_Ecran() {
  //static eEcran_possible etat = Frontpage;

  switch (etat) {

    case Frontpage:
      afficherFrontpage();
      if (lireBTNA()) {
        etat = Jeu;
        initialiserPlanetes();  //Préparer les planètes
        xVaisseau = 5;
        yVaisseau = 15;
        gameOver = false;
        delay(500);
      }

      break;

    case Jeu:
      jouer();
      break;

    case Score:
      if (score > meilleurScore) {
        meilleurScore = score;
        EEPROM.put(0, meilleurScore);  //Sauvegarde dans EEPROM
      }

      afficherScore();
      if (lireBTNC()) {
        etat = Frontpage;
        score = 0;
        delay(500);
      }

      break;

    case Pause:
      afficherPause();
      if (lireBTNB()) {
        etat = Jeu;
        delay(500);
      }
      break;

    default:
      break;
  }
}

//Case Frontpage
void afficherFrontpage() {
  static int frame = 0;


static int starX = 0;
static int starY = 0;
matrix.drawPixel(starX, starY, matrix.Color888(0, 0, 0));

 starX = random(0, 64);
 starY = random(0, 32);
uint8_t brightness = random(100, 255);
    matrix.drawPixel(starX, starY, matrix.Color888(brightness, brightness, brightness));







/*
  for (int i = 0; i < 1; i++) {

    static int starX = random(0, 64);
static int starY = random(0, 32);
    matrix.drawPixel(starX, starY, matrix.Color888(0, 0, 0));
    uint8_t brightness = random(100, 255);
    matrix.drawPixel(starX, starY, matrix.Color888(brightness, brightness, brightness));

  }
  */
/*
void EffacerEtoile(){

}
*/
  //Titre du jeu
  matrix.setCursor(4, 4);
  matrix.setTextSize(1);
  matrix.setTextColor(matrix.Color888(255,frame % 255,  255));  //Varier le bleu
  matrix.print("SolarSpace");


  //Demarage du jeu
  matrix.setCursor(4, 14);
  matrix.setTextColor(matrix.Color888(0, 255, 0));  //Blanc
  matrix.print("Press A ");
}

//Case Jeu
void jouer() {
  lireBTNDeplacement();

  dessinerVaisseau();
  dessinerPlanetes();


  if (gameOver) {
    etat = Score;
  }
}

//Case Score
void afficherScore() {
  matrix.setCursor(2, 4);
  matrix.print("Score:");
  matrix.setCursor(2, 12);
  matrix.print(score);

  matrix.setCursor(2, 22);
  matrix.print("Best:");
  matrix.setCursor(2, 30);
  matrix.print(meilleurScore);
}

//Case Pause
void afficherPause() {
  matrix.setCursor(10, 10);
  matrix.print("Jeu en pause");
  matrix.setCursor(10, 20);
  matrix.print("Appuyer sur B pour reprendre");
}

void WipeScreen(){
  matrix.fillRect(0,0, matrix.width(), matrix.height(), matrix.Color888(0,0,0));
}

int volatile vitesseTimer;

//Vaisseau
void dessinerVaisseau() {
  uint16_t couleurCorps, couleurCockpit, couleurAile;


  //les couleurs changent selon la vitesse
  if (vitesseTimer >= 60000) {
    couleurCorps = matrix.Color888(0, 200, 255);      // Bleu clair
    couleurCockpit = matrix.Color888(255, 255, 255);  // Blanc
    couleurAile = matrix.Color888(100, 100, 255);     // Bleu foncé
  } else if (vitesseTimer >= 45000) {
    couleurCorps = matrix.Color888(0, 255, 0);        // Vert
    couleurCockpit = matrix.Color888(255, 255, 255);  // Blanc
    couleurAile = matrix.Color888(0, 150, 0);         // Vert foncé
  } else if (vitesseTimer >= 30000) {
    couleurCorps = matrix.Color888(255, 165, 0);      // Orange
    couleurCockpit = matrix.Color888(255, 255, 255);  // Blanc
    couleurAile = matrix.Color888(180, 100, 0);       // Marron/orange
  } else {
    couleurCorps = matrix.Color888(255, 0, 0);        // Rouge
    couleurCockpit = matrix.Color888(255, 255, 255);  // Blanc
    couleurAile = matrix.Color888(150, 0, 0);         // Rouge foncé
  }

  // Design orienté vers la droite →
  //   A C A
  //   C O C
  //   C   C
  //   A   A

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 0, couleurAile);
  matrix.drawPixel(xVaisseau + 1, yVaisseau + 0, couleurCorps);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 0, couleurAile);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 1, couleurCorps);
  matrix.drawPixel(xVaisseau + 1, yVaisseau + 1, couleurCockpit);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 1, couleurCorps);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 2, couleurCorps);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 2, couleurCorps);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 3, couleurAile);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 3, couleurAile);
}




//Effacer les pixels du vaisseau
void EffacerVaisseau() {
  uint16_t couleurCorpsN, couleurCockpitN, couleurAileN;

  if (vitesseTimer >= 60000) {
    couleurCorpsN = matrix.Color888(0, 0, 0);    // Bleu clair
    couleurCockpitN = matrix.Color888(0, 0, 0);  // Blanc
    couleurAileN = matrix.Color888(0, 0, 0);     // Bleu foncé
  } else if (vitesseTimer >= 45000) {
    couleurCorpsN = matrix.Color888(0, 0, 0);    // Vert
    couleurCockpitN = matrix.Color888(0, 0, 0);  // Blanc
    couleurAileN = matrix.Color888(0, 0, 0);     // Vert foncé
  } else if (vitesseTimer >= 30000) {
    couleurCorpsN = matrix.Color888(0, 0, 0);    // Orange
    couleurCockpitN = matrix.Color888(0, 0, 0);  // Blanc
    couleurAileN = matrix.Color888(0, 0, 0);     // Marron/orange
  } else {
    couleurCorpsN = matrix.Color888(0, 0, 0);    // Rouge
    couleurCockpitN = matrix.Color888(0, 0, 0);  // Blanc
    couleurAileN = matrix.Color888(0, 0, 0);     // Rouge foncé
  }

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 0, couleurAileN);
  matrix.drawPixel(xVaisseau + 1, yVaisseau + 0, couleurCorpsN);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 0, couleurAileN);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 1, couleurCorpsN);
  matrix.drawPixel(xVaisseau + 1, yVaisseau + 1, couleurCockpitN);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 1, couleurCorpsN);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 2, couleurCorpsN);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 2, couleurCorpsN);

  matrix.drawPixel(xVaisseau + 2, yVaisseau + 3, couleurAileN);
  matrix.drawPixel(xVaisseau + 0, yVaisseau + 3, couleurAileN);
}

void lireBTNDeplacement() {
  if (!(PINC & (1 << 2)) && yVaisseau > 0) {
    EffacerVaisseau();
    yVaisseau--;
  }  // Haut
  if (!(PINC & (1 << 7)) && yVaisseau < HAUTEUR - 2) {
    EffacerVaisseau();
    yVaisseau++;  // Bas
    if (!(PINC & (1 << 1)) && xVaisseau > 0) {
      EffacerVaisseau();
      xVaisseau--;
    }  // Gauche
    if (!(PINC & (1 << 3)) && xVaisseau < 20) {
      EffacerVaisseau();
      xVaisseau++;
    }           // Droite limitée
    delay(50);  // eviter les doubles deplacements
  }
}


  //Planete
  void initialiserPlanetes() {
    for (int i = 0; i < nbPlanetes; i++) {
      planetes[i].active = false;
    }
  }

  void EffacerPlanete(){


  }

  void dessinerPlanetes() {
    for (int i = 0; i < nbPlanetes; i++) {
      if (planetes[i].active) {
        for (int dx = 0; dx < 2; dx++) {
          for (int dy = 0; dy < 2; dy++) {
            matrix.drawPixel(planetes[i].x + dx, planetes[i].y + dy, matrix.Color888(255, 0, 0));
          }
        }
      }
    }
  }


  void deplacerPlanetes() {
    for (int i = 0; i < nbPlanetes; i++) {
      if (planetes[i].active) {
        planetes[i].x--;
        if (planetes[i].x < 0) planetes[i].active = false;
      }
    }
  }

  void ajouterPlanete() {
    for (int i = 0; i < nbPlanetes; i++) {
      if (!planetes[i].active) {
        planetes[i].x = LARGEUR - 2;
        planetes[i].y = random(0, HAUTEUR - 2);
        planetes[i].active = true;
        break;
      }
    }
  }


  //Pour le gameOver
  void checkCollision() {
    for (int i = 0; i < nbPlanetes; i++) {
      if (planetes[i].active) {
        if (planetes[i].x + 1 >= xVaisseau && planetes[i].x <= xVaisseau + 1 && planetes[i].y + 1 >= yVaisseau && planetes[i].y <= yVaisseau + 1) {
          gameOver = true;
        }
      }
    }
  }

  //animation pour le timer 3
  void initialiserTimer3() {
    cli(); // Désactiver interruptions

    TCCR3A = 0;
    TCCR3B = 0;
    TCNT3 = 0;

    OCR3A = 62500;  //Comparateur pour 100 ms (16MHz / 256 prescaler)
    TCCR3B |= (1 << WGM32);
    TCCR3B |= (1 << CS32);
    TIMSK3 |= (1 << OCIE3A);  // Autoriser interruption

    sei();  //Réactiver interruptions
  }


  void ajusterVitesse() {
    if (Score % 20 == 0 && vitesseTimer > 15000) {  //20 points = augmente difficulte
      vitesseTimer -= 5000;                         //Augmente la vitesse

      cli();
      OCR3A = vitesseTimer;
      sei();
    }
  }





  ISR(TIMER3_COMPA_vect) {
    if (!gameOver) {
      deplacerPlanetes();
      ajouterPlanete();
      checkCollision();
      score++;
    }
  }




  //test matrix
  /*
void machine_etat_Menu() {
  //Nom du jeu
  matrix.setTextSize(1);
  matrix.setTextWrap(false);
  matrix.setCursor(3, 3);
  matrix.setTextColor(matrix.Color888(255, 0, 0));
  matrix.print("Solar");
  matrix.setCursor(34, 3);
  matrix.setTextColor(matrix.Color888(255, 0, 222));
  matrix.print("Space");

  //Demarrer
  matrix.setTextColor(matrix.Color888(0, 255, 17));
  matrix.setCursor(9, 13);
  matrix.println("Demarrer");
}
*/


  //test matrix
  /*
void Matrix_Setup() {
  matrix.setTextSize(1);
  matrix.setTextWrap(false);
  matrix.setCursor(3, 10);
  matrix.setTextColor(matrix.Color888(255, 255, 255));
  matrix.print("SolarSpace");
}
*/



  void setup() {
    // put your setup code here, to run once:
    initialisationDEL_BTN();
    attachInterrupt(1, LireChannelB, RISING);
    Serial.begin(9600);
    matrix.begin();
    initialiserTimer3();
    initialiserPlanetes();


    EEPROM.get(0, meilleurScore);

    //eviter les bugs de score parce que des fois les valeurs sont parfois erronées
    if (meilleurScore < 0 || meilleurScore > 9999) {
      meilleurScore = 0;
    }
  }



  void loop() {
    // put your main code here, to run repeatedly:
    machine_etat_Ecran();


    DEL_1();
    DEL_2();
    DEL_3();

    Serial.println(InterruptEtat);
    delay(50);
  }
