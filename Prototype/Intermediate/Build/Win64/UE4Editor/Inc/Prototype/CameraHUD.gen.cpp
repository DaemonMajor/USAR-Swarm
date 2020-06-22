// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/CameraHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraHUD() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_ACameraHUD_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ACameraHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void ACameraHUD::StaticRegisterNativesACameraHUD()
	{
	}
	UClass* Z_Construct_UClass_ACameraHUD_NoRegister()
	{
		return ACameraHUD::StaticClass();
	}
	struct Z_Construct_UClass_ACameraHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACameraHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "CameraHUD.h" },
		{ "ModuleRelativePath", "Public/CameraHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACameraHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACameraHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACameraHUD_Statics::ClassParams = {
		&ACameraHUD::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACameraHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACameraHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACameraHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACameraHUD, 1579502636);
	template<> PROTOTYPE_API UClass* StaticClass<ACameraHUD>()
	{
		return ACameraHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACameraHUD(Z_Construct_UClass_ACameraHUD, &ACameraHUD::StaticClass, TEXT("/Script/Prototype"), TEXT("ACameraHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
