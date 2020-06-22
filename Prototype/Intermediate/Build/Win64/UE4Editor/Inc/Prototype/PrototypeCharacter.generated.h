// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROTOTYPE_PrototypeCharacter_generated_h
#error "PrototypeCharacter.generated.h already included, missing '#pragma once' in PrototypeCharacter.h"
#endif
#define PROTOTYPE_PrototypeCharacter_generated_h

#define Prototype_Source_Prototype_PrototypeCharacter_h_14_SPARSE_DATA
#define Prototype_Source_Prototype_PrototypeCharacter_h_14_RPC_WRAPPERS
#define Prototype_Source_Prototype_PrototypeCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Prototype_Source_Prototype_PrototypeCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPrototypeCharacter(); \
	friend struct Z_Construct_UClass_APrototypeCharacter_Statics; \
public: \
	DECLARE_CLASS(APrototypeCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(APrototypeCharacter)


#define Prototype_Source_Prototype_PrototypeCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAPrototypeCharacter(); \
	friend struct Z_Construct_UClass_APrototypeCharacter_Statics; \
public: \
	DECLARE_CLASS(APrototypeCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(APrototypeCharacter)


#define Prototype_Source_Prototype_PrototypeCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrototypeCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrototypeCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrototypeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrototypeCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrototypeCharacter(APrototypeCharacter&&); \
	NO_API APrototypeCharacter(const APrototypeCharacter&); \
public:


#define Prototype_Source_Prototype_PrototypeCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrototypeCharacter(APrototypeCharacter&&); \
	NO_API APrototypeCharacter(const APrototypeCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrototypeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrototypeCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APrototypeCharacter)


#define Prototype_Source_Prototype_PrototypeCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__charCameraComp() { return STRUCT_OFFSET(APrototypeCharacter, charCameraComp); }


#define Prototype_Source_Prototype_PrototypeCharacter_h_11_PROLOG
#define Prototype_Source_Prototype_PrototypeCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_SPARSE_DATA \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_RPC_WRAPPERS \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_INCLASS \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_PrototypeCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_SPARSE_DATA \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_PrototypeCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class APrototypeCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_PrototypeCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
