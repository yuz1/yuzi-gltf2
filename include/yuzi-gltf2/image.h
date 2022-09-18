#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/image.schema.json
    class Image final : public glTFChildOfRootProperty
    {
    public:
	    std::optional<std::string> mimeType;

        // one of
        std::optional<std::string> uri;
        std::optional<glTFid> bufferView; // must have mimeType

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            uri = j.contains("uri") ? j["uri"].template get<std::optional<std::string>>() : std::nullopt;
            mimeType = j.contains("mimeType") ? j["mimeType"].template get<std::optional<std::string>>() : std::nullopt;
            if (mimeType && !uri)
            {
                bufferView = j["bufferView"].template get<int>();
            }
        }
    };
    ADLGLTF(Image)
}
