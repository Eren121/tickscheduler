#ifndef TICKSCHEDULER_TICKSCHEDULER_H_INCLUDED
#define TICKSCHEDULER_TICKSCHEDULER_H_INCLUDED

#include <cstdint>
#include <functional>
#include <map>
#include <vector>

/**
 * Defines a tick-based task scheduler.
 * 
 * Tick :
 * 
 * You can execute tasks after N ticks. TickScheduler actually doesn't know what a tick is.
 * So you can't use this for precise time based task scheduling, unless you
 * don't need big precision and you consider 1 tick = 1 second.
 */
class TickScheduler
{
public:
  using task_type = std::function<void()>;
  using tick_type = int64_t;

  /**
   * Schedule a task to be executed in a certain amount of ticks.
   * Execute the task \p task in \p amount ticks in the future.
   * 
   * @param task The task to execute in the future.
   * 
   * @param amount The amount of ticks to wait before executing the task.
   * If amount == 0, the task is executed right now.
   * If amount < 0, this function is a no-op.
   */
  void add(tick_type amount, task_type task);

  /**
   * Call this to notify the scheduler to go forward 1 tick.
   */
  void tick();

  /**
   * Get the amount of elapsed time since the initialization of the scheduler.
   */
  tick_type elapsed() const;

private:
  using TaskSet = std::vector<task_type>;

  /**
   * All scheduled tasks.
   * 
   * @remarks
   * The key is the **absolute** tick of the task.
   * We use absolute tick because it is easier to manage because of each
   * insertion would offset each relative amount of ticks of the next tasks.
   * 
   * You can still do 1 billion of ticks per second during 100'000 years
   * (2^63 / 3600 / 24 / 1e9 = 100'000). Just be care if you use
   * batch ticks.
   * 
   * 
   * @remarks
   * We use a map also because it is a convenient sorted container with
   * good search complexity.
   * 
   * @remarks
   * Since the map key is constant, we can't decrement it each tick so we have
   */
  std::map<tick_type, TaskSet> m_tasks;

  /**
   * Ticks elapsed since the initialization of the set.
   */
  tick_type m_elapsed = {};

  using map_pair = decltype(m_tasks)::value_type;
};

#endif // TICKSCHEDULER_TICKSCHEDULER_H_INCLUDED