// Class Card represents the face and suit of a card.
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
   static const size_t FACES{13}; // total number of faces
   static const size_t SUITS{4}; // total number of suits
   
   enum class Face {Ace, Deuce, Three, Four, Five, Six, Seven, Eight,
      Nine, Ten, Jack, Queen, King};
   enum class Suit {Hearts, Diamonds, Clubs, Spades};

   Card(Face cardFace, Suit cardSuit); // initialize face and suit
   std::string toString() const; // returns a string representation of a Card

   // get the card's face
   Face getFace() const {
      return face;
   } 

   // get the card's suit
   Suit getSuit() const {
      return suit;
   } 
private:
   Face face;
   Suit suit;

   static const std::string faceNames[FACES];
   static const std::string suitNames[SUITS];
}; 

#endif
