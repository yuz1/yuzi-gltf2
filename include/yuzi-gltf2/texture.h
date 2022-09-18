#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/texture.schema.json
    class Texture final : public glTFChildOfRootProperty
    {
    public:
	    std::optional<glTFid> sampler;
        std::optional<glTFid> source;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            sampler = j.contains("sampler") ? j["sampler"].template get<std::optional<glTFid>>() : std::nullopt;
            source = j.contains("source") ? j["source"].template get<std::optional<glTFid>>() : std::nullopt;
        }
    };

    ADLGLTF(Texture)
}
