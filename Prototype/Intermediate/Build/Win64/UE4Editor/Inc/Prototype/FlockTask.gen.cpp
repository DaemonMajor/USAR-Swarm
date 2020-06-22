// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/FlockTask.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlockTask() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_UFlockTask_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_UFlockTask();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_Prototype();
// End Cross Module References
	void UFlockTask::StaticRegisterNativesUFlockTask()
	{
	}
	UClass* Z_Construct_UClass_UFlockTask_NoRegister()
	{
		return UFlockTask::StaticClass();
	}
	struct Z_Construct_UClass_UFlockTask_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlockTask_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlockTask_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "FlockTask.h" },
		{ "ModuleRelativePath", "Public/FlockTask.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlockTask_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlockTask>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlockTask_Statics::ClassParams = {
		&UFlockTask::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UFlockTask_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlockTask_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlockTask()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlockTask_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlockTask, 3260368402);
	template<> PROTOTYPE_API UClass* StaticClass<UFlockTask>()
	{
		return UFlockTask::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlockTask(Z_Construct_UClass_UFlockTask, &UFlockTask::StaticClass, TEXT("/Script/Prototype"), TEXT("UFlockTask"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlockTask);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
