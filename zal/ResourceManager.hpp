#pragma once

#include "Resource.hpp"

class ResourceManager{
    Resource *Res;
    
    public:
    ResourceManager(){
        Res = new Resource;
    };
    ~ResourceManager()
    {
        delete Res;
    };
    ResourceManager(const ResourceManager& d){
        Res = new Resource;
        *Res = *d.Res;
    };
    ResourceManager(ResourceManager && a){
       Res = a.Res;
       a.Res = nullptr; 
    }
    ResourceManager& operator=(const ResourceManager& b){
        if(this !=&b)
            *Res = *b.Res;
        return *this;
        };
    ResourceManager& operator=(ResourceManager&& c){
        if (this != &c){
            delete Res; 
            Res = c.Res;
            c.Res = nullptr;
            return *this;}
        else{
              return *this;
        };
    };

        double get(){
            return Res->get();
        };
           
};
 