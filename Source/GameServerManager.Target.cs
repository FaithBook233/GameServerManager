// Copyright © 2023 Chen Feng All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GameServerManagerTarget : TargetRules
{
	public GameServerManagerTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("GameServerManager");
	}
}
