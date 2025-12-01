#include "SDL.h"
#include "Renderer.h"
#include "SDL_Resource.h"
#include "RenderManager.h"
#include "Game.h"
#include "Transform.h"

#undef main

// ResourceManager 

/* TODO: Make resourcemanager implementation separate file
*/

struct ResourceImpl
{
	/* TODO: Get texture and resource impl can be made noexcept
	* Refactor to make use of less pointers
	* Make the pointers unique pointers
	* Uninitialized
	* Rewrite the get texture with a algorithm
	*/
	ResourceImpl(SDL_Renderer* renderer) : renderer(renderer) {};
	std::vector<std::pair<std::string, SDL_Texture*>> textures;
	SDL_Renderer* renderer;
	SDL_Texture* GetTexture(unsigned int id)
	{
		if (id < textures.size())
			return textures[id].second;
		else
			return nullptr;
	}
};



// RenderManager


/* TODO: Change name to add something to symbolize the functions adding to the sprite and rect
*  Probably can make all three noexcept maybe const
*/


void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Clear()
{
	
	rectEntries.clear();
}




int main()
{
	/* TODO: Look into removing all of the render stuff
	*  width and height can be made const, dt can be made const
	*  Make the game throw an exception if the things are nullptr
	*/
	Game game;

	SDL_Resource resource;
	Window window(game.get_width(), game.get_height(), game.get_title(), 0);
	Renderer renderer(window, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	bool running = true;

	float dt = 1.0f / 60.0f;

	/* TODO: Potentially remove the sprite drawing logic and just draw rectangles
	*/
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(e.key.keysym.sym); break;

			}
		}

		game.Update(dt, renderer);
		
	}

	return 0;
}
