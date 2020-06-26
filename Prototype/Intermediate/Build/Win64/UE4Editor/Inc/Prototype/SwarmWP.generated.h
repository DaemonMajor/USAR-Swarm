// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PROTOTYPE_SwarmWP_generated_h
#error "SwarmWP.generated.h already included, missing '#pragma once' in SwarmWP.h"
#endif
#define PROTOTYPE_SwarmWP_generated_h

#define Prototype_Source_Prototype_Public_SwarmWP_h_12_SPARSE_DATA
#define Prototype_Source_Prototype_Public_SwarmWP_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnAgentLeave); \
	DECLARE_FUNCTION(execOnAgentEnter); \
	DECLARE_FUNCTION(execSetID); \
	DECLARE_FUNCTION(execGetID);


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnAgentLeave); \
	DECLARE_FUNCTION(execOnAgentEnter); \
	DECLARE_FUNCTION(execSetID); \
	DECLARE_FUNCTION(execGetID);


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASwarmWP(); \
	friend struct Z_Construct_UClass_ASwarmWP_Statics; \
public: \
	DECLARE_CLASS(ASwarmWP, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ASwarmWP)


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASwarmWP(); \
	friend struct Z_Construct_UClass_ASwarmWP_Statics; \
public: \
	DECLARE_CLASS(ASwarmWP, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ASwarmWP)


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASwarmWP(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASwarmWP) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASwarmWP); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASwarmWP); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASwarmWP(ASwarmWP&&); \
	NO_API ASwarmWP(const ASwarmWP&); \
public:


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASwarmWP(ASwarmWP&&); \
	NO_API ASwarmWP(const ASwarmWP&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASwarmWP); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASwarmWP); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASwarmWP)


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__wpID() { return STRUCT_OFFSET(ASwarmWP, wpID); } \
	FORCEINLINE static uint32 __PPO__wpRoot() { return STRUCT_OFFSET(ASwarmWP, wpRoot); } \
	FORCEINLINE static uint32 __PPO__wpArea() { return STRUCT_OFFSET(ASwarmWP, wpArea); } \
	FORCEINLINE static uint32 __PPO__wpRadius() { return STRUCT_OFFSET(ASwarmWP, wpRadius); }


#define Prototype_Source_Prototype_Public_SwarmWP_h_9_PROLOG
#define Prototype_Source_Prototype_Public_SwarmWP_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_SPARSE_DATA \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_RPC_WRAPPERS \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_INCLASS \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_Public_SwarmWP_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_SPARSE_DATA \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_SwarmWP_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class ASwarmWP>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_Public_SwarmWP_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
