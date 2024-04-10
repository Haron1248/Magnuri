// Fill out your copyright notice in the Description page of Project Settings.


#include "Control_Turret.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


AControl_Turret::AControl_Turret(){
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    TurMesh = GetTurretMesh();

    UpDownSpeed = 50.f;
    TurnSpeed = 30.f;
    UpLimit = 30.f;
    DownLimit = -10.f;
}

void AControl_Turret::BeginPlay()
{
    Super::BeginPlay();

    Turret_Controller = Cast<APlayerController>(GetController());
}

void AControl_Turret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AControl_Turret::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("UpDown"),this,&AControl_Turret::UpDown);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AControl_Turret::Turn);
    
}

void AControl_Turret::UpDown(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    if(TurMesh == nullptr) return;
    
	FRotator CntLocalRotation = TurMesh->GetRelativeRotation();

    CntLocalRotation.Roll += Vaule*DeltaTime*UpDownSpeed;
	CntLocalRotation.Roll = FMath::ClampAngle(CntLocalRotation.Roll,DownLimit,UpLimit);

    TurMesh->SetRelativeRotation(CntLocalRotation,true);

	UE_LOG(LogTemp,Display,TEXT("now : %f"),TurMesh->GetRelativeRotation().Roll);
}

void AControl_Turret::Turn(float Vaule)
{
    double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FRotator DeltaRotation(0.f);
    DeltaRotation.Yaw += Vaule*DeltaTime*TurnSpeed;
    AddActorLocalRotation(DeltaRotation,true);

}