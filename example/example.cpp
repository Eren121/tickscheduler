#include <iostream>
#include <cstdlib>
#include <sstream>
#include "TickScheduler.h"

std::function<void()> createTask(const std::string &message)
{
  return [message]() {
    std::cout << message << std::endl;
  };
}

int main(int main, char *argv[])
{
  TickScheduler scheduler;

  for(int i : {0, 5, 20, 50, 80})
  {
    std::ostringstream ss;
    ss << " hello (after " << i << " ticks)";

    scheduler.add(i, createTask(ss.str()));
  }
/*  */
  for(int i = 0; i < 100; i++) {
    
    if(i % 10 == 0)
    {
      std::ostringstream ss;
      ss << " hello (submitted at tick "
         << scheduler.elapsed()
         << " to run after 50 ticks";

      scheduler.add(50, createTask(ss.str()));
    }

    std::cout << "==== tick " << (i + 1) << ":" << std::endl;
    scheduler.tick();
  }

  return EXIT_SUCCESS;
}