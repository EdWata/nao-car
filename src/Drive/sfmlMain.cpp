//
// sfmlMain.cpp for  in /home/olivie_a//rendu/nao/nao-car/src/Drive
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Wed Sep 26 15:45:37 2012 samuel olivier
// Last update Fri Sep 28 19:10:54 2012 samuel olivier
//

#include <iostream>
#include <alcommon/almodulecore.h>
#include <alcommon/almoduleinfo.h>
#include "sfWindow.hpp"

int main(int ac, char **av)
{
  if (ac != 2 && ac != 3)
    {
      std::cout << "Usage: " << av[0] << " ip [joystickId=1]" << std::endl;
      return (1);
    }
  boost::shared_ptr<AL::ALBroker> broker;
  try
    {
      broker = AL::ALBroker::createBroker("broker",
                                          "0.0.0.0",
                                          0,
                                          av[1],
                                          9559,
                                          0);      
    }
  catch (...)
    {
      std::cerr << "Error" << std::endl;
    }
  boost::shared_ptr< std::vector< AL::ALModuleInfo > >  pModuleList(new std::vector<AL::ALModuleInfo>());
  broker->getModuleList(pModuleList);
  for (int i = 0; i < pModuleList->size(); ++i)
    std::cout << pModuleList->at(i).name << std::endl;
  gst_init (&ac, &av);
  int id = 1;
  if (ac == 3)
    id = std::atoi(av[2]);
  Window	win(broker, id, av[1]);
  win.exec();
  return (0);
}
