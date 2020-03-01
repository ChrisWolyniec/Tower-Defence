// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TDCameraController.generated.h"

class ATDCameraPawn;
/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API ATDCameraController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATDCameraController();

private:
	virtual void PlayerTick(float deltaTime) override;
	virtual void SetupInputComponent() override;
	void InitCameraPawn();

	// Input handlers 
	void PlaceTowerClick();
	void PlaceTowerTouch(const ETouchIndex::Type FingerIndex, const FVector Location);

	// Camera Movement
	float mMoveSpeed = 10.0f;
	float mRotationSpeed = 0.5f;
	float mTiltSpeed = 0.2f;
	float mZoomSpeed = 20.0f;


	void ScreenCameraMovement();
	void MoveHorizontal(float direction);
	void MoveVerticle(float direction);
	void Rotate(float direction);
	void Tilt(float direction);
	void Zoom(float direction);
	void BindCameraToRegion();


	ATDCameraPawn* mCameraPawn;
};
