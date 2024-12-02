#// Orders.h

#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <vector>
#include <string>
#include "../LoggingObserver/LoggingObserver.h"

// Forward declarations
class Player;
class Territory;

/**
 * @brief Base Order Class
 */
class Order : public Subject, public Iloggable
{
public:
    string stringToLog() const override;
    // Constructors and Destructor

    /**
     * @brief Default constructor
     */
    Order();

    /**
     * @brief Copy constructor
     * @param other Order to copy
     */
    Order(const Order &other);

    /**
     * @brief Destructor
     */
    virtual ~Order();

    // Assignment Operator

    /**
     * @brief Assignment operator
     * @param other Order to assign from
     * @return Reference to this Order
     */
    Order &operator=(const Order &other);

    // Pure Virtual Methods

    /**
     * @brief Validate the order
     * @return True if valid, false otherwise
     */
    virtual bool validate() = 0;

    /**
     * @brief Execute the order
     */
    virtual void execute() = 0;

    // Stream Insertion Operator

    /**
     * @brief Stream insertion operator
     * @param os Output stream
     * @param order Order to output
     * @return Reference to output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const Order &order);

    // Getters

    /**
     * @brief Get the description of the order
     * @return Description string
     */
    std::string getDescription() const;

    /**
     * @brief Get the effect of the order
     * @return Effect string
     */
    std::string getEffect() const;

protected:
    std::string *description; /** Description of the order */
    std::string *effect;      /** Effect of the order after execution */
    bool *executed;           /** Whether the order has been executed */
};

// Derived Order Classes

/**
 * @brief Deploy Order Class
 */
class Deploy : public Order
{
public:
    // Constructors and Destructor
    /**
     * @brief Deploy Order Class
     */
    Deploy();
    Deploy(Player *player, Territory *target, int units);
    Deploy(const Deploy &other);
    ~Deploy();

    Deploy &operator=(const Deploy &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Territory *target;
    int units;
};

/**
 * @brief Advance Order Class
 */
class Advance : public Order
{
public:
    Advance();
    Advance(Player *player, Territory *source, Territory *target, int units);
    Advance(const Advance &other);
    ~Advance();
    Advance &operator=(const Advance &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Territory *source;
    Territory *target;
    int units;
};

/**
 * @brief Bomb Order Class
 */
class Bomb : public Order
{
public:
    Bomb();
    Bomb(Player *player, Territory *target);
    Bomb(const Bomb &other);
    ~Bomb();

    Bomb &operator=(const Bomb &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Territory *target;
};

/**
 * @brief Blockade Order Class
 */
class Blockade : public Order
{
public:
    Blockade();
    Blockade(Player *player, Territory *target);
    Blockade(const Blockade &other);
    ~Blockade();

    Blockade &operator=(const Blockade &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Territory *target;
};

/**
 * @brief Airlift Order Class
 */
class Airlift : public Order
{
public:
    Airlift();
    Airlift(Player *player, Territory *source, Territory *target, int units);
    Airlift(const Airlift &other);
    ~Airlift();

    Airlift &operator=(const Airlift &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Territory *source;
    Territory *target;
    int units;
};

/**
 * @brief Negotiate Order Class
 */
class Negotiate : public Order
{
public:
    Negotiate();
    Negotiate(Player *player, Player *targetPlayer);
    Negotiate(const Negotiate &other);
    ~Negotiate();
    Negotiate &operator=(const Negotiate &other);

    bool validate() override;
    void execute() override;

private:
    Player *player;
    Player *targetPlayer;
};

/**
 * @brief OrdersList Class
 */
class OrdersList : public Subject, public Iloggable
{
public:
    // Constructors and Destructor
    OrdersList();
    OrdersList(const OrdersList &other);
    ~OrdersList();

    OrdersList &operator=(const OrdersList &other);

    /**
     * @brief Add an order to the list
     * @param order Pointer to the order to add
     */
    void add(Order *order);

    /**
     * @brief Remove an order from the list
     * @param index Index of the order to remove
     */
    void remove(int index);

    /**
     * @brief Move an order within the list
     * @param fromIndex Current index of the order
     * @param toIndex New index for the order
     */
    void move(int fromIndex, int toIndex);

    /**
     * @brief Get the list of orders
     * @return Constant reference to the vector of order pointers
     */
    const std::vector<Order *> &getOrders() const;

    std::string stringToLog() const override;

    // Stream Insertion Operator

    /**
     * @brief Stream insertion operator for OrdersList
     * @param os Output stream
     * @param ordersList OrdersList to output
     * @return Reference to output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const OrdersList &ordersList);

private:
    std::vector<Order *> *orders; /**< Pointer to the vector of Order pointers */
};

class CheaterOrder : public Order
{
private:
    Player *player;

public:
    CheaterOrder(Player *p);
    CheaterOrder(const CheaterOrder &other);
    ~CheaterOrder();

    CheaterOrder &operator=(const CheaterOrder &other);

    bool validate();
    void execute();
};

#endif // ORDERS_H
