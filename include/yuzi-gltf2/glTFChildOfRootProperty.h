#pragma once

#include <yuzi-gltf2/glTFProperty.h>

namespace yuzi_gltf2
{
    //https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/glTFChildOfRootProperty.schema.json
    class glTFChildOfRootProperty : public GLTFProperty
    {
    public:
	    std::optional<std::string> name;
    public:
        void to_json(nlohmann::json& j) const override
        {
            GLTFProperty::to_json(j);
        }

        void from_json(const nlohmann::json& j) override
        {
            GLTFProperty::from_json(j);
            name = j.contains("name") ? j["name"].template get<std::optional<std::string>>() : std::nullopt;
        }
    };
    ADLGLTF(glTFChildOfRootProperty)
}

