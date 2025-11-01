#pragma once

struct Texture {
	Texture(const char* filepath);
	~Texture();

	unsigned int id;
};
