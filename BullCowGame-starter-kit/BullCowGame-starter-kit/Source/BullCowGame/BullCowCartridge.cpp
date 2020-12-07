// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    // welcoming the player
    PrintLine(TEXT("Welcome to the BullCow game"));
    PrintLine(TEXT("Guess the 4 letter word")); // remove the magic number!
    PrintLine(TEXT("Input something and press the enter key"));

    // setting up the games
    HiddenWord = TEXT("cake");
    // set lives

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