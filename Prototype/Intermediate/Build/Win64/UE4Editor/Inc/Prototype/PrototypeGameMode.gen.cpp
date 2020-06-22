// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/PrototypeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototypeGameMode() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeGameMode_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void APrototypeGameMode::StaticRegisterNativesAPrototypeGameMode()
	{
	}
	UClass* Z_Construct_UClass_APrototypeGameMode_NoRegister()
	{
		return APrototypeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APrototypeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrototypeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototypeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PrototypeGameMode.h" },
		{ "ModuleRelativePath", "PrototypeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrototypeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototypeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrototypeGameMode_Statics::ClassParams = {
		&APrototypeGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_APrototypeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrototypeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrototypeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrototypeGameMode, 1962875012);
	template<> PROTOTYPE_API UClass* StaticClass<APrototypeGameMode>()
	{
		return APrototypeGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrototypeGameMode(Z_Construct_UClass_APrototypeGameMode, &APrototypeGameMode::StaticClass, TEXT("/Script/Prototype"), TEXT("APrototypeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrototypeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
