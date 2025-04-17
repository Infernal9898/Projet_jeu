//Projet - 2025/03/21
//William-Anthony Legault
//Projet_jour1
//V1.0 - Projet-Legault_WilliamAnthony
//#include <elapsedMillis.h>
#include <MOMO_RGB_Matrix.h>

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
  return ((PINC & (1 << 2)) == 0);
}
unsigned char lireBTNBas() {
  return ((PINC & (1 << 7)) == 0);
}
unsigned char lireBTNGauche() {
  return ((PINC & (1 << 1)) == 0);
}

unsigned char lireBTNADroite() {
  return ((PINC & (1 << 3)) == 0);
}

unsigned char lireBTNA() {
  return ((PINC & (1 << 6)) == 0);
}

unsigned char lireBTNB() {
  return ((PINC & (1 << 4)) == 0);
}

unsigned char lireBTNC() {
  return ((PINC & (1 << 5)) == 0);
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
void LireChannelB(){
  DDRE &= ~(1 << 5);  // Interruption 3 : Entree (DDR @ 0)
  DDRE &= ~(1 << 3);  // Interruption 5 : Entree (DDR @ 0)


if(PINE & (1<<3)){
InterruptEtat ++;
}
else{InterruptEtat --;
}
}

enum eEcran_possible {Frontpage, Jeu, Score, Pause};
void machine_etat_Ecran(){
static eEcran_possible etat = Frontpage;

switch(etat){

case Frontpage:
if (lireBTNA())
else {
lireBTNB()}
else {
lireBTNC()}

break;

case Jeu:

if(lireBTNB())



break;

case Score:
if(lireBTNC())

break;

case Pause:
break;

default:
break;

}


}

//void machine_etat_Menu()
void machine_etat_Menu(){
//Nom du jeu
matrix.setTextSize(1);
matrix.setTextWrap(false);
matrix.setCursor(3, 3);
matrix.setTextColor(matrix.Color888(255,0,0));
matrix.print("Solar");
matrix.setCursor(34, 3);
matrix.setTextColor(matrix.Color888(255,0,222));
matrix.print("Space");

//Demarrer
matrix.setTextColor(matrix.Color888(0,255,17));
matrix.setCursor(9, 13);
matrix.println("Demarrer");
}
/*
enum eEcran_SetupVaisseau {Vaisseau ,machine_etat_deplacement};
void machine_etat_Jeu(){
  static eEcran_SetupVaisseau etat = Vaisseau;

  switch(etat){
case Vaisseau:
//if
break;

case machine_etat_deplacement:
//if
break;

default:
break;
}
}
*/

/*
enum eDeplacement_Vaisseau{dDroite, dGauche, dHaut, dBas, dFixe};
void machine_etat_deplacement(){
static eDeplacement_Vaisseau = dFixe;
switch(etat){

case dFixe:
//if
break;

case dDroite:
//if
break;

case dGauche:
//if
break;

case dHAut:
//if
break;

case dBas:
//if
break;

default:
break;
}
}
*/
/*void machine_etat_CouleurVaisseau(){

}*/
void SetupVaisseau(){
//Génération du vaisseau
}


void machine_etat_Pause(){


}





void Matrix_Setup(){
matrix.setTextSize(1);
matrix.setTextWrap(false);
matrix.setCursor(3, 10);
matrix.setTextColor(matrix.Color888(255,255,255));
matrix.print("SolarSpace");
}




void setup() {
  // put your setup code here, to run once:
  initialisationDEL_BTN();
 attachInterrupt(1,LireChannelB,RISING);
 Serial.begin(9600);
 matrix.begin();
//Matrix_Setup();
//machine_etat_Menue();
//machine_etat_Ecran();
}

void loop() {
  // put your main code here, to run repeatedly:
  DEL_1();
  DEL_2();
  DEL_3();

Serial.println(InterruptEtat);
delay(50);
}
