//
// Drive.hh for  in /home/olivie_a//naoqi-sdk-1.12.5-linux64/examples/drive
// 
// Made by samuel olivier
// Login   <olivie_a@epitech.net>
// 
// Started on  Wed Sep  5 23:47:40 2012 samuel olivier
// Last update Thu Nov 15 14:17:01 2012 samuel olivier
//

#ifndef __AUTO_DRIVE_HH__
# define __AUTO_DRIVE_HH__

# include <map>

# include <alcommon/almodule.h>
# include <PoseManager.hpp>
# include <Animation.hpp>
# include <atomic>
# include <thread>
# include <mutex>
# include <gst/gst.h>
# include <glib.h>
# include <gst/app/gstappsink.h>

# include "DriveProxy.hpp"

namespace AL
{
  class ALBroker;
}

class AutoDrive : public AL::ALModule
{
public:

  AutoDrive(boost::shared_ptr<AL::ALBroker> broker,
	    const std::string &name);
  virtual ~AutoDrive();

  typedef enum State {
    Up,
    Down,
    Stop
  } State;

  typedef enum Direction {
    Right,
    Left,
    Front
  } Direction;

  virtual void	init();
  void		start();
  void		stop();
  int		thread();
  void		getNextState(State &state,
			     Direction &direction,
			     double value);

private:

  boost::shared_ptr<AL::ALBroker>	_broker;
  DriveProxy*				_proxy;
  std::thread				*_thread;
  std::atomic<bool>			_stopThread;
  GstElement				*_pipeline;
};

#endif
