#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void ClearPreviousLine() {
    printf("\x1b[1A");
    printf("\33[2K\r");
}

bool IntConstraintVerfication(string index) {
    for (int i = 0; i < index.length(); i++) {
        if (isdigit(index[i])) {
            return true;
        }
    }
    return false;
}

void PokemonSlot(int pokemonIndex) {
    string tempStr;

    cout << "\n\nWhich Pokémon would you like to choose?\n";

    while (true) {
        cout << "Choose your Pokémon (1-3): ";
        cin >> tempStr;

        if (!IntConstraintVerfication(tempStr)) {
            cout << "Invalid input. Please enter a digit between 1 and 3.\n";
            Sleep(1000);
            ClearPreviousLine();
            ClearPreviousLine();
            continue;
        }

        pokemonIndex = stoi(tempStr);

        if (pokemonIndex < 1 || pokemonIndex > 3) {
            cout << "Out of range. Enter a number between 1 and 3.\n";
            Sleep(1000);
            ClearPreviousLine();
            ClearPreviousLine();
            continue;
        }

        break;
    }

    ClearPreviousLine();
    cout << "\nChoose your Pokémon 2 (1-3): " << pokemonIndex << "\n";

    switch (pokemonIndex) {
    case 1:
        cout << "\nYou chose Bulbasaur! A wise choice.\n";
        break;
    case 2:
        cout << "\nYou chose Charmander! A fiery choice.\n";
        break;
    case 3:
        cout << "\nYou chose Squirtle! A cool choice.\n";
        break;
    default:
        cout << "\nInvalid Pokémon selection.\n";
        break;
    }
}

bool NameConstraintVerfication(string tempName) {
    for (int i = 0; i < tempName.length(); i++) {
        if (isdigit(tempName[i])) {
            cout << "Invalid name. Please try again.\n";
            Sleep(1000);
            ClearPreviousLine();
            return true;
        }
    }
    return false;
}

string UserInputFormat(string userName, string userIntro) {
    bool isStatus = true;
    string temp;
    cout << "\n";
    while (true) {
        ClearPreviousLine();
        cout << userIntro << flush;
        getline(cin, userName);

        if (!userName.empty()) {
            isStatus = NameConstraintVerfication(userName);
            if (!isStatus) {
                ClearPreviousLine();
                break;
            }
        }
    }

    if (!isStatus) {
        cout << "\n" << userIntro;
        temp = userName;
    }

    return temp;
}

int main() {
    string playerName;
    string userIntro = "Enter Player Name: ";
    int playerChoice = 0;

    cout << "\nTrainer! Before you embark on your journey, the Pokémon world needs to know who you are!\n";
    cout << "Time to step up and tell us your name.\nAnd remember, a great name is the start of every great adventure!\n\n";

    playerName = UserInputFormat(playerName, userIntro);
    cout << "\nGreat start, " << playerName << "!\n";

    if (playerName.length() != 0) {
        cout << "\nWelcome to the world of Pokémon! I am Professor Oak.\n";
        cout << "You can choose one of the following Pokémon:\n\n";
        cout << "1. Bulbasaur\n2. Charmander\n3. Squirtle\n";

        PokemonSlot(playerChoice);

        cout << "\n\nAh, an excellent choice!\n";
        cout << "\nBut beware, Trainer,\n";
        cout << "this is only the beginning.\n";
        cout << "Your journey is about to unfold.\n";
        cout << "\nNow let’s see if you’ve got what it takes to keep going!\n";
        cout << "Good luck, and remember… Choose wisely!\n\n";
    }

    return 0;
}
