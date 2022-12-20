#ifndef MATERIAL
#define MATERIAL

class Material { //bestenfalls abstract machen
    public:
        Material();

    protected:
        virtual float getPrice();
        

};

#endif