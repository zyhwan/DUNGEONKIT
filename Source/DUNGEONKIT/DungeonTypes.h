#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DungeonTypes.generated.h"

UENUM()
enum class ERoomType : uint8
{
    ADMonsterRoom   UMETA(DisplayName = "ADMonsterRoom"),
    APMonsterRoom   UMETA(DisplayName = "APMonsterRoom"),
    RewardRoom      UMETA(DisplayName = "RewardRoom"),
    HallWay         UMETA(DisplayName = "HallWay"),
    StartRoom       UMETA(DisplayName = "StartRoom"),
    BossRoom        UMETA(DisplayName = "BossRoom")
};

USTRUCT(BlueprintType)
struct FDungeonData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ERoomType RoomType = ERoomType::HallWay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> RoomClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Weight = 1.0f;
};