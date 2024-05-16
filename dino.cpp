#include "dino.h"

using namespace std;

Dino::Dino()
{

    dino_x = 330;
    dino_y = 390;

    collision = {getX() + 20, getY() + 20, 68, 77 };

    for (int i=0; i<RUN_FRAME; i++)
    {
        runClips[i] = {i*FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE};
    }
    for (int i=0; i<COUCH_FRAME; i++)
    {
        couchClips[i] = {(i+16)*FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE};
    }
}

Dino::~Dino()
{

}

bool Dino::loadFromFile(string path, SDL_Renderer* renderer)
{
    bool res = Texture::loadFromFile(path, renderer);
    return res;
}

void Dino::HandleInput(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (ground)
            {
                y_val -=15;
                ground = false;
            }
            break;
        }

    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (!ground)
            {
                y_val += 5;
            }
            break;
        }
    }
}

void Dino::Gravity()
{
    if (!ground)
    {
        y_val += GRAVITY;
        if (y_val>=MAX_GRAVITY)
        {
            y_val=MAX_GRAVITY;
        }
    }
    else y_val = GRAVITY;
}

bool Dino::checkCollision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}
void Dino::Update(Obs* obs)
{
    Gravity();
    dino_y += y_val;

    collision.y = getY() + 20;


        if (checkCollision(collision, obs->getCollision()))
        {
            death = true;
        }
        if (dino_y>=390)
        {
            dino_y = 390;
            y_val = 0;
            ground = true;
        }


}
void Dino::Render(SDL_Renderer* renderer)
{
    if (!couch && !death)
    {
        couch_cnt = 0;
        renderClip(dino_x, dino_y, renderer, &runClips[run_cnt]);
        run_cnt++;
        if (run_cnt >= RUN_FRAME)
        {
            run_cnt =0;
        }
    }
    else if (!death)
    {
        run_cnt = 0;
        renderClip(dino_x, dino_y, renderer, &couchClips[couch_cnt]);
        couch_cnt++;
        if (couch_cnt >= COUCH_FRAME)
        {
            couch_cnt =0;
        }
    }

}




/*case SDLK_DOWN:
            couch =true;
            dino_y = 390;
            break;
case SDLK_DOWN:
            couch =true;
            dino_y = 390;
            break;
*/

