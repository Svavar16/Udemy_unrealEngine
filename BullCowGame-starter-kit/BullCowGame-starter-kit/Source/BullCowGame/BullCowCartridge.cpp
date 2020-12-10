// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
   
    SetupGame();
   
    PrintLine(TEXT("The hiddenword is: %s"), *HiddenWord);
    // welcoming the player
    PrintLine(TEXT("Welcome to the BullCow game"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press the enter key"));

    // prompt Player for a guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();    

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You have Won"));
    } 
    else 
    {
        if(Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long, try again"), HiddenWord.Len());
        }
        PrintLine(TEXT("You have Lost"));
    }
    // check if isogram
    // prompt to GuessAgain
    // check number of characters
    // prompt to GuessAgain
    // remove a life

    // check if lives > 0
    // if yes GuessAgain
    // show lives left
    // if no show game is over show the HiddenWord
    // prompt to play again, press enter to play again.
    // check user input
    // PlayAgain or Quit
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes"); // set the hiddenword

    Lives = 3; // set lives
}

