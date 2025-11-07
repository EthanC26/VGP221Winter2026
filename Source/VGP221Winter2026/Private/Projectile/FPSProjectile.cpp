// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(15.0f);
		CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
		RootComponent = CollisionComponent;
	}
	if (!ProjectileMesh)
	{
		ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));

		//1. Setup an imported mesh
		static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Meshes/Projectile/Sphere.Sphere"));

		//2. Get Assest from Unreal
		//static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Engine/BasicShapes/Sphere"));

		if (MeshAsset.Succeeded())
			ProjectileMesh->SetStaticMesh(MeshAsset.Object);
		
		//setting up material for sphere
		static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Materials/Projectiles/M_Projectile.M_Projectile"));
		if (MaterialAsset.Succeeded())
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(MaterialAsset.Object, ProjectileMaterialInstance);


		ProjectileMesh->SetMaterial(0, ProjectileMaterialInstance);
		ProjectileMesh->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMesh->SetupAttachment(RootComponent);
	}

	if (!ProjectileMovementComponent) {

		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = BulletSpeed;
		ProjectileMovementComponent->MaxSpeed = BulletSpeed;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	}

	InitialLifeSpan = 3.0f;// unity destory(3.0f)

}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection) //(1, 0, 0)
{
	//1.FVector ShootDirection: Pass by value, least efficient, basically just duplicating the data and giving it to you
	//2.FVector* ShootDirection: Pass Pointer Memeory, efficient cus memeory address. 
	// but need to dereference the pointer to get the vlaue
	// 3. FVector& ShootDirection: Pass by Reference, most efficient, no duplication of data, 
	// no pointer dereferencing, just an alias to the original data or think of it as a out
	//4.cosnt FVector& ShootDirection: pass by reference but read only, cannot modify the original data effiecent and safe

	ProjectileMovementComponent->Velocity = ProjectileMovementComponent->InitialSpeed * ShootDirection;
}

void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		Destroy();
	}
}
