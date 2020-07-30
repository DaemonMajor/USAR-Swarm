#include "USARAgent.h"

/* Add survivor locations to environment map. Survivors have DETECTION_ACC chance of being successfully detected.
*/
void AUSARAgent::DetectionTask()
{
	for (AVictimActor* victim : victimsInRange) {
		float didDetect = FMath::FRand();

		if (didDetect <= DETECTION_ACC) {
			FVector vicLoc	= victim->GetActorLocation();
			int x		= (int)vicLoc.X - (int)vicLoc.X % GRID_SIZE;
			int y		= (int)vicLoc.Y - (int)vicLoc.Y % GRID_SIZE;
			int z		= (int)vicLoc.Z - (int)vicLoc.Z % GRID_SIZE;
			float conf	= CONF_INCR * FVector::DistXY(vicLoc, GetActorLocation());

			FLocGridStruct grid = FLocGridStruct(x, y, z, conf, GetWorld()->GetTimeSeconds());

			int idx;
			bool isNewGrid = grid.InsertInMap(envMap, idx);
			if (!isNewGrid) {
				envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + conf, 0.f, 1.f);
			}

			envMap[idx].survivors.AddUnique(vicLoc);
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