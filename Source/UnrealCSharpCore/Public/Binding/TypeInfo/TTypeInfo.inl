#pragma once

#include "FTypeInfo.h"
#include "Binding/TypeInfo/TNameSpace.inl"
#include "Common/FUnrealCSharpFunctionLibrary.h"

template <typename T, typename Enable = void>
struct TTypeInfo
{
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, uint8>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("Byte");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, uint16>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("UInt16");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, uint32>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("UInt32");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, uint64>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("UInt64");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, int8>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("SByte");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, int16>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("Int16");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, int32>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("Int32");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, int64>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("Int64");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, bool>::Value, T>::Type>
{
private:
	struct FInner final : FPrimitiveTypeInfo
	{
		virtual FString GetClass() const override
		{
			return TEXT("Boolean");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, float>::Value, T>::Type>
{
private:
	class FInner final : public FPrimitiveTypeInfo
	{
	public:
		virtual FString GetClass() const override
		{
			return TEXT("Single");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsDerivedFrom<typename TRemovePointer<T>::Type, UObject>::Value, T>::Type>
{
private:
	class FInner final : public FPrimitiveTypeInfo
	{
	public:
		virtual FString GetClass() const override
		{
			return FUnrealCSharpFunctionLibrary::GetFullClass(TRemovePointer<T>::Type::StaticClass());
		}

		virtual FNameSpace* GetNameSpace() const override
		{
			return TNameSpace<T, T>::Get();
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};

template <typename T>
struct TTypeInfo<T, typename TEnableIf<TIsSame<T, double>::Value, T>::Type>
{
private:
	class FInner final : public FPrimitiveTypeInfo
	{
	public:
		virtual FString GetClass() const override
		{
			return TEXT("Double");
		}
	};

public:
	static FTypeInfo* Get()
	{
		static FInner Instance;

		return &Instance;
	}
};
