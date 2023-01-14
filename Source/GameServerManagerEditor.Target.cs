// Copyright © 2023 Chen Feng All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GameServerManagerEditorTarget : TargetRules
{
	public GameServerManagerEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("GameServerManager");
	}
}
