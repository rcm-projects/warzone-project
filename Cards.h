#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Hand;
class Deck;
enum CardType { Bomb, Reinforcement, Blockade, Airlift, Diplomacy };


class Card{
public:
    Card(CardType type);
    Card();
    ~Card();
    void play(Hand* hand, Deck* deck);
    CardType getType() const;
  
protected: 
    string CardTypeToString(CardType type) const {
        switch (type) {
        case CardType::Bomb: return "Bomb";
        case CardType::Reinforcement: return "Reinforcement";
        case CardType::Blockade: return "Blockade";
        case CardType::Airlift: return "Airlift";
        case CardType::Diplomacy: return "Diplomacy";
        default: return "Unknown";
        }
    }
private:
    CardType type;
};


class Deck : public Card{
public: 
    Deck(int CardsInDeck = 30);
    ~Deck();
   Card* draw();
   void AddCardToDeck(Card* card);
   void ShowCardInDeck();
    
private:
    vector<Card*> deck;
    Card* tempCard;
};

class Hand: public Deck{

public:
    
	Hand();
	~Hand();
    Hand* operator->();
    void AddCardToHand(Card* card);
    void RemoveCardFromHand(Card* card);
    void ShowCardInHand();
    vector<Card*> getHandCards();
   
private:
    vector<Card*> handCards;
    
};
