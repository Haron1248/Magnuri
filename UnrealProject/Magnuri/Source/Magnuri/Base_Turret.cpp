// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Turret.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABase_Turret::ABase_Turret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;

	RotateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RotateMesh->SetupAttachment(CapsuleComponent);

	UpDownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpDownMesh"));
	UpDownMesh->SetupAttachment(RotateMesh);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(UpDownMesh);

	

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

// Called when the game starts or when spawned
void ABase_Turret::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABase_Turret::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation_Yaw = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	FRotator LookAtRotation_Turret = FRotator(0.f,0.f, ToTarget.Rotation().Roll);
	RotateMesh->SetWorldRotation(
		FMath::RInterpTo(RotateMesh->GetComponentRotation(),
		LookAtRotation_Yaw,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		TurnSpeed)
	);
	TurretMesh->AddLocalRotation(LookAtRotation_Turret, true);
}

// Called every frame
void ABase_Turret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
