#include "Application.h"

#include "raylib.h"

Application::Application(int width, int height, const std::string& title)
	: m_width(width)
	, m_height(height)
	, m_title(title)
{

}

Application::~Application()
{
	shutdown();
}

void Application::run()
{
	InitWindow(m_width, m_height, m_title.c_str());
	SetTargetFPS(60);

	init();
	m_running = true;

	while (!WindowShouldClose())
	{
		update();
		render();
	}

	shutdown();
	CloseWindow();
}

void Application::init()
{

}

void Application::update()
{

}

void Application::render()
{

}

void Application::shutdown()
{

}

