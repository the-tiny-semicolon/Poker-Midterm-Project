#include <iostream>
// #include "./include/core.h"
#define SUITS 13
#define RANKS 4
using namespace std;

void swap(int* a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}
void shuffleCards(int deck[RANKS][SUITS]) {
  srand(time(0));
  int position[52];
  int n = 52;
  int pos;

  for(int i = 0; i < n; i++) {
    position[i] = i + 1;
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 13; j++) {
      pos = rand() % n;
      deck[i][j] = position[pos];
      swap(position, pos, n - 1);
      n = n - 1;
    }
  }
}
void output(int deck[RANKS][SUITS]) {
  for(int i = 0 ; i < 4 ; i++) {
    for(int j = 0 ; j < 13 ; j++) {
      cout << deck[i][j] << "\t";
    }
    cout << endl;
  }
}
void printCardsShuffling(int deck[RANKS][SUITS], const char* suits[], const char* ranks[]) {
  for(int pos = 1; pos <= 52; pos++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) {
        if(deck[i][j] == pos) {
          cout << "(" << suits[i] << ", "<< ranks[j] << ")\n";
          break;
        }
      }
    }
  }
}
int main() {
  const char *Suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  const char *Ranks[] = {"Ace", "Two", "Three", "Four", "Five",
  "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" "King"};
  int deck[RANKS][SUITS];
  
  shuffleCards(deck);
  output(deck);

  printCardsShuffling(deck, Suits, Ranks);

  return 0;
}