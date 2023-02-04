// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpectralRoots : ModuleRules
{
	public SpectralRoots(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "FMODStudio" });

		PrivateIncludePaths.AddRange(new string[] {
			"SpectralRoots"
		});
		/*
		PrivateIncludePaths.AddRange(new string[] {
			"SpectralRoots/Dict",
			"SpectralRoots/GameMode",
			"SpectralRoots/GameMode/Tree",
			"SpectralRoots/Interface",
			"SpectralRoots/Player",
			"SpectralRoots/Sound",
			"SpectralRoots/Utils"
		});
		 */
	}
}
