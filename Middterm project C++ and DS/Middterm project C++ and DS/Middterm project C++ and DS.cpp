//#include <iostream>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//// Initialising with struct to represent items
//struct Item 
//{
//    string name;
//    double price;
//    int quantity;
//    double total; // Total price for the item
//};
//
//// struct to represent a category
//struct Category 
//{
//    string name;
//    queue<Item> items;
//};
//
//// Function to display available categories
//void Categories(const Category categories[], int numCategories) 
//{
//    cout << "Available Categories:" << endl;
//    for (int i = 0; i < numCategories; ++i) 
//    {
//        cout << i + 1 << ". " << categories[i].name << endl;
//    }
//}
//
//// Function to display items in a category
//void CategoriesItems(const Category& category) 
//{
//    cout << "Items in " << category.name << ":" << endl;
//    queue<Item> temp = category.items;
//    int index = 1;
//    while (!temp.empty()) {
//        cout << index++ << ". " << temp.front().name << " - ₹" << temp.front().price << endl;
//        temp.pop();
//    }
//}
//
//// Function to add item to the cart
//void addingToCart(Item* cart[], const Item& item, int quantity, int& cartSize, const int maxCartSize) 
//{
//    // Check if the item is already in the cart
//    for (int i = 0; i < cartSize; ++i) 
//    {
//        if (cart[i]->name == item.name) 
//        {
//            cart[i]->quantity += quantity;
//            cout << "Added " << quantity << " " << item.name << " to the cart." << endl;
//            // Update total price for this item
//            cart[i]->total = cart[i]->price * cart[i]->quantity;
//            cout << "Total for " << item.name << ": ₹" << cart[i]->total << endl;
//            return;
//        }
//    }
//    // If the item is not in the cart, add it
//    if (cartSize < maxCartSize) 
//    {
//        cart[cartSize] = new Item{ item.name, item.price, quantity, item.price * quantity };
//        cout << "Added " << quantity << " " << item.name << " to the cart." << endl;
//        cout << "Total for " << item.name << ": ₹" << cart[cartSize]->total << endl;
//        ++cartSize;
//    }
//    else {
//        cout << "Cart is full. Cannot add more items." << endl;
//    }
//}
//
//// Function to display items in the cart and calculate total price
//void displayCart(Item* cart[], int cartSize) {
//    cout << "Items in Cart:" << endl;
//    double total = 0.0;
//    for (int i = 0; i < cartSize; ++i) {
//        cout << cart[i]->name << " - ₹" << cart[i]->price << " x " << cart[i]->quantity
//            << " = ₹" << cart[i]->total << endl;
//        total += cart[i]->total;
//    }
//    cout << "Total: ₹" << total << endl;
//}
//
//int main() {
//    // Defining categories and items
//    const int numCategories = 3;
//    Category shoppingList[numCategories] = {
//        {"Topwears", queue<Item>()},
//        {"Bottomwear", queue<Item>()},
//        {"Footwear", queue<Item>()}
//    };
//
//    // For Adding items to the categories
//    shoppingList[0].items.push({ "SweatShirts", 999.99, 0 });
//    shoppingList[0].items.push({ "Casuals", 599.99, 0 });
//    shoppingList[0].items.push({ "Jackets", 1999.99, 0 });
//
//    shoppingList[1].items.push({ "Cargos", 3000, 0 });
//    shoppingList[1].items.push({ "Jeans", 1999, 0 });
//    shoppingList[1].items.push({ "Joggers", 2999, 0 });
//
//    shoppingList[2].items.push({ "Sneakers", 6000, 0 });
//    shoppingList[2].items.push({ "Sports", 2500, 0 });
//    shoppingList[2].items.push({ "Formals", 4300, 0 });
//
//    const int maxCartSize = 10; // Maximum number of items in the cart
//    Item* cart[maxCartSize]{}; // Initialize pointers to nullptr
//    int cartSize = 0;            // Number of items currently in the cart
//
//    cout << "Welcome to the Woozy!" << endl;
//    cout << "Get the latest trends over here!!" << endl;
//    cout << "\n";
//
//    while (true) {
//        // Display available categories
//        Categories(shoppingList, numCategories);
//
//        // Ask user to select a category
//        int selectedCategory;
//        cout << "Enter the category number you want to shop from (0 to checkout): ";
//        cin >> selectedCategory;
//
//        // Check if the user wants to checkout
//        if (selectedCategory == 0) {
//            // Display items in the cart and total price
//            displayCart(cart, cartSize);
//            break;
//        }
//
//        // Check if the selected category is valid
//        if (selectedCategory >= 1 && selectedCategory <= numCategories) {
//            // Display items in the selected category
//            CategoriesItems(shoppingList[selectedCategory - 1]);
//
//            // Ask user to select an item from the category
//            int selectedItem;
//            cout << "Enter the item number you want to buy (0 to go back): ";
//            cin >> selectedItem;
//
//            // Check if the user wants to go back
//            if (selectedItem == 0) {
//                continue;
//            }
//
//            // Check if the selected item is valid
//            if (selectedItem >= 1 && selectedItem <= shoppingList[selectedCategory - 1].items.size()) {
//                // Ask user for the quantity
//                int quantity;
//                cout << "Enter the quantity: ";
//                cin >> quantity;
//
//                // Add item to the cart
//                int selectedIndex = selectedItem - 1; // Adjust index to 0-based
//                Item selected_item = shoppingList[selectedCategory - 1].items.front();
//                for (int i = 0; i < selectedIndex; ++i) {
//                    shoppingList[selectedCategory - 1].items.push(shoppingList[selectedCategory - 1].items.front());
//                    shoppingList[selectedCategory - 1].items.pop();
//                }
//                addingToCart(cart, selected_item, quantity, cartSize, maxCartSize);
//            }
//            else {
//                cout << "Invalid item selected." << endl;
//            }
//        }
//        else {
//            cout << "Invalid category selected." << endl;
//        }
//    }
//    // Free memory allocated for items in the cart
//    for (int i = 0; i < cartSize; ++i) {
//        delete cart[i];
//    }
//
//    return 0;
//}

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struct to represent an item
struct Item
{
    string name;
    double price;
    int quantity;
    double total; // Total price for the item
};

// Struct to represent a category
struct Category
{
    string name;
    queue<Item> items;
};

// Function to display available categories
void displayCategories(const Category categories[], int numCategories)
{
    cout << "Available Categories:" << endl;
    for (int i = 0; i < numCategories; ++i)
    {
        cout << i + 1 << ". " << categories[i].name << endl;
    }
}

// Function to display items in a category
void displayItems(const Category& category)
{
    cout << "Items in " << category.name << ":" << endl;
    queue<Item> temp = category.items;
    int index = 1;
    while (!temp.empty())
    {
        cout << index++ << ". " << temp.front().name << " - $" << temp.front().price << endl;
        temp.pop();
    }
}

// Function to add item to the cart
void addToCart(Item* cart[], const Item& item, int quantity, int& cartSize, const int maxCartSize)
{
    // Check if the item is already in the cart
    for (int i = 0; i < cartSize; ++i)
    {
        if (cart[i]->name == item.name)
        {
            cart[i]->quantity += quantity;
            cout << "Added " << quantity << " " << item.name << " to the cart." << endl;
            // Update total price for this item
            cart[i]->total = cart[i]->price * cart[i]->quantity;
            cout << "Total for " << item.name << ": $" << cart[i]->total << endl;
            return;
        }
    }
    // If the item is not in the cart, add it
    if (cartSize < maxCartSize)
    {
        cart[cartSize] = new Item{ item.name, item.price, quantity, item.price * quantity };
        cout << "Added " << quantity << " " << item.name << " to the cart." << endl;
        cout << "Total for " << item.name << ": $" << cart[cartSize]->total << endl;
        ++cartSize;
    }
    else
    {
        cout << "Cart is full. Cannot add more items." << endl;
    }
}

// Function to remove item from the cart
void removeFromCart(Item* cart[], int& cartSize)
{
    cout << "Enter the index of the item you want to remove: ";
    int index;
    cin >> index;
    if (index >= 1 && index <= cartSize)
    {
        delete cart[index - 1];
        // Shift items to fill the gap
        for (int i = index - 1; i < cartSize - 1; ++i)
        {
            cart[i] = cart[i + 1];
        }
        cart[cartSize - 1] = nullptr;
        --cartSize;
        cout << "Item removed from cart." << endl;
    }
    else
    {
        cout << "Invalid index." << endl;
    }
}

// Function to display items in the cart and calculate total price
void displayCart(Item* cart[], int cartSize)
{
    cout << "Items in Cart:" << endl;
    double total = 0.0;
    for (int i = 0; i < cartSize; ++i)
    {
        cout << i + 1 << ". " << cart[i]->name << " - $" << cart[i]->price << " x " << cart[i]->quantity
            << " = $" << cart[i]->total << endl;
        total += cart[i]->total;
    }
    cout << "Total: $" << total << endl;
}

int main()
{
    // Define categories and items
    const int numCategories = 3;
    Category shoppingList[numCategories] = {
        {"Topwears", queue<Item>()},
        {"Bottomwear", queue<Item>()},
        {"Footwear", queue<Item>()}
    };

    // For Adding items to the categories
    shoppingList[0].items.push({ "SweatShirts", 999.99, 0 });
    shoppingList[0].items.push({ "Casuals", 599.99, 0 });
    shoppingList[0].items.push({ "Jackets", 1999.99, 0 });

    shoppingList[1].items.push({ "Cargos", 3000, 0 });
    shoppingList[1].items.push({ "Jeans", 1999, 0 });
    shoppingList[1].items.push({ "Joggers", 2999, 0 });

    shoppingList[2].items.push({ "Sneakers", 6000, 0 });
    shoppingList[2].items.push({ "Sports", 2500, 0 });
    shoppingList[2].items.push({ "Formals", 4300, 0 });

    const int maxCartSize = 10; // Maximum number of items in the cart
    Item* cart[maxCartSize]{}; // Initialize pointers to nullptr
    int cartSize = 0;           // Number of items currently in the cart

    cout << "Welcome to the Woozy!" << endl;
    cout << "Get the latest trends over here!!" << endl;
    cout << "\n";

    while (true)
    {
        // Display available categories
        displayCategories(shoppingList, numCategories);

        // Ask user to select a category
        int selectedCategory;
        cout << "Enter the category number you want to shop from (0 to checkout): ";
        cin >> selectedCategory;

        // Check if the user wants to checkout
        if (selectedCategory == 0)
        {
            // Display items in the cart and total price
            displayCart(cart, cartSize);

            // Ask if the user wants to remove any item from the cart
            cout << "Would you like to remove any item from the cart? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                removeFromCart(cart, cartSize);
                // Display updated cart
                displayCart(cart, cartSize);
            }
            break;
        }

        // Check if the selected category is valid
        if (selectedCategory >= 1 && selectedCategory <= numCategories)
        {
            // Display items in the selected category
            displayItems(shoppingList[selectedCategory - 1]);

            // Ask user to select an item from the category
            int selectedItem;
            cout << "Enter the item number you want to buy (0 to go back): ";
            cin >> selectedItem;

            // Check if the user wants to go back
            if (selectedItem == 0)
            {
                continue;
            }

            // Check if the selected item is valid
            if (selectedItem >= 1 && selectedItem <= shoppingList[selectedCategory - 1].items.size())
            {
                // Ask user for the quantity
                int quantity;
                cout << "Enter the quantity: ";
                cin >> quantity;

                // Add item to the cart
                int selectedIndex = selectedItem - 1; // Adjust index to 0-based
                queue<Item>& selectedQueue = shoppingList[selectedCategory - 1].items;
                for (int i = 0; i < selectedIndex; ++i)
                {
                    selectedQueue.push(selectedQueue.front());
                    selectedQueue.pop();
                }
                addToCart(cart, selectedQueue.front(), quantity, cartSize, maxCartSize);
            }
            else
            {
                cout << "Invalid item selected." << endl;
            }
        }
        else
        {
            cout << "Invalid category selected." << endl;
        }
    }

    // Free memory allocated for items in the cart
    for (int i = 0; i < cartSize; ++i)
    {
        delete cart[i];
    }

    return 0;
}
