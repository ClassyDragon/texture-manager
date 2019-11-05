
#include "TextureManager.h"

TextureManager::TextureManager() {
}

TextureManager::~TextureManager() {
    for (auto i = textures.begin(); i != textures.end(); i++) {
        Debug_Log("Deleting " + i->first);
        delete i->second;
        textures.erase(i->first);
    }
    Debug_Log("Deconstructor called.");
}

void TextureManager::load(std::string filepath) {
    if (textures.find(filepath) == textures.end()) {
        this->textures.insert(std::pair<std::string, sf::Texture*>(filepath, new sf::Texture));
        if (!this->textures[filepath]->loadFromFile(filepath)) {
            std::cout << "\nWarning:\n\t"
                "File     - TextureManager.cpp\n\t"
                "Location - void TextureManager::load(std::string filepath)\n\t"
                "Issue    - TextureManager could not load " << filepath << ".\n\n";
        }
        Debug_Log("Loaded " + filepath + ".");
    }
    else {
        std::cout << "\nWarning\n\t"
            "File     - TextureManager.cpp\n\t"
            "Location - void TextureManager::load(std::string filepath)\n\t"
            "Issue    - " << filepath << " has already been loaded.\n\t"
            "           To access the texture, use texture_manager[filepath].\n\n";
    }
}

sf::Texture* TextureManager::get_texture(std::string key) {
    if (textures.find(key) == textures.end()) {
        std::cout << "\nWarning\n\t"
            "File     - TextureManager.cpp\n\t"
            "Location - sf::Texture* TextureManager::get_texture(std::string key)\n\t"
            "Issue    - " << key << " was not found in the map.\n\t"
            "           Please load the texture using texture_manager.load(filepath).\n\n";
        return nullptr;
    }
    else {
        return textures[key];
    }
}

sf::Texture* TextureManager::operator [] (std::string key) {
    if (textures.find(key) == textures.end()) {
        std::cout << "\nWarning\n\t"
            "File     - TextureManager.cpp\n\t"
            "Location - sf::Texture* TextureManager::operator [] (std::string key)\n\t"
            "Issue    - " << key << " was not found in the map.\n\t"
            "           Please load the texture using texture_manager.load(filepath).\n\n";
        return nullptr;
    }
    else {
        return textures[key];
    }
}

void TextureManager::operator = (TextureManager& original) {
    this->textures = original.textures;
}

std::map<std::string, sf::Texture*>::iterator TextureManager::begin() {
    return textures.begin();
}

std::map<std::string, sf::Texture*>::iterator TextureManager::end() {
    return textures.end();
}

int TextureManager::size() {
    return textures.size();
}

void TextureManager::Debug_Log(std::string message) {
    if (debug_mode) {
        std::cout << message << std::endl;
    }
}
