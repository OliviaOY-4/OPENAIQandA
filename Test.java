import java.util.ArrayList;
import java.util.Scanner;

// Base class for items
class Item {
    private String name;
    private int id;
    private static int nextId = 1;

    public Item(String name) {
        this.name = name;
        this.id = nextId++;
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String newName) {
        name = newName;
    }
}

// Manager class to handle items
class ItemManager {
    private ArrayList<Item> items;

    public ItemManager() {
        items = new ArrayList<>();
    }

    public void addItem(Item item) {
        items.add(item);
        System.out.println("Item added successfully!");
    }

    public void removeItem(int id) {
        boolean found = false;
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i).getId() == id) {
                items.remove(i);
                System.out.println("Item removed successfully!");
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Item not found!");
        }
    }

    public void displayAllItems() {
        if (items.isEmpty()) {
            System.out.println("No items in the collection.");
            return;
        }

        System.out.println("\nAll Items:");
        for (Item item : items) {
            item.display();
        }
    }
}

// CLI class to handle user interface
class CLI {
    private ItemManager manager;
    private Scanner scanner;

    public CLI() {
        manager = new ItemManager();
        scanner = new Scanner(System.in);
    }

    private void printMenu() {
        System.out.println("\n=== Item Management System ===");
        System.out.println("1. Add Item");
        System.out.println("2. Remove Item");
        System.out.println("3. Display All Items");
        System.out.println("4. Exit");
        System.out.print("Enter your choice: ");
    }

    public void run() {
        while (true) {
            printMenu();
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter item name: ");
                    String name = scanner.nextLine();
                    manager.addItem(new Item(name));
                    break;

                case 2:
                    System.out.print("Enter item ID to remove: ");
                    int id = scanner.nextInt();
                    manager.removeItem(id);
                    break;

                case 3:
                    manager.displayAllItems();
                    break;

                case 4:
                    System.out.println("Exiting program. Goodbye!");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

public class Test {
    public static void main(String[] args) {
        CLI cli = new CLI();
        cli.run();
    }
} 