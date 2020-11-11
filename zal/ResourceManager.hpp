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
    ResourceManager(const ResourceManager& a){
        Res = new Resource;
        *Res = *a.Res;
    };
    ResourceManager& operator=(const ResourceManager& b){
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
 