#pragma once

#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

typedef std::chrono::milliseconds Interval; //do zmiany na minuty/sekundy
typedef std::function<void(void)> Callback;

class i_Timer
{
    virtual void start(const Interval& interval, const Callback& timeoutCallback) = 0;
    virtual void stop() = 0;
};

class Timer : public i_Timer 
{
public:
    virtual ~Timer();

    void start(const Interval& interval, const Callback& timeoutCallback) override;
    void stop() override;

private:
    std::thread m_timerThread{};
    std::atomic_bool m_timerIsRunning{};
};
