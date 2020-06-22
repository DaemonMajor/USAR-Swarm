// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROTOTYPE_CameraHUD_generated_h
#error "CameraHUD.generated.h already included, missing '#pragma once' in CameraHUD.h"
#endif
#define PROTOTYPE_CameraHUD_generated_h

#define Prototype_Source_Prototype_Public_CameraHUD_h_15_SPARSE_DATA
#define Prototype_Source_Prototype_Public_CameraHUD_h_15_RPC_WRAPPERS
#define Prototype_Source_Prototype_Public_CameraHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Prototype_Source_Prototype_Public_CameraHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACameraHUD(); \
	friend struct Z_Construct_UClass_ACameraHUD_Statics; \
public: \
	DECLARE_CLASS(ACameraHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ACameraHUD)


#define Prototype_Source_Prototype_Public_CameraHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesACameraHUD(); \
	friend struct Z_Construct_UClass_ACameraHUD_Statics; \
public: \
	DECLARE_CLASS(ACameraHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Prototype"), NO_API) \
	DECLARE_SERIALIZER(ACameraHUD)


#define Prototype_Source_Prototype_Public_CameraHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACameraHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACameraHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACameraHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACameraHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACameraHUD(ACameraHUD&&); \
	NO_API ACameraHUD(const ACameraHUD&); \
public:


#define Prototype_Source_Prototype_Public_CameraHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACameraHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACameraHUD(ACameraHUD&&); \
	NO_API ACameraHUD(const ACameraHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACameraHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACameraHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACameraHUD)


#define Prototype_Source_Prototype_Public_CameraHUD_h_15_PRIVATE_PROPERTY_OFFSET
#define Prototype_Source_Prototype_Public_CameraHUD_h_12_PROLOG
#define Prototype_Source_Prototype_Public_CameraHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_SPARSE_DATA \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_RPC_WRAPPERS \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_INCLASS \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Prototype_Source_Prototype_Public_CameraHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_SPARSE_DATA \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_INCLASS_NO_PURE_DECLS \
	Prototype_Source_Prototype_Public_CameraHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROTOTYPE_API UClass* StaticClass<class ACameraHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Prototype_Source_Prototype_Public_CameraHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
