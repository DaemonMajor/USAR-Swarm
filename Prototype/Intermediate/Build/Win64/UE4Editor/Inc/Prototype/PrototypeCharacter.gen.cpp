// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prototype/PrototypeCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototypeCharacter() {}
// Cross Module References
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeCharacter_NoRegister();
	PROTOTYPE_API UClass* Z_Construct_UClass_APrototypeCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Prototype();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void APrototypeCharacter::StaticRegisterNativesAPrototypeCharacter()
	{
	}
	UClass* Z_Construct_UClass_APrototypeCharacter_NoRegister()
	{
		return APrototypeCharacter::StaticClass();
	}
	struct Z_Construct_UClass_APrototypeCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_charCameraComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_charCameraComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrototypeCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Prototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototypeCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PrototypeCharacter.h" },
		{ "ModuleRelativePath", "PrototypeCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototypeCharacter_Statics::NewProp_charCameraComp_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Camera" },
		{ "Comment", "// Camera\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PrototypeCharacter.h" },
		{ "ToolTip", "Camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrototypeCharacter_Statics::NewProp_charCameraComp = { "charCameraComp", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrototypeCharacter, charCameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APrototypeCharacter_Statics::NewProp_charCameraComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeCharacter_Statics::NewProp_charCameraComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrototypeCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeCharacter_Statics::NewProp_charCameraComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrototypeCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototypeCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrototypeCharacter_Statics::ClassParams = {
		&APrototypeCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APrototypeCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APrototypeCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrototypeCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrototypeCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrototypeCharacter, 4170477598);
	template<> PROTOTYPE_API UClass* StaticClass<APrototypeCharacter>()
	{
		return APrototypeCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrototypeCharacter(Z_Construct_UClass_APrototypeCharacter, &APrototypeCharacter::StaticClass, TEXT("/Script/Prototype"), TEXT("APrototypeCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrototypeCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
