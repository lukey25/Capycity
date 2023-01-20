#ifndef MATERIAL
#define MATERIAL

using std::string;

class Material { 
    public:
        Material() = default;
        virtual float getPrice() = 0; 
        string getName() {return name;};
    protected:
        string name;
        

};

#endif