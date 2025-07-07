#include <iostream>
#include <string>
#include <windows.h>
#include <map>
#include <conio.h>


#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"
#define AC_ORANGE "\x1b[38;5;208m"
using namespace std;

enum class PokemonChoice {
    CHARMANDER = 1,
    BULBASAUR,
    SQUIRTLE,
    INVALID
};

enum class PokemonType {
    FIRE,
    GRASS,
    WATER,
    ELECTRIC,
    NORMAL
};

class Tool {
public:
    void ClearPreviousLine() {
        printf("\x1b[1A");
        printf("\33[2K\r");
    }

    bool IntConstraintVerification(string input) {
        if (input.empty()) return false;
        for (char c : input) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    int WhiteSpaceLength(string playerName) {
        return playerName.length();
    }

    string TypeWrtingEffect(string dialogue, double time) {
        char ch;
        bool skip = false;

        for (int i = 0; i < dialogue.length(); i++) {
            if (!skip && _kbhit()) {
                ch = _getch();
                if (ch == '\r') {
                    skip = true;
                    time = 0;
                }
            }
            cout << dialogue[i];
            if (dialogue[i] != ' ')
                Sleep(static_cast<int>(round(time * 1000)));
        }
        return dialogue;
    }

    bool NameConstraintVerfication(string tempName) {
        for (int i = 0; i < tempName.length(); i++) {
            if (isdigit(tempName[i])) {
                cout << AC_RED << "Invalid name. Please try again.\n";
                Sleep(1000);
                ClearPreviousLine();
                return true;
            }
        }
        return false;
    }
};

class NPCName {
public:
    string PlayerListInGame(int index) {
        map<int, string> playerName;
        playerName[0] = "Professor Oak :";
        playerName[1] = "Enter Your Name: ";
        return playerName[index];
    }

    map<int, string>& ShareData() {
        static map<int, string> playerList;
        return playerList;
    }

    map<int, string> PlayerListDataContainer(int index, string playerName) {
        ShareData()[index] = playerName;
        return ShareData();
    }
};

class ProfessorOakNpc {
public:
    string ProfessorOakDialogue(int index, int whiteSpace, map<int, string> dyanmicUserName) {
        string color[] = { AC_BLACK, AC_RED, AC_GREEN, AC_YELLOW,
            AC_BLUE, AC_MAGENTA, AC_CYAN, AC_WHITE,
            AC_NORMAL,AC_ORANGE };

        map<int, string> dialogue;

        Sleep(100);
        dialogue[0] = color[6] + "Hello there! Welcome to the world of Pokemon!\n"
            + string(whiteSpace, ' ') + "My name is Oak. People call me the Pokemon Professor!\n"
            + string(whiteSpace, ' ') + "But enough about me. Let's talk about you!\n"
            + string(whiteSpace, ' ') + "First, tell me, what’s your name?\n";

        dialogue[1] = color[6] + "Ah," + dyanmicUserName[0] + "\n"
            + string(whiteSpace, ' ') + "What a fantastic name!\n";

        dialogue[2] = color[6] + "You must be eager to start your adventure.\n"
            + string(whiteSpace, ' ') + "But first, you’ll need a Pokemon of your own!\n";

        dialogue[3] = color[6] + "I have three Pokemon here with me. They’re all quite feisty!\n";

        dialogue[4] = color[1] + "Choose wisely...\n" + color[2]
            + string(whiteSpace, ' ') + "1. Charmander - The fire type. A real hothead!\n"
            + string(whiteSpace, ' ') + "2. Bulbasaur - The grass type. Calm and collected!\n"
            + string(whiteSpace, ' ') + "3. Squirtle - The water type. Cool as a cucumber!\n";

        dialogue[5] = color[1] + "So, which one will it be? Enter the number of your choice: ";

        dialogue[6] = color[9] + "\nA fiery choice! Charmander is yours!\n" + color[7];
        dialogue[7] = color[3] + "\nA fine choice! Bulbasaur is always ready to grow on you!\n" + color[7];
        dialogue[8] = color[4] + "\nSplendid! Squirtle will keep you cool under pressure!\n" + color[7];

        dialogue[9] = color[6] + dyanmicUserName[0] + " and you, " + dyanmicUserName[1] + ", are going to be the best of friends!\n";

        dialogue[10] = color[6] + "Your journey begins now! Get ready to explore the vast world of Pokemon!\n" + color[7];

        return dialogue[index];
    }

    string UserInputFormat(string userName, string userIntro, Tool tool) {
        bool isStatus = true;
        string temp;
        cout << "\n\n";
        while (true) {
            tool.ClearPreviousLine();
            cout << AC_WHITE << userIntro << flush;
            cout << AC_GREEN;
            getline(cin, userName);

            if (!userName.empty()) {
                isStatus = tool.NameConstraintVerfication(userName);
                if (!isStatus) {
                    tool.ClearPreviousLine();
                    break;
                }
            }
        }

        if (!isStatus) {
            temp = userName;
            cout << AC_WHITE << userIntro << flush << temp << "\n";
        }

        return temp;
    }
};

class Pokemon {
    PokemonChoice chosenPokemon;
    string pokemonName;
    PokemonType pokemonType;
    int health;

public:
    Pokemon() {
        pokemonName = "Trainer";
        pokemonType = PokemonType::NORMAL;
        health = 50;
    }

    Pokemon(string name, PokemonType type, int hp) {
        pokemonName = name;
        pokemonType = type;
        health = hp;
    }

    // Deep copy constructor
    Pokemon(const Pokemon& other) {
        pokemonName = other.pokemonName;
        pokemonType = other.pokemonType;
        health = other.health;
    }

    ~Pokemon() {
        cout << AC_MAGENTA << pokemonName << " has been released.\n" << AC_NORMAL;
    }

    void Display() {
        cout << AC_YELLOW << "Pokemon: " << pokemonName << "\n";
        cout << "Health: " << health << "\n";
        cout << "Type: ";
        switch (pokemonType) {
        case PokemonType::FIRE: cout << "Fire\n"; break;
        case PokemonType::GRASS: cout << "Grass\n"; break;
        case PokemonType::WATER: cout << "Water\n"; break;
        default: cout << "Normal\n"; break;
        }
        cout << AC_NORMAL;
    }

    string GetPokemonName(int pokemonIndex) {
        switch (pokemonIndex) {
        case 1: return "Charmander";
        case 2: return "Bulbasaur";
        case 3: return "Squirtle";
        default: return "";
        }
    }

    void PokemonSlot(int& pokemonIndex, map<int, string> dynamicUserName, ProfessorOakNpc professorOakNpc, Tool tool, NPCName npcName) {
        string tempStr;
        cout << "\n";
        while (true) {
            cout << AC_WHITE << npcName.PlayerListInGame(0);
            cout << professorOakNpc.ProfessorOakDialogue(5, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), dynamicUserName);
            cout << AC_GREEN;

            getline(cin, tempStr);

            if (tempStr.empty()) {
                tool.ClearPreviousLine();
                continue;
            }

            if (!tool.IntConstraintVerification(tempStr)) {
                cout << AC_RED << "Invalid input. Please enter a digit between 1 and 3.\n";
                Sleep(1000);
                tool.ClearPreviousLine();
                tool.ClearPreviousLine();
                continue;
            }

            pokemonIndex = stoi(tempStr);

            if (pokemonIndex < 1 || pokemonIndex > 3) {
                cout << AC_RED << "Out of range. Enter a number between 1 and 3.\n";
                Sleep(1000);
                tool.ClearPreviousLine();
                tool.ClearPreviousLine();
                continue;
            }

            break;
        }

        tool.ClearPreviousLine();
        cout << AC_WHITE << npcName.PlayerListInGame(0);
        cout << professorOakNpc.ProfessorOakDialogue(5, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), dynamicUserName) << pokemonIndex << "\n";

        switch (pokemonIndex) {
        case 1:
            cout << professorOakNpc.ProfessorOakDialogue(6, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), dynamicUserName);
            break;
        case 2:
            cout << professorOakNpc.ProfessorOakDialogue(7, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), dynamicUserName);
            break;
        case 3:
            cout << professorOakNpc.ProfessorOakDialogue(8, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), dynamicUserName);
            break;
        default:
            cout << AC_RED << "\nInvalid Pokémon selection.\n";
            break;
        }
    }
};

int main() {
    string playerName;
    int pokemonIndex = 0;

    string whiteColor = AC_NORMAL;
    ProfessorOakNpc professorOakNpc;
    Tool tool;
    NPCName npcName;
    Pokemon basePokemon;

    // Dialogue 0
    cout << whiteColor << npcName.PlayerListInGame(0);
    tool.TypeWrtingEffect(professorOakNpc.ProfessorOakDialogue(0, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), npcName.ShareData()), 0.05);

    // Get user input
    playerName = professorOakNpc.UserInputFormat(playerName, npcName.PlayerListInGame(1), tool);
    npcName.PlayerListDataContainer(0, playerName);

    // Dialogue 1–4
    for (int i = 1; i <= 4; i++) {
        cout << "\n" << whiteColor << npcName.PlayerListInGame(0);
        tool.TypeWrtingEffect(professorOakNpc.ProfessorOakDialogue(i, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), npcName.ShareData()), 0.05);
    }

    // Choose Pokémon
    basePokemon.PokemonSlot(pokemonIndex, npcName.ShareData(), professorOakNpc, tool, npcName);

    string chosenName = basePokemon.GetPokemonName(pokemonIndex);

    PokemonType chosenType;
    if (pokemonIndex == 1) chosenType = PokemonType::FIRE;
    else if (pokemonIndex == 2) chosenType = PokemonType::GRASS;
    else if (pokemonIndex == 3) chosenType = PokemonType::WATER;
    else chosenType = PokemonType::NORMAL;

    // Create actual and copied Pokémon
    Pokemon selectedPokemon(chosenName, chosenType, 100);
    Pokemon clonedPokemon(selectedPokemon); 

    npcName.PlayerListDataContainer(1, chosenName);

    // Dialogue 9–10
    cout << "\n\n" << whiteColor << npcName.PlayerListInGame(0);
    tool.TypeWrtingEffect(professorOakNpc.ProfessorOakDialogue(9, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), npcName.ShareData()), 0.05);

    cout << "\n" << whiteColor << npcName.PlayerListInGame(0);
    tool.TypeWrtingEffect(professorOakNpc.ProfessorOakDialogue(10, tool.WhiteSpaceLength(npcName.PlayerListInGame(0)), npcName.ShareData()), 0.05);

    // Display both Pokémon
    cout << "\n\n" << AC_GREEN << "[Selected Pokémon Info]\n";
    selectedPokemon.Display();
    cout << AC_CYAN << "[Cloned Pokémon Info]\n";
    clonedPokemon.Display();

    return 0;
}
