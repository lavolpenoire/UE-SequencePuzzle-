// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleButtonElement.generated.h"

UCLASS()
class SEQUENCEPUZZLE_API APuzzleButtonElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleButtonElement();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Highlight(bool bIsHighlight);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	UPROPERTY(BlueprintReadOnly)
	FLinearColor Color;

	UPROPERTY(BlueprintReadOnly)
	class APuzzle* Puzzle;

	UPROPERTY(BlueprintReadOnly)
		int32 Index;

};
