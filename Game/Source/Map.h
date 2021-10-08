#ifndef __MAP_H__
#define __MAP_H__

#include "Module.h"
#include "List.h"
#include "Point.h"

#include "PugiXml\src\pugixml.hpp"

// L03: TODO 2: Create a struct to hold information for a TileSet
// Ignore Wangsets and Tile Types for now, but we want the image!
struct TileSet
{
    int firstgid;
    SString name;
    int tilewidth;
    int tileheight;
    int spacing;
    int margin;
    int tilecount;
    int columns;
    SString source;
    int width;
    int height;
    SDL_Texture* texture;
};

// L03: TODO 1: Create a struct needed to hold the information to Map node
struct MapData
{
    int width;
    int height;
    int tilewidth;
    int tileheight;
    List<TileSet*> tilesets;
};

class Map : public Module
{
public:

    Map();

    // Destructor
    virtual ~Map();

    // Called before render is available
    bool Awake(pugi::xml_node& conf);

    // Called each loop iteration
    void Draw();

    // Called before quitting
    bool CleanUp();

    // Load new map
    bool Load(const char* path);

private:

    // L03: TODO 3: Implement LoadMap to load the map properties
	bool LoadMap(pugi::xml_node mapFile);

	// L03: TODO 4: Implement the LoadTileSet function to load the tileset
	bool LoadTileSet(pugi::xml_node mapFile);

	// L03: TODO 1: Declare a variable data of the struct MapData
	

    SString folder;
    bool mapLoaded;
    MapData mapData;
};

#endif // __MAP_H__