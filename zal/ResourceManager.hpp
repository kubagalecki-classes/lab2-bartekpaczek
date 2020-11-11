#pragma once

#include "Resource.hpp"

class ResourceManager
{
    ResourceManager(){
        Res = nullptr;
    };
    ~ResourceManager()
    {
        delete Res;
    };
    ResourceManager(const ResourceManager& R){};
    ResourceManager& operator=(const ResourceManager& t){return *this;};
  
    double get(){
      return Res.get();
    };


    private:
        Resource *Res;
};
 
