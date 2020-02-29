// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TowerDefence/BaseTower.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseTower() {}
// Cross Module References
	TOWERDEFENCE_API UClass* Z_Construct_UClass_ABaseTower_NoRegister();
	TOWERDEFENCE_API UClass* Z_Construct_UClass_ABaseTower();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TowerDefence();
// End Cross Module References
	void ABaseTower::StaticRegisterNativesABaseTower()
	{
	}
	UClass* Z_Construct_UClass_ABaseTower_NoRegister()
	{
		return ABaseTower::StaticClass();
	}
	struct Z_Construct_UClass_ABaseTower_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABaseTower_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TowerDefence,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABaseTower_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BaseTower.h" },
		{ "ModuleRelativePath", "BaseTower.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABaseTower_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseTower>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABaseTower_Statics::ClassParams = {
		&ABaseTower::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABaseTower_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABaseTower_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABaseTower()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABaseTower_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseTower, 3143779591);
	template<> TOWERDEFENCE_API UClass* StaticClass<ABaseTower>()
	{
		return ABaseTower::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseTower(Z_Construct_UClass_ABaseTower, &ABaseTower::StaticClass, TEXT("/Script/TowerDefence"), TEXT("ABaseTower"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseTower);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
