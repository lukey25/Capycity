#ifndef MATERIAL
#define MATERIAL

using std::string;

class Material { //bestenfalls abstract machen
    public:
        Material() = default;
        virtual float getPrice() = 0; //abstract machen
        string getName() {return name;};
    protected:
        string name;
        

};

#endif