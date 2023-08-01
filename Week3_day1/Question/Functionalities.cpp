#include "Functionalities.h"


void CreateEngineeringStudentsObject(Container &data)
{
    data.emplace_back(
        std::make_shared<EngineeringStudent>(
            1,
            EngineeringStudentBranch::CIVIL,
            600000.0F,
            8.09
        )
    );
    data.emplace_back(
        std::make_shared<EngineeringStudent>(
            "E2",
            EngineeringStudentBranch::CS,
            292929.0f,
            5.5f
        )
    );
    data.emplace_back(
        std::make_shared<EngineeringStudent>(
            3,
            EngineeringStudentBranch::ECE,
            1003.0f,
            9.9f
        )
    );
    data.emplace_back(
        std::make_shared<EngineeringStudent>(
            "E3",
            EngineeringStudentBranch::ELECTRONICS,
            500000.0f,
            7.73f
        )
    );
}

void CreateCommerceStudentObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<CommerceStudent>(
            1,
            CommerceStudentBranch::BANKING,
            292929.0f,
            5.5f
        )
    );
    data.emplace_back(
        std::make_shared<CommerceStudent>(
            "C2",
            CommerceStudentBranch::CA,
            30000.0f,
            9.9f
        )
    );
    data.emplace_back(
        std::make_shared<CommerceStudent>(
            3,
            CommerceStudentBranch::FINANCE,
            400000.0f,
            8.4f
        )
    );
    data.emplace_back(
        std::make_shared<CommerceStudent>(
            "C4",
            CommerceStudentBranch::CS,
            29292.0f,
            7.8f
        )
    );
}

std::optional<Container> FindAbove8CGPAInstances(Container &data)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    Container result;
    /*
        We are looping over data . data containes variants (either sharedptr to engineer 
        or to commerce student )
    */
    for(auto & a : data){
        std::visit([&](auto&& val){
            if(val->getStudentCGPA() > 8.0f){
                result.emplace_back(val);
            }
        },a);
    }
    if(result.empty()){
        return {};
    }
    else{
        return result;
    }
}

std::optional<Container> FindAbove10kScholarshipInstances(Container &data)
{
    if(data.empty()){
        throw std::runtime_error("EMPTY");
    }
    Container result;
    for(auto & a : data){
        std::visit([&](auto && val){
            if(val->CalculateScholarshipAmount() > 10000.0f){
                result.emplace_back(val);
            }
        },a);
    }
    if(result.empty())
    {
        return {};
    }
    else{
        return result;
    }
}

// beacause there something common behaviour between two classes and there is posibility to genralized them into one 
// then we use run time polymorphism

/*
    1. Optional visit and variant
    2. std::any Wrapper
    3. variadic templates
    4. fold expressions
    5. GAURANTEE COPY ELISION 
    6. structure binding
    7. constextr
*/