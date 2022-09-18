#pragma once

#include <yuzi-gltf2/glTFChildOfRootProperty.h>

namespace yuzi_gltf2
{
    // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/accessor.schema.json
    class Accessor final : public glTFChildOfRootProperty
    {
    public:
        enum class ComponentType
        {
            BYTE = 5120,
            UNSIGNED_BYTE = 5121,
            SHORT = 5122,
            UNSIGNED_SHORT = 5123,
            INT = 5124,
            UNSIGNED_INT = 5125,
            FLOAT = 5126
        };

        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/accessor.sparse.schema.json
        class Sparse final : public GLTFProperty
        {
        public:
	        // https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/accessor.sparse.indices.schema.json
            class Indices final : public GLTFProperty
            {
            public:
	            enum class ComponentType
                {
                    UNSIGNED_BYTE = 5121,
                    UNSIGNED_SHORT = 5123,
                    UNSIGNED_INT = 5125
                };

            public:
                glTFid bufferView = 0;
                ComponentType componentType = ComponentType::UNSIGNED_BYTE;
                std::optional<size_t> byteOffset;

                void to_json(nlohmann::json& j) const override
                {
	                
                }
                void from_json(const nlohmann::json& j) override
                {
                    GLTFProperty::from_json(j);
                    bufferView = j["bufferView"].template get<glTFid>();
                    componentType = static_cast<ComponentType>(j["componentType"].template get<int>());
                    byteOffset = j.contains("byteOffset") ? j["byteOffset"].template get<std::optional<int>>() : std::nullopt;
                   
                }
            };

            //https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/accessor.sparse.values.schema.json
            class Values final : public GLTFProperty
            {
            public:
	            glTFid bufferView = 0;
                std::optional<size_t> byteOffset;

                void to_json(nlohmann::json& j) const override
                {
	                
                }
                void from_json(const nlohmann::json& j) override
                {
                    GLTFProperty::from_json(j);
                    bufferView = j["bufferView"].template get<glTFid>();
                    byteOffset = j.contains("byteOffset") ? j["byteOffset"].template get<std::optional<int>>() : std::nullopt;
                }
            };
        public:
            int count = 1;
            Indices indices;
            Values values;

            void to_json(nlohmann::json& j) const override
            {
	            
            }
            void from_json(const nlohmann::json& j) override
            {
                GLTFProperty::from_json(j);
                count = j["count"].template get<int>();
                indices = j["indices"].template get<Indices>();
                values = j["values"].template get<Values>();
            }
        };

    public:
        ComponentType componentType;
        size_t count;     // > 0
        std::string type; // [SCALAR] [VEC2] [VEC3] [VEC4] [MAT2] [MAT3] [MAT4]
        std::optional<glTFid> bufferView;
        std::optional<size_t> byteOffset; // 0
        std::vector<double> max;//1 2 3 4 9 16
        std::vector<double> min;//1 2 3 4 9 16
        std::optional<bool> normalized; // false
        std::optional<Sparse> sparse;

        void to_json(nlohmann::json& j) const override
        {

        }
        void from_json(const nlohmann::json& j) override
        {
            glTFChildOfRootProperty::from_json(j);
            componentType = static_cast<ComponentType>(j["componentType"].template get<int>());
            count = j["count"].template get<size_t>();
            type = j["type"].template get<std::string>();
            bufferView = j.contains("bufferView") ? j["bufferView"].template get<std::optional<int>>() : std::nullopt;
            if (bufferView) byteOffset = j.contains("byteOffset") ? j["byteOffset"].template get<std::optional<size_t>>() : std::nullopt;
            normalized = j.contains("normalized") ? j["normalized"].template get<std::optional<bool>>() : std::nullopt;
            if (j.contains("max")) max =  j["max"].template get<std::vector<double>>();
            if (j.contains("min")) min =  j["min"].template get<std::vector<double>>();
            sparse = j.contains("sparse") ? j["sparse"].template get<std::optional<Sparse>>() : std::nullopt;
        }
        
    };
    ADLGLTF(Accessor)
	ADLGLTF(Accessor::Sparse)
	ADLGLTF(Accessor::Sparse::Indices)
	ADLGLTF(Accessor::Sparse::Values)
}