// Card shuffling and dealing program.
#include <iostream>
#include <iomanip>
#include "DeckOfCards.h"
#include "Hand.h"
using namespace std;

int main() {
   DeckOfCards myDeckOfCards;
   myDeckOfCards.shuffle();   // place Cards in random order

   Hand hand(myDeckOfCards);  // deal a hand from the deck
   cout << endl;
   hand.print();              // display hand

   // check for each type of hand by decreasing ranking
   if (hand.fourOfAKind()) {
      cout << "Hand contains four of a kind" << endl;
   }
   else if (hand.flush() && hand.straight()) {
      cout << "Hand contains a straight flush" << endl;
   }
   else if (hand.flush()) {
      cout << "Hand contains a flush" << endl;
   }
   else if (hand.straight()) {
      cout << "Hand contains a straight" << endl;
   }
   else if (hand.threeOfAKind()) {
      cout << "Hand contains three of a kind" << endl;
   }
   else if (hand.twoPair()) {
      cout << "Hand contains two pairs" << endl;
   }
   else if (hand.pair()) {
      cout << "Hand contains a pair" << endl;
   }
} 