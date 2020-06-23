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
	DEFINE_FUNCTION(ABoidSpawnPoint::execSpawnAgent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnAgent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidSpawnPoint::execInit)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_numAgents);
		P_GET_PROPERTY(FFloatProperty,Z_Param_timing);
		P_GET_PROPERTY(FFloatProperty,Z_Param_radius);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Init(Z_Param_numAgents,Z_Param_timing,Z_Param_radius);
		P_NATIVE_END;
	}
	void ABoidSpawnPoint::StaticRegisterNativesABoidSpawnPoint()
	{
		UClass* Class = ABoidSpawnPoint::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Init", &ABoidSpawnPoint::execInit },
			{ "SpawnAgent", &ABoidSpawnPoint::execSpawnAgent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics
	{
		struct BoidSpawnPoint_eventInit_Parms
		{
			float numAgents;
			float timing;
			float radius;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_timing;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numAgents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_radius = { "radius", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidSpawnPoint_eventInit_Parms, radius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_timing = { "timing", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidSpawnPoint_eventInit_Parms, timing), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_numAgents = { "numAgents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidSpawnPoint_eventInit_Parms, numAgents), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_timing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::NewProp_numAgents,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidSpawnPoint, nullptr, "Init", nullptr, nullptr, sizeof(BoidSpawnPoint_eventInit_Parms), Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidSpawnPoint_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidSpawnPoint_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidSpawnPoint, nullptr, "SpawnAgent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABoidSpawnPoint_NoRegister()
	{
		return ABoidSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_ABoidSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_spawnRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_spawnRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_timeBetweenSpawns_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_timeBetweenSpawns;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numAgentsToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numAgentsToSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoidSpawnPoint_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoidSpawnPoint_Init, "Init" }, // 2189311410
		{ &Z_Construct_UFunction_ABoidSpawnPoint_SpawnAgent, "SpawnAgent" }, // 737972490
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidSpawnPoint.h" },
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_spawnRadius_MetaData[] = {
		{ "Category", "BoidSpawnPoint" },
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_spawnRadius = { "spawnRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidSpawnPoint, spawnRadius), METADATA_PARAMS(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_spawnRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_spawnRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_timeBetweenSpawns_MetaData[] = {
		{ "Category", "BoidSpawnPoint" },
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_timeBetweenSpawns = { "timeBetweenSpawns", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidSpawnPoint, timeBetweenSpawns), METADATA_PARAMS(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_timeBetweenSpawns_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_timeBetweenSpawns_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_numAgentsToSpawn_MetaData[] = {
		{ "Category", "BoidSpawnPoint" },
		{ "ModuleRelativePath", "Public/BoidSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_numAgentsToSpawn = { "numAgentsToSpawn", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidSpawnPoint, numAgentsToSpawn), METADATA_PARAMS(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_numAgentsToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_numAgentsToSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidSpawnPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_spawnRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_timeBetweenSpawns,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidSpawnPoint_Statics::NewProp_numAgentsToSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoidSpawnPoint_Statics::ClassParams = {
		&ABoidSpawnPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoidSpawnPoint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoidSpawnPoint_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ABoidSpawnPoint, 1757986768);
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
