// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/PrototypeGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototypeGameState() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeGameState_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_Prototype();
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidsAgent_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ASwarmWP_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(APrototypeGameState::execAddWaypoint)
	{
		P_GET_OBJECT(ASwarmWP,Z_Param_waypoint);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->AddWaypoint(Z_Param_waypoint);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APrototypeGameState::execAddAgent)
	{
		P_GET_OBJECT(ABoidsAgent,Z_Param_agent);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->AddAgent(Z_Param_agent);
		P_NATIVE_END;
	}
	void APrototypeGameState::StaticRegisterNativesAPrototypeGameState()
	{
		UClass* Class = APrototypeGameState::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAgent", &APrototypeGameState::execAddAgent },
			{ "AddWaypoint", &APrototypeGameState::execAddWaypoint },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics
	{
		struct PrototypeGameState_eventAddAgent_Parms
		{
			ABoidsAgent* agent;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrototypeGameState_eventAddAgent_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::NewProp_agent = { "agent", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrototypeGameState_eventAddAgent_Parms, agent), Z_Construct_UClass_ABoidsAgent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::NewProp_agent,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PrototypeGameState.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrototypeGameState, nullptr, "AddAgent", nullptr, nullptr, sizeof(PrototypeGameState_eventAddAgent_Parms), Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrototypeGameState_AddAgent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrototypeGameState_AddAgent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics
	{
		struct PrototypeGameState_eventAddWaypoint_Parms
		{
			ASwarmWP* waypoint;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_waypoint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrototypeGameState_eventAddWaypoint_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::NewProp_waypoint = { "waypoint", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrototypeGameState_eventAddWaypoint_Parms, waypoint), Z_Construct_UClass_ASwarmWP_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::NewProp_waypoint,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// increment numAgents and assign the passed agent a unique ID\n" },
		{ "ModuleRelativePath", "PrototypeGameState.h" },
		{ "ToolTip", "increment numAgents and assign the passed agent a unique ID" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrototypeGameState, nullptr, "AddWaypoint", nullptr, nullptr, sizeof(PrototypeGameState_eventAddWaypoint_Parms), Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrototypeGameState_AddWaypoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrototypeGameState_AddWaypoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APrototypeGameState_NoRegister()
	{
		return APrototypeGameState::StaticClass();
	}
	struct Z_Construct_UClass_APrototypeGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrototypeGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APrototypeGameState_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APrototypeGameState_AddAgent, "AddAgent" }, // 2522260225
		{ &Z_Construct_UFunction_APrototypeGameState_AddWaypoint, "AddWaypoint" }, // 3217035220
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototypeGameState_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PrototypeGameState.h" },
		{ "ModuleRelativePath", "PrototypeGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrototypeGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototypeGameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrototypeGameState_Statics::ClassParams = {
		&APrototypeGameState::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APrototypeGameState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrototypeGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrototypeGameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrototypeGameState, 2961555873);
	template<> PROTOTYPE_API UClass* StaticClass<APrototypeGameState>()
	{
		return APrototypeGameState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrototypeGameState(Z_Construct_UClass_APrototypeGameState, &APrototypeGameState::StaticClass, TEXT("/Script/Prototype"), TEXT("APrototypeGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrototypeGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
