#include <iostream>
#include <ctime>

using namespace std;


void PrintInstructions(int Difficulty) 
{
    // to tell the user what this is about
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room...\nEnter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty){


    PrintInstructions(Difficulty);
    // starting declarations of variables
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    // getting the sum and the multiply
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // print the multiplycation and sum in the terminal
    cout << "+ there are 3 numbers in the code\n";
    cout << "+ the code multipy to give: " << CodeProduct;
    cout << "\n+ the code adds up to : " << CodeSum;
    cout << "\n\n";

    // player guesses
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    // player guess sum and product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // winning conditions
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "\nYou Managed to find the correct code" << endl;
        return true;
    } else {
        cout << "\nYou entered the wrong code! be careful agent" << endl;
        return false;
    }
}

int main(){
    srand(time(NULL));
    int LevedDifficulty = 1;
    const int MaxLevel = 10;

    while (LevedDifficulty <= MaxLevel) // loop until we finish the game
    {

        bool bLevelComplete = PlayGame(LevedDifficulty);

        cin.clear();    // clears any errors
        cin.ignore();   // discards the buffer

        if (bLevelComplete) {
            ++LevedDifficulty;
        }   
    }

    cout << "You got all the files agent..." << endl;
    cout << "Congratulations on completing the game" << endl;
    
    return 0;
}