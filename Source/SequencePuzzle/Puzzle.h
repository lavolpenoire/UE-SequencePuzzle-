// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle.generated.h"

class APuzzleButtonElement;

UCLASS()
class SEQUENCEPUZZLE_API APuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlaySequence();

	UFUNCTION(BlueprintCallable)
	void Guess(int32 Guess);

protected:
	// Called when the game starts or when spawned 
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<APuzzleButtonElement> ButtonClass;

	int32 NumberOfButtons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DitanceFromCenter;

	UPROPERTY(BlueprintReadOnly)
	TArray<APuzzleButtonElement*> Buttons;

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Sequence;

private:

	//Add to the sequence
	void FillTheSequence();

	//
	int32 SequenceIndex;

};
