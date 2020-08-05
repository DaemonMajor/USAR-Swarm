#include "USARAgent.h"


/* Add survivor locations to environment map. Survivors have DETECTION_ACC chance of being successfully detected.
*/
void AUSARAgent::DetectionTask()
{
	FHitResult hitResult;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	FCollisionResponseParams responseParams;

	for (AVictimActor* vic : victimsInRange) {
		if (GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), vic->GetActorLocation(), ECC_Pawn, queryParams, responseParams)) {
			if (hitResult.GetActor()->IsA(AVictimActor::StaticClass())) {
				float didDetect = FMath::FRand();

				if (didDetect <= DETECTION_ACC) {
					FVector vicLoc = vic->GetActorLocation();

					FGridStruct* grid = AddGrid(vicLoc, false);
					grid->survivors.AddUnique(vicLoc);
				}

				/*DEBUGGING*/
				//DrawDebugPoint(GetWorld(), vic->GetActorLocation(), 25, FColor::Emerald, true, 1.f);
				/*DEBUGGING*/
			}
		}
	}
}

/* Agent behavior when a victim is detected.
*
*/
void AUSARAgent::OnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.AddUnique(Cast<AVictimActor>(victim));
	}
}

/* Agent behavior when a victim leaves the range of agent's sensors.
*
*/
void AUSARAgent::OnUnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.Remove(Cast<AVictimActor>(victim));
	}
}