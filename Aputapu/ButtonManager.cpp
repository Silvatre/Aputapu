#include <iostream>
#include "ButtonManager.h"
 
using namespace std;

ButtonManager gButtonManager;

sf::AnimatedButton& ButtonManager::AddResource( sf::AnimatedButton& newResource, const std::string& strId )
{
        sf::AnimatedButton* resource = find( strId );
        if( resource == NULL ) {
			resource = new sf::AnimatedButton();
			*resource = newResource;
			m_resource.insert( Resource( strId, resource ) );
        }
        return *resource;
    }

sf::AnimatedButton& ButtonManager::getResource( const std::string& strId ) {
        sf::AnimatedButton* resource = find( strId );
        return *resource;
    }

/*/ Specialized instance /*/
sf::AnimatedButton* ButtonManager::load( const std::string& strId ) { return NULL; }