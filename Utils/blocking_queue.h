#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T>
class blocking_queue
{
private:
    std::mutex m_mutex;
    std::condition_variable m_condition;
    std::queue<T> m_queue;

public:
    void push(const T& value)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(value);
        lock.unlock();
        m_condition.notify_one();
    }
    void push(T&& value)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(std::move(value));
        lock.unlock();
        m_condition.notify_one();
    }
    void push_no_lock(const T& value)
    {
        m_queue.push(value);
    }
    void push_no_lock(T&& value)
    {
        m_queue.push(std::move(value));
    }
    T get()
    {
        std::unique_lock<std::mutex> lock(m_mutex, std::defer_lock);
        m_condition.wait(lock, [=]{ return !this->m_queue.empty(); });
        T ret(std::move(m_queue.front()));
        m_queue.pop();
        if (!m_queue.empty())
        {
            lock.unlock();
            m_condition.notify_one();
        }
        else { lock.unlock(); }
        return ret;
    }
    std::unique_lock<std::mutex> lock()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return lock;
    }
    void unlock(std::unique_lock<std::mutex>& lock)
    {
        lock.unlock();
        m_condition.notify_one();
        lock.release();
    }
};

#endif //!BLOCKING_QUEUE_H
