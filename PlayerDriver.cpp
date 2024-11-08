
// PlayerDriver.cpp
#include "Player.h"

using namespace std;

// Free function
void testPlayers() {
    // Vectors to hold territory names, cards, and orders
    vector<string> territories;
    //vector<string> cards;
    Hand* playerHand = new Hand();
    vector<Order*> orders;

    // Define territories
    territories.emplace_back("Africa");
    territories.emplace_back("Europe");

    // Define cards
    //cards.emplace_back("Attack");
    //cards.emplace_back("Defense");

    // Create a player
    string playerName = "Alice";
    Player player1(playerName, territories, playerHand, orders);

    // Issue orders and display them
    player1.issueOrder("Deploy troops");
    player1.issueOrder("Secure territory");
    player1.printOrder();

    // Show attack and defend territories
    player1.toAttack();
    player1.toDefend();

    // Copy player of the first player using the copy constructor
    Player player2(player1);
    cout << endl << "Player 2 (copy) territories to attack:" << endl;
    player2.toAttack();
    cout << "Player 2 (copy) territories to defend:" << endl;
    player2.toDefend();

    // Clean up dynamically allocated orders
    for (auto order : orders) {
        delete order;
    }
}

//int main() {
//    testPlayers();
//    return 0;
//}
