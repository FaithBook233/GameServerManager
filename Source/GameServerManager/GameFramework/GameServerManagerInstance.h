// Copyright © 2023 Chen Feng All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameServerManagerInstance.generated.h"

struct FServerInfo
{
	FString ServerName;
	FGuid HomeOwner;
	uint32 Port;
};

/**
 * 
 */
UCLASS()
class GAMESERVERMANAGER_API UGameServerManagerInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UGameServerManagerInstance();

	void InitServerPath();

	FProcHandle OpenAServer();
	void CloseServer(FProcHandle& procHandle);
	bool IsServerRunning(FProcHandle& procHandle) const;

private:
	FString mServerPath;
	TMap<FGuid, FProcHandle> mServers;
};
