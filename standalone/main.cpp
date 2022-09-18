#include <iostream>
#include <yuzi-gltf2/gltf.h>

int main(){
	try
	{
		yuzi_gltf2::GLTF glTF;
		glTF.LoadFromFile("");
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    return 0;
}