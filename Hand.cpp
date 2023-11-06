// Stores and calculates attributes of a hand of cards.
#include <iostream>
#include "Hand.h"
using namespace std;

// constructor takes 5 cards from Deck; it assumes 5 cards are available
Hand::Hand(DeckOfCards &deck) : faceCount(Card::FACES) {
   // get hand from deck
   for (unsigned i{0}; i < 5; ++i) {
      hand.push_back(deck.dealCard());
   }

   // count number of times each face appears (for later use)
   for (unsigned i{0}; i < hand.size(); ++i) {
      ++faceCount[static_cast<int>(hand[i].getFace())];
   }
} 

// display contents of hand to standard output stream
void Hand::print() const {
  //
  // TO DO
  //
  cout << "Hand is:\n";
  for ( unsigned i{0}; i < hand.size(); ++i ){
    cout << hand[i].toString() << '\n';
  }
  cout << endl;
} 

// determine if hand contains a pair
bool Hand::pair() const {
  //
  // TO DO
  //
  for ( unsigned i{0}; i < faceCount.size(); ++i ){
    if( faceCount[i] == 2 );
    return true;
  }

  return false;
} 

// determine if hand contains two pairs
bool Hand::twoPair() const {
  //
  // TO DO
  //
  bool foundOne = false; 

  for( unsigned i{0}; i < faceCount.size(); ++i){
    if ( faceCount[i] == 2 && foundOne ){
      return true; 
    }
    else if ( faceCount[i] ==2 )
      foundOne = true;
  }
  return false;
} 

// determine if hand contains three of a kind
bool Hand::threeOfAKind() const {
  //
  // TO DO
  //
  for( unsigned i{0}; i < faceCount.size(); ++i ){
    if( faceCount[i] == 3 ){
      return true;
    }
  }
  return false;

} 

// determine if hand contains four of a kind
bool Hand::fourOfAKind() const {
  //
  // TO DO
  //
  for( unsigned i{0}; i < faceCount.size(); ++i ){
    if( faceCount[i] == 4 ){
      return true;
    } 
  }
  return false;
} 

// determine if hand contains a flush
bool Hand::flush() const { 
  //
  // TO DO
  //
  auto suit = hand[0].getSuit();

  for( auto i{1}; i < hand.size(); ++i ){
    if( hand[i].getSuit() != suit ){
      return false;
    }
  }
  return true;
} 

// determine if hand contains a straight
bool Hand::straight() const {
  //
  // TO DO
  //
  vector< int > tmp = faceCount;
  tmp.push_back(tmp[0]);

  if( tmp [0] == 1 && tmp[1] == 1 && tmp[2] == 1 && tmp[3] == 1 && tmp[4] == 1 ){
    return true;
  }
  unsigned i{1};

  while( i < tmp.size() && tmp[i] == 0 ){
    ++i;
  }

  unsigned start = i; 

  while( i < tmp.size() && tmp[i] == 1){
    ++i;
  }

  return i == start + 5;

} 