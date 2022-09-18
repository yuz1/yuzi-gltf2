#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/node.schema.json
    class Node : public glTFChildOfRootProperty
    {
    public:
	    std::optional<glTFid> camera;
        std::optional<glTFid> mesh;
        std::vector<glTFid> children;

        std::optional<std::array<double, 16>> matrix; //[ 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ]
        std::optional<std::array<double, 4>> rotation;    // quaternion [ 0.0, 0.0, 0.0, 1.0 ]
        std::optional<std::array<double, 3>> scale;       //[ 1.0, 1.0, 1.0 ]
        std::optional<std::array<double, 3>> translation; //[ 0.0, 0.0, 0.0 ]
        
        std::optional<glTFid> skin;// depend mesh
        std::vector<double> weights;// depend mesh

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            camera = j.contains("camera") ? j["camera"].template get<std::optional<int>>() : std::nullopt;
            mesh = j.contains("mesh") ? j["mesh"].template get<std::optional<int>>() : std::nullopt;
            if (j.contains("children")) children = j["children"].template get<std::vector<int>>();
            matrix = j.contains("matrix") ? j["matrix"].template get<std::optional<std::array<double, 16>>>() : std::nullopt;
            rotation = j.contains("rotation") ? j["rotation"].template get<std::optional<std::array<double, 4>>>() : std::nullopt;
            scale = j.contains("scale") ? j["scale"].template get<std::optional<std::array<double, 3>>>() : std::nullopt;
            translation = j.contains("translation") ? j["translation"].template get<std::optional<std::array<double, 3>>>() : std::nullopt;
            if (mesh) {
                skin = j.contains("skin") ? j["skin"].template get<std::optional<int>>() : std::nullopt;
                if (j.contains("weights")) weights = j["weights"].template get<std::vector<double>>();
            }
        }
    };

    ADLGLTF(Node)
}
