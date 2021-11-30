#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* TODO : - Fonction pour demander le mot à l'utilisateur
          - Fonction cachant le mot avec des '*'
          - Fonction pour demander d'entrer un caractère à l'utilisateur
          - Fonction pour comparer les caractères jusqu'à découverte entière --> si caractère dans le mot alors afficher
                                                                             --> sinon ne rien afficher
*/

// Demande le mot initial au Joueur1
const char* askWord();

// Cache le mot initial
char* hidingCharacter(char const *initialWord);

// Demander au Joueur2 un caractère à entrer
char* guessCharacter();

// Compare le caractère entré avec les caractères du mot initial
char compareCharacter(char const *initialWord, char guessedCharacter);

int getchar(void);
void clearInputBuffer();


int main(int argc, char const *argv[]) {
  const char* initialWord = askWord();

  //printf("%s\n", initialWord);

  char* hideCharacter = hidingCharacter(initialWord);
  printf("%s\n", hideCharacter);

  char* guessedCharacter = guessCharacter();
  printf("%d\n", *guessedCharacter);

  return 0;
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
  *guessedCharacter = getchar();

  return guessedCharacter;

}

void clearInputBuffer(){
  char characterFromInputBuffer;

  while(characterFromInputBuffer != '\n'){

    characterFromInputBuffer = getchar();

  }
}
