#include "OrdersDriver.h"
#include "Orders.h"

// Function to test the order list by creating, manipulating, and displaying orders
void testOrdersLists()
{
    // Create an order list object to hold the orders
    orderList ordersList;

    // Creating and adding various types of orders to the list
    ordersList.addOrder(new deployOrder());
    ordersList.addOrder(new advanceOrder());
    ordersList.addOrder(new bombOrder());
    ordersList.addOrder(new blockadeOrder());
    ordersList.addOrder(new airliftOrder());
    ordersList.addOrder(new negotiateOrder());

    // Display the current orders before any modification
    std::cout << "Orders before execution:\n";
    ordersList.showAllOrders();

    // Modify the orders list by removing and moving orders
    ordersList.removeOrder(0);  // Remove the first order (DeployOrder)
    ordersList.moveOrder(2, 0); // Move BlockadeOrder from index 2 to index 0

    // Display the orders list after performing the modifications
    std::cout << "\n\nOrders after modifications (move and remove):\n";
    ordersList.showAllOrders();
}

// int main() {
//     testOrdersLists();
//     return 0;
// }
