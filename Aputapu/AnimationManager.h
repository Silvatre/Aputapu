#pragma once
 
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "ResourceManager.h"
 
class AnimationManager : public ResourceManager< sf::Animation > {
private:
protected:
    virtual sf::Animation* load( const std::string& Path, const std::string& FileName, const std::string& Extension, const int FramesAmmount );
	virtual sf::Animation* load( const std::string& strId );
public:
	//-----------------------------------------------------------------
	//							*AddResource*								
	// Parameters:															
	// 1) const std::string& Path		- Directory path, ends with '/'		
	// 2) const std::string& FileName	- Constant name of the files		
	// 3) const int FramesAmmount		- Number of frames					
	// 4) const std::string& AnimID		- ID in resource manager		
	//-----------------------------------------------------------------
	sf::Animation& AddResource( const std::string& Path, const std::string& FileName, const std::string& Extension, const int FramesAmmount, const std::string& AnimID );
	sf::Animation& getResource( const std::string& strId );
};

extern AnimationManager gAnimationManager;