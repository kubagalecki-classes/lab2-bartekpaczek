#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource *Res;

    ResourceManager(){
        Res = nullptr;
    };
    ~ResourceManager()
    {
        delete Res;
    };
    ResourceManager(const ResourceManager& R){};
    ResourceManager& operator=(const ResourceManager& t){return *this;};
    ResourceManager& operator=(ResourceManager&&){return *this;};
    
    public:
        double get(){
            return Res->get();
        };
           
};
 