// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/MaintainHeightBehavior.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMaintainHeightBehavior() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_UMaintainHeightBehavior_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_UMaintainHeightBehavior();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void UMaintainHeightBehavior::StaticRegisterNativesUMaintainHeightBehavior()
	{
	}
	UClass* Z_Construct_UClass_UMaintainHeightBehavior_NoRegister()
	{
		return UMaintainHeightBehavior::StaticClass();
	}
	struct Z_Construct_UClass_UMaintainHeightBehavior_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMaintainHeightBehavior_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaintainHeightBehavior_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MaintainHeightBehavior.h" },
		{ "ModuleRelativePath", "Public/MaintainHeightBehavior.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMaintainHeightBehavior_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMaintainHeightBehavior>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMaintainHeightBehavior_Statics::ClassParams = {
		&UMaintainHeightBehavior::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UMaintainHeightBehavior_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMaintainHeightBehavior_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMaintainHeightBehavior()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMaintainHeightBehavior_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMaintainHeightBehavior, 3186566334);
	template<> PROTOTYPE_API UClass* StaticClass<UMaintainHeightBehavior>()
	{
		return UMaintainHeightBehavior::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMaintainHeightBehavior(Z_Construct_UClass_UMaintainHeightBehavior, &UMaintainHeightBehavior::StaticClass, TEXT("/Script/Prototype"), TEXT("UMaintainHeightBehavior"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaintainHeightBehavior);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
