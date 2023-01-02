#ifndef MATERIAL
#define MATERIAL

class Material { //bestenfalls abstract machen
    public:
        Material() = default;
        virtual float getPrice() = 0; //abstract machen
        

};

#endif