#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/mesh.schema.json
    class Mesh : public glTFChildOfRootProperty
    {
    public:
	    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/mesh.primitive.schema.json
        class Primitive : public GLTFProperty
        {
        public:
	        enum class Mode
            {
                POINTS = 0,
                LINE = 1,
                LINE_LOOP = 2,
                TRIANGLES = 4,
                TRIANGLE_STRIP = 5,
                TRIANGLE_FAN = 6
            };

        public:
            std::map<std::string, int> attributes;

            std::optional<glTFid> indices;
            std::optional<glTFid> material;
            std::optional<Mode> mode;
            std::vector<std::map<std::string, glTFid>> targets;

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                GLTFProperty::from_json(j);
                attributes = j["attributes"].template get<std::map<std::string, int>>();
                indices = j.contains("indices") ? j["indices"].template get<std::optional<int>>() : std::nullopt;
                material = j.contains("material") ? j["material"].template get<std::optional<int>>() : std::nullopt;
                mode = j.contains("mode") ? std::make_optional<Mode>(static_cast<Mode>(j["mode"].template get<std::optional<int>>().value())) : std::nullopt;
            	if (j.contains("targets")) targets = j["targets"].template get< std::vector<std::map<std::string, glTFid>>>();
            }
        };

    public:
        std::vector<Primitive> primitives;
        
        std::vector<double> weights;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            primitives = j["primitives"].template get<std::vector<Mesh::Primitive>>();
            if (j.contains("weights")) weights = j["weights"].template get<std::vector<double>>();
        }
    };

    ADLGLTF(Mesh)
	ADLGLTF(Mesh::Primitive)
}
