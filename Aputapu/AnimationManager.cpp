#include <iostream>
#include "AnimationManager.h"
#include "ImageManager.h"
 
using namespace std;

AnimationManager gAnimationManager;

sf::Animation* AnimationManager::load( const std::string& Path, const std::string& FileName, const std::string& Extension, const int FramesAmmount ) {

	sf::Animation* animation = new sf::Animation(24, 0, true);
	for(int i = 1; i<FramesAmmount; ++i)
	{
		char* FrameNum;
		FrameNum = new char[10];
		itoa(i, FrameNum, 10);
		/*/ Loading by Adobe Flash saving style /*/
		if(i<10)
			animation->AddFrame(gImageManager.getResource(Path + FileName + "000" + (std::string)FrameNum + Extension), 1);
		else
			animation->AddFrame(gImageManager.getResource(Path + FileName + "00" + (std::string)FrameNum + Extension), 1);
		delete [] FrameNum;
	}
    return animation;
}

sf::Animation& AnimationManager::AddResource( const std::string& Path, const std::string& FileName, const std::string& Extension, const int FramesAmmount, const std::string& strId ) {
        sf::Animation* resource = find( strId );
        if( resource == NULL ) {
            resource = load( Path, FileName, Extension, FramesAmmount );
            if( resource != NULL )
                m_resource.insert( Resource( strId, resource ) );
        }
        return *resource;
    }

sf::Animation& AnimationManager::getResource( const std::string& strId ) {
        sf::Animation* resource = find( strId );
        return *resource;
    }

/*/ Specialized instance /*/
sf::Animation* AnimationManager::load( const std::string& strId ) { return NULL; }