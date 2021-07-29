//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#ifndef INFINITECONQUEST_FONTMANAGER_H
#define INFINITECONQUEST_FONTMANAGER_H

#include "Manager.h"

#include "Text/Font.h"

class FontManager : public Manager<Font>
{

public:
	
	FontManager(){init();}
	
	void init() override
	{
		add("ice_pixel-7", Font("content/Fonts/ice_pixel-7.ttf"));
		setDefault();
	}
	
	void setDefault() override
	{
		add(ERROR_RESOURCE_NAME, Font());
	}
};


#endif //INFINITECONQUEST_FONTMANAGER_H
