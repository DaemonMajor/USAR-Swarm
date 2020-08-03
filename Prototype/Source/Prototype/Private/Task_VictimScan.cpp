#include "USARAgent.h"

/* Add survivor locations to environment map. Survivors have DETECTION_ACC chance of being successfully detected.
*/
void AUSARAgent::DetectionTask()
{
	for (AVictimActor* victim : victimsInRange) {
		float didDetect = FMath::FRand();

		if (didDetect <= DETECTION_ACC) {
			FVector vicLoc	= victim->GetActorLocation();
			
			FGridStruct* grid = AddGrid(vicLoc, false);
			grid->survivors.AddUnique(vicLoc);
		}
	}
}

/* Checks detected actors for victims
*
*	@return The number of victims detected.
*/
int AUSARAgent::CheckDetections()
{
	int numPosIDs = 0;

	FHitResult hitResult;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	FCollisionResponseParams responseParams;

	for (AVictimActor* vic : victimsInRange) {
		if (GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), vic->GetActorLocation(), ECC_Pawn, queryParams, responseParams)) {
			if (hitResult.GetActor()->IsA(AVictimActor::StaticClass())) {
				numPosIDs++;

				/*DEBUGGING*/
				DrawDebugPoint(GetWorld(), vic->GetActorLocation(), 25, FColor::Emerald, true, 1.f);
				/*DEBUGGING*/
			}
		}
	}

	return numPosIDs;
}