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
    /* 
    if the game is over, ClearScreen() and SetupGame() the game
    else, checking PlayerGuess 
    */
    if(bGameOver){
        ClearScreen();
        SetupGame();
    } else {
        if(Input == HiddenWord)
        {
            PrintLine(TEXT("You have Won"));
            EndGame();
        } 
        else 
        {
            --Lives;
            PrintLine(TEXT("Lost a life!"));
            if(Lives > 0)
            {
                if(Input.Len() == HiddenWord.Len())
                {
                    PrintLine(TEXT("You have lost a life and have %i, \ntry again"), Lives);
                }   
            } 
            else 
            {
                PrintLine(TEXT("You have no lives left."));
                EndGame();  
            }
        }
        // check if isogram
        // prompt to GuessAgain
        // check number of characters
        // prompt to GuessAgain
        // remove a life
    }



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
    // welcoming the player
    PrintLine(TEXT("Welcome to the BullCow game"));

    HiddenWord = TEXT("cakes"); // set the hiddenword
    Lives = HiddenWord.Len(); // set lives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and press the enter key")); // prompt Player for a guess

    // bGameOver = false
}

// create end game funciton
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("You have no lives left, press enter to continue"));
}