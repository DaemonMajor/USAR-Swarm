// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ASwarmWP;
class ABoidsAgent;
#ifdef PROTOTYPE_PrototypeGameState_generated_h
#error "PrototypeGameState.generated.h already included, missing '#pragma once' in PrototypeGameState.h"
#endif
#define PROTOTYPE_PrototypeGameState_generated_h

#define Prototype_Source_Prototype_PrototypeGameState_h_15_SPARSE_DATA
#define Prototype_Source_Prototype_PrototypeGameState_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddWaypoint); \
	DECLARE_FUNCTION(execAddAgent);


#define Prototype_Source_Prototype_PrototypeGameState_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddWaypoint); \
	DECLARE_FUNCTION(execAddAgent);


#define Prototype_Source_Prototype_PrototypeGameState_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPrototypeGameState(); \
	friend struct Z_Construct_UClass_APrototypeGameState_Statics; \
public: \
	DECLARE_CLASS(APrototypeGameState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(APrototypeGameState)


#define Prototype_Source_Prototype_PrototypeGameState_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPrototypeGameState(); \
	friend struct Z_Construct_UClass_APrototypeGameState_Statics; \
public: \
	DECLARE_CLASS(APrototypeGameState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(APrototypeGameState)


#define Prototype_Source_Prototype_PrototypeGameState_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrototypeGameState(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrototypeGameState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrototypeGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrototypeGameState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrototypeGameState(APrototypeGameState&&); \
	NO_API APrototypeGameState(const APrototypeGameState&); \
public:


#define Prototype_Source_Prototype_PrototypeGameState_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrototypeGameState(APrototypeGameState&&); \
	NO_API APrototypeGameState(const APrototypeGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrototypeGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrototypeGameState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APrototypeGameState)


#define Prototype_Source_Prototype_PrototypeGameState_h_15_PRIVATE_PROPERTY_OFFSET
#define Prototype_Source_Prototype_PrototypeGameState_h_12_PROLOG
#define Prototype_Source_Prototype_PrototypeGameState_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_PrototypeGameState_h_15_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_PrototypeGameState_h_15_SPARSE_DATA \
	Prototype_Source_Prototype_PrototypeGameState_h_15_RPC_WRAPPERS \
	Prototype_Source_Prototype_PrototypeGameState_h_15_INCLASS \
	Prototype_Source_Prototype_PrototypeGameState_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_PrototypeGameState_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_PrototypeGameState_h_15_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_PrototypeGameState_h_15_SPARSE_DATA \
	Prototype_Source_Prototype_PrototypeGameState_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_PrototypeGameState_h_15_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_PrototypeGameState_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class APrototypeGameState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_PrototypeGameState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
