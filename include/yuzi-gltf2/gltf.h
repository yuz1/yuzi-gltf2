#pragma once
#include <filesystem>
#include <fstream>

#include <yuzi-gltf2/asset.h>
#include <yuzi-gltf2/scene.h>
#include <yuzi-gltf2/node.h>
#include <yuzi-gltf2/camera.h>
#include <yuzi-gltf2/animation.h>
#include <yuzi-gltf2/accessor.h>
#include <yuzi-gltf2/buffer.h>
#include <yuzi-gltf2/bufferview.h>
#include <yuzi-gltf2/image.h>
#include <yuzi-gltf2/material.h>
#include <yuzi-gltf2/mesh.h>
#include <yuzi-gltf2/sampler.h>
#include <yuzi-gltf2/skin.h>
#include <yuzi-gltf2/texture.h>

namespace yuzi_gltf2
{
	// https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/glTF.schema.json
	class GLTF final : public GLTFProperty
	{
	public:
		Asset asset;
		std::vector<Scene> scenes;
		std::optional<int> scene;
		std::vector<Node> nodes;
		//std::vector<Camera> cameras;
		std::vector<Mesh> meshes;
		std::vector<Animation> animations;
		std::vector<Skin> skins;
		std::vector<Accessor> accessors;
		std::vector<Material> materials;
		std::vector<Texture> textures;
		std::vector<Image> images;
		std::vector<Sampler> samplers;
		std::vector<BufferView> bufferViews;
		std::vector<Buffer> buffers;
		std::set<std::string> extensionsRequired;
		std::set<std::string> extensionsUsed;
		

		void to_json(nlohmann::json& j) const override
		{
			
		}
		void from_json(const nlohmann::json& j) override
		{
			GLTFProperty::from_json(j);
			asset.from_json(j["asset"]);
			if (j.contains("scenes")) scenes = j["scenes"].template get<std::vector<Scene>>();
			if (j.contains("scene")) scene = j["scene"].template get<int>();
			if (j.contains("nodes")) nodes = j["nodes"].get<std::vector<Node>>();
			if (j.contains("meshes")) meshes = j["meshes"].template get<std::vector<Mesh>>();
			if (j.contains("animations")) animations = j["animations"].template get<std::vector<Animation>>();
			if (j.contains("skins")) skins = j["skins"].template get<std::vector<Skin>>();
			if (j.contains("accessors")) accessors = j["accessors"].template get<std::vector<Accessor>>();
			if (j.contains("materials")) materials = j["materials"].template get<std::vector<Material>>();
			if (j.contains("textures")) textures = j["textures"].template get<std::vector<Texture>>();
			if (j.contains("images")) images = j["images"].template get<std::vector<Image>>();
			if (j.contains("samplers")) samplers = j["samplers"].template get<std::vector<Sampler>>();
			if (j.contains("bufferViews")) bufferViews = j["bufferViews"].template get<std::vector<BufferView>>();
			if (j.contains("buffers")) buffers = j["buffers"].template get<std::vector<Buffer>>();
			if (j.contains("extensionsRequired")) extensionsRequired = j["extensionsRequired"].template get<std::set<std::string>>();
			if (j.contains("extensionsUsed")) extensionsUsed = j["extensionsUsed"].template get<std::set<std::string>>();
		}

		void LoadFromCache(const std::vector<unsigned char>& file_cache)
		{
			const auto j = nlohmann::json::parse(file_cache.begin(), file_cache.end());
			from_json(j);
		}

		void LoadFromFile(const std::string& file_path)
		{
			std::ifstream ifs(file_path.c_str(), std::ios::binary);
			LoadFromStream(ifs);
		}

		void LoadFromStream(std::ifstream& ifs)
		{
			const auto j = nlohmann::json::parse(ifs);
			from_json(j);
		}
	};

}
