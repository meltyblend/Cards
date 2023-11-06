// Member-function definitions for class DeckOfCards that simulates
// the shuffling and dealing of a deck of playing cards.
#include <random> 
#include <ctime>
#include "DeckOfCards.h" // DeckOfCards class definition
using namespace std;

default_random_engine engine(static_cast<unsigned int>(time(0)));

// DeckOfCards default constructor initializes deck
DeckOfCards::DeckOfCards() {
   currentCard = 0; // set currentCard so first Card dealt is deck[0]

   // populate deck with Card objects
   for (size_t i = 0; i < Card::FACES * Card::SUITS; ++i)
   {
      Card card(static_cast<Card::Face>(i % Card::FACES), static_cast<Card::Suit>(i / Card::FACES));
      deck.push_back(card); // adds copy of card to the end of the deck
   } 
} 

// shuffle cards in deck
void DeckOfCards::shuffle() {
   uniform_int_distribution<size_t> randomInt(0, deck.size() - 1); 

   // after shuffling, dealing should start at deck[0] again
   currentCard = 0; 

   // for each Card, pick another random Card and swap them
   for (size_t first = 0; first < deck.size(); ++first) {
      // select a random number between 0 and 51
      unsigned second = randomInt(engine);

      // swap current Card with randomly selected Card
      Card temp = deck[first];
      deck[first] = deck[second];
      deck[second] = temp;
   } 
} 

// deal cards in deck
Card DeckOfCards::dealCard() {
   return deck[currentCard++]; // return current Card in vector
} 

// Check if there are more cards in the deck
bool DeckOfCards::moreCards() const {
   return currentCard < deck.size();
} 