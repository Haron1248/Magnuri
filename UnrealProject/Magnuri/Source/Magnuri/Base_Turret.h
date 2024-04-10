// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Base_Turret.generated.h"

UCLASS()
class MAGNURI_API ABase_Turret : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABase_Turret();

public:
	UPROPERTY(EditAnywhere, Category = "Move")
	float UpDownSpeed = 30.f;
	UPROPERTY(EditAnywhere, Category = "Move")
	float TurnSpeed = 30.f;
	UPROPERTY(EditAnywhere, Category = "Move")
	float UpLimit = 30.f;
	UPROPERTY(EditAnywhere, Category = "Move")
	float DownLimit = -10.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	void RotateTurret(FVector LookAtTheTarget);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* RotateMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* UpDownMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetTurretMesh(){return TurretMesh;};
	// Called to bind functionality to input
	
};
