// Fill out your copyright notice in the Description page of Project Settings.


#include "TDCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/DecalComponent.h"
#include "Materials/Material.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values
ATDCameraPawn::ATDCameraPawn()
{
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Create a camera...
	mTopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	mTopDownCameraComponent->SetWorldRotation(mRotation);
	mTopDownCameraComponent->SetWorldLocation(mLocation);


	// Create a decal in the world to show the cursor's location
	mCursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	mCursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/Assets/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		mCursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	mCursorToWorld->DecalSize = FVector(32.0f, 64.0f, 64.0f);
	mCursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());
}

// Called when the game starts or when spawned
void ATDCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATDCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if (mCursorToWorld != nullptr)
		{
			mCursorToWorld->SetHiddenInGame(false);
			FHitResult TraceHitResult;
			playerController->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			mCursorToWorld->SetWorldLocation(TraceHitResult.Location);
			mCursorToWorld->SetWorldRotation(CursorR);

			if (TraceHitResult.Location == FVector(0, 0, 0))
			{
				mCursorToWorld->SetHiddenInGame(true);
			}
		}
	}
}
