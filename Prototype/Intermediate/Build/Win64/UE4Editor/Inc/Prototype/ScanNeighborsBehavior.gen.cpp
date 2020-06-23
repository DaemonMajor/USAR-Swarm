// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/ScanNeighborsBehavior.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScanNeighborsBehavior() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_UScanNeighborsBehavior_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_UScanNeighborsBehavior();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void UScanNeighborsBehavior::StaticRegisterNativesUScanNeighborsBehavior()
	{
	}
	UClass* Z_Construct_UClass_UScanNeighborsBehavior_NoRegister()
	{
		return UScanNeighborsBehavior::StaticClass();
	}
	struct Z_Construct_UClass_UScanNeighborsBehavior_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScanNeighborsBehavior_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScanNeighborsBehavior_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ScanNeighborsBehavior.h" },
		{ "ModuleRelativePath", "Public/ScanNeighborsBehavior.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScanNeighborsBehavior_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScanNeighborsBehavior>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UScanNeighborsBehavior_Statics::ClassParams = {
		&UScanNeighborsBehavior::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UScanNeighborsBehavior_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UScanNeighborsBehavior_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UScanNeighborsBehavior()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UScanNeighborsBehavior_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UScanNeighborsBehavior, 3266663693);
	template<> PROTOTYPE_API UClass* StaticClass<UScanNeighborsBehavior>()
	{
		return UScanNeighborsBehavior::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UScanNeighborsBehavior(Z_Construct_UClass_UScanNeighborsBehavior, &UScanNeighborsBehavior::StaticClass, TEXT("/Script/Prototype"), TEXT("UScanNeighborsBehavior"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UScanNeighborsBehavior);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
