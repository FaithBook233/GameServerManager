// Copyright © 2023 Chen Feng All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameServerManagerInstance.generated.h"

struct FServerInfo
{
	FString ServerName;
	FGuid HomeOwner;
	int32 Port;
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
	void CloseServer(FProcHandle& procHandle); // TODO 未验证
	void CloseAllServer();
	bool IsServerRunning(FProcHandle& procHandle) const;

private:
	FString mServerPath;
	TArray<FProcHandle> mServers;
};
