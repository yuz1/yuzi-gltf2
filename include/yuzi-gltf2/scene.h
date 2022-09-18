#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/scene.schema.json
    class Scene : public glTFChildOfRootProperty
    {
    public:
	    std::vector<glTFid> nodes;// > 1

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            nodes = j["nodes"].template get<std::vector<int>>();
        }
    };

    ADLGLTF(Scene)
}
