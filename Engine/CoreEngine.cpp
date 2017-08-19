#include "CoreEngine.h"

#include "SDL.h"
#include "Managers\ManagerSystem.h"
#include "Managers\LogManager.h"
#include "Managers\DeviceManager.h"
#include "Managers\InputManager.h"
#include "Managers\ObjectManager.h"
#include "Managers\CameraManager.h"
#include "Managers\RenderManager.h"

namespace Engine {

	CoreEngine::CoreEngine(const char *title, int width, int height, double frames_per_second) :
		title_(title),
		width_(width),
		height_(height) ,
		frames_per_second_limit_(frames_per_second)
	{
		
	}
	
	CoreEngine::~CoreEngine() {
	}

	bool CoreEngine::init() {
		bool sdl_initialized = SDL::init();

		if (!sdl_initialized) {
			return false;
		}

		// register managers
		ManagerSystem::getInstance().registerManager<LogManager>();
		ManagerSystem::getInstance().registerManager<DeviceManager>();
		ManagerSystem::getInstance().registerManager<InputManager>();
		ManagerSystem::getInstance().registerManager<ObjectManager>();
		ManagerSystem::getInstance().registerManager<CameraManager>();
		ManagerSystem::getInstance().registerManager<RenderManager>();

		// initialize core manager stuff
		pDeviceManager->createWindow(title_, width_, height_);
		pCameraManager->setupDefaultCamera((float)pDeviceManager->getWindowWidth(), (float)pDeviceManager->getWindowHeight());

		return true;
	}

	void CoreEngine::deinit() {
		game_->deinit();
		ManagerSystem::getInstance().unregisterManagers();
		SDL::deinit();
	}

	void CoreEngine::run() {
		game_->init();

		bool should_render;

		int frames = 0;
		double frame_time = 1.0 / frames_per_second_limit_;
		double frame_counter = 0;

		double current_time = 0;
		double previous_time = 0;
		double elapsed_time = 0;
		double lag = 0;

		frames_per_second_ = 0;

		while (!pInputManager->getQuitRequested()) {
			should_render = false;

			current_time = SDL_GetTicks() * 0.001;
			elapsed_time = current_time - previous_time;
			previous_time = current_time;

			lag += elapsed_time;
			frame_counter += elapsed_time;

			while (lag >= frame_time) {
				update((float)frame_time);

				should_render = true;
				lag -= frame_time;

				if (frame_counter >= 1.0) {
					frames_per_second_ = frames;
					frames = 0;
					frame_counter = 0;
				}
			}

			if (should_render) {
				render();
				frames++;
			}
			else {
				SDL_Delay(1);
			}
		}
	}

	const char * CoreEngine::getTitle() const {
		return title_;
	}

	const int& CoreEngine::getWidth() const {
		return width_;
	}

	const int& CoreEngine::getHeight() const {
		return height_;
	}

	const float CoreEngine::getFramesPerSecond() const {
		return (float) frames_per_second_;
	}

	void CoreEngine::setGame(Game* game) {
		game_ = game;
	}

	void CoreEngine::update(const float &frame_time) {
		pInputManager->update();
		game_->update(frame_time);
	}

	void CoreEngine::render() {
		pRenderManager->render();
	}
}