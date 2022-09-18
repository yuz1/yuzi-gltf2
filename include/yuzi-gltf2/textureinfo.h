#pragma once

#include <yuzi-gltf2/glTFProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/textureInfo.schema.json
    class TextureInfo : public GLTFProperty
    {
    public:
	    glTFid index = 0;
        std::optional<int> texCoord;
        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            GLTFProperty::from_json(j);
            index = j["index"].template get<int>();
            texCoord = j.contains("texCoord") ? j["texCoord"].template get<std::optional<int>>() : std::nullopt;
        }
    };

    ADLGLTF(TextureInfo)
}
