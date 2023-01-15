// Copyright © 2023 Chen Feng All rights reserved.

#pragma once

#include "CoreMinimal.h"

DEFINE_LOG_CATEGORY_STATIC(ServerLog, Log, All);

#define ensureLog(inExpresion, inFormat, ...) ensure(inExpresion); if(!inExpresion) UE_LOG(ServerLog, Log, inFormat, ##__VA_ARGS__);
#define ensureWarning(inExpresion, inFormat, ...) ensure(inExpresion); if(!inExpresion) UE_LOG(ServerLog, Warning, inFormat, ##__VA_ARGS__);
#define ensureError(inExpresion, inFormat, ...) ensure(inExpresion); if(!inExpresion) UE_LOG(ServerLog, Error, inFormat, ##__VA_ARGS__);
