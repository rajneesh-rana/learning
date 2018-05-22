#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>     
 
typedef enum MessageType
{
    ERROR,
    WARNING,
    GENERAL,
}MessageType;
 
class Subject;
 
class Observer  // Logging Platform
{
public:
    virtual void update(Subject * pSubject) = 0;
    virtual ~Observer(){}
 
};
 
class Subject
{
    std::map<int , std::vector<Observer *> > registryMap;
    std::string data;
public:
    std::string getData()   { return data; }
    void setData(std::string value) { data = value; }
    void attach( int event, Observer * pObsrvr);
    void deattach( Observer * pObsrvr);
    void notify(int event);
};
 
void Subject::attach( int event, Observer * pObsrvr)
{
    registryMap[event].push_back(pObsrvr);
}
void Subject::deattach( Observer * pObsrvr)
{
    for (std::map<int , std::vector<Observer *> >::iterator it=registryMap.begin(); it!=registryMap.end(); ++it)
    {
        std::vector<Observer *>::iterator itV = std::find(it->second.begin(), it->second.end(), pObsrvr);
        if(itV != it->second.end())
        {
            it->second.erase(itV);
            continue;
        }
    }
}
void Subject::notify(int event)
{
    std::map<int , std::vector<Observer *> >::iterator it = registryMap.find(event);
    if(it != registryMap.end())
    {
        for(std::vector<Observer *>::iterator itV = it->second.begin(); itV != it->second.end(); itV++)
        {
            (*itV)->update(this);
        }
    }
}
 
class Logger : public Subject
{
    std::map<MessageType, int> messageStatusMap;
public:
    Logger()
    {
        messageStatusMap[ERROR] = true;
        messageStatusMap[WARNING] = true;
        messageStatusMap[GENERAL] = true;
    }
    void writeLog(MessageType type, std::string message)
    {
        if(messageStatusMap[type])
        {
            setData(message);
            notify(type);
        }
    }
    void enableLoggingOfMessage(MessageType type)
    {
        messageStatusMap[type] = true;
    }
    void disableLoggingOfMessage(MessageType type)
    {
        messageStatusMap[type] = false;
    }
};
 
class ConsoleLoggingPlatform : public Observer
{
    public:
    void update(Subject * pSubject)
    {
        std::cout<<pSubject->getData()<<std::endl;
    }
};
class FlatFileLoggingPlatform : public Observer
{
    std::string fileName;
public:
    FlatFileLoggingPlatform(std::string name) : fileName(name) {}
    void update(Subject * pSubject)
    {
        std::string data = pSubject->getData();
        std::cout<<"Written in file "<<data<<std::endl;
        // Add data to file
    }
};
class NetworkLoggingPlatform : public Observer
{
    public:
    void update(Subject * pSubject)
    {
        std::string data = pSubject->getData();
        std::cout<<"Sent on network "<<data<<std::endl;
        // Send data in network
    }
};
 
int main()
{
    Logger * pLogger = new Logger();
    ConsoleLoggingPlatform * pConsolePlatform = new ConsoleLoggingPlatform();
    FlatFileLoggingPlatform * pFilePlatform = new FlatFileLoggingPlatform("temp");
    NetworkLoggingPlatform * pNetworkPlatform = new NetworkLoggingPlatform();
 
    pLogger->attach(ERROR, pConsolePlatform);
    pLogger->attach(WARNING, pConsolePlatform);
    pLogger->attach(GENERAL, pConsolePlatform);
    pLogger->attach(ERROR, pFilePlatform);
    pLogger->attach(GENERAL, pNetworkPlatform);
 
    pLogger->writeLog(ERROR, "This is error");
    pLogger->writeLog(WARNING, "This is warning");
    pLogger->writeLog(GENERAL, "This is general message");
 
    pLogger->disableLoggingOfMessage(ERROR);
    pLogger->deattach(pConsolePlatform);
 
    pLogger->writeLog(ERROR, "This is error 2");
    pLogger->writeLog(GENERAL, "This is general message 2");
 
    delete pNetworkPlatform;
    delete pFilePlatform;
    delete pConsolePlatform;
    delete pLogger;
 
    return 0;
}
