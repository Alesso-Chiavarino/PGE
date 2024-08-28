#include <iostream>
#include <chrono>
#include <thread>

class Enemy;
class Item;

void onItemPickupCallback();

class Player
{
public:
    Player() : x(0), y(0), hasItem(false), itemPickedUp(false), onItemPickup(nullptr) {}

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
        checkItemPickup();
    }

    void attack(Enemy &enemy, Item &item);

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
        else if (hasItem)
        {
            std::cout << "Player already has the item!" << std::endl;
        }
        else
        {
            std::cout << "There is no item to pick up!" << std::endl;
        }
    }

    bool hasItemStatus() const { return hasItem; }

    int getX() const { return x; }
    int getY() const { return y; }

    void setOnItemPickupCallback(void (*callback)())
    {
        onItemPickup = callback;
    }

private:
    int x, y;
    bool hasItem;
    bool itemPickedUp;
    static const int itemX = 5;
    static const int itemY = 5;
    void (*onItemPickup)();

    void checkItemPickup()
    {
        if (x == itemX && y == itemY && !itemPickedUp)
        {
            pickupItem();
        }
    }
};

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

void onItemPickupCallback()
{
    std::cout << "Special event triggered: Player has picked up the item!" << std::endl;
}

void Player::attack(Enemy &enemy, Item &item)
{
    if (x == enemy.getX() && y == enemy.getY())
    {
        if (hasItem)
        {
            if (x == item.getX() && y == item.getY())
            {
                std::cout << "The player picks up the item while attacking!" << std::endl;
                pickupItem();
                item.setPosition(-1, -1);
            }

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

void printStatus(const Player &player, const Enemy &enemy, const Item &item)
{
    std::cout << "Player's position: (" << player.getX() << ", " << player.getY() << ")" << std::endl;
    std::cout << "Enemy's position: (" << enemy.getX() << ", " << enemy.getY() << ")" << std::endl;
    std::cout << "Item's position: (" << item.getX() << ", " << item.getY() << ")" << std::endl;
}

int main()
{
    Player player;
    Enemy enemy;
    Item item;

    player.setOnItemPickupCallback(onItemPickupCallback);

    char command;
    bool running = true;

    while (running)
    {
        printStatus(player, enemy, item);
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
    return 0;
}
