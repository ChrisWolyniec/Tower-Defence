// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TDCameraPawn.generated.h"

UCLASS()
class TOWERDEFENCE_API ATDCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATDCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* mTopDownCameraComponent;


	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* mCursorToWorld;


	/* Camera Offset */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		FVector mLocation = FVector(0, 0, 3000);

	/* Camera Rotation */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		FRotator mRotation = FRotator(-60.f, 0.f, 0.f);
};
