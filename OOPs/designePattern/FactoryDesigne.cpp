// #include <iostream>
// #include <memory>
// using namespace std;

// // Step 1: Base class (Interface)
// class Shape {
// public:
//     virtual void draw() = 0; // pure virtual function
//     virtual ~Shape() {}
// };

// // Step 2: Concrete classes
// class Circle : public Shape {
// public:
//     void draw() override {
//         cout << "Drawing Circle" << endl;
//     }
// };

// class Square : public Shape {
// public:
//     void draw() override {
//         cout << "Drawing Square" << endl;
//     }
// };

// // Step 3: Factory class
// class ShapeFactory {
// public:
//     static unique_ptr<Shape> createShape(const string& type) {
//         if (type == "circle") {
//             return make_unique<Circle>();
//         } else if (type == "square") {
//             return make_unique<Square>();
//         } else {
//             return nullptr;
//         }
//     }
// };

// // Main function to use the factory
// int main() {
//     auto shape1 = ShapeFactory::createShape("circle");
//     if (shape1) shape1->draw();

//     auto shape2 = ShapeFactory::createShape("square");
//     if (shape2) shape2->draw();

//     auto shape3 = ShapeFa    tory::createShape("triangle"); // Invalid input
//     if (!shape3) cout << "Invalid shape type!" << endl;

//     return 0;
// }









// class IGameObject{
//     public:
//     virtual ~IGameObject(){};
//     virtual void Update()=0;
//     virtual void Render()=0;
// };

// class Plane: public IGameObject{
//     public:
//     Plane(){};
//     void Update ()override {}
//     void Render ()override {}
// };

// class Boat: public IGameObject{
//     public:
//       Boat(){cout<<"this is me sahil "};
//      void Update ()override {}
//      void Render ()override {}
// };



// int main(){
//     Plane planeObj= new Plane(); 
//     return 0;
// }










// #include<bits/stdc++.h>
// using namespace std;

// class IGameObject{
//     public:
//     virtual ~IGameObject(){};
//     virtual void Update()=0;
//     virtual void Render()=0;
// };

// class Plane: public IGameObject{
//     public:
//     Plane(){};
//     void Update ()override {}
//     void Render ()override {}
// };

// class Boat: public IGameObject{
//     public:
//       Boat(){cout<<"this is me sahil ";};
//      void Update ()override {cout<<"this is me sahil ";}
//      void Render ()override {}
// };
// enum class ObjectType {PLANE, BOAT};

// static unique_ptr<IGameObject> MakeGameObjectFactory (ObjectType type){
//     if(ObjectType::PLANE==type){
//         return unique_ptr<Plane>();
//     }else if(ObjectType::BOAT==type){
//         return unique_ptr<Boat>();
//     }
//     return nullptr;
// }

// int main(){
//     unique_ptr<IGameObject> Obj1 =  MakeGameObjectFactory(ObjectType::BOAT);
//   Obj1.Update()
//     return 0;
// }

















#include<bits/stdc++.h>
using namespace std;

class IGameObject{
    public:
    virtual ~IGameObject(){};
    virtual void Update()=0;
    virtual void Render()=0;
};

class Plane: public IGameObject{
    public:
    Plane(){};
    void Update ()override {}
    void Render ()override {}
};

class Boat: public IGameObject{
    public:
      Boat(){cout<<"this is me sahil ";};
     void Update ()override {cout<<"this is me sahil ";}
     void Render ()override {}
};
enum class ObjectType {PLANE, BOAT};

class FactoryGameObjects{
    public:
    static unique_ptr<IGameObject> createObjects (ObjectType type){
    if(ObjectType::PLANE==type){
        s_palnes++;
        return unique_ptr<Plane>();
    }else if(ObjectType::BOAT==type){
        s_boats++;
        return unique_ptr<Boat>();
    }
    return nullptr;
}

static void PrintCounts (){
    cout<<"Plane Counter ==> " << s_palnes<<endl;
     cout<<"Boat Counter ==> " << s_boats<<endl;
}
private :
FactoryGameObjects(){};
~FactoryGameObjects(){};
FactoryGameObjects(const FactoryGameObjects &o){};
static int s_palnes;
static int s_boats;
};


int FactoryGameObjects::s_palnes=0;
int FactoryGameObjects::s_boats=0;


int main(){
    // unique_ptr<IGameObject> Obj1 =  MakeGameObjectFactory(ObjectType::BOAT);
    unique_ptr<IGameObject> obj1 =  FactoryGameObjects ::createObjects(ObjectType::PLANE);
     unique_ptr<IGameObject> obj2 =  FactoryGameObjects ::createObjects(ObjectType::BOAT);
 FactoryGameObjects::PrintCounts();
    return 0;
}