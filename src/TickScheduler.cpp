#include "TickScheduler.h"

#include <algorithm>

void TickScheduler::add(tick_type amount, task_type task)
{
  if(amount == 0)
  {
    task();
  }
  else if(amount > 0)
  {
    m_tasks[m_elapsed + amount].push_back(std::move(task));
  }
}

void TickScheduler::tick()
{
  m_elapsed++;
  
  // Get the nearest set of scheduled tasks,
  // check if it is now,
  // and if so execute all tasks in the set and remove it from the map
  
  if(!m_tasks.empty())
  {
    const auto it = m_tasks.begin();

    if(it->first == m_elapsed)
    {
      for(task_type& task : it->second)
      {
        task();
      }

      m_tasks.erase(it);
    }
  } 
}

TickScheduler::tick_type TickScheduler::elapsed() const
{
  return m_elapsed;
}