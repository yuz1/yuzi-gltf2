#pragma once

#include <yuzi-gltf2/glTFProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/asset.schema.json
    class Asset : public GLTFProperty
    {
    public:
	    std::string generator = "yuzi-gltf2";
        std::string version = "2.0";
        std::optional<std::string> copyright;
        std::optional<std::string> minVersion;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            GLTFProperty::from_json(j);
            generator = j["generator"].template get<std::string>();
            version = j["version"].template get<std::string>();
            copyright = j.contains("copyright") ? j["copyright"].template get<std::optional<std::string>>() : std::nullopt;
            minVersion = j.contains("minVersion") ? j["minVersion"].template get<std::optional<std::string>>() : std::nullopt;
        }
    };

    ADLGLTF(Asset)
}