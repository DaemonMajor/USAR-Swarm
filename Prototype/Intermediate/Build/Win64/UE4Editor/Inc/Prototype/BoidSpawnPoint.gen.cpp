// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/BoidSpawnPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidSpawnPoint() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidSpawnPoint_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidSpawnPoint();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void ABoidSpawnPoint::StaticRegisterNativesABoidSpawnPoint()
	{
	}
	UClass* Z_Construct_UClass_ABoidSpawnPoint_NoRegister()
	{
		return ABoidSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_ABoidSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidSpawnPoint.h" },
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoidSpawnPoint_Statics::ClassParams = {
		&ABoidSpawnPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoidSpawnPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidSpawnPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoidSpawnPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABoidSpawnPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoidSpawnPoint, 2375425684);
	template<> PROTOTYPE_API UClass* StaticClass<ABoidSpawnPoint>()
	{
		return ABoidSpawnPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoidSpawnPoint(Z_Construct_UClass_ABoidSpawnPoint, &ABoidSpawnPoint::StaticClass, TEXT("/Script/Prototype"), TEXT("ABoidSpawnPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidSpawnPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
