#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include<unistd.h>

void titleScreen() {
  printf("\x1b[42m WELCOME TO BANDERSNATCH \x1b[0m  \n");
  printf("\n");
}
void convert(char input[50]) {
//converts input in all uppercase
  for (int i = 0; i <= strlen(input); ++i) {
      input[i] = toupper(input[i]);
    }
}

void printPoolRoom(int *currentRoom) {
  printf("You fall into a deep pool of water. You are struggling to tread water\n");
  printf("You feel like you might drown; your anxiety worsens as you feel something touching your leg\n");
  (*currentRoom) = 3;
}

void printWetRoom(int* currentRoom) {
  printf("You quickly swim out the large body of water\n");
  printf("You are cold, scared, and wet.\n");
  printf("You may be hallucinating, but you see a faint light in the north distance...\n");

  (*currentRoom) = 34;
}

void printHogwartsRoom(int* currentRoom) {
  printf("You're now in the Hogwarts great hall??\n");
  printf("And you got sorted into hufflepuff?????\n");
  printf("You're definitely hallucinating\n");
  (*currentRoom) = 75;
}

void printChildBackyard(int *currentRoom) {
  printf("You're in your childhood home's backyard...\n");
  printf("You see nothing out of the ordinary; however something does not feel right.\n");
  printf("You immediatly turn around and see a dark figure slice your head off\n");
  printf("\x1b[31m YOU DIED A PAINLESS DEATH. \x1b[0m  \n");
  exit(0);
  (*currentRoom) = 8;
}

void printNarrowRoom(int r, char token[3][10], int* currentRoom) {
    printf("You end up in a narrow path, leading to a dead end.\n");
    printf("Strangely, you see a small %s", token[r]);
    (*currentRoom) = 100;
}

void printBloodRoom(char items[3][10], int r, int *currentRoom) {
  printf("You walked into the north direction, crawling into a small path in the cave.\n");
  printf("You ended up in a large, circular room. The walls are covered in blood.\n");
  printf("You are scared and slowly losing your sanity. Luckily, you see items on the ground\n");
  //printf("Pick up the: ");
  //printf("%s", items[r]);
  //printf("?");
  //printf("\n");

  (*currentRoom) = 10;
}

void printBacktoInitial(int *currentRoom) {
  printf("...\n");
  fflush(stdout);

  printf("...\n");
  fflush(stdout);
  printf("...\n");
  fflush(stdout);

  printf("\x1b[41m YOU WENT BACK TO YOUR INITAL POSITION. \x1b[0m  \n");
  printf("\n");


  (*currentRoom) = 0;
}

//mimic the pass by reference in C++
void printChildHome(int *currentRoom) {
    printf("You end up in your childhood home. The only difference is that the colors of everything in your room are...\n");
    printf("Inverted??? Black turns to White; red turns to blue\n");
    printf("Your comfort quickly turns into dread as you feel like someone watching you\n");

    (*currentRoom) = 4;
}

void printMiddleSchool(int *currentRoom) {
  printf("You stumble into your old middle school homeroom classroom??\n");
  printf("You are sitting in your old desk...\n");
  printf("It's as if you are reliving your past\n");
  printf("\n");


  (*currentRoom) = 24;
}

void passingOn(int *currentRoom, char **orderIds) {
  char YN[6];

  printf("You see your family crying over your grave\n");
  printf("You WERE dead the entire time...\n");
  printf("However, do you refuse to die?\n");
  printf("Yes or No: ");
  scanf("%s", YN);
  convert(YN);
  
  if (strcmp(YN, "YES") == 0 && strcmp(*orderIds, "Doge") == 0) {
    printf("You wake up in you bedroom with your doge sleeping happily on your lap\n");
    printf("YOU WIN");
    exit(0);
  }
  
  else if (strcmp(YN, "YES") == 0 && strcmp(*orderIds, "Balloon") == 0) {
    printf("You wake up in you bedroom with a balloon in your hands??\n");
    printf("YOU WIN");
    exit(0);
  }

  else if (strcmp(YN, "YES") == 0 && strcmp(*orderIds, "Knife") == 0) {
    printf("You wake up in you bedroom with a knife in your hands??\n");
    printf("YOU WIN");
    exit(0);
  }

  else if (strcmp(YN, "YES") == 0 && strcmp(*orderIds, "Torch") == 0) {
    printf("You wake up in you bedroom with a torch in your hands??\n");
    printf("YOU WIN");
    exit(0);
  }

  else if (strcmp(YN, "NO") == 0) {
    printf("\x1b[31m THATS TOO BAD HAHAAHAHAHAHA. \x1b[0m  \n");
    exit(0);
  } 
  else if (strcmp(YN, "YES") == 0 && orderIds == NULL){
    printf("Pick up and item to win... Transporting you back to the beginning.");
    (*currentRoom) = 0;
  }
}

void printCementary(int *currentRoom) {
  printf("You are in a cementary...\n");
  printf("A gravestone falls into your field of vision\n");
  printf("The gravestone has your name on it...\n");
  printf("Were you already dead this entire time?\n");

  (*currentRoom) = 38;
}

void printWaterFall(int *currentRoom) {
  printf("You walk north again.\n");
  printf("You end up seeing a large waterfall. The water is illuminated by dozens of bioluminescent organisms.\n");
  printf("You sit down, taking a short break as you admire the waterfall\n");

  (*currentRoom) = 11;
}


void commandList(char input[50]) {
    printf("\n");
    printf("Available Commands: GO, BAG, QUIT, DROP \n");
    printf("Enter Input: ");
    scanf("%49s",input);

    //converts to all uppercase
    convert(input);
}

void phaseNORTH(char input[50]) {
  //print command list
  commandList(input);
}


void f() {
  titleScreen();
  printf("You are currently spelunking in a cave. You are lost and scared.\n");
  printf("You must find your wiy to the exit.\n");
  //to make game run constantly
  bool run = true;

  //checking which items player has
  bool hasTorch = false;
  bool hasBalloon = false;
  bool hasKnife = false;
  bool hasItem = false;

  //setting initial room 
  int i = 0;
  int *currentRoom = &i;

  //*currentRoom = 0;

  //setting deferenced currentRoom to 0 for initial room

  char input[50];
  char items[3][10] = {"Knife", "Balloon", "Torch"};
  char token[3][10] = {"Flower", "Cat", "Doge"};

  //init random seed
  srand(time(NULL));

  int r = rand() % 3;

  //printf("%9s\n", items[r]);

  //printf("%zu\n", strlen(input));
  char **orderIds = NULL;

  while (run == true) {

    //print commandList, takes in and converts input
    commandList(input);

    if(strcmp(input, "GO") == 0) {
      char direction[10];
      printf("Which direction?\n");
      printf("Options: NORTH, WEST, SOUTH, EAST\n");
      printf("\n");
      printf("Enter Direction: ");
      scanf("%9s", direction);

      //conver:s direction to all uppercase
      convert(direction);

      if (strcmp(direction, "NORTH") == 0) {
        char y[5];

        //dereference for switch statement
        switch(*currentRoom) {

        //goes north from initial room
        case 0:
          //print out room description
          printBloodRoom(items, r, currentRoom);
          printf("Pick up the: ");
          printf("%s", items[r]);
          printf("?");
          printf("\n");
          printf("Enter YES or NO: ");
          scanf("%4s", y);
          convert(y);

          if (strcmp(y, "YES") == 0 && !hasItem) {
              //char **orderIds;
              orderIds = malloc(strlen(items[r]) * sizeof(char*));

              for(int i = 0; i < strlen(items[r]); ++i) {
                orderIds[i] = malloc((strlen(items[r]) + 1) * sizeof(char));
                strcpy(orderIds[i], &items[r][i]);
              }
              printf("You picked up a: %s\n", *orderIds);
              hasItem = true;
              printf("\n");
            }

          else if (strcmp(y, "YES") == 0 && hasItem) {
            printf("You already picked that up...\n");
          }

          else if (strcmp(y, "NO") == 0) {
            printf("You did not pick up that item\n");
          }
          break;

        //goes north again
          case 10:
            printWaterFall(currentRoom);
            break;
          
          //North from childhood room
          case 4:
            printMiddleSchool(currentRoom);
            break;
           
          case 38:
            passingOn(currentRoom, orderIds);
            break;
          //Go north from pool room
          case 3:
           printWetRoom(currentRoom); 
           break;

          case 11:
            //North from waterfall 
            printHogwartsRoom(currentRoom);
            break;
          
          //north from middle school
          case 24:
            printCementary(currentRoom);
            break;
        }
      }

      else if (strcmp(direction, "SOUTH") == 0) {

        switch(*currentRoom) {

          //goes south from initial room
          case 0:
            printNarrowRoom(r, token, currentRoom);
            //currentRoom is 100
            break;

          //goes south again
          case 100:
            //printf("Walked South again\n");
            printBacktoInitial(currentRoom);
            break;

          case 10:
              printf("You went back to your initial position.\n");

              //setting back to initial room
              (*currentRoom) = 0;
              break;

          case 11:
            printBloodRoom(items, r, currentRoom);
            break;
          
          //south from Hogwarts 
          case 75:
            printWaterFall(currentRoom);
            break;

          //going south from middle school
          case 24:
            printChildHome(currentRoom);
            break;

          case 4:
          printf("Dead End. You cannot go that way...\n");
          break;

          case 34:
          printf("You cannot turn back...\n");
          printf("\n");
          break;
        }
      }

      else if (strcmp(direction, "EAST") == 0) {
        switch(*currentRoom) {
          //went east from initial position
          case 0:
          printPoolRoom(currentRoom);
            break;
          case 3:
            //walked east again
            printf("A large sea monster with dragon-like features emerges from the water look at you in hunger...\n");
            printf("\x1b[31m YOU DIED. \x1b[0m  \n");
            exit(0);
            break;
          case 8:
            //printf("Walked west, west, and then east\n");
            printChildHome(currentRoom);
            break;
          
          //walked west, west, and then east, east
          case 4:
            printf("You went back to your initial position");
            (*currentRoom) = 0;
            break;

          case 11:
            printf("Dead End... Try another direction.\n");
            break;

          case 38:
            printf("Dead End... You must continue North.\n");
            break;

          case 24:
            printf("Dead End... You must continue North.\n");
            break;
        }
      }

      else if (strcmp(direction, "WEST") == 0) {
        switch (*currentRoom) {
          case 0:
            printChildHome(currentRoom);
            break;

          case 3:
            printf("You went back to your inital position.\n");
            break;
          case 4:
            //printf("Walked west again\n");
            printChildBackyard(currentRoom);
            break;

          case 34:
            printf("You fell into ravine...\n");
            printf("Perhaps you should try using skill next time, player\n");
            printf("\x1b[31m YOU DIED. \x1b[0m  \n");
            exit(0);
            break;

          case 10:
            printf("\x1b[31m YOU DIED FOR NO REASON IN PARTICULAR. \x1b[0m  \n");
            exit(0);
            break;

          case 38:
            printf("Dead End... You must continue North.\n");
            break;

          case 24:
            printf("Dead End... You must continue North.\n");
            break;
        }
      }
      else {
        printf("Invalid Direction Input.\n");
      }
    }
    else if(strcmp(input, "BAG") == 0) {
      if (orderIds == NULL)
        printf("Your bag is empty.\n");
      else {
        printf("Items in your bag: ");
        printf("%s", *orderIds);
      }
    }

    else if(strcmp(input, "QUIT") == 0) {
      printf("See Ya! \n");

      //so no memory leaks :))
      free(orderIds);
      run = false;
    }

    else if(strcmp(input, "DROP") == 0) {
      //so no memory leaks :))
      free(orderIds);
      orderIds = NULL;

      printf("You dropped everything in your bag.\n");
    }
    else {
      printf("Invalid Input.\n");
      printf("\n");
    }
  }
}

int main () {
  f();
}

