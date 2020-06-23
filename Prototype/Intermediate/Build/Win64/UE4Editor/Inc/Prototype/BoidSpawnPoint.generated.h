// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROTOTYPE_BoidSpawnPoint_generated_h
#error "BoidSpawnPoint.generated.h already included, missing '#pragma once' in BoidSpawnPoint.h"
#endif
#define PROTOTYPE_BoidSpawnPoint_generated_h

#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_SPARSE_DATA
#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSpawnAgent); \
	DECLARE_FUNCTION(execInit);


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSpawnAgent); \
	DECLARE_FUNCTION(execInit);


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoidSpawnPoint(); \
	friend struct Z_Construct_UClass_ABoidSpawnPoint_Statics; \
public: \
	DECLARE_CLASS(ABoidSpawnPoint, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ABoidSpawnPoint)


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_INCLASS \
private: \
	static void StaticRegisterNativesABoidSpawnPoint(); \
	friend struct Z_Construct_UClass_ABoidSpawnPoint_Statics; \
public: \
	DECLARE_CLASS(ABoidSpawnPoint, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ABoidSpawnPoint)


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoidSpawnPoint(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoidSpawnPoint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidSpawnPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidSpawnPoint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidSpawnPoint(ABoidSpawnPoint&&); \
	NO_API ABoidSpawnPoint(const ABoidSpawnPoint&); \
public:


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoidSpawnPoint(ABoidSpawnPoint&&); \
	NO_API ABoidSpawnPoint(const ABoidSpawnPoint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoidSpawnPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoidSpawnPoint); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoidSpawnPoint)


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_PRIVATE_PROPERTY_OFFSET
#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_9_PROLOG
#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_SPARSE_DATA \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_RPC_WRAPPERS \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_INCLASS \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_SPARSE_DATA \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_BoidSpawnPoint_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class ABoidSpawnPoint>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_Public_BoidSpawnPoint_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
