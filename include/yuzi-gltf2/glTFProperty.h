#pragma once

#include <yuzi-gltf2/define.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/GLTFProperty.schema.json
    class GLTFProperty
    {
    public:
        GLTFProperty() = default;
        GLTFProperty(const GLTFProperty&) = default;
        GLTFProperty(GLTFProperty&&) = default;
        GLTFProperty& operator=(const GLTFProperty&) = default;
        GLTFProperty& operator=(GLTFProperty&&) = default;
	    virtual ~GLTFProperty() = default;

	    std::map<std::string, std::shared_ptr<GLTFProperty>> extensions;
        nlohmann::json extras;

        virtual void to_json(nlohmann::json& j) const {
            if (!extensions.empty())
            {
                /* code */
            }
            if (!extras.empty())
            {
               j["extras"] = extras;
            }
        }

        virtual void from_json(const nlohmann::json& j){
            if (j.contains("extensions"))
            {
                if (j["extensions"].is_object())
                {
                    /* code */
                } 
            }
            if (j.contains("extras"))
            {
                extras = j["extras"];
            }
        }
    };

    ADLGLTF(GLTFProperty)
}