#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <string>
#include <vector>

// Base class for all orders
class Order
{
protected:
    std::string *effect; // Effect of the order after execution
    bool *executed;      // Status to check if the order has been executed

public:
    std::string *name; // Name of the order

    // Constructor
    Order();

    // Destructor to clean up dynamic memory
    virtual ~Order();

    // Copy constructor for deep copying dynamic data members
    Order(const Order &other);

    // Assignment operator for deep copying when assigning one order to another
    Order &operator=(const Order &other);

    // Virtual method to validate an order, returns true if valid
    virtual bool validate() const;

    // Virtual method to execute the order if it's valid
    virtual void execute();

    // Method to get a string representation of the order
    virtual std::string toString() const;

    // Stream insertion operator to output the order's details
    friend std::ostream &operator<<(std::ostream &os, const Order &order);
};

// Derived classes for specific order types

// Deploy order class
class deployOrder : public Order
{
public:
    deployOrder();                  // Constructor for deploy order
    bool validate() const override; // Override to validate deploy order
    void execute() override;        // Override to execute deploy order
};

// Advance order class
class advanceOrder : public Order
{
public:
    advanceOrder();                 // Constructor for advance order
    bool validate() const override; // Override to validate advance order
    void execute() override;        // Override to execute advance order
};

// Bomb order class
class bombOrder : public Order
{
public:
    bombOrder();                    // Constructor for bomb order
    bool validate() const override; // Override to validate bomb order
    void execute() override;        // Override to execute bomb order
};

// Blockade order class
class blockadeOrder : public Order
{
public:
    blockadeOrder();                // Constructor for blockade order
    bool validate() const override; // Override to validate blockade order
    void execute() override;        // Override to execute blockade order
};

// Airlift order class
class airliftOrder : public Order
{
public:
    airliftOrder();                 // Constructor for airlift order
    bool validate() const override; // Override to validate airlift order
    void execute() override;        // Override to execute airlift order
};

// Negotiate order class
class negotiateOrder : public Order
{
public:
    negotiateOrder();               // Constructor for negotiate order
    bool validate() const override; // Override to validate negotiate order
    void execute() override;        // Override to execute negotiate order
};

// Class to manage a list of orders
class orderList
{
private:
    std::vector<Order *> orders; // Vector to store a list of Order pointers

public:
    // Destructor to clean up dynamic memory in the orders list
    ~orderList();

    // Method to add a new order to the list
    void addOrder(Order *order);

    // Method to remove an order from the list by index
    void removeOrder(int index);

    // Method to move an order from one index to another in the list
    void moveOrder(int oldIndex, int newIndex);

    // Method to display all orders in the list
    void showAllOrders() const;

    // Stream insertion operator to output all orders in the list
    friend std::ostream &operator<<(std::ostream &os, const orderList &ordersList);
};

#endif // ORDERS_H
