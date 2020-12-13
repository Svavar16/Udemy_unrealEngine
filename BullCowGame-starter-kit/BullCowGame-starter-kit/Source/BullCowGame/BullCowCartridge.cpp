// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
   
    SetupGame();
   
    PrintLine(TEXT("The hiddenword is: %s"), *HiddenWord);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver){
        ClearScreen();
        SetupGame();
        return;
    }
    else 
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    // welcoming the player
    PrintLine(TEXT("Welcome to the BullCow game"));

    HiddenWord = TEXT("cakes"); // set the hiddenword
    Lives = HiddenWord.Len(); // set lives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and press the enter key")); // prompt Player for a guess


    /* const TCHAR HW[] = TEXT("plums");
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // prints "c"
    PrintLine(TEXT("The fourth character of HW is: %c"), HW[3]); // prints "m" */
}

// create end game funciton
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won"));
        EndGame();
        return;
    }
    
    if(Guess.Len() == HiddenWord.Len())
    {
        PrintLine(TEXT("You have lost a life and have %i, \ntry again"), Lives);
        PrintLine(TEXT("The HiddenWord is %i long"), HiddenWord.Len());
        return;
    } 

    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating characters, guess again"));
        return;
    }

    // remove a life
    PrintLine(TEXT("Lost a life!"));
    --Lives;

    // check if lives > 0
    if(Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left."));
        PrintLine(TEXT("The HiddenWord was: %s."), *HiddenWord);
        EndGame(); 
        return;
    }

    // show the player the Bulls And Cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    // loop through the word
    // check Word agains HiddenWord
    // if it has two same letters, return false
    // else return true
    return true;
}