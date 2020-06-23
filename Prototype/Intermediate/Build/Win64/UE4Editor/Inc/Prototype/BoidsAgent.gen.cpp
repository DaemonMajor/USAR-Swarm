// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/Public/BoidsAgent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidsAgent() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidsAgent_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_ABoidsAgent();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Prototype();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABoidsAgent::execMoveAgent)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_deltaSec);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveAgent(Z_Param_deltaSec);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execOnNeighborLeave)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_agentSensor);
		P_GET_OBJECT(AActor,Z_Param_neighbor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_neighborBody);
		P_GET_PROPERTY(FIntProperty,Z_Param_neighborIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnNeighborLeave(Z_Param_agentSensor,Z_Param_neighbor,Z_Param_neighborBody,Z_Param_neighborIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execOnNeighborEnter)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_agentSensor);
		P_GET_OBJECT(AActor,Z_Param_neighbor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_neighborBody);
		P_GET_PROPERTY(FIntProperty,Z_Param_neighborIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnNeighborEnter(Z_Param_agentSensor,Z_Param_neighbor,Z_Param_neighborBody,Z_Param_neighborIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execBootUpSequence)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BootUpSequence();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execScanNeighbors)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ScanNeighbors();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execSetVelocity)
	{
		P_GET_STRUCT(FVector,Z_Param_newVel);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVelocity(Z_Param_newVel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execGetNeighbors)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ABoidsAgent*>*)Z_Param__Result=P_THIS->GetNeighbors();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execSetID)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_id);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetID(Z_Param_id);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoidsAgent::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	void ABoidsAgent::StaticRegisterNativesABoidsAgent()
	{
		UClass* Class = ABoidsAgent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BootUpSequence", &ABoidsAgent::execBootUpSequence },
			{ "GetID", &ABoidsAgent::execGetID },
			{ "GetNeighbors", &ABoidsAgent::execGetNeighbors },
			{ "MoveAgent", &ABoidsAgent::execMoveAgent },
			{ "OnNeighborEnter", &ABoidsAgent::execOnNeighborEnter },
			{ "OnNeighborLeave", &ABoidsAgent::execOnNeighborLeave },
			{ "ScanNeighbors", &ABoidsAgent::execScanNeighbors },
			{ "SetID", &ABoidsAgent::execSetID },
			{ "SetVelocity", &ABoidsAgent::execSetVelocity },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// populate neighborAgents (used at BeginPlay)\n" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "populate neighborAgents (used at BeginPlay)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "BootUpSequence", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_BootUpSequence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_BootUpSequence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_GetID_Statics
	{
		struct BoidsAgent_eventGetID_Parms
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
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ABoidsAgent_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventGetID_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_GetID_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_GetID_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// how far apart agents should be spaced\n" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "how far apart agents should be spaced" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "GetID", nullptr, nullptr, sizeof(BoidsAgent_eventGetID_Parms), Z_Construct_UFunction_ABoidsAgent_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_GetID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_GetID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_GetID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics
	{
		struct BoidsAgent_eventGetNeighbors_Parms
		{
			TArray<ABoidsAgent*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventGetNeighbors_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ABoidsAgent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "GetNeighbors", nullptr, nullptr, sizeof(BoidsAgent_eventGetNeighbors_Parms), Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_GetNeighbors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_GetNeighbors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics
	{
		struct BoidsAgent_eventMoveAgent_Parms
		{
			float deltaSec;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_deltaSec;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::NewProp_deltaSec = { "deltaSec", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventMoveAgent_Parms, deltaSec), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::NewProp_deltaSec,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "MoveAgent", nullptr, nullptr, sizeof(BoidsAgent_eventMoveAgent_Parms), Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_MoveAgent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_MoveAgent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics
	{
		struct BoidsAgent_eventOnNeighborEnter_Parms
		{
			UPrimitiveComponent* agentSensor;
			AActor* neighbor;
			UPrimitiveComponent* neighborBody;
			int32 neighborIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_neighborIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighborBody_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighborBody;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighbor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentSensor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborEnter_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_SweepResult_MetaData)) };
	void Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((BoidsAgent_eventOnNeighborEnter_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BoidsAgent_eventOnNeighborEnter_Parms), &Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborIndex = { "neighborIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborEnter_Parms, neighborIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborBody_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborBody = { "neighborBody", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborEnter_Parms, neighborBody), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborBody_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborBody_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighbor = { "neighbor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborEnter_Parms, neighbor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_agentSensor_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_agentSensor = { "agentSensor", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborEnter_Parms, agentSensor), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_agentSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_agentSensor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_SweepResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighborBody,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_neighbor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::NewProp_agentSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "OnNeighborEnter", nullptr, nullptr, sizeof(BoidsAgent_eventOnNeighborEnter_Parms), Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics
	{
		struct BoidsAgent_eventOnNeighborLeave_Parms
		{
			UPrimitiveComponent* agentSensor;
			AActor* neighbor;
			UPrimitiveComponent* neighborBody;
			int32 neighborIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_neighborIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighborBody_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighborBody;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighbor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentSensor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentSensor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborIndex = { "neighborIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborLeave_Parms, neighborIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborBody_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborBody = { "neighborBody", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborLeave_Parms, neighborBody), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborBody_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborBody_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighbor = { "neighbor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborLeave_Parms, neighbor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_agentSensor_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_agentSensor = { "agentSensor", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventOnNeighborLeave_Parms, agentSensor), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_agentSensor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_agentSensor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighborBody,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_neighbor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::NewProp_agentSensor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "OnNeighborLeave", nullptr, nullptr, sizeof(BoidsAgent_eventOnNeighborLeave_Parms), Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// start neighbor scans after this delay (after all agents have been placed in world)\n" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "start neighbor scans after this delay (after all agents have been placed in world)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "ScanNeighbors", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_ScanNeighbors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_ScanNeighbors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_SetID_Statics
	{
		struct BoidsAgent_eventSetID_Parms
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
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ABoidsAgent_SetID_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventSetID_Parms, id), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_SetID_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_SetID_Statics::NewProp_id,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_SetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_SetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "SetID", nullptr, nullptr, sizeof(BoidsAgent_eventSetID_Parms), Z_Construct_UFunction_ABoidsAgent_SetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_SetID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_SetID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_SetID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_SetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_SetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics
	{
		struct BoidsAgent_eventSetVelocity_Parms
		{
			FVector newVel;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_newVel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::NewProp_newVel = { "newVel", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoidsAgent_eventSetVelocity_Parms, newVel), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::NewProp_newVel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoidsAgent, nullptr, "SetVelocity", nullptr, nullptr, sizeof(BoidsAgent_eventSetVelocity_Parms), Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoidsAgent_SetVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoidsAgent_SetVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABoidsAgent_NoRegister()
	{
		return ABoidsAgent::StaticClass();
	}
	struct Z_Construct_UClass_ABoidsAgent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bootUpDelayTimer_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_bootUpDelayTimer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bootUpDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_bootUpDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_target_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighborAgents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_neighborAgents;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighborAgents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighborSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_neighborSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentBody_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentBody;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_moveComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_moveComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_agentMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rollRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rollRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_yawRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_yawRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pitchRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_pitchRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_separationWeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_separationWeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cohesionWeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_cohesionWeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_alignmentWeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_alignmentWeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_visionRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_visionRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_neighborRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_neighborRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bodySize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_bodySize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_flockID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_flockID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentID_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_agentID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sepVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_sepVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_flockCenter_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_flockCenter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_alignVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_alignVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_agentVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_agentVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numNeighbors_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_numNeighbors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_separationFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_separationFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cohesionFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_cohesionFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_alignmentFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_alignmentFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_speed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidsAgent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoidsAgent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoidsAgent_BootUpSequence, "BootUpSequence" }, // 1470244637
		{ &Z_Construct_UFunction_ABoidsAgent_GetID, "GetID" }, // 713279168
		{ &Z_Construct_UFunction_ABoidsAgent_GetNeighbors, "GetNeighbors" }, // 2493533642
		{ &Z_Construct_UFunction_ABoidsAgent_MoveAgent, "MoveAgent" }, // 4275488691
		{ &Z_Construct_UFunction_ABoidsAgent_OnNeighborEnter, "OnNeighborEnter" }, // 3110050870
		{ &Z_Construct_UFunction_ABoidsAgent_OnNeighborLeave, "OnNeighborLeave" }, // 291663052
		{ &Z_Construct_UFunction_ABoidsAgent_ScanNeighbors, "ScanNeighbors" }, // 16613326
		{ &Z_Construct_UFunction_ABoidsAgent_SetID, "SetID" }, // 646116494
		{ &Z_Construct_UFunction_ABoidsAgent_SetVelocity, "SetVelocity" }, // 1508022264
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BoidsAgent.h" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelayTimer_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelayTimer = { "bootUpDelayTimer", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, bootUpDelayTimer), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelayTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelayTimer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelay_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelay = { "bootUpDelay", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, bootUpDelay), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_target_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_target = { "target", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, target), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_target_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents = { "neighborAgents", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, neighborAgents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents_Inner = { "neighborAgents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ABoidsAgent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborSphere_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborSphere = { "neighborSphere", nullptr, (EPropertyFlags)0x00200800000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, neighborSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborSphere_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentBody_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentBody = { "agentBody", nullptr, (EPropertyFlags)0x00200800000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, agentBody), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentBody_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentBody_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_moveComp_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_moveComp = { "moveComp", nullptr, (EPropertyFlags)0x00200800000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, moveComp), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_moveComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_moveComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentMesh_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentMesh = { "agentMesh", nullptr, (EPropertyFlags)0x00200800000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, agentMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_rollRate_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_rollRate = { "rollRate", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, rollRate), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_rollRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_rollRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_yawRate_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_yawRate = { "yawRate", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, yawRate), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_yawRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_yawRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_pitchRate_MetaData[] = {
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_pitchRate = { "pitchRate", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, pitchRate), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_pitchRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_pitchRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationWeight_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationWeight = { "separationWeight", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, separationWeight), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationWeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationWeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionWeight_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionWeight = { "cohesionWeight", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, cohesionWeight), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionWeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionWeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentWeight_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentWeight = { "alignmentWeight", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, alignmentWeight), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentWeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentWeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_visionRadius_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_visionRadius = { "visionRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, visionRadius), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_visionRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_visionRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborRadius_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborRadius = { "neighborRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, neighborRadius), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bodySize_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bodySize = { "bodySize", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, bodySize), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bodySize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bodySize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxTurnRate_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxTurnRate = { "maxTurnRate", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, maxTurnRate), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxSpeed_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxSpeed = { "maxSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, maxSpeed), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockID_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "Comment", "// switch to const after debugging\n" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "switch to const after debugging" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockID = { "flockID", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, flockID), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentID_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "Comment", "/*MOVE TO PROTECTED AFTER DEBUGGING*/" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "MOVE TO PROTECTED AFTER DEBUGGING" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentID = { "agentID", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, agentID), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_sepVector_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_sepVector = { "sepVector", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, sepVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_sepVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_sepVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockCenter_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockCenter = { "flockCenter", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, flockCenter), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockCenter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockCenter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignVector_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignVector = { "alignVector", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, alignVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentVelocity_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentVelocity = { "agentVelocity", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, agentVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_numNeighbors_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_numNeighbors = { "numNeighbors", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, numNeighbors), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_numNeighbors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_numNeighbors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationFactor_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationFactor = { "separationFactor", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, separationFactor), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionFactor_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionFactor = { "cohesionFactor", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, cohesionFactor), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentFactor_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentFactor = { "alignmentFactor", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, alignmentFactor), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidsAgent_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "BoidsAgent" },
		{ "Comment", "/* FOR DEBUGGING ONLY */" },
		{ "ModuleRelativePath", "Public/BoidsAgent.h" },
		{ "ToolTip", "FOR DEBUGGING ONLY" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidsAgent_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoidsAgent, speed), METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::NewProp_speed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidsAgent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelayTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bootUpDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborAgents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentBody,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_moveComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_rollRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_yawRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_pitchRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationWeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionWeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentWeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_visionRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_neighborRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_bodySize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_maxSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_sepVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_flockCenter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_agentVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_numNeighbors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_separationFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_cohesionFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_alignmentFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidsAgent_Statics::NewProp_speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidsAgent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidsAgent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoidsAgent_Statics::ClassParams = {
		&ABoidsAgent::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoidsAgent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoidsAgent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoidsAgent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoidsAgent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABoidsAgent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoidsAgent, 2388264387);
	template<> PROTOTYPE_API UClass* StaticClass<ABoidsAgent>()
	{
		return ABoidsAgent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoidsAgent(Z_Construct_UClass_ABoidsAgent, &ABoidsAgent::StaticClass, TEXT("/Script/Prototype"), TEXT("ABoidsAgent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidsAgent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
