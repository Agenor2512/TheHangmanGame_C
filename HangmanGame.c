
/*
* / Fichier : HangmanGame.c
* / Auteur : Agenor2512
* / Dernière modification : 18/01/2022
*/

/************************************************************************************/
/*                                 LIBRAIRIES                                       */
/************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*** DECLARATION DES PROTOTYPES DES FONCTIONS ***/

void gameLoop(int counter);

// Demande le mot initial au Joueur1
const char* askWord();

// Cache le mot initial
char* hidingCharacter(char const *initialWord);

// Demander au Joueur2 un caractère à entrer
char* guessCharacter();

// Compare le caractère entré avec les caractères du mot initial
void compareAndRevealCharacter(char const *initialWord, char guessedCharacter, char* hideCharacter, int* counter);

int getchar(void);
void clearInputBuffer();

// Affiche le menu et demande à l'utilisateur d'entrer son choix
void displayMenu();

// Exécute le traitement du choix effectué à partir du menu
void processChoice(int* difficultLvl);


/*
  TODO :   - Faire un dico
           - Pouvoir entrer le mot entier en guess
*/

int main(int argc, char const *argv[]) {

    displayMenu();

  return 0;
}

void gameLoop(int counter) {


  const char* initialWord = askWord();

  char* hideCharacter = hidingCharacter(initialWord);

  do {

    printf("%s\n", hideCharacter);

    char* guessedCharacter = guessCharacter();

    compareAndRevealCharacter(initialWord, *guessedCharacter, hideCharacter, &counter);

  } while(strcmp(initialWord, hideCharacter) != 0 && counter > 0);

  if (strcmp(initialWord, hideCharacter) == 0) {
    printf("You win. The word was %s. %d life remained. \n", initialWord, counter);
  }
  else {
    printf("You lose.The word was %s. \n", initialWord);
  }
}


// On renvoie un const pour que la valeur de retour ne soit pas modifiée
const char* askWord(){

  /*A la fin des fonctions, les variables (et les tableaux) sont supprimés de la mémoire mais pas les pointeurs
    Lorsqu'on définit un pointeur on doit lui allouer de l'espace mémoire à l'aide de malloc.
    En argument de malloc, on envoie l'espace souhaité à l'aide de sizeof qui renvoie le nombre d'octets nécessaires.
    Pour les tableaux, on multiplie la valeur renvoyée par sizeof par le nombre de cases désirées.
  */
  char* initialWord = malloc(100 * sizeof(char));

  printf("Please enter a word to guess : ");
  scanf("%s", initialWord);

  clearInputBuffer();

  return initialWord;

}

char* hidingCharacter(char const *initialWord) {
  char* hideCharacter = malloc((strlen(initialWord) + 1) * sizeof(char));
  int i;

  for (i = 0; i < strlen(initialWord); i++) {
    hideCharacter[i] = '*';

  }

  hideCharacter[i] = '\0';

  return hideCharacter;

}

char* guessCharacter(){
  char* guessedCharacter = malloc(sizeof(char));


  printf("Please enter a character : ");
  *guessedCharacter = getchar(); // gets() ?

  clearInputBuffer();

  return guessedCharacter;

}

void clearInputBuffer(){
  // char characterFromInputBuffer;

  while(getchar() != '\n'){

    // characterFromInputBuffer = getchar();

  }
}

void compareAndRevealCharacter(char const *initialWord, char guessedCharacter, char* hideCharacter, int* counter){
  int i, flag = 0;


  for (i = 0; i < strlen(initialWord); i++) {

    if(initialWord[i] == guessedCharacter){

      flag = 1;
      hideCharacter[i] = initialWord[i];
    }
  }

  if(flag == 0) {
    (*counter) --;
  }
}


void displayMenu(){
  int difficultLvl;

  do{

    puts("===Menu===");
    puts("1. Easy : 20 lives");
    puts("2. Medium : 10 lives");
    puts("3. Hard : 5 lives");
    puts("0. Exit");

    scanf("%d", &difficultLvl);
    clearInputBuffer();

    processChoice(&difficultLvl);


  }while(difficultLvl != 0);
}


void processChoice(int* difficultLvl){

  int isInvalidChoice;
  int counter = 0;

  do {

    isInvalidChoice = 0;

  switch (*difficultLvl) {
    case 1 :
      counter = 20;
      break;
    case 2 :
      counter = 10;
      break;
    case 3 :
      counter = 5;
      break;
    case 0 : // Exit program
      break;
    default:
      isInvalidChoice = 1;
      puts("Please enter a valid choice.");
      scanf("%d", difficultLvl);

      clearInputBuffer();
    }

  } while(isInvalidChoice);

  // difficultLvl == 1 || difficultLvl == 2 || difficultLvl == 3;

  if (*difficultLvl != 0) {
    gameLoop(counter);
  }
}
