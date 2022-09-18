#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/buffer.schema.json
    class Buffer final : public glTFChildOfRootProperty
    {
    public:
	    size_t byteLength = 0; // must > 0
        std::optional<std::string> uri;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            byteLength = j["byteLength"].template get<int>();
            uri = j.contains("uri") ? j["uri"].template get<std::optional<std::string>>() : std::nullopt;
        }
    };

    ADLGLTF(Buffer)
}
