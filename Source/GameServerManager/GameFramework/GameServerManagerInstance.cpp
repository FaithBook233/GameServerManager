// Copyright © 2023 Chen Feng All rights reserved.


#include "GameFramework/GameServerManagerInstance.h"
#include "GameServerManager.h"
UGameServerManagerInstance::UGameServerManagerInstance()
{
	InitServerPath();
}

void UGameServerManagerInstance::InitServerPath()
{
	TArray<FString> commandLines, switches;
	FCommandLine::Parse(FCommandLine::Get(), commandLines, switches);
	for (auto& lineStr : commandLines)
	{
		if (FPaths::FileExists(*lineStr))
		{
			mServerPath = lineStr;
			break;
		}
	}
}

bool UGameServerManagerInstance::IsServerRunning(FProcHandle& procHandle) const
{
	return FPlatformProcess::IsProcRunning(procHandle);
}

FProcHandle UGameServerManagerInstance::OpenAServer()
{
	const auto& newGuid = FGuid::NewGuid();
	auto newHandler = FPlatformProcess::CreateProc(*mServerPath, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
	ensureError(IsServerRunning(newHandler), TEXT("服务器启动失败，服务器URL : %s"), *mServerPath);
	if (IsServerRunning(newHandler))
	{
		mServers.Add(newHandler);
	}

	return newHandler;
}

void UGameServerManagerInstance::CloseServer(FProcHandle& procHandle)
{
	FPlatformProcess::CloseProc(procHandle);
}
