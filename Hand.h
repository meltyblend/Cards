// Stores and calculates attributes of a hand of cards.
#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"

class Hand {
public:
   // constructor takes 5 cards from Deck
   Hand(DeckOfCards& deck);
   
   void print() const; // display hand

   // determine if we have the given scoring hand
   bool pair() const;
   bool twoPair() const;
   bool threeOfAKind() const;
   bool fourOfAKind() const;
   bool flush() const;
   bool straight() const;

private:
   std::vector<Card> hand; // our hand
   std::vector<int> faceCount; // number of each face
}; 

#endif
