#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Base class for items
class Item {
protected:
    std::string name;
    int id;
    static int nextId;

public:
    Item(const std::string& name) : name(name), id(nextId++) {}
    
    virtual ~Item() = default;
    
    virtual void display() const {
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }
    
    int getId() const { return id; }
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }
};

int Item::nextId = 1;

// Manager class to handle items
class ItemManager {
private:
    std::vector<Item*> items;

public:
    ~ItemManager() {
        for (auto item : items) {
            delete item;
        }
    }

    void addItem(Item* item) {
        items.push_back(item);
        std::cout << "Item added successfully!" << std::endl;
    }

    void removeItem(int id) {
        auto it = std::find_if(items.begin(), items.end(),
            [id](const Item* item) { return item->getId() == id; });
        
        if (it != items.end()) {
            delete *it;
            items.erase(it);
            std::cout << "Item removed successfully!" << std::endl;
        } else {
            std::cout << "Item not found!" << std::endl;
        }
    }

    void displayAllItems() const {
        if (items.empty()) {
            std::cout << "No items in the collection." << std::endl;
            return;
        }
        
        std::cout << "\nAll Items:" << std::endl;
        for (const auto& item : items) {
            item->display();
        }
    }
};

// CLI class to handle user interface
class CLI {
private:
    ItemManager manager;

    void printMenu() {
        std::cout << "\n=== Item Management System ===" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Remove Item" << std::endl;
        std::cout << "3. Display All Items" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
    }

public:
    void run() {
        int choice;
        std::string name;
        int id;

        while (true) {
            printMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter item name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    manager.addItem(new Item(name));
                    break;
                
                case 2:
                    std::cout << "Enter item ID to remove: ";
                    std::cin >> id;
                    manager.removeItem(id);
                    break;
                
                case 3:
                    manager.displayAllItems();
                    break;
                
                case 4:
                    std::cout << "Exiting program. Goodbye!" << std::endl;
                    return;
                
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main() {
    CLI cli;
    cli.run();
    return 0;
} 