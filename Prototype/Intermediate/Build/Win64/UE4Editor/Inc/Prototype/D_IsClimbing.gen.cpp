// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/D_IsClimbing.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeD_IsClimbing() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_UD_IsClimbing_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_UD_IsClimbing();
	AIMODULE_API UClass* Z_Construct_UClass_UBTDecorator();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void UD_IsClimbing::StaticRegisterNativesUD_IsClimbing()
	{
	}
	UClass* Z_Construct_UClass_UD_IsClimbing_NoRegister()
	{
		return UD_IsClimbing::StaticClass();
	}
	struct Z_Construct_UClass_UD_IsClimbing_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UD_IsClimbing_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UD_IsClimbing_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "D_IsClimbing.h" },
		{ "ModuleRelativePath", "Public/D_IsClimbing.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UD_IsClimbing_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UD_IsClimbing>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UD_IsClimbing_Statics::ClassParams = {
		&UD_IsClimbing::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UD_IsClimbing_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UD_IsClimbing_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UD_IsClimbing()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UD_IsClimbing_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UD_IsClimbing, 2963157558);
	template<> PROTOTYPE_API UClass* StaticClass<UD_IsClimbing>()
	{
		return UD_IsClimbing::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UD_IsClimbing(Z_Construct_UClass_UD_IsClimbing, &UD_IsClimbing::StaticClass, TEXT("/Script/Prototype"), TEXT("UD_IsClimbing"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UD_IsClimbing);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
