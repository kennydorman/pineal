/*
 * Map.h
 *
 *  Created on: 2012-09-25
 *      Author: kdorman
 */

#ifndef MAP_H_
#define MAP_H_

#include "tmx_parser/Tmx.h"
using Tmx::Map;

class GameMap {
private:
	Map* tmxMap;
public:
	GameMap(char* _map_uri) {
		this->tmxMap = new Map( );
		this->tmxMap->ParseFile(_map_uri);
	};
	virtual ~GameMap() {
		delete this->tmxMap;
	};

};

#endif /* MAP_H_ */
