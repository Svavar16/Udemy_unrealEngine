// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the BullCow game"));
    PrintLine(TEXT("Guess the 4 letter word"));
    PrintLine(TEXT("Input something and press the enter key"));
    HiddenWord = TEXT("cake");
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
}