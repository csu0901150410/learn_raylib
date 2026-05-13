#pragma once

#include <string>

class Application
{
public:
    Application(int width, int height, const std::string& title);
    ~Application();

    void run();

private:
    virtual void init();
    virtual void update();
    virtual void render();
    virtual void shutdown();

private:
    int m_width;
    int m_height;
    std::string m_title;

    bool m_running = false;
};
