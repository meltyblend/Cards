// Member-function definitions and array initializers for the Card class.
#include "Card.h"
using namespace std;

// contents of arrays to convert index into name
const string Card::faceNames[FACES] =
   { "Ace", "Deuce", "Three", "Four", "Five", "Six", 
     "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const string Card::suitNames[SUITS] =
   { "Hearts", "Diamonds", "Clubs", "Spades" };

// Card constructor initializes face and suit
Card::Card(Face cardFace, Suit cardSuit) {
   face = cardFace;
   suit = cardSuit;
} 

// returns a string representation of a Card
string Card::toString() const {
   return faceNames[static_cast<int>(face)] + " of " + suitNames[static_cast<int>(suit)];
} 
