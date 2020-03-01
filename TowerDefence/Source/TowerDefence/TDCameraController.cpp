// Fill out your copyright notice in the Description page of Project Settings.


#include "TDCameraController.h"
#include "TDCameraPawn.h"






// Functions
ATDCameraController::ATDCameraController()
{
	bShowMouseCursor = true;
	//DefaultMouseCursor = EMouseCursor::Crosshairs;
}





void ATDCameraController::PlayerTick(float deltaTime)
{
	InitCameraPawn();
	ScreenCameraMovement();


	Super::PlayerTick(deltaTime);
}





void ATDCameraController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Mouse / Keyboard
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATDCameraController::PlaceTowerClick);

	InputComponent->BindAxis("MoveHorizontal", this, &ATDCameraController::MoveHorizontal);
	InputComponent->BindAxis("MoveVerticle", this, &ATDCameraController::MoveVerticle);
	InputComponent->BindAxis("Rotate", this, &ATDCameraController::Rotate);
	InputComponent->BindAxis("Tilt", this, &ATDCameraController::Tilt);
	InputComponent->BindAxis("Zoom", this, &ATDCameraController::Zoom);

	// TouchScreen
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATDCameraController::PlaceTowerTouch);

}





void ATDCameraController::InitCameraPawn()
{
	if (!mCameraPawn)
		mCameraPawn = Cast<ATDCameraPawn>(GetPawn());
}






//====================================================================================================
//		Tower Placement
//----------------------------------------------------------------------------------------------------
void ATDCameraController::PlaceTowerClick()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something
	}
}





void ATDCameraController::PlaceTowerTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something
	}
}





void ATDCameraController::ScreenCameraMovement()
{
	// Get Viewport and Mouse Pos
	FVector2D viewPortSize(GEngine->GameViewport->Viewport->GetSizeXY());
	FVector2D mousePos;
	GetMousePosition(mousePos.X, mousePos.Y);

	// Set Up Buffers
	int32 leftBuffer = viewPortSize.X * 0.1;
	int32 rightBuffer = viewPortSize.X * 0.9;

	int32 topBuffer = viewPortSize.Y * 0.1;
	int32 bottomBuffer = viewPortSize.Y * 0.9;

	// Check mouse position
	if      (mousePos.X < leftBuffer)   MoveHorizontal(-1.0f);
	else if (mousePos.X > rightBuffer)  MoveHorizontal(1.0f);

	if      (mousePos.Y < topBuffer)    MoveVerticle(1.0f);
	else if (mousePos.Y > bottomBuffer) MoveVerticle(-1.0f);

	// Prevent the camera from going to far from the map
	BindCameraToRegion();

	// Debug Logging
	FVector currentCameraPos = mCameraPawn->GetActorLocation();
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, FString::Printf(TEXT("Camera Pos: x: %f, y: %f"), currentCameraPos.X, currentCameraPos.Y));
}





void ATDCameraController::MoveHorizontal(float direction)
{
	InitCameraPawn();
	FVector currentCameraPos = mCameraPawn->GetActorLocation();
	FVector rightVec   = mCameraPawn->GetActorRightVector();
	rightVec.Z = 0;
	rightVec.Normalize();

	mCameraPawn->SetActorLocation(currentCameraPos + (rightVec * direction * mMoveSpeed));
}





void ATDCameraController::MoveVerticle(float direction)
{
	InitCameraPawn();
	FVector currentCameraPos = mCameraPawn->GetActorLocation();
	FVector forwardVec = mCameraPawn->GetActorForwardVector();
	forwardVec.Z = 0;
	forwardVec.Normalize();

	mCameraPawn->SetActorLocation(currentCameraPos + (forwardVec * direction * mMoveSpeed));
}





void ATDCameraController::Rotate(float direction)
{
	InitCameraPawn();
	FRotator rotation = mCameraPawn->GetActorRotation();
	rotation.Yaw += (mRotationSpeed * direction);
	mCameraPawn->SetActorRotation(rotation);
}





void ATDCameraController::Tilt(float direction)
{
	InitCameraPawn();
	FRotator rotation = mCameraPawn->GetActorRotation();
	rotation.Pitch += (mTiltSpeed * direction);
	// Keep the tilt within sane values
	if (rotation.Pitch < -84.0f) rotation.Pitch = -84.0f;
	else if (rotation.Pitch > -48.0f) rotation.Pitch = -48.0f;
	mCameraPawn->SetActorRotation(rotation);
}





void ATDCameraController::Zoom(float direction)
{
	InitCameraPawn();
	FVector currentCameraPos = mCameraPawn->GetActorLocation();
	FVector forwardVec = mCameraPawn->GetActorForwardVector();

	FVector newCameraPos = currentCameraPos + (forwardVec * direction * mZoomSpeed);

	// Keep Zoom within sane values
	if (newCameraPos.Z > 2000 && newCameraPos.Z < 4700)
		mCameraPawn->SetActorLocation(newCameraPos);
}





void ATDCameraController::BindCameraToRegion()
{
	InitCameraPawn();
	FVector currentCameraPos = mCameraPawn->GetActorLocation();

	if      (currentCameraPos.X < -2500)  currentCameraPos.X = -2500;
	else if (currentCameraPos.X >  2500)  currentCameraPos.X =  2500;

	if      (currentCameraPos.Y < -2500)  currentCameraPos.Y = -2500;
	else if (currentCameraPos.Y >  2500)  currentCameraPos.Y =  2500;

	mCameraPawn->SetActorLocation(currentCameraPos);
}