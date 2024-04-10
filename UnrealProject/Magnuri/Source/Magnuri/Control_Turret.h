// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Turret.h"
#include "Control_Turret.generated.h"

/**
 * 
 */
UCLASS()
class MAGNURI_API AControl_Turret : public ABase_Turret
{
	GENERATED_BODY()
	
public:
	AControl_Turret();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UStaticMeshComponent* TurMesh;
	void UpDown(float Vaule);
	void Turn(float Vaule);

	APlayerController* Turret_Controller;

};
