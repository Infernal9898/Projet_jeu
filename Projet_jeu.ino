//Projet - 2025/03/21
//William-Anthony Legault
//Projet_jour1
//V1.0 - Projet-Legault_WilliamAnthony


initialisationDEL_BTN(){
  //registre_DEL1
  DDRG |= (1<<0); // DEL1 Rouge : Sortie (DDR @ 1)
  DDRG |= (1<<1); // DEL1 Vert : Sortie (DDR @ 1)
  DDRG |= (1<<2); // DEL1 Bleu : Sortie (DDR @ 1)
  //registre_DEL2
  DDRL |= (1<<7); // DEL2 Rouge : Sortie (DDR @ 1)
  DDRL |= (1<<6); // DEL2 Vert : Sortie (DDR @ 1)
  DDRL |= (1<<5); // DEL2 Bleu : Sortie (DDR @ 1)
  //registre_DEL3
  DDRL |= (1<<4); // DEL3 Rouge : Sortie (DDR @ 1)
  DDRL |= (1<<3); // DEL3 Vert : Sortie (DDR @ 1)
  DDRL |= (1<<2); // DEL3 Bleu : Sortie (DDR @ 1)

//Bouton
DDRC &= ~(1<<2); // Bouton 1 : Entree (DDR @ 0) ↑
DDRC &= ~(1<<7); // Bouton 2 : Entree (DDR @ 0) ↓
DDRC &= ~(1<<1); // Bouton 3 : Entree (DDR @ 0) ←
DDRC &= ~(1<<3); // Bouton 4 : Entree (DDR @ 0) →
DDRC &= ~(1<<6); // Bouton 5 : Entree (DDR @ 0) A
DDRC &= ~(1<<4); // Bouton 6 : Entree (DDR @ 0) B
DDRC &= ~(1<<5); // Bouton 7 : Entree (DDR @ 0) C

// PullUp_Bouton
  PORTC |= (1<<2); // Bouton 1 : PullUp (PORT @ 1)
  PORTC |= (1<<7); // Bouton 2 : Entree (PORT @ 1)
  PORTC |= (1<<1); // Bouton 3 : Entree (PORT @ 1)
  PORTC |= (1<<3); // Bouton 4 : Entree (PORT @ 1)
  PORTC |= (1<<6); // Bouton 5 : Entree (PORT @ 1)
  PORTC |= (1<<4); // Bouton 6 : Entree (PORT @ 1)
  PORTC |= (1<<5); // Bouton 7 : Entree (PORT @ 1)

}



void setup() {
  // put your setup code here, to run once:
initialisationDEL_BTN();



}

void loop() {
  // put your main code here, to run repeatedly:

}
