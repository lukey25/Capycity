#ifndef MATERIAL
#define MATERIAL

class Material { //bestenfalls abstract machen
    public:
        Material() = default;
        virtual float getPrice(){return 0.0f;};
        

};

#endif