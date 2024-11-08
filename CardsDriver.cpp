#include "Cards.h"

void testCards(){
    //creates a deck of Warzone cards
    Deck* deck = new Deck;
    cout << "The cards in the deck are : " << endl;
    deck->ShowCardInDeck();
    //create a hand object that is filled by drawing cards from the deck
    Hand* hand = new Hand;
        //draw cards from the deck to create a hand
        for (int i = 0; i < 6; i++) {
            hand->AddCardToHand(deck->draw());
        }
   
    cout << "The cards in the hand are : " << endl;
    hand->ShowCardInHand();

    //iterating through cards in hand to play
    for (const auto& card : hand->getHandCards()) {
        card->play(hand, deck);
    }

    // Clean up
    delete hand;
    delete deck;
}
//int main(){
//
//    testCards();
//
//}


  
