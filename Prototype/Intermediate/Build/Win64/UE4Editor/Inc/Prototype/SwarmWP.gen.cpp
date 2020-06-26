// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/SwarmWP.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSwarmWP() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_ASwarmWP_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ASwarmWP();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Prototype();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASwarmWP::execOnAgentLeave)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_wpAreaComp);
		P_GET_OBJECT(AActor,Z_Param_agent);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_agentBody);
		P_GET_PROPERTY(FIntProperty,Z_Param_agentIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnAgentLeave(Z_Param_wpAreaComp,Z_Param_agent,Z_Param_agentBody,Z_Param_agentIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASwarmWP::execOnAgentEnter)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_wpAreaComp);
		P_GET_OBJECT(AActor,Z_Param_agent);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_agentBody);
		P_GET_PROPERTY(FIntProperty,Z_Param_agentIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnAgentEnter(Z_Param_wpAreaComp,Z_Param_agent,Z_Param_agentBody,Z_Param_agentIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASwarmWP::execSetID)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_id);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetID(Z_Param_id);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASwarmWP::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	void ASwarmWP::StaticRegisterNativesASwarmWP()
	{
		UClass* Class = ASwarmWP::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetID", &ASwarmWP::execGetID },
			{ "OnAgentEnter", &ASwarmWP::execOnAgentEnter },
			{ "OnAgentLeave", &ASwarmWP::execOnAgentLeave },
			{ "SetID", &ASwarmWP::execSetID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASwarmWP_GetID_Statics
	{
		struct SwarmWP_eventGetID_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASwarmWP_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventGetID_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASwarmWP_GetID_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_GetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASwarmWP_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASwarmWP, nullptr, "GetID", nullptr, nullptr, sizeof(SwarmWP_eventGetID_Parms), Z_Construct_UFunction_ASwarmWP_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_GetID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_GetID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_GetID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASwarmWP_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASwarmWP_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics
	{
		struct SwarmWP_eventOnAgentEnter_Parms
		{
			UPrimitiveComponent* wpAreaComp;
			AActor* agent;
			UPrimitiveComponent* agentBody;
			int32 agentIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_agentIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentBody_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentBody;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpAreaComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_wpAreaComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentEnter_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((SwarmWP_eventOnAgentEnter_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SwarmWP_eventOnAgentEnter_Parms), &Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentIndex = { "agentIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentEnter_Parms, agentIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentBody_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentBody = { "agentBody", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentEnter_Parms, agentBody), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentBody_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentBody_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agent = { "agent", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentEnter_Parms, agent), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_wpAreaComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_wpAreaComp = { "wpAreaComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentEnter_Parms, wpAreaComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_wpAreaComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_wpAreaComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agentBody,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_agent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::NewProp_wpAreaComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASwarmWP, nullptr, "OnAgentEnter", nullptr, nullptr, sizeof(SwarmWP_eventOnAgentEnter_Parms), Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASwarmWP_OnAgentEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASwarmWP_OnAgentEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics
	{
		struct SwarmWP_eventOnAgentLeave_Parms
		{
			UPrimitiveComponent* wpAreaComp;
			AActor* agent;
			UPrimitiveComponent* agentBody;
			int32 agentIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_agentIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentBody_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentBody;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpAreaComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_wpAreaComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentIndex = { "agentIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentLeave_Parms, agentIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentBody_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentBody = { "agentBody", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentLeave_Parms, agentBody), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentBody_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentBody_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agent = { "agent", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentLeave_Parms, agent), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_wpAreaComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_wpAreaComp = { "wpAreaComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventOnAgentLeave_Parms, wpAreaComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_wpAreaComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_wpAreaComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agentBody,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_agent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::NewProp_wpAreaComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASwarmWP, nullptr, "OnAgentLeave", nullptr, nullptr, sizeof(SwarmWP_eventOnAgentLeave_Parms), Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASwarmWP_OnAgentLeave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASwarmWP_OnAgentLeave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASwarmWP_SetID_Statics
	{
		struct SwarmWP_eventSetID_Parms
		{
			int32 id;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_id;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASwarmWP_SetID_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SwarmWP_eventSetID_Parms, id), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASwarmWP_SetID_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASwarmWP_SetID_Statics::NewProp_id,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASwarmWP_SetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASwarmWP_SetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASwarmWP, nullptr, "SetID", nullptr, nullptr, sizeof(SwarmWP_eventSetID_Parms), Z_Construct_UFunction_ASwarmWP_SetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_SetID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASwarmWP_SetID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASwarmWP_SetID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASwarmWP_SetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASwarmWP_SetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASwarmWP_NoRegister()
	{
		return ASwarmWP::StaticClass();
	}
	struct Z_Construct_UClass_ASwarmWP_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_wpRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpArea_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_wpArea;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_wpRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wpID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_wpID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASwarmWP_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASwarmWP_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASwarmWP_GetID, "GetID" }, // 1249324338
		{ &Z_Construct_UFunction_ASwarmWP_OnAgentEnter, "OnAgentEnter" }, // 2715862860
		{ &Z_Construct_UFunction_ASwarmWP_OnAgentLeave, "OnAgentLeave" }, // 3228285637
		{ &Z_Construct_UFunction_ASwarmWP_SetID, "SetID" }, // 3001399298
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASwarmWP_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SwarmWP.h" },
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRadius_MetaData[] = {
		{ "Category", "SwarmWP" },
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRadius = { "wpRadius", nullptr, (EPropertyFlags)0x0020080000030015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASwarmWP, wpRadius), METADATA_PARAMS(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpArea_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpArea = { "wpArea", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASwarmWP, wpArea), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpArea_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpArea_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRoot_MetaData[] = {
		{ "Comment", "// Unique waypoint ID. Value of -1 sets waypoint as inactive.\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
		{ "ToolTip", "Unique waypoint ID. Value of -1 sets waypoint as inactive." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRoot = { "wpRoot", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASwarmWP, wpRoot), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpID_MetaData[] = {
		{ "Category", "SwarmWP" },
		{ "ModuleRelativePath", "Public/SwarmWP.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpID = { "wpID", nullptr, (EPropertyFlags)0x0020080000030015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASwarmWP, wpID), METADATA_PARAMS(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASwarmWP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpArea,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASwarmWP_Statics::NewProp_wpID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASwarmWP_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASwarmWP>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASwarmWP_Statics::ClassParams = {
		&ASwarmWP::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASwarmWP_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASwarmWP_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASwarmWP_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASwarmWP()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASwarmWP_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASwarmWP, 1337044204);
	template<> PROTOTYPE_API UClass* StaticClass<ASwarmWP>()
	{
		return ASwarmWP::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASwarmWP(Z_Construct_UClass_ASwarmWP, &ASwarmWP::StaticClass, TEXT("/Script/Prototype"), TEXT("ASwarmWP"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASwarmWP);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
