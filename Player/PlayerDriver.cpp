// PlayerDriver.cpp
#include "Player.h"

using namespace std;

//free funtion
void testPlayers() {
    // Vectors to hold territory names, cards, and orders
    vector<string*> territories;
    vector<string*> cards;
    vector<Order*> orders;  

    // Define territories
    string t1 = "Africa";
    string t2 = "Europe";
    territories.push_back(&t1);
    territories.push_back(&t2);

    // Define cards
    string card1 = "Attack";
    string card2 = "Defense";  
    cards.push_back(&card1);
    cards.push_back(&card2);

    // Create a player
    string playerName = "Alice";
    Player player1(&playerName, territories, cards, orders);

    // Issue orders and display them
    player1.issueOrder("Deploy troops");
    player1.issueOrder("Secure territory");
    player1.printOrder();

    // Show attack and defend territories
    player1.toAttack();
    player1.toDefend();

    // Copy player of the first player using the copy constructo
    Player player2(player1);
    cout << endl << "Player 2 (copy) territories to attack:" << endl;
    player2.toAttack();
    cout << "Player 2 (copy) territories to defend:" << endl;
    player2.toDefend();
.
}
//no manually delete f pointers =>s we are not using `new` (local)


int main() {
   
    testPlayers();

    return 0;
}


