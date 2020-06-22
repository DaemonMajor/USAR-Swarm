// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/BoidsAgentFlockBehavior.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidsAgentFlockBehavior() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_UBoidsAgentFlockBehavior_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_UBoidsAgentFlockBehavior();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void UBoidsAgentFlockBehavior::StaticRegisterNativesUBoidsAgentFlockBehavior()
	{
	}
	UClass* Z_Construct_UClass_UBoidsAgentFlockBehavior_NoRegister()
	{
		return UBoidsAgentFlockBehavior::StaticClass();
	}
	struct Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BoidsAgentFlockBehavior.h" },
		{ "ModuleRelativePath", "Public/BoidsAgentFlockBehavior.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoidsAgentFlockBehavior>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::ClassParams = {
		&UBoidsAgentFlockBehavior::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBoidsAgentFlockBehavior()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBoidsAgentFlockBehavior_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBoidsAgentFlockBehavior, 2556163580);
	template<> PROTOTYPE_API UClass* StaticClass<UBoidsAgentFlockBehavior>()
	{
		return UBoidsAgentFlockBehavior::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBoidsAgentFlockBehavior(Z_Construct_UClass_UBoidsAgentFlockBehavior, &UBoidsAgentFlockBehavior::StaticClass, TEXT("/Script/Prototype"), TEXT("UBoidsAgentFlockBehavior"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBoidsAgentFlockBehavior);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
