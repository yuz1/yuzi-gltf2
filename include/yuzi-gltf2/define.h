#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include <optional>
#include <variant>
#include <memory>
#include <set>
#include <map>

namespace nlohmann
{

	template <typename T>
	struct adl_serializer<std::optional<T>>
	{
		static void to_json(json& j, const std::optional<T>& opt)
		{
			if (opt == std::nullopt)
			{
				j = nullptr;
			}
			else
			{
				j = *opt;
			}
		}

		static void from_json(const json& j, std::optional<T>& opt)
		{
			if (j.is_null())
			{
				opt = std::nullopt;
			}
			else
			{
				opt = j.get<T>();
			}
		}
	};

	template <typename T>
	struct adl_serializer<std::shared_ptr<T>>
	{
		static void to_json(json& j, const std::shared_ptr<T>& opt)
		{
			if (opt)
			{
				j = *opt;
			}
			else
			{
				j = nullptr;
			}
		}

		static void from_json(const json& j, std::shared_ptr<T>& opt)
		{
			if (j.is_null())
			{
				opt = nullptr;
			}
			else
			{
				opt.reset(new T(j.get<T>()));
			}
		}
	};
}

namespace yuzi_gltf2
{
	// https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/glTFid.schema.json
	using glTFid = int;

#define ADLGLTF(val)										\
  inline void to_json(nlohmann::json& j, const val& p)		\
  {															\
		p.to_json(j);										\
  }															\
															\
  inline void from_json(const nlohmann::json& j, val& p)	\
  {															\
		p.from_json(j);										\
  }
}