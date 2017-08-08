/* 
 * Copyright (C) 2012 Istituto Italiano di Tecnologia (IIT)
 * Author: Elena Ceseracciu
 * email:  elena.ceseracciu@iit.it
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <iostream>
#include <yarp/os/all.h>

#include <Demo.h>

// ************************************* //
// We implement the Demo interface
// ************************************* //
class DemoServerModule : public Demo, public yarp::os::RFModule
{
  // Class members declaration
  int32_t answer;
  bool isRunning;

  yarp::os::Port cmdPort;
public:
  DemoServerModule();
  // ******************************************
  // Function declarations, copied from Demo.h 
  // ******************************************
  virtual int32_t get_answer();
  virtual bool set_answer(int32_t rightAnswer);
  virtual int32_t add_one(const int32_t x);
  virtual bool start();
  virtual bool stop();
  virtual bool is_running();

  //  virtual bool read(yarp::os::ConnectionReader& connection);
  
  // ******************************************
  // RFModule functions declaration
  // ******************************************
  
  bool attach(yarp::os::Port &source);
  bool configure( yarp::os::ResourceFinder &rf );
  bool updateModule();
  bool close();  
};

//implementation of each function:
DemoServerModule::DemoServerModule()
{
  // members initialization
  answer=42;
  isRunning=false;
  std::cout << "I know the answer!"<< std::endl; 
}

int32_t DemoServerModule::get_answer()
{
  std::cout << "The answer is "<< answer << std::endl;   
  return answer;
}
bool DemoServerModule::set_answer(int32_t rightAnswer)
{
  std::cout << "OMG are you serious? The answer is "<< rightAnswer << "?!?" << std::endl;  
  answer=rightAnswer;
  return true;
}

int32_t DemoServerModule::add_one(const int32_t x)
{
  std::cout << "I'm adding one to "<< x << ". That's easy :) " << std::endl;  
  return x+1;
}

bool DemoServerModule::start()
{
  std::cout << "Starting!" << std::endl;  
  isRunning=true;
  return true;
}

bool DemoServerModule::stop()
{
  std::cout << "Stopping!" << std::endl;  
  isRunning=false;
  return true;
}

bool DemoServerModule::is_running()
{
  std::cout << "Indeed I am " << (isRunning ? "" : "not ") << "running" << std::endl;  
  return isRunning;
}

// 
// RFModule implementation


bool DemoServerModule::attach(yarp::os::Port &source)
{
    return this->yarp().attachAsServer(source);
}
bool DemoServerModule::configure( yarp::os::ResourceFinder &rf )
{
    std::string moduleName = rf.check("name", 
            yarp::os::Value("demoServerModule"), 
            "module name (string)").asString().c_str();
    setName(moduleName.c_str());
    
    std::string slash="/";
    
    attach(cmdPort);
    
    std::string cmdPortName= "/";
    cmdPortName+= getName();
    cmdPortName += "/cmd";
    if (!cmdPort.open(cmdPortName.c_str())) {           
        std::cout << getName() << ": Unable to open port " << cmdPortName << std::endl;  
        return false;
    }
    return true;
}   
bool DemoServerModule::updateModule()
{
    //do something very useful

    return true;
}
bool DemoServerModule::close()
{
    cmdPort.close(); 
    return true;
}

// ************************************* //
// Check YARP and run the module
// ************************************* //
int main(int argc, char *argv[]) {
    yarp::os::Network yarp;
    if (!yarp.checkNetwork())
    {
        std::cout<<"Error: yarp server does not seem available"<<std::endl;
        return -1;
    }
    
    yarp::os::ResourceFinder rf;
    rf.setVerbose(true);
    rf.configure("YARP_POLICY", argc, argv);

    DemoServerModule demoMod; 

    if (!demoMod.configure(rf))
        return -1;

    return demoMod.runModule();
}
