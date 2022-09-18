#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/animation.schema.json
    class Animation final : public glTFChildOfRootProperty
    {
    public:
	    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/animation.channel.schema.json
        class Channel final : public GLTFProperty
        {
        public:
	        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/animation.channel.target.schema.json
            class Target final : public GLTFProperty
            {
            public:
	            std::string path; //"translation" "rotation" "scale" "weights"
                std::optional<glTFid> node;

                void to_json(nlohmann::json& j) const override
                {
	                
                }
                void from_json(const nlohmann::json& j) override
                {
                    GLTFProperty::from_json(j);
                    node = j.contains("node") ? j["node"].template get<std::optional<int>>() : std::nullopt;
                    path = j["path"].template get<std::string>();
                }
            };

        public:
            glTFid sampler;
            Target target;

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                GLTFProperty::from_json(j);
                sampler = j["sampler"].template get<glTFid>();
                target = j["target"].template get<Target>();
            }
        };

        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/animation.sampler.schema.json
        class Sampler final : public GLTFProperty
        {
        public:
	        
	        glTFid input;
            glTFid output;

            std::optional<std::string> interpolation; // "LINEAR" "STEP" "CUBICSPLINE"

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                GLTFProperty::from_json(j);
                input = j["input"].template get<int>();
                output = j["output"].template get<int>();
                interpolation = j.contains("interpolation") ? j["interpolation"].template get<std::optional<std::string>>() : std::nullopt;
               
            }
        };

    public:
        std::vector<Channel> channels;//must > 0
        std::vector<Sampler> samplers;//must > 0

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            channels = j["channels"].template get<std::vector<Channel>>();
            samplers = j["samplers"].template get<std::vector<Sampler>>();
        }
    };

    ADLGLTF(Animation)
    ADLGLTF(Animation::Channel)
    ADLGLTF(Animation::Channel::Target)
    ADLGLTF(Animation::Sampler)

}
