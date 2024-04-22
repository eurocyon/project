
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <limits>
#include <vector>
#include <random>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

enum class ItemType {
    COPPERSWORD = 1,
    COPPERLSWORD = 2,
    COPPERAXE = 3,
    COPPERBAXE = 4,
    COPPERMACE = 5,
    COPPERHAM = 6,
};

struct Inventory {
    string name = " ";
    string desc = " ";
    int price = 0;
};

struct atk {
    string name = " ";
    string desc = " ";
    int dmg = 0;
    int price = 0;
};

struct GameData {
    int playerScore;
    string playerName;
    // Add more game data fields as needed
};
int showMenu();
int random(int min, int max);
int invMenu();
void getInv(vector<Inventory>* list, vector<ItemType>* LowTeirItm);
void displayInv(vector<Inventory>* list, int invInput);
void SaveGameState(const GameData& data, const string& filename);
void LoadGameState(GameData& data, const std::string& filename);
string GetSaveFilename(int slotNumber);
//float calculatePrice(BookInfo* bookList, int size);
//void sortPrices(BookInfo* bookList, int size);

int main() {
    int randNum = random(0, 10);

    const int SIZE = 15;
    vector<Inventory> list;
    vector<ItemType> LowTeirItm = {
    ItemType::COPPERSWORD,
    ItemType::COPPERLSWORD,
    ItemType::COPPERAXE,
    ItemType::COPPERBAXE,
    ItemType::COPPERMACE,
    ItemType::COPPERHAM,
    };
    GameData gameData;
    gameData.playerScore = 100;
    gameData.playerName = "Player10";
    int saveSlot = 1;


    do {
        showMenu();
        int invInput = 0;
        char input, sInput;
        cin >> input;

        switch (input) {
        case 'w':
            for (int i = 0; i < 6; i++) {
                cout << int(LowTeirItm[i]);
            }
            break;
        case 's':
            LoadGameState(gameData, GetSaveFilename(saveSlot));
            std::cout << "Loaded Player Name: " << gameData.playerName << std::endl;
            std::cout << "Loaded Player Score: " << gameData.playerScore << std::endl;
            break;

        case 'i':
            displayInv(&list, invInput);
            break;
        case 'e':
            getInv(&list, &LowTeirItm);
            break;
        case 'q':

            break;
        case '0':
            cout << "\n Are you sure you would like to save? Saving will overwrite the previous file, and you will no longer be able to reload it?(y/n)\n";
            cin >> sInput;
            if (sInput == 'y') {
                SaveGameState(gameData, GetSaveFilename(saveSlot));
            }
            else {
                cout << "\nCarry on\n";
            }

            break;

        default:
            cout << "Invalid input\n";
        }


    } while (true);

    return 0;
}

void getInv(vector<Inventory>* list, vector<ItemType>* LowTeirItm) {
    // Generate a random index within the range of available items
    int randomIndex = 0;
    randomIndex = random(0, LowTeirItm->size() - 1);


    // Assign the random item's details to the inventory
    switch ((*LowTeirItm)[randomIndex]) {
    case ItemType::COPPERSWORD: {
        //Creates a new Item
        atk* CopSrdProp = new atk;

        //Assigns properties to the Item
        CopSrdProp->name = "\nCopper Short Sword\n";
        CopSrdProp->dmg = 3;
        CopSrdProp->price = 5;
        CopSrdProp->desc = "\nA cheap sword often used by peasantry, the sword feels heavier and awkward around the hilt.\n";

        //Adds the Item to the player inv and saves the properties
        cout << "\nYou have found a " << CopSrdProp->name << endl;
        (*list)[0].name = CopSrdProp->name;
        (*list)[0].desc = CopSrdProp->desc;
        (*list)[0].price = CopSrdProp->price;

        delete CopSrdProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    case ItemType::COPPERLSWORD: {
        //Creates a new Item
        atk* CopLSrdProp = new atk;

        //Assigns properties to the Item
        CopLSrdProp->name = "\nCopper Long Sword\n";
        CopLSrdProp->dmg = 6;
        CopLSrdProp->price = 10;
        CopLSrdProp->desc = "\nA cheap and heavy long sword, seemingly the blade is of questionable quality.\n";

        //Adds the Item to the player inv and saves the properties
        cout << "\nYou have found a " << CopLSrdProp->name << endl;
        (*list)[0].name = CopLSrdProp->name;
        (*list)[0].desc = CopLSrdProp->desc;
        (*list)[0].price = CopLSrdProp->price;

        delete CopLSrdProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    case ItemType::COPPERAXE: {
        //Creates a new Item
        atk* CopAxeProp = new atk;

        //Assigns properties to the Item
        CopAxeProp->name = "\nCopper Axe\n";
        CopAxeProp->dmg = 4;
        CopAxeProp->price = 5;
        CopAxeProp->desc = "\nA low end axe, it appears that the hilt hasn't been sanded down.\n";

        //Adds the Item to the player inv and saves the properties
        cout << "\nYou have found a " << CopAxeProp->name << endl;
        (*list)[0].name = CopAxeProp->name;
        (*list)[0].desc = CopAxeProp->desc;
        (*list)[0].price = CopAxeProp->price;

        delete CopAxeProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    case ItemType::COPPERBAXE: {
        //Creates a new Item
        atk* CopBAxeProp = new atk;

        //Assigns properties to the Item
        CopBAxeProp->name = "\nCopper Battle Axe\n";
        CopBAxeProp->dmg = 7;
        CopBAxeProp->price = 10;
        CopBAxeProp->desc = "\nA flimsy battle axe, it's much bigger than you and the weight distribution is awkward.\n";

        cout << "\nYou have found a " << CopBAxeProp->name << endl;
        (*list)[0].name = CopBAxeProp->name;
        (*list)[0].desc = CopBAxeProp->desc;
        (*list)[0].price = CopBAxeProp->price;

        delete CopBAxeProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    case ItemType::COPPERMACE: {
        //Creates a new Item
        atk* CopMaceProp = new atk;

        //Assigns properties to the Item
        CopMaceProp->name = "\nCopper Mace\n";
        CopMaceProp->dmg = 4;
        CopMaceProp->price = 5;
        CopMaceProp->desc = "\nA heavy and dull mace, its hard to see this being any different from a club.\n";

        //Adds the Item to the player inv and saves the properties
        cout << "\nYou have found a " << CopMaceProp->name << endl;
        (*list)[0].name = CopMaceProp->name;
        (*list)[0].desc = CopMaceProp->desc;
        (*list)[0].price = CopMaceProp->price;

        delete CopMaceProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    case ItemType::COPPERHAM: {
        //Creates a new Item
        atk* CopHamProp = new atk;

        //Assigns properties to the Item
        CopHamProp->name = "\nCopper Warhammer\n";
        CopHamProp->dmg = 8;
        CopHamProp->price = 10;
        CopHamProp->desc = "\nA heavy Warhammer, its much smaller than you'd expect but still requiring 2 hands.\n";


        //Adds the Item to the player inv and saves the properties
        cout << "\nYou have found a " << CopHamProp->name << endl;
        (*list)[0].name = CopHamProp->name;
        (*list)[0].desc = CopHamProp->desc;
        (*list)[0].price = CopHamProp->price;

        delete CopHamProp; // Release the allocated memory

        LowTeirItm->erase(LowTeirItm->begin() + randomIndex); // Remove from loot pool
        break;
    }
    default:
        cout << "found nothing\n";
    }


}

void displayInv(vector<Inventory>* list, int invInput)
{
    do {
        invMenu();

        cin >> invInput;
        switch (invInput) {
        case 1:

            break;
        case 2:
            // Display inventory
            cout << "Inventory:\n";
            for (const auto& item : (*list)) {
                cout << item.name << "\n" << item.desc << "\n" << item.price << "\n" << endl;
            }
            break;
        case 3:

            break;
        case 4:

            break;
        default:
            cout << "Invalid input\n";
        }
    } while (invInput != 4);
}


/*
float calculatePrice(BookInfo* bookList, int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += bookList[i].price;
    }
    cout << "Total price of all books: $" << fixed << setprecision(2) << sum << endl;
    return sum;
}

void sortPrices(BookInfo* bookList, int size) {
    sort(bookList, bookList + size, [](const BookInfo& a, const BookInfo& b) {
        return a.price > b.price;
        });

    cout << "Sorted array in descending order: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << bookList[i].title << " by " << bookList[i].author << " published by " << bookList[i].publisher << " for $" << fixed << setprecision(2) << bookList[i].price << endl;
    }
}*/

int showMenu() {
    cout << "\nWhat will you do?\n";
    cout << "---------------------------------------------------------------\n";
    cout << "w. Next room\n";
    cout << "i. Inventory\n";
    cout << "e. Interact\n";
    cout << "s. Status\n";
    cout << "q. Inspect\n";
    cout << "0. Save\n";

    return 0;
}

int invMenu()
{
    cout << "\nWhat would you like to do?\n";
    cout << "---------------------------------------------------------------\n";
    cout << "1. Search Item\n";
    cout << "2. Display All\n";
    cout << "3. Inspect Item\n";
    cout << "4. Cancel\n";
    return 0;
}

int random(int min, int max)
{
    int randomNum = 0;

    random_device engine; // Random number engine
    std::random_device rand_dev; // Distribution object
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> random(min, max);

    randomNum = random(generator);
    return randomNum;
}

void SaveGameState(const GameData& data, const std::string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "ERROR - Unable to save\n";
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&data), sizeof(GameData));
    outFile.close();
}

void LoadGameState(GameData& data, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "ERROR - Unable to load\n";
        return;
    }
    inFile.read(reinterpret_cast<char*>(&data), sizeof(GameData));
    inFile.close();
}
string GetSaveFilename(int slotNumber) {
    ostringstream oss;
    oss << "saved_game_" << slotNumber << ".dat";
    return oss.str();
}


