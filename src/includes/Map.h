/*
 * Map.h
 *
 *  Created on: 2012-09-25
 *      Author: kdorman
 */

#ifndef MAP_H_
#define MAP_H_

#include "tmx_parser/Tmx.h"

class Map {
private:
	Tmx:Map tmxMap;
public:
	Map();
	virtual ~Map();
};

#endif /* MAP_H_ */
