// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BuildingEscape/CubeWorldPosition.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCubeWorldPosition() {}
// Cross Module References
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_UCubeWorldPosition_NoRegister();
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_UCubeWorldPosition();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BuildingEscape();
// End Cross Module References
	void UCubeWorldPosition::StaticRegisterNativesUCubeWorldPosition()
	{
	}
	UClass* Z_Construct_UClass_UCubeWorldPosition_NoRegister()
	{
		return UCubeWorldPosition::StaticClass();
	}
	struct Z_Construct_UClass_UCubeWorldPosition_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCubeWorldPosition_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BuildingEscape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCubeWorldPosition_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "CubeWorldPosition.h" },
		{ "ModuleRelativePath", "CubeWorldPosition.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCubeWorldPosition_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCubeWorldPosition>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCubeWorldPosition_Statics::ClassParams = {
		&UCubeWorldPosition::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCubeWorldPosition_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCubeWorldPosition_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCubeWorldPosition()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCubeWorldPosition_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCubeWorldPosition, 847692988);
	template<> BUILDINGESCAPE_API UClass* StaticClass<UCubeWorldPosition>()
	{
		return UCubeWorldPosition::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCubeWorldPosition(Z_Construct_UClass_UCubeWorldPosition, &UCubeWorldPosition::StaticClass, TEXT("/Script/BuildingEscape"), TEXT("UCubeWorldPosition"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCubeWorldPosition);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
