
#include "WorldBuilder.h"
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "Ground.h"
#include "Fazendinha.h"
#include "Build.h"
WorldBuilder::WorldBuilder(const char* path)
{
	unsigned char* image = stbi_load(path, &width, &height, &channels, 3);

	for (int xx = 0; xx < width; xx++)
	{

		for (int yy = 0; yy < height; yy++)
		{

			if (image[3 * (xx + (yy * width))] == 255
				&& image[3 * (xx + (yy * width)) + 1] == 255
				&& image[3 * (xx + (yy * width)) + 2] == 255
				){
				Fazendinha::scene->Add(new Ground(xx * 64.0f, yy * 64.0f), STATIC);
			}
			if (image[3 * (xx + (yy * width))] == 255
				&& image[3 * (xx + (yy * width)) + 1] == 2
				&& image[3 * (xx + (yy * width)) + 2] == 255
				) {
				//Fazendinha::scene->Add((new Build(xx * 144.0f, yy * 144.0f,new Sprite("Resources/home.png"), HOME)), STATIC);
			}

		}

	}

	stbi_image_free(image);
}

WorldBuilder::~WorldBuilder()
{}