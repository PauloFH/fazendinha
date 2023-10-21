
#include "WorldBuilder.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Floor.h"
#include "GeoWars.h"
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
				Floor* floor = new Floor(xx * 68.0f, yy * 68.0f);
				GeoWars::scene->Add(floor, STATIC);
			}

		}

	}

	stbi_image_free(image);
}

WorldBuilder::~WorldBuilder()
{}