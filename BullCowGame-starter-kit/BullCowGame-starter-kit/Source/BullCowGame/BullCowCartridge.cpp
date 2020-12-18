// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
// #include "Math/UnrealMathUtility.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    if(bGameOver){
        ClearScreen();
        SetupGame();
        return;
    }
    else 
    {
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{
    // welcoming the player
    PrintLine(TEXT("Welcome to the BullCow game"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)]; // set the hiddenword
    Lives = HiddenWord.Len(); // set lives
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and press the enter key")); // prompt Player for a guess
    PrintLine(TEXT("The hiddenword is: %s"), *HiddenWord);
}

// create end game funciton
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won"));
        EndGame();
        return;
    }
    
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating characters, guess again!"));
        return;
    }

    if(Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("You have lost a life and have %i, \ntry again"), Lives);
        PrintLine(TEXT("The HiddenWord is %i long"), HiddenWord.Len());
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
    FBullCowCount Score = GetBullCow(Guess);

    PrintLine(TEXT("you have %i Bulls, and %i Cows"), Score.Bulls, Score.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for(int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if(Word[Index] == Word[Comparison]){
                return false;
            }
        }
    }

    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordsList) const
{
    TArray<FString> ValidWords;

    for(FString Word : WordsList)
    {
        if(Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCow(const FString& Guess) const
{
    FBullCowCount Count;
 
    for(int32 GuessI = 0; GuessI < Guess.Len(); GuessI++)
    {
        if(Guess[GuessI] == HiddenWord[GuessI])
        {
            Count.Bulls++;
            continue;
        }
        for(int32 GuessX = 0; GuessX < HiddenWord.Len(); GuessX++)
        {
            if(Guess[GuessI] == HiddenWord[GuessX])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}