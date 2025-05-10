#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager
{
public:
	static TextureManager* GetInstanse();

	void AddTexture(const std::string& name,
					const std :: string & filename);

	sf::Texture* GetTexture(const std::string& name);

private:
	TextureManager();

	std::map<std::string, sf::Texture*>Textures;
	static TextureManager* Instance;
};

