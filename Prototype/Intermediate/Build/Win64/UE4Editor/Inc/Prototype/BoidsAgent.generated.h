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
struct FVector;
class ABoidsAgent;
#ifdef PROTOTYPE_BoidsAgent_generated_h
#error "BoidsAgent.generated.h already included, missing '#pragma once' in BoidsAgent.h"
#endif
#define PROTOTYPE_BoidsAgent_generated_h

#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_SPARSE_DATA
#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execmoveAgent); \
	DECLARE_FUNCTION(execonNeighborLeave); \
	DECLARE_FUNCTION(execonNeighborEnter); \
	DECLARE_FUNCTION(execscanNeighbors); \
	DECLARE_FUNCTION(execsetVelocity); \
	DECLARE_FUNCTION(execgetNeighbors);


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execmoveAgent); \
	DECLARE_FUNCTION(execonNeighborLeave); \
	DECLARE_FUNCTION(execonNeighborEnter); \
	DECLARE_FUNCTION(execscanNeighbors); \
	DECLARE_FUNCTION(execsetVelocity); \
	DECLARE_FUNCTION(execgetNeighbors);


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoidsAgent(); \
	friend struct Z_Construct_UClass_ABoidsAgent_Statics; \
public: \
	DECLARE_CLASS(ABoidsAgent, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ABoidsAgent)


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesABoidsAgent(); \
	friend struct Z_Construct_UClass_ABoidsAgent_Statics; \
public: \
	DECLARE_CLASS(ABoidsAgent, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ABoidsAgent)


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoidsAgent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoidsAgent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidsAgent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidsAgent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidsAgent(ABoidsAgent&&); \
	NO_API ABoidsAgent(const ABoidsAgent&); \
public:


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidsAgent(ABoidsAgent&&); \
	NO_API ABoidsAgent(const ABoidsAgent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidsAgent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidsAgent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoidsAgent)


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__pitchRate() { return STRUCT_OFFSET(ABoidsAgent, pitchRate); } \
	FORCEINLINE static uint32 __PPO__yawRate() { return STRUCT_OFFSET(ABoidsAgent, yawRate); } \
	FORCEINLINE static uint32 __PPO__rollRate() { return STRUCT_OFFSET(ABoidsAgent, rollRate); } \
	FORCEINLINE static uint32 __PPO__flockID() { return STRUCT_OFFSET(ABoidsAgent, flockID); } \
	FORCEINLINE static uint32 __PPO__agentMesh() { return STRUCT_OFFSET(ABoidsAgent, agentMesh); } \
	FORCEINLINE static uint32 __PPO__moveComp() { return STRUCT_OFFSET(ABoidsAgent, moveComp); } \
	FORCEINLINE static uint32 __PPO__agentBody() { return STRUCT_OFFSET(ABoidsAgent, agentBody); } \
	FORCEINLINE static uint32 __PPO__neighborSphere() { return STRUCT_OFFSET(ABoidsAgent, neighborSphere); } \
	FORCEINLINE static uint32 __PPO__neighborAgents() { return STRUCT_OFFSET(ABoidsAgent, neighborAgents); } \
	FORCEINLINE static uint32 __PPO__target() { return STRUCT_OFFSET(ABoidsAgent, target); }


#define Prototype_Source_Prototype_Public_BoidsAgent_h_10_PROLOG
#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_SPARSE_DATA \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_RPC_WRAPPERS \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_INCLASS \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_Public_BoidsAgent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_SPARSE_DATA \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_BoidsAgent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class ABoidsAgent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_Public_BoidsAgent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
