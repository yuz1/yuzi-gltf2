#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/sampler.schema.json
    class Sampler final : public glTFChildOfRootProperty
    {
    public:
	    enum class TextureMagFilter
        {
            NEAREST = 9728,
            LINEAR = 9729
        };

        enum class TextureMinFilter
        {
            NEAREST = 9728,
            LINEAR = 9729,
            NEAREST_MIPMAP_NEAREST = 9984,
            LINEAR_MIPMAP_NEAREST = 9985,
            NEAREST_MIPMAP_LINEAR = 9986,
            LINEAR_MIPMAP_LINEAR = 9987
        };

        enum class TextureWrapMode
        {
            CLAMP_TO_EDGE = 33071,
            MIRRORED_REPEAT = 33648,
            REPEAT = 10497
        };

    public:
        std::optional<TextureMagFilter> magFilter;
        std::optional<TextureMinFilter> minFilter;
        std::optional<TextureWrapMode> wrapS;
        std::optional<TextureWrapMode> wrapT;

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            magFilter = j.contains("magFilter") ? std::make_optional<TextureMagFilter>(static_cast<TextureMagFilter>(j["magFilter"].template get<std::optional<int>>().value())) : std::nullopt;
            minFilter = j.contains("minFilter") ? std::make_optional<TextureMinFilter>(static_cast<TextureMinFilter>(j["minFilter"].template get<std::optional<int>>().value())) : std::nullopt;
            wrapS = j.contains("wrapS") ? std::make_optional<TextureWrapMode>(static_cast<TextureWrapMode>(j["wrapS"].template get<std::optional<int>>().value())) : std::nullopt;
            wrapT = j.contains("wrapT") ? std::make_optional<TextureWrapMode>(static_cast<TextureWrapMode>(j["wrapT"].template get<std::optional<int>>().value())) : std::nullopt;
        }
    };

    ADLGLTF(Sampler)
}
