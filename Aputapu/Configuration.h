#pragma once

#include <string>
#include <vector>

template <typename T>
class Configuration
{
protected:
	T* myResource;
	std::vector<std::string> myAdded;
public:
	Configuration() {}
	virtual ~Configuration(){
		Release();
	}
	void Release(){
		for (unsigned int i = 0; i < myAdded.size(); ++i)
			myResource->releaseResource(myAdded[i]);
	}
	virtual void Init() = 0;
};