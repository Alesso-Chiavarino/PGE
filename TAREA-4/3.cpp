#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
 
class Item;  // Declaración anticipada de Item
 
class Enemy
{
public:
    Enemy() : x(10), y(10), alive(true) {}
 
    void move(int dx, int dy)
    {
        x += dx;
    }
 
    void attack() const
    {
        std::cout << "The enemy attacks!" << std::endl;
    }
 
    void die()
    {
        if (alive)
        {
            alive = false;
            std::cout << "The enemy has been defeated!" << std::endl;
        }
    }
 
    bool isAlive() const { return alive; }
 
    int getX() const { return x; }
    int getY() const { return y; }
 
private:
    int x, y;
    bool alive;
};
 
class Player
{
public:
    Player() : x(0), y(0), hasItem(false), itemPickedUp(false), onItemPickup(nullptr) {}
 
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
        checkItemPickup();
        checkSpecialEvent();
    }
 
    void attack(Enemy &enemy, Item &item)
    {
        if (x == enemy.getX() && y == enemy.getY())
        {
            if (hasItem)
            {
                if (enemy.isAlive())
                {
                    std::cout << "The player attacks the enemy!" << std::endl;
                    enemy.die();
                }
                else
                {
                    std::cout << "The enemy is already dead!" << std::endl;
                }
            }
            else
            {
                std::cout << "You must pick up the item before attacking!" << std::endl;
            }
        }
        else
        {
            std::cout << "You must be at the enemy's position to attack!" << std::endl;
        }
    }
 
    void pickupItem()
    {
        if (!hasItem && !itemPickedUp)
        {
            std::cout << "Player picks up the item!" << std::endl;
            hasItem = true;
            itemPickedUp = true;
 
            if (onItemPickup)
            {
                onItemPickup();
            }
        }
    }
 
    bool hasItemStatus() const { return hasItem; }
 
    int getX() const { return x; }
    int getY() const { return y; }
 
    void setOnItemPickupCallback(void (*callback)())
    {
        onItemPickup = callback;
    }
 
    void setOnSpecialEventCallback(std::function<void()> callback)
    {
        onSpecialEvent = callback;
    }
 
private:
    int x, y;
    bool hasItem;
    bool itemPickedUp;
    static const int itemX = 5;
    static const int itemY = 5;
    void (*onItemPickup)();
    std::function<void()> onSpecialEvent;
 
    void checkItemPickup()
    {
        if (x == itemX && y == itemY && !itemPickedUp)
        {
            pickupItem();
        }
    }
 
    void checkSpecialEvent()
    {
        if (x == 10 && y == 10 && onSpecialEvent)
        {
            onSpecialEvent();
        }
    }
};
 
class Item
{
public:
    Item() : x(5), y(5) {}
 
    void use() const
    {
        std::cout << "The item is used!" << std::endl;
    }
 
    int getX() const { return x; }
    int getY() const { return y; }
 
    void setPosition(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
 
private:
    int x, y;
};
 
class Game
{
public:
    Game() : running(true)
    {
        setupCallbacks();
    }
 
    void run()
    {
        char command;
 
        while (running)
        {
            printStatus();
            std::cout << "Enter command (WASD to move, X to attack, Q to quit): ";
 
            std::cin >> command;
            command = tolower(command);
 
            switch (command)
            {
            case 'w':
                player.move(0, -1);
                break;
            case 's':
                player.move(0, 1);
                break;
            case 'a':
                player.move(-1, 0);
                break;
            case 'd':
                player.move(1, 0);
                break;
            case 'x':
                player.attack(enemy, item);
                break;
            case 'q':
                running = false;
                break;
            default:
                std::cout << "Invalid command!" << std::endl;
                break;
            }
 
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
 
        std::cout << "Game over!" << std::endl;
    }
 
private:
    Player player;
    Enemy enemy;
    Item item;
    bool running;
 
    void setupCallbacks()
    {
        player.setOnItemPickupCallback([]() {
            std::cout << "Special event triggered: Player has picked up the item!" << std::endl;
        });
 
        player.setOnSpecialEventCallback([]() {
            std::cout << "Special event triggered: Player has reached a milestone (10, 10)!" << std::endl;
        });
    }
 
    void printStatus()
    {
        std::cout << "Player's position: (" << player.getX() << ", " << player.getY() << ")" << std::endl;
        std::cout << "Enemy's position: (" << enemy.getX() << ", " << enemy.getY() << ")" << std::endl;
        std::cout << "Item's position: (" << item.getX() << ", " << item.getY() << ")" << std::endl;
    }
};
 
int main()
{
    Game game;
    game.run();
    return 0;
}