#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>
#include <yuzi-gltf2/textureinfo.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/material.schema.json
    class Material final : public glTFChildOfRootProperty
    {
    public:
	    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/material.pbrMetallicRoughness.schema.json
        class PBRMetallicRoughness final : public GLTFProperty
        {
        public:
	        std::optional<std::array<double, 4>> baseColorFactor; // 1,1,1,1
            std::optional<TextureInfo> baseColorTexture;
            std::optional<double> metallicFactor;  // 1
            std::optional<double> roughnessFactor; // 1
            std::optional<TextureInfo> metallicRoughnessTexture;

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                GLTFProperty::from_json(j);
                baseColorFactor = j.contains("baseColorFactor") ? j["baseColorFactor"].template get<std::optional<std::array<double, 4>>>() : std::nullopt;
                baseColorTexture = j.contains("baseColorTexture") ? j["baseColorTexture"].template get<std::optional<TextureInfo>>() : std::nullopt;
                metallicFactor = j.contains("metallicFactor") ? j["metallicFactor"].template get<std::optional<double>>() : std::nullopt;
                roughnessFactor = j.contains("roughnessFactor") ? j["roughnessFactor"].template get<std::optional<double>>() : std::nullopt;
                metallicRoughnessTexture = j.contains("metallicRoughnessTexture") ? j["metallicRoughnessTexture"].template get<std::optional<TextureInfo>>() : std::nullopt;
            }
        };
        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/material.normalTextureInfo.schema.json
        class NormalTextureInfo final : public TextureInfo
        {
        public:
	        std::optional<double> scale; // 1.0
            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                TextureInfo::from_json(j);
                scale = j.contains("scale") ? j["scale"].template get<std::optional<double>>() : std::nullopt;
            }
        };
        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/material.occlusionTextureInfo.schema.json
        class OcclusionTextureInfo final : public TextureInfo
        {
        public:
	        std::optional<double> strength; // 1.0

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                TextureInfo::from_json(j);
                strength = j.contains("strength") ? j["strength"].template get<std::optional<double>>() : std::nullopt;
            }
        };

    public:
        std::optional<PBRMetallicRoughness> pbrMetallicRoughness;
        std::optional<NormalTextureInfo> normalTexture;
        std::optional<OcclusionTextureInfo> occlusionTexture;
        std::optional<TextureInfo> emissiveTexture;
        std::optional<std::array<double, 3>> emissiveFactor;//0,0,0
        std::optional<bool> doubleSided; //false
        std::optional<std::string> alphaMode;// OPAQUE  [OPAQUE,MASK,BLEND]
        std::optional<double> alphaCutoff; //0.5  depend alphaMode

        void to_json(nlohmann::json& j) const override
        {
	        
        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            pbrMetallicRoughness = j.contains("pbrMetallicRoughness") ? j["pbrMetallicRoughness"].template get<std::optional<PBRMetallicRoughness>>() : std::nullopt;
            normalTexture = j.contains("normalTexture") ? j["normalTexture"].template get<std::optional<NormalTextureInfo>>() : std::nullopt;
            occlusionTexture = j.contains("occlusionTexture") ? j["occlusionTexture"].template get<std::optional<OcclusionTextureInfo>>() : std::nullopt;
            emissiveTexture = j.contains("emissiveTexture") ? j["emissiveTexture"].template get<std::optional<TextureInfo>>() : std::nullopt;
            emissiveFactor = j.contains("emissiveFactor") ? j["emissiveFactor"].template get<std::optional<std::array<double, 3>>>() : std::nullopt;
            alphaMode = j.contains("alphaMode") ? j["alphaMode"].template get<std::optional<std::string>>() : std::nullopt;
            if (alphaMode)
            {
                alphaCutoff = j.contains("alphaCutoff") ? j["alphaCutoff"].template get<std::optional<double>>() : std::nullopt;
            }
            doubleSided = j.contains("doubleSided") ? j["doubleSided"].template get<std::optional<bool>>() : std::nullopt;
        }
    };

    ADLGLTF(Material)
    ADLGLTF(Material::PBRMetallicRoughness)
    ADLGLTF(Material::NormalTextureInfo)
	ADLGLTF(Material::OcclusionTextureInfo)
}
