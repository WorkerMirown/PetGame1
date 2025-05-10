#include "TextureManager.h"

TextureManager* TextureManager::Instance = nullptr;

TextureManager* TextureManager::GetInstanse()
{
	if (Instance == nullptr)
	{
		Instance = new TextureManager();
	}
	return Instance;
}

void TextureManager::AddTexture(const std::string& name,
								const std::string& filename)
{
	sf::Texture* Texture = new sf::Texture();
	Texture->loadFromFile(filename);
	Textures.insert(std::make_pair(name, Texture));
}

sf::Texture* TextureManager::GetTexture(const std::string& name)
{
	std::map<std::string, sf::Texture*>::iterator iter = Textures.find(name);
	return(iter != Textures.end()) ? iter->second : nullptr;
}
TextureManager::TextureManager()
	:Textures()
{

}