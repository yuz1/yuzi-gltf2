#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/bufferView.schema.json
    class BufferView : public glTFChildOfRootProperty
    {
    public:
	    enum class Target
        {
            ARRAY_BUFFER = 34962,
            ELEMENT_ARRAY_BUFFER = 34963
        };

    public:
        glTFid buffer;
        size_t byteLength; // > 0

        std::optional<int> byteOffset; // 0
        std::optional<int> byteStride; // 4 <= byteStride <= 252
        std::optional<Target> target;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            buffer = j["buffer"].template get<int>();
            byteOffset = j.contains("byteOffset") ? j["byteOffset"].template get<std::optional<int>>() : std::nullopt;
            byteLength = j["byteLength"].template get<int>();
            byteStride = j.contains("byteStride") ? j["byteStride"].template get<std::optional<int>>() : std::nullopt;
            if (j.contains("target")) target = static_cast<Target>(j["target"].template get<int>());
        }
    };

    ADLGLTF(BufferView)
}
