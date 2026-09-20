#include "Resource.h"
#include <vector>
//Open with a default constuctor
Resource::Resource()


//This is an overloaded constructor with all the four accessors
Resource::Resource(const string& id, const string& name, const string& type, bool available)
{}
//lets initialize the variables above
     : resourceID(id), 
       resourceName(name), 
       resourceType(type), 
       isAvailable(available);
{}

//After this we need to have a return for all of the above
//The getters allows some of the parts to access private variables
string& Resource::getResourceID() const{
    return resourceID;
}
string& Resource::getResourceName() const{
    return resourceName;
}
string& Resource::getResourceType() const{
    return resourceType;
}
bool Resource::getIsAvailable(){
    return isAvailable;
}
//void allows us to change whats inside the function
//So we will have a different id, name, and the type
void Resource::setResourceName(const string& name)
{
    resourceName = name;
}
void Resource::setResourceType(const string& type)
{
    resourceType = type;
}
void Resource::setAvailable(bool available)
{
    isAvailable = available;
}
void Resource::display() const{  //This function displays everthing on resource
     cout << *this <<endl;//this allows the dispaly of the current resource
}
//we need to display our resource as a referrence
//the operator is for overloading
//
ostream& operator<<(ostream& os, const Resource& resource){


string availabilityStatus;
if (resource.isAvailable ==true){
    availabilityStatus = "Available";
}
else{
    availabilityStatus= "Unavailable";
}
//instead of repeating cout we use os

os << "ID: "<< resource.resourceID
   << " | Name: " << resource.resourceName
   << " | Type: " << resource.resourceType
   << " | Status: "<< availabilityStatus;

return os;
}
//This operator compares two resources two see if us the same ID
bool Resource::operator==(const Resource& other) const
{
    if(resourceID == other.resourceID){
        return true;
    }
    else{
        return false;
    }
    
}
