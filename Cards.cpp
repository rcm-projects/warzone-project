#include "Cards.h"

//constructor
Card::Card()
{
	
}
//constructor
Card::Card(CardType type):type(type)
{

}
//destructor
Card::~Card()
{

}

CardType Card::getType() const {
    return type;
}

Card* Deck::draw(){
    if (deck.empty()) {
        std::cerr << "The deck is empty. Cannot draw a card." << std::endl;
        return nullptr;
    }
    //choose a random number from the cards in the deck
    srand(time(0));
    int randomNum = rand() % deck.size();
    //Assign the drawn card as the randomly chosen card in the deck
    tempCard = deck.at(randomNum);
    //Eliminate the drawn card from the deck
    deck.erase(deck.begin()+ randomNum);

    return tempCard;

}

void Deck:: AddCardToDeck(Card* card){
    //adds card to end of Deck
    deck.push_back(card);
}

void Hand::AddCardToHand(Card* card){
    //adds card to end of hand
    handCards.push_back(card);
}

void Hand::RemoveCardFromHand(Card* card){
    //iterate through the hand and remove the card
    auto it= std::remove_if(handCards.begin(), handCards.end(),[card] (Card* c){return c==card;});
    handCards.erase(it, handCards.end());

}

//play method
void Card::play(Hand*hand, Deck *deck){
    cout << "The card being played is: ";
    cout << CardTypeToString(this->getType()) << endl;
    //put back into deck
    deck->AddCardToDeck(this);
    //remove from the player's hand
    hand->RemoveCardFromHand(this);

}

//constructor
Deck::Deck(int CardsInDeck) {
    
    const int numTypes = 5; // The number of card types as defined in the
    int cardsPerType = CardsInDeck / numTypes; // Equal number of each type
    // Create equal amounts of each type
    for (int i = 0; i < cardsPerType; ++i) {
        deck.emplace_back(new Card(CardType::Bomb));
        deck.emplace_back(new Card(CardType::Reinforcement));
        deck.emplace_back(new Card(CardType::Blockade));
        deck.emplace_back(new Card(CardType::Airlift));
        deck.emplace_back(new Card(CardType::Diplomacy));
    }
}

//destructor
Deck::~Deck()
{
    //going through deck and deleting the cards
    for (auto& card : deck) {
        delete card; 
    }
}

//method to show cards in Deck
void Deck::ShowCardInDeck() {
    for (int i = 0; i < deck.size(); i++) {
        CardType type = deck.at(i)->getType();
        cout << CardTypeToString(type) << endl;
    }
}

//constructor
Hand::Hand(){

}

//destructor
Hand::~Hand(){

}

Hand* Hand::operator->(){
    return this;
}

//method to show cards in hand
void Hand::ShowCardInHand() {
    for (int i = 0; i < handCards.size(); i++) {
        CardType type = handCards.at(i)->getType();
        cout << CardTypeToString(type) << endl;
    }
}

vector<Card*> Hand::getHandCards() {
    return handCards;
}
