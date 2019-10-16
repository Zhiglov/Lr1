#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class IOutput
{
public:
    virtual ~IOutput() = default;
    
    virtual string getOutputString() const = 0;
};

class Person : public IOutput
{
public:
    Person() = delete;
    Person & operator = (const Person & p) = delete;

    Person(const string & fio, const uint16_t age, uint16_t average_income,const string & party,uint16_t number_vote)
        : _fio(fio), _age(age), _average_income(average_income),_party(party),_number_vote(number_vote)
    {
    }

    const string & getFio() const { return _fio; }
    const string & getParty() const { return _party; }
    uint16_t       getAge() const { return _age; }
    uint16_t       getAverageIncome() const {return _average_income; }
    uint16_t       getNumberVote() const {return _number_vote;}
    virtual string getOutputString() const override
    {
        return _fio + ", " + to_string(_age) + " y.o , Average Income: " + to_string(_average_income) + ", Party: " + _party +", Number votes: " + to_string(_number_vote);
    }

private:

    string _fio;
    uint16_t _age;
    uint16_t _average_income;
    string _party;
    uint16_t _number_vote;

};

int main(int , char **)
{
    vector<unique_ptr<IOutput>> crew;

    crew.push_back(make_unique<Person>("Иван Иванов",  35,123455,"Машины",100));
    crew.push_back(make_unique<Person>("Леонид Леонидов", 45,784332,"Яблоко",123));
    crew.push_back(make_unique<Person>("Семён Семёнов", 51,90000,"Черешня",124));
    crew.push_back(make_unique<Person>("Алексей Алексеев", 39,120000,"Город",324));
    crew.push_back(make_unique<Person>("Пётр Петров", 41,10000,"Люстра",10));

    for(const auto & o : crew)
        cout << "\"" << o->getOutputString() << endl;

    return 0;
}

