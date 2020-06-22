// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/BoidsAgentController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidsAgentController() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidsAgentController_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidsAgentController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_Prototype();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ABoidsAgentController::StaticRegisterNativesABoidsAgentController()
	{
	}
	UClass* Z_Construct_UClass_ABoidsAgentController_NoRegister()
	{
		return ABoidsAgentController::StaticClass();
	}
	struct Z_Construct_UClass_ABoidsAgentController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_boidsAgentBT_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_boidsAgentBT;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidsAgentController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgentController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BoidsAgentController.h" },
		{ "ModuleRelativePath", "Public/BoidsAgentController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgentController_Statics::NewProp_boidsAgentBT_MetaData[] = {
		{ "Category", "BoidsAgentController" },
		{ "ModuleRelativePath", "Public/BoidsAgentController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgentController_Statics::NewProp_boidsAgentBT = { "boidsAgentBT", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgentController, boidsAgentBT), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgentController_Statics::NewProp_boidsAgentBT_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgentController_Statics::NewProp_boidsAgentBT_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidsAgentController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgentController_Statics::NewProp_boidsAgentBT,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidsAgentController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidsAgentController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoidsAgentController_Statics::ClassParams = {
		&ABoidsAgentController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABoidsAgentController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgentController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoidsAgentController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgentController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoidsAgentController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABoidsAgentController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoidsAgentController, 2567589345);
	template<> PROTOTYPE_API UClass* StaticClass<ABoidsAgentController>()
	{
		return ABoidsAgentController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoidsAgentController(Z_Construct_UClass_ABoidsAgentController, &ABoidsAgentController::StaticClass, TEXT("/Script/Prototype"), TEXT("ABoidsAgentController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidsAgentController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
