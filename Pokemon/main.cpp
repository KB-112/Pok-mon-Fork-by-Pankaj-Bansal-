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





void ClearPreviousLine() {
    printf("\x1b[1A");
    printf("\33[2K\r");
}

bool IntConstraintVerification( string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isdigit(c)) return false;  
    }
    return true;
}


string PlayerListInGame(int index)
{
    map<int, string> playerName;

    playerName[0] = "Professor Oak :";





    return playerName[index];
}
map<int, string>& ShareData() {
    static map<int, string> playerList;
    return playerList;
}

map<int, string> PlayerListDataContainer(int index, string playerName)
{
    ShareData()[index] = playerName; 
    return ShareData();             
}




int WhiteSpaceLength(string playerName)
{
    int temp = playerName.length();

    return temp;
}

string  ProfessorOakDialogue(int index, int whiteSpace, map<int, string> dyanmicUserName)
{
    string color[] = { AC_BLACK, AC_RED, AC_GREEN, AC_YELLOW,
     AC_BLUE, AC_MAGENTA, AC_CYAN, AC_WHITE,
     AC_NORMAL,AC_ORANGE };

    map<int, string> dialogue;

    //Loading Color
    Sleep(100);

    dialogue[0] = color[6] + "Hello there! Welcome to the world of Pokemon!\n"
        + string(whiteSpace, ' ') + "My name is Oak. People call me the Pokemon Professor!\n"
        + string(whiteSpace, ' ') + "But enough about me. Let's talk about you!\n"
        + string(whiteSpace, ' ') + "First, tell me, what’s your name?\n";




    dialogue[1] = color[6] + "Ah," + dyanmicUserName[0] + "\n"
        + string(whiteSpace, ' ') + +"What a fantastic name!\n";



    dialogue[2] = color[6] + "You must be eager to start your adventure.\n"
        + string(whiteSpace, ' ') + "But ,first, you’ll need a Pokemon of your own!\n";


    dialogue[3] = color[6] + "I have three Pokemon here with me.They’re all quite feisty!\n";


    dialogue[4] = color[1] + "Choose wisely...\n" + color[2]
        + string(whiteSpace, ' ') + "1. Charmander - The fire type. A real hothead!\n"
        + string(whiteSpace, ' ') + "2. Bulbasaur - The grass type. Calm and collected!\n"
        + string(whiteSpace, ' ') + "3. Squirtle - The water type. Cool as a cucumber!\n";


    dialogue[5] = color[1] + " So, which one will it be? Enter the number of your choice: ";

    dialogue[6] = color[9] + "\nA fiery choice!Charmander is yours!\n" + color[7];
    dialogue[7] = color[3] + "\nA fine choice!Bulbasaur is always ready to grow on you!" + color[7];
    dialogue[8] = color[4] + "\nSplendid!Squirtle will keep you cool under pressure!\n";

   
    dialogue[9] = color[6] + dyanmicUserName[0] + " and you, " + dyanmicUserName[1] + ", are going to be the best of friends!\n";

    dialogue[10] = color[6] + "Your journey begins now!Get ready to explore the vast world of Pokemon!\n" + color[7];

    return dialogue[index];
}

string MainPlayerDialogue(int index, int whiteSpace)
{
    map<int, string> dialogue;
    string whiteColor = AC_NORMAL;
    dialogue[0] = whiteColor + "Enter Your Name: ";

    return dialogue[index];
}

string  TypeWrtingEffect(string dialogue, double time)
{
    char ch;
    bool skip = false;


    for (int i = 0; i < dialogue.length(); i++)
    {
        if (!skip && _kbhit())
        {
            ch = _getch();
            if (ch == '\r')
            {
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

enum class PokemonNature
{
    Fire,
    Electric,
    Water,
    Earth,
    Normal
};
enum class PokemonChoice {
    Charmander,
    Bulbasaur,
    Squirtle,
    InvalidChoice
};

void ChosenPokemon(int pokemonIndex, map<int, string> dyanmicUserName)
{
    PokemonChoice chosenPokemon;

    switch (pokemonIndex) {
    case 1:
        chosenPokemon = PokemonChoice::Charmander;
        break;
    case 2:
        chosenPokemon = PokemonChoice::Bulbasaur;
        break;
    case 3:
        chosenPokemon = PokemonChoice::Squirtle;
        break;
    default:
        chosenPokemon = PokemonChoice::InvalidChoice;
        break;
    }

    switch (chosenPokemon) {
    case PokemonChoice::Charmander:
        cout << ProfessorOakDialogue(6, WhiteSpaceLength(PlayerListInGame(0)), dyanmicUserName);
        break;
    case PokemonChoice::Bulbasaur:
        cout << ProfessorOakDialogue(7, WhiteSpaceLength(PlayerListInGame(0)), dyanmicUserName);
        break;
    case PokemonChoice::Squirtle:
        cout << ProfessorOakDialogue(8, WhiteSpaceLength(PlayerListInGame(0)), dyanmicUserName);
        break;
    default:
        cout << AC_RED << "\nInvalid Pokémon selection.\n";
        break;
    }
}


string GetPokemonName(int pokemonIndex) {
    switch (pokemonIndex) {
    case 1: return "Charmander";
    case 2: return "Bulbasaur";
    case 3: return "Squirtle";
    default: return "";
    }
}
void PokemonSlot(int &pokemonIndex, map<int, string> dynamicUserName) {
    string tempStr;

    cout << "\n";

    while (true) {
        // Professor Oak Dialogue 5
        cout << AC_WHITE << PlayerListInGame(0);
        cout << ProfessorOakDialogue(5, WhiteSpaceLength(PlayerListInGame(0)), dynamicUserName);
        cout << AC_GREEN;
       
        getline(cin, tempStr);
      
        if (tempStr.empty())
        {
            ClearPreviousLine(); 
            continue;
            
        }
        else
        {
            if (!IntConstraintVerification(tempStr)) {
                cout << AC_RED << "Invalid input. Please enter a digit between 1 and 3.\n";
                Sleep(1000);
                ClearPreviousLine();
                ClearPreviousLine();
                continue;
            }
        }
       
      

        pokemonIndex = stoi(tempStr);

        if (pokemonIndex < 1 || pokemonIndex > 3) {
            cout << AC_RED << "Out of range. Enter a number between 1 and 3.\n";
            Sleep(1000);
            ClearPreviousLine();
            ClearPreviousLine();
            continue;
        }

        break;
    }

    ClearPreviousLine();
    // Professor Oak Dialogue 5
    cout << AC_WHITE << PlayerListInGame(0);
    cout << ProfessorOakDialogue(5, WhiteSpaceLength(PlayerListInGame(0)), dynamicUserName) << pokemonIndex << "\n";


    ChosenPokemon(pokemonIndex, dynamicUserName);
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

string UserInputFormat(string userName, string userIntro) {
    bool isStatus = true;
    string temp;
    cout << "\n\n";
    while (true) {
        ClearPreviousLine();
        cout << userIntro << flush;
        cout << AC_GREEN;
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
        temp = userName;
        cout << userIntro << flush << temp << "\n";

    }

    return temp;
}

// 0 : Prof Oak

int main() {
    string playerName;
    int pokemonIndex = 0;
   
    string whiteColor = AC_NORMAL;


    // Professor Oak Dialogue 0 
    cout << whiteColor << PlayerListInGame(0);
    TypeWrtingEffect(ProfessorOakDialogue(0, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

    // User Input Verfication
    playerName = UserInputFormat(playerName, MainPlayerDialogue(0, WhiteSpaceLength(playerName)));

    // Dynamic List index 0 
    PlayerListDataContainer( 0, playerName);

    // Professor Oak Dialogue 1 
    cout << "\n" << whiteColor << PlayerListInGame(0);
    TypeWrtingEffect(ProfessorOakDialogue(1, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

    // Professor Oak Dialogue 2 
    cout << "\n" << whiteColor << PlayerListInGame(0);
    TypeWrtingEffect(ProfessorOakDialogue(2, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

    // Professor Oak Dialogue 3
    cout << "\n" << whiteColor << whiteColor << PlayerListInGame(0);
    TypeWrtingEffect(ProfessorOakDialogue(3, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

    // Professor Oak Dialogue 4 
    cout << "\n" << whiteColor << PlayerListInGame(0);
    TypeWrtingEffect(ProfessorOakDialogue(4, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

    if (playerName.length() != 0) {

        PokemonSlot(pokemonIndex, ShareData());
        // Dynamic List index 0 
      
      
        PlayerListDataContainer(1,GetPokemonName(pokemonIndex));
        // Professor Oak Dialogue 9 
        cout << "\n\n" << whiteColor << PlayerListInGame(0);
        TypeWrtingEffect(ProfessorOakDialogue(9, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);

        // Professor Oak Dialogue 10
        cout << "\n" << whiteColor << PlayerListInGame(0);
        TypeWrtingEffect(ProfessorOakDialogue(10, WhiteSpaceLength(PlayerListInGame(0)), ShareData()), 0.05);
    }

    return 0;
}