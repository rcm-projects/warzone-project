#include "Orders.h"

// Order class methods

// Constructor: Initializes effect, executed, and name with default values using dynamic memory allocation
Order::Order() : effect(new std::string), executed(new bool(false)), name(new std::string) {}

// Destructor: Deletes dynamically allocated members to prevent memory leaks
Order::~Order()
{
    delete effect;
    delete executed;
    delete name;
}

// Copy constructor: Performs deep copy of effect, executed, and name to handle dynamic memory
Order::Order(const Order &other)
{
    effect = new std::string(*other.effect); // Copy effect string
    executed = new bool(*other.executed);    // Copy executed status
    name = new std::string(*other.name);     // Copy name string
}

// Assignment operator: Handles deep copy of dynamically allocated members
Order &Order::operator=(const Order &other)
{
    if (this == &other)
        return *this; // Return *this if self-assignment

    // Clean up existing dynamic memory
    delete effect;
    delete executed;
    delete name;

    // Deep copy the other order's data
    effect = new std::string(*other.effect);
    executed = new bool(*other.executed);
    name = new std::string(*other.name);

    return *this;
}

// Base validation method: By default, all orders are valid (can be overridden in subclasses)
bool Order::validate() const
{
    return true;
}

// Base execution method: Executes the order if valid, and sets its effect and executed status
void Order::execute()
{
    if (validate())
    {
        *effect = "Base order executed"; // Sets default effect message
        *executed = true;                // Marks the order as executed
    }
}

// Returns a string description of the order, including its name and execution status
std::string Order::toString() const
{
    if (*executed && !name->empty())
    {
        return "Order: " + *name + " is executed\n";
    }
    else if (!*executed && !name->empty())
    {
        return "Order: " + *name + " is not executed\n";
    }
    else
    {
        return "Order: Null\n";
    }
}

// Stream insertion operator: Outputs the order's name, execution status, and effect
std::ostream &operator<<(std::ostream &os, const Order &order)
{
    os << "Order: " << *order.name << (*order.executed ? " (Executed)" : " (Not executed)") << "\n";
    os << "Effect: " << *order.effect << "\n";
    return os;
}

// Subclass implementations

// deployOrder constructor: Initializes order name
deployOrder::deployOrder()
{
    *name = "deployOrder";
}

// validate method for deployOrder: Always returns true (valid)
bool deployOrder::validate() const
{
    return true;
}

// execute method for deployOrder: Sets the effect and marks the order as executed
void deployOrder::execute()
{
    if (validate())
    {
        *effect = "Deploy troops";
        *executed = true;
    }
}

// advanceOrder constructor: Initializes order name
advanceOrder::advanceOrder()
{
    *name = "Advance Order";
}

// validate method for advanceOrder: Always returns true (valid)
bool advanceOrder::validate() const
{
    return true;
}

// execute method for advanceOrder: Sets the effect and marks the order as executed
void advanceOrder::execute()
{
    if (validate())
    {
        *effect = "Advance troops";
        *executed = true;
    }
}

// bombOrder constructor: Initializes order name
bombOrder::bombOrder()
{
    *name = "Bomb Order";
}

// validate method for bombOrder: Always returns true (valid)
bool bombOrder::validate() const
{
    return true;
}

// execute method for bombOrder: Sets the effect and marks the order as executed
void bombOrder::execute()
{
    if (validate())
    {
        *effect = "Bomb troops";
        *executed = true;
    }
}

// blockadeOrder constructor: Initializes order name
blockadeOrder::blockadeOrder()
{
    *name = "Blockade Order";
}

// validate method for blockadeOrder: Always returns true (valid)
bool blockadeOrder::validate() const
{
    return true;
}

// execute method for blockadeOrder: Sets the effect and marks the order as executed
void blockadeOrder::execute()
{
    if (validate())
    {
        *effect = "Blockade troops";
        *executed = true;
    }
}

// airliftOrder constructor: Initializes order name
airliftOrder::airliftOrder()
{
    *name = "Airlift Order";
}

// validate method for airliftOrder: Always returns true (valid)
bool airliftOrder::validate() const
{
    return true;
}

// execute method for airliftOrder: Sets the effect and marks the order as executed
void airliftOrder::execute()
{
    if (validate())
    {
        *effect = "Airlift troops";
        *executed = true;
    }
}

// negotiateOrder constructor: Initializes order name
negotiateOrder::negotiateOrder()
{
    *name = "Negotiate Order";
}

// validate method for negotiateOrder: Always returns true (valid)
bool negotiateOrder::validate() const
{
    return true;
}

// execute method for negotiateOrder: Sets the effect and marks the order as executed
void negotiateOrder::execute()
{
    if (validate())
    {
        *effect = "Negotiate troops";
        *executed = true;
    }
}

// orderList methods

// Destructor: Deletes all orders in the list and releases memory
orderList::~orderList()
{
    for (Order *order : orders)
    {
        delete order; // Delete each order in the list
    }
}

// Adds a new order to the list
void orderList::addOrder(Order *order)
{
    orders.push_back(order);
}

// Removes an order from the list by index, deletes it from memory
void orderList::removeOrder(int index)
{
    if (index >= 0 && index < orders.size())
    {
        delete orders[index];                 // Free memory for the removed order
        orders.erase(orders.begin() + index); // Remove the order from the list
    }
}

// Moves an order from oldIndex to newIndex within the list
void orderList::moveOrder(int oldIndex, int newIndex)
{
    if (oldIndex >= 0 && oldIndex < orders.size() &&
        newIndex >= 0 && newIndex < orders.size())
    {
        std::swap(orders[oldIndex], orders[newIndex]); // Swap the orders
    }
}

// Displays all orders in the list by printing each order's details
void orderList::showAllOrders() const
{
    for (const auto &order : orders)
    {
        std::cout << order->toString();
    }
}

// Stream insertion operator: Outputs all orders in the list
std::ostream &operator<<(std::ostream &os, const orderList &ordersList)
{
    for (const auto &order : ordersList.orders)
    {
        os << *order; // Output each order using its stream insertion operator
    }
    return os;
}
