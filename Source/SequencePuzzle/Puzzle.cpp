// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle.h"
#include "PuzzleButtonElement.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APuzzle::APuzzle() : 
	NumberOfButtons(4), 
	DitanceFromCenter(70)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	FillTheSequence();

}

void APuzzle::Guess(int32 Guess)
{
	//UE_LOG(LogTemp, Warning, TEXT("This is the sample log"));
	int32 Actual = Sequence[SequenceIndex];
	if (Guess == Actual)
	{
		UE_LOG(LogTemp, Warning, TEXT("Correct"));
		SequenceIndex++;
		if (SequenceIndex == Sequence.Num())
		{
			SequenceIndex = 0;
			FillTheSequence();
			PlaySequence();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Incorrect"));
		SequenceIndex = 0;
		Sequence.Empty();
		FillTheSequence();
		PlaySequence();
	}
}

// Called when the game starts or when spawned
void APuzzle::BeginPlay()
{
	Super::BeginPlay();

	FLinearColor Colors[] = {FLinearColor(1,0,0,0), FLinearColor(0,1,0,0) , FLinearColor(0,0,1,0) , FLinearColor(1,1,0,0) };

	UWorld* World = GetWorld();
	if (World)
	{

		FVector OffsetVector(DitanceFromCenter, 0, DitanceFromCenter);

		const FRotator Rotator(90, 0, 0);

		for (int32 i = 0; i < NumberOfButtons; i++) 
		{
			FTransform Transform = GetTransform();
			Transform.SetLocation(OffsetVector);
			
			APuzzleButtonElement* Button = Cast<APuzzleButtonElement>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ButtonClass, Transform));
			Button->Color = Colors[i]; 
			Button->Index = i;
			Button->Puzzle = this;
			Buttons.Add(Button);
			UGameplayStatics::FinishSpawningActor(Button, Transform);

			OffsetVector = Rotator.RotateVector(OffsetVector);
		}

		


	}
	
}

void APuzzle::FillTheSequence()
{
	int32 ToAdd = FMath::RandRange(0, NumberOfButtons-1);
	Sequence.Add(ToAdd);
}



