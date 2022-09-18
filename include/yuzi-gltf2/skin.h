#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/skin.schema.json
    class Skin final : public glTFChildOfRootProperty
    {
    public:
        std::optional<glTFid> inverseBindMatrices;
        std::optional<glTFid> skeleton;
        std::vector<glTFid> joints;

        void to_json(nlohmann::json& j) const override
        {

        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            joints = j["joints"].template get<std::vector<glTFid>>();
            inverseBindMatrices = j.contains("inverseBindMatrices") ? j["inverseBindMatrices"].template get<std::optional<glTFid>>() : std::nullopt;
            skeleton = j.contains("skeleton") ? j["skeleton"].template get<std::optional<glTFid>>() : std::nullopt;
        }
    };
    ADLGLTF(Skin)
}
