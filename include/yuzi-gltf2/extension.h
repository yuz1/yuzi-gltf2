#pragma once

#include <yuzi-gltf2/define.h>

namespace yuzi_gltf {
    //https://github.com/KhronosGroup/glTF/blob/main/specification/2.0/schema/extension.schema.json
    using Extension = std::map<std::string, std::shared_ptr<GlTFProperty>>;
}

